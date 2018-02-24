#!/usr/bin/python

import os
import sys
import re
import struct
import crcmod

BOOTLOADER_SIZE = 0x10000  # The size of sboot is 64K bytes.
PM_CODE_SIZE = 0x10000     # The size of PM code is 64K bytes.
CHUNK_HEADER_SIZE = 0x80   # The size of chunk header is 128 bytes.
UNCOMPRESSED_LEN = 0x3800  # The size of uncompressed part is 14K bytes.

bLittleEndian = False
bCRC16Enable  = True
bMultiFlash = False

CRC16 = crcmod.mkCrcFun(0x18005, 0, 0)
CRC32 = crcmod.mkCrcFun(0x104C11DB7, 0, 0)
LZSS = "./scripts/lzss/lzss.out c "
MSCOMP = "./scripts/util/mscompress -c -u 0 -9 "
MSCOMP7 = "./scripts/util/mscompress7 e 0 "

FLAG_COMPRESS = 0x01
FLAG_FLASH2   = 0x02
FLAG_MSCOMPRESS = 0x04
FLAG_MSCOMPRESS7 = 0x08

def getFlashTable2(data):
    print "getFlashTable2()"
    merge_bin_size = len(data)
    print "merge_bin_size = 0x%X" % (merge_bin_size)
    magic = struct.pack("BBBB", 0x39, 0xB6, 0x5B, 0x53)
    tbl2 = data.find(magic)
    print ".isp_info at 0x%X" % (tbl2)
    if tbl2 < 0:
        return None
    for i in '\x01' + data[tbl2+4:tbl2+10]:
        n = tbl2 + 10
        #print "i=%s, n=0x%X" % (i, n)
        while True:
            if n > (merge_bin_size-4):
                print "n=0x%X" % n
                break
            u16Len = struct.unpack('>H', data[n:n+2])[0]
            if u16Len == 0xFFFF:
                n += 2
                break
            u16Len >>= 14
            n += (2 + (u16Len + 1) * 2)

    print ".isp_info tbl1 end at 0x%X" % (n)

    return data[tbl2:n]


def parseBinIDInfo(binid_fn):
    bin_map = {}
    define = re.compile('^\s*#define\s+(\S+)\s+(\S+)\s+//~([0-9]+)KB(\+[0-9]*)?\s+//@(\S+)\s+(..*)?')
    f_binid = open(binid_fn)
    for l in f_binid:
        m = define.match(l)
        if (m):
            id = int(m.group(2).strip(), 16)
            len = int(m.group(3), 10) * 1024
            if m.group(4) is not None:
                len = len + int(m.group(4), 10)
            fn = m.group(5).strip().replace('\\', '/')
            flags = 0
            if m.group(6) is not None:
                if m.group(6).find('-c') >= 0:
                    flags |= FLAG_COMPRESS
                if m.group(6).find('-g') >= 0:
                    flags |= FLAG_MSCOMPRESS
                if m.group(6).find('-7') >= 0:
                    flags |= FLAG_MSCOMPRESS7
                if m.group(6).find('-2') >= 0:
                    flags |= FLAG_FLASH2
            bin_map[id] = (fn, len, flags)

    return bin_map

def doPack(bin_align, file_align, magic, dst_fn, binid_fn, ImgInfo_Offset, ap_c_fn, compress_format):
    print "doPack()"
    print "magic = %s" % (magic)
    #print "dst_fn = %s" % (dst_fn)
    dir = os.path.dirname(binid_fn)
    bin_id = parseBinIDInfo(binid_fn)
    f = open(dst_fn, 'r+b', 0)
    data = f.read()
    data_size = len(data)
    print "data_size = 0x%X" % (data_size)
    tail = f.tell()
    tail = ((tail + file_align - 1) / file_align) * file_align
    tbl2 = getFlashTable2(data)
    
    magic = int(magic, 16)
    print "magic-2 = 0x%X" % (magic)
    magic = struct.pack("BBBBB",
                        (magic >> 32) & 0xFF,
                        (magic >> 24) & 0xFF,
                        (magic >> 16) & 0xFF,
                        (magic >> 8)  & 0xFF,
                        (magic >> 0)  & 0xFF)
    #print "magic-3", (magic)                        
    idx_magic = data.find(magic)
    print "magic-5: 0x%X" % (idx_magic)

    if idx_magic < 0:
        i = 5
        while i > 0:
            sys.stderr.write('\x1b[31m Could not find magic signature \x1b[0m\n')
            i -= 1 

    else:
        idx_count = idx_magic + len(magic)
        flash_leftsize = struct.unpack('>L', data[idx_count:idx_count+4])[0] # Get left flash size
        idx_count = idx_count + 4
        idx_item  = idx_count + 2
        count = 0
        while True:
            (id, ) = struct.unpack('>H', data[idx_item:idx_item+2])
            if id == 0xF000:
                break
            count = count + 1
            tail = (tail + (bin_align - 1)) & ~(bin_align - 1)

            (fn, rs, flags) = bin_id[id]

            try:
                if bMultiFlash and (flags & FLAG_FLASH2):
                    flash2_bin.append(id)
                    f.seek(idx_item + 2)
                    f.write(struct.pack('>L', 0))
                    f.write(struct.pack('>L', 0))
                    f.write(struct.pack('>B', 0x80 | ((flags & FLAG_COMPRESS) != 0)))
                else:
                    if flags & FLAG_COMPRESS:
    				    os.system(LZSS + dir + "/../" + fn + " " + dir + "/../" + fn + "c");
    				    fn = fn + "c"
                    if flags & FLAG_MSCOMPRESS:
    				    os.system(MSCOMP + dir + "/../" + fn + " > " + dir + "/../" + fn + "c");
    				    fn = fn + "c"
                    if flags & FLAG_MSCOMPRESS7:
    				    os.system(MSCOMP7 + dir + "/../" + fn + " " + dir + "/../" + fn + "c");
    				    fn = fn + "c"
                    b = open(dir + "/../" + fn, "rb")
                    d = b.read()
                    bin_file_ori_size = len(d)
                    d += '\x00' * (8 - ((len(d) + 2) % 8))  # padding + CRC16
                    bin_size_2 = len(d)
                    bin_crc16 = CRC16(d)
                    #bin_crc32 = CRC32(d)
                    #print  "crc16=0x%X" % CRC16(d)
                    d += struct.pack('>H', CRC16(d))

                    print "%04X @ %06X %6X %X %04X %s" % (id, tail, len(d), flags, bin_crc16, fn)
                    #print "0x%X crc16=%X, bin_crc32=%X" % (bin_size_2, bin_crc16, bin_crc32 )

                    f.seek(idx_item + 2)
                    f.write(struct.pack('>L', tail))
                    f.write(struct.pack('>L', len(d)))
                    f.write(struct.pack('>B', (flags & FLAG_COMPRESS)|(flags & FLAG_MSCOMPRESS)|(flags & FLAG_MSCOMPRESS7) ))

                    f.seek(tail, 0)
                    f.write(d)

                    tail = tail + len(d)

                    b.close()
            except IOError, e:
                sys.stderr.write(str(e) + '\n')
                quit(2)

            idx_item = idx_item + 11

        f.seek(idx_count)
        f.write(struct.pack('>H', count))

    print '\x1b[35m%s:\n\t\t 0x%X octets (%f KB / %f MB)\x1b[0m' % (dst_fn, tail, tail / 1024.0, tail / 1024.0 / 1024.0)

    fcompress = open(ap_c_fn, 'r+b', 0)
    datac = fcompress.read()
    len_of_AP = fcompress.tell()
    #print "\x1b[35m After compress: 0x%X octets (%f KB / %f MB)\x1b[0m" % (len_of_AP, len_of_AP / 1024.0, len_of_AP / 1024.0 / 1024.0)
    print '\x1b[35m%s:\n\t\t 0x%X octets (%f KB / %f MB)\x1b[0m' % (ap_c_fn, len_of_AP, len_of_AP / 1024.0, len_of_AP / 1024.0 / 1024.0)
    fcompress.close()
    if compress_format == '0':
        CompressMagicNum = 0x00DEADBE
    else:
        CompressMagicNum = 0x00DEADEF
    CompressMagicNum = struct.pack("BBB",
                        (CompressMagicNum >> 0) & 0xFF,
                        (CompressMagicNum >> 8) & 0xFF,
                        (CompressMagicNum >> 16)  & 0xFF)
    f.seek((BOOTLOADER_SIZE + ImgInfo_Offset + 0x47))
    f.write(CompressMagicNum)

    #len_of_AP is the size of AP_C.bin
    len_of_AP_bytes = struct.pack("BBBB",
                        (len_of_AP >> 0) & 0xFF,
                        (len_of_AP >> 8) & 0xFF,
                        (len_of_AP >> 16)  & 0xFF,
                        (len_of_AP >> 24)  & 0xFF)
    f.seek((BOOTLOADER_SIZE + ImgInfo_Offset + 0x4A))
    f.write(len_of_AP_bytes)

    f.seek(BOOTLOADER_SIZE)
    data = f.read(len(data) - BOOTLOADER_SIZE - 2)
    crc = struct.pack('>H', CRC16(data))
    print "crc16  %X" % (CRC16(data))

    f.write(crc)

    # calculate CRC32 of AP_C.bin and then write CRC32 into chunk_header (offset: 0x14)
    f.seek((BOOTLOADER_SIZE + PM_CODE_SIZE + CHUNK_HEADER_SIZE))
    data = f.read(len_of_AP)
    crc32 = CRC32(data)
    crc32_bytes = struct.pack("BBBB",
                        (crc32 >> 0) & 0xFF,
                        (crc32 >> 8) & 0xFF,
                        (crc32 >> 16)  & 0xFF,
                        (crc32 >> 24)  & 0xFF)
    print "crc32 of AP %X" % (crc32)
    f.seek((BOOTLOADER_SIZE + PM_CODE_SIZE + 0x14))
    f.write(crc32_bytes)

    # cal file size and then write "file_size" into chunk_header (offset: 0x1C)
    file_size = tail + 4
    file_size_bytes = struct.pack("BBBB",
                        (file_size >> 0) & 0xFF,
                        (file_size >> 8) & 0xFF,
                        (file_size >> 16)  & 0xFF,
                        (file_size >> 24)  & 0xFF)
    print '\x1b[35mPACK: file_size: 0x%X octets (%f KB / %f MB)\x1b[0m\n' % (file_size, file_size / 1024.0, file_size / 1024.0 / 1024.0)
    f.seek((BOOTLOADER_SIZE + PM_CODE_SIZE + 0x1C))
    f.write(file_size_bytes)


    # write out AP.bin with bin_info for Obama
    ap = open(os.path.dirname(dst_fn) + '/AP_INFO.bin', 'wb')
    ap.write(data + crc)
    ap.close()

    f.seek(0)
    crc = struct.pack('>L', CRC32(f.read()))
    f.write(crc)

    f.close()

    #
    # flash2
    #
    if len(flash2_bin) > 0:
        i = dst_fn.find('.')
        if i >= 0:
            dst_fn = dst_fn[0:i] + '2' + dst_fn[i:]
        else:
            dst_fn = dst_fn + '2'

        f = open(dst_fn, 'w+b', 0)

        f.write(magic)

        f.write(struct.pack('>H', len(flash2_bin)))

        for id in flash2_bin:
            f.write(struct.pack('>H', id))
            f.write(struct.pack('>L', 0))
            f.write(struct.pack('>L', 0))
            f.write(struct.pack('>B', 0x80))

        f.write(struct.pack('>H', 0xF000))
        f.write(struct.pack('>L', 0))
        f.write(struct.pack('>L', 0))
        f.write(struct.pack('>B', 0x80))

        if tbl2 != None:
            f.write(tbl2)

        idx_item = 7
        tail = f.tell()
        tail = (tail + (bin_align - 1)) & ~(bin_align - 1)

        for id in flash2_bin:
            tail = (tail + (bin_align - 1)) & ~(bin_align - 1)

            (fn, rs, flags) = bin_id[id]

            try:
                if flags & FLAG_COMPRESS:
				    os.system(LZSS + dir + "/../" + fn + " " + dir + "/../" + fn + "c");
				    fn = fn + "c"
                b = open(dir + "/../" + fn, "rb")
                d = b.read()

                d += '\x00' * (8 - ((len(d) + 2) % 8))  # padding + CRC16
                d += struct.pack('>H', CRC16(d))

                print "%04X @ %06X %6X %X %s" % (id, tail, len(d), flags, fn)

                f.seek(idx_item + 2)
                f.write(struct.pack('>L', tail))
                f.write(struct.pack('>L', len(d)))
                f.write(struct.pack('>B', 0x80 | ((flags & FLAG_COMPRESS) != 0)))

                f.seek(tail, 0)
                f.write(d)

                tail = tail + len(d)

                b.close()
            except IOError, e:
                sys.stderr.write(str(e) + '\n')
                quit(2)

            idx_item = idx_item + 11

        print '%s:\n\t0x%X octets (%f KB / %f MB)' % (dst_fn, tail, tail / 1024.0, tail / 1024.0 / 1024.0)

    f.close()

    if tail > flash_leftsize:
        sys.stderr.write("\x1b[31m\n\n *************************   Warning   ******************************\n")
        sys.stderr.write(" *    File size larger than 0x%X! Flash will be overwrite!!!    *" % (flash_leftsize))
        sys.stderr.write("\n ********************************************************************\x1b[0m\n\n")

if __name__ == '__main__':
    args = []

    for arg in sys.argv[1:]:
        l_arg = arg.lower()
        if l_arg == '-bigendian':
            bLittleEndian = False
        elif l_arg == '-littleendian':
            bLittleEndian = True
        elif l_arg == '-crc16enable':
            bCRC16Enable = True
        elif l_arg == '-crc16disable':
            bCRC16Enable = False
        elif l_arg == '-multiflash':
            bMultiFlash = True
        else:
            args.append(arg)

    bin_align = int(args[0])
    file_align = int(args[1])
    magic = args[2]
    dst_fn = args[3]
    binid_fn = args[4]
    ImgInfo_Offset = int(args[5])
    ap_c_fn = args[6]
    compress_format = args[7]
    os_type = args[8]
    flash2_bin = []

    #print "\x1b[35m"
    #print "%s %s %s %s %s" % (args[0], args[1], args[2], args[3], args[4])

    #print "\x1b[35m"
    print "bin_align=%d" % bin_align
    print "file_align=%d" % file_align
    print "magic=%s" % magic
    print "dst_fn=%s" % dst_fn
    print "os_type=%s" % os_type
    #print "\x1b[0m"

    (z,y,x,w,v) = os.uname()
    #print "%s %s %s %s %s \n" % (z,y,x,w,v)
    if z[:6] == "CYGWIN":
		LZSS = "./scripts/lzss/lzss.exe c "
    else:
		LZSS = "./scripts/lzss/lzss.out c "

    doPack(bin_align, file_align, magic, dst_fn, binid_fn, ImgInfo_Offset, ap_c_fn, compress_format)
	
    #print "\x1b[0m"
    