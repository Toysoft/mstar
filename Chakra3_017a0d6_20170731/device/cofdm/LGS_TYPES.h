//<MStar Software>
//******************************************************************************
// MStar Software
// Copyright (c) 2010 - 2012 MStar Semiconductor, Inc. All rights reserved.
// All software, firmware and related documentation herein ("MStar Software") are
// intellectual property of MStar Semiconductor, Inc. ("MStar") and protected by
// law, including, but not limited to, copyright law and international treaties.
// Any use, modification, reproduction, retransmission, or republication of all 
// or part of MStar Software is expressly prohibited, unless prior written 
// permission has been granted by MStar. 
//
// By accessing, browsing and/or using MStar Software, you acknowledge that you
// have read, understood, and agree, to be bound by below terms ("Terms") and to
// comply with all applicable laws and regulations:
//
// 1. MStar shall retain any and all right, ownership and interest to MStar
//    Software and any modification/derivatives thereof.
//    No right, ownership, or interest to MStar Software and any
//    modification/derivatives thereof is transferred to you under Terms.
//
// 2. You understand that MStar Software might include, incorporate or be
//    supplied together with third party`s software and the use of MStar
//    Software may require additional licenses from third parties.  
//    Therefore, you hereby agree it is your sole responsibility to separately
//    obtain any and all third party right and license necessary for your use of
//    such third party`s software. 
//
// 3. MStar Software and any modification/derivatives thereof shall be deemed as
//    MStar`s confidential information and you agree to keep MStar`s 
//    confidential information in strictest confidence and not disclose to any
//    third party.  
//
// 4. MStar Software is provided on an "AS IS" basis without warranties of any
//    kind. Any warranties are hereby expressly disclaimed by MStar, including
//    without limitation, any warranties of merchantability, non-infringement of
//    intellectual property rights, fitness for a particular purpose, error free
//    and in conformity with any international standard.  You agree to waive any
//    claim against MStar for any loss, damage, cost or expense that you may
//    incur related to your use of MStar Software.
//    In no event shall MStar be liable for any direct, indirect, incidental or
//    consequential damages, including without limitation, lost of profit or
//    revenues, lost or damage of data, and unauthorized system use.
//    You agree that this Section 4 shall still apply without being affected
//    even if MStar Software has been modified by MStar in accordance with your
//    request or instruction for your use, except otherwise agreed by both
//    parties in writing.
//
// 5. If requested, MStar may from time to time provide technical supports or
//    services in relation with MStar Software to you for your use of
//    MStar Software in conjunction with your or your customer`s product
//    ("Services").
//    You understand and agree that, except otherwise agreed by both parties in
//    writing, Services are provided on an "AS IS" basis and the warranty
//    disclaimer set forth in Section 4 above shall apply.  
//
// 6. Nothing contained herein shall be construed as by implication, estoppels
//    or otherwise:
//    (a) conferring any license or right to use MStar name, trademark, service
//        mark, symbol or any other identification;
//    (b) obligating MStar or any of its affiliates to furnish any person,
//        including without limitation, you and your customers, any assistance
//        of any kind whatsoever, or any information; or 
//    (c) conferring any license or right under any intellectual property right.
//
// 7. These terms shall be governed by and construed in accordance with the laws
//    of Taiwan, R.O.C., excluding its conflict of law rules.
//    Any and all dispute arising out hereof or related hereto shall be finally
//    settled by arbitration referred to the Chinese Arbitration Association,
//    Taipei in accordance with the ROC Arbitration Law and the Arbitration
//    Rules of the Association by three (3) arbitrators appointed in accordance
//    with the said Rules.
//    The place of arbitration shall be in Taipei, Taiwan and the language shall
//    be English.  
//    The arbitration award shall be final and binding to both parties.
//
//******************************************************************************
//<MStar Software>
/***************************************************************************************
*					             
*			(c) Copyright 2008, LegendSilicon, beijing, China
*
*				         All Rights Reserved
*
* Description : Legend Silicon Demod Library header file
*
* Notice: DO NOT change the file in your project
*
***************************************************************************************/
#include "Board.h"

#if(FRONTEND_DEMOD_TYPE == LEGEND_8G75_DEMOD)
#ifndef _TYPES_C631FEF2_89A8_4ae5_B22A_04122BA8B12D_H_
#define _TYPES_C631FEF2_89A8_4ae5_B22A_04122BA8B12D_H_


typedef unsigned char	LGS_RESULT;
typedef unsigned char	LGS_HANDLE;

#define MAX_NAME_LEN	128
#define TIMEOUT			100
#define INT8	char
#define INT16	short
#define INT32	long

#define UINT8	unsigned char
#define UINT16	unsigned short
#define UINT32	unsigned long
//#define BOOL	int


////////////////////////////////////////////////////////////////
// ����ֵ����
////////////////////////////////////////////////////////////////
#define LGS_NO_ERROR				0
#define LGS_REGISTER_ERROR			0xFF	//�Ĵ�������
#define LGS_I2C_OPEN_ERROR			0xFE	//��I2C����
#define LGS_I2C_READ_ERROR			0xFD	//��I2C����
#define LGS_I2C_WRITE_ERROR			0xFC	//дI2C����
#define LGS_I2C_CLOSE_ERROR			0xFB	//�ر�I2C����
#define LGS_NO_LOCKED				0xFA	//�ź�δ����
#define LGS_AUTO_DETECT_FAILED			0xF9	//�Զ����ʧ��
#define LGS_FREQUENCY_ERROR			0xF8	//Ƶ�ʴ���
#define LGS_NO_DEFINE				0xF7	//�޶���
#define LGS_NO_MAGIC				0xF6	//MAGICֵ��ƥ��,����������
#define LGS_NO_DEVICE				0xF5
#define LGS_DETECT_ERROR			0xF4
#define LGS_OPENECHO_ERROR			0xF3
#define LGS_CLOSEECHO_ERROR			0xF2
#define LGS_SPI_WRITE_ERROR			0xF1
#define LGS_SET_FREQ_ERROR			0xF0
#define LGS_PARA_ERROR				0xEF	//��������


#define LGS_CHANGE_MODE_ERROR			0xDF
#define LGS_SET_MANUAL_ERROR			0xDE
#define LGS_USB_READ_ERROR			0xDD
#define LGS_USB_WRITE_ERROR			0xDC
#define LGS_TIMEOUT_ERROR			0xDB

typedef enum
{
    DMBT_CARRIER_MULTI = 0,
    DMBT_CARRIER_SINGLE,
} DMBT_CARRIER_MODE;

typedef enum
{
    DMBT_PN420 = 0,
    DMBT_PN595,
    DMBT_PN945,
} DMBT_PN_MODE;


typedef LGS_RESULT (*LGS_OPEN_I2C)(	LGS_HANDLE *phI2c, 
					const UINT8 secAddr, 
					UINT16 timeout);

typedef LGS_RESULT (*LGS_READ_I2C)(	LGS_HANDLE hI2c,
					UINT8 *pbuffer, 
					UINT16 len, 
					UINT16 timeout);

typedef LGS_RESULT (*LGS_WRITE_I2C)(	LGS_HANDLE hI2c,
					const UINT8 *pbuffer, 
					UINT16 len, 
					UINT16 timeout);

typedef LGS_RESULT (*LGS_CLOSE_I2C)(LGS_HANDLE hI2c);

typedef void (*LGS_WAIT)(UINT32 millisecond);


typedef struct _st_DEMOD_PARAMETERS
{
	int	GuardIntvl;		// �������
	int	SubCarrier;		// ���ز�
	int	FecRate;		// FEC
	int	TimeDeintvl;		// ʱ��֯
	int	PnNumber;		// 
	int	AdcClock;		//
	int	IsMpegClockInvert;	// MPEG Clock�Ƿ������
	int	DataOutput;		//
	int	CarrierMode;		// �ز�ģʽ(��/���ز�)
} DEMOD_PARAMETERS;

#endif
#else
#ifndef _TYPES_C631FEF2_89A8_4AE5_B22A_04122BA8B12D_H_
#define _TYPES_C631FEF2_89A8_4AE5_B22A_04122BA8B12D_H_


/////////////////////////////////////////////////////////////////
/// Definition of basic data type
/////////////////////////////////////////////////////////////////

typedef unsigned char	LGS_RESULT;
typedef unsigned char	LGS_HANDLE;

#define MAX_NAME_LEN		128
#define TIMEOUT			100

#ifndef INT8
	#define INT8	char
#endif

#ifndef INT16
	#define INT16	short
#endif

#ifndef INT32
	#define INT32	long
#endif

#ifndef UINT8
	#define UINT8	unsigned char
#endif

#ifndef UINT16
	#define UINT16	unsigned short
#endif

#ifndef UINT32
	#define UINT32	unsigned long
#endif

#ifndef BOOL
	#define BOOL	int
#endif

#ifndef _TCHAR_DEFINED
	#define	TCHAR short int
#endif

#ifndef _T
	#define _T(x)      L ## x
#endif


/////////////////////////////////////////////////////////////////
/// Definition of function's return value
/////////////////////////////////////////////////////////////////
#define LGS_NO_ERROR				0
#define LGS_REGISTER_ERROR			0xFF	//�Ĵ�������
#define LGS_I2C_OPEN_ERROR			0xFE	//��I2C����
#define LGS_I2C_READ_ERROR			0xFD	//��I2C����
#define LGS_I2C_WRITE_ERROR			0xFC	//дI2C����
#define LGS_I2C_CLOSE_ERROR			0xFB	//�ر�I2C����
#define LGS_NO_LOCKED				0xFA	//�ź�δ����
#define LGS_AUTO_DETECT_FAILED			0xF9	//�Զ����ʧ��
#define LGS_FREQUENCY_ERROR			0xF8	//Ƶ�ʴ���
#define LGS_NO_DEFINE				0xF7	//�޶���
#define LGS_NO_MAGIC				0xF6	//MAGICֵ��ƥ��,����������
#define LGS_NO_DEVICE				0xF5
#define LGS_DETECT_ERROR			0xF4
#define LGS_OPENECHO_ERROR			0xF3
#define LGS_CLOSEECHO_ERROR			0xF2
#define LGS_SPI_WRITE_ERROR			0xF1
#define LGS_SET_FREQ_ERROR			0xF0
#define LGS_PARA_ERROR				0xEF	//��������
#define LGS_ERROR				0xE0

#define LGS_CHANGE_MODE_ERROR			0xDF
#define LGS_SET_MANUAL_ERROR			0xDE
#define LGS_USB_READ_ERROR			0xDD
#define LGS_USB_WRITE_ERROR			0xDC
#define LGS_TIMEOUT_ERROR			0xDB





/////////////////////////////////////////////////////////////////////
// ���帽�Ӳ���
//
// _LGS_DEVICEHANDLE_ �ǵ�����(sigle parameter)ʱʹ�õĺ꣬���в���������
// _LGS_DEVICEHANDLEC_ �Ƕ����ʱʹ�õĺ꣬����һ������(Comma)
//
/////////////////////////////////////////////////////////////////////
//#define _WDMDDK_
#ifdef _WDMDDK_

	#define _LGS_DEVICEHANDLE_TYPE_		int
	#define _LGS_DEVICEHANDLE_PARA_		pKSDevice
	#define _LGS_DEVICEHANDLE_PARAC_	,pKSDevice

	#define _LGS_DEVICEHANDLE_	_LGS_DEVICEHANDLE_TYPE_  _LGS_DEVICEHANDLE_PARA_
	#define _LGS_DEVICEHANDLEC_	,_LGS_DEVICEHANDLE_TYPE_  _LGS_DEVICEHANDLE_PARA_

#else

	#define _LGS_DEVICEHANDLE_TYPE_
	#define _LGS_DEVICEHANDLE_PARA_
	#define _LGS_DEVICEHANDLE_PARAC_

	#define _LGS_DEVICEHANDLE_ void
	#define _LGS_DEVICEHANDLEC_

#endif


////////////////////////////////////////////////////////////////
// �Ĵ�����д����ԭ�Ͷ���
////////////////////////////////////////////////////////////////
typedef LGS_RESULT (*LGS_REGISTER_READ)(UINT8 secAddr, UINT8 regAddr, UINT8 *pregVal  _LGS_DEVICEHANDLEC_);
typedef LGS_RESULT (*LGS_REGISTER_WRITE)(UINT8 secAddr, UINT8 regAddr, UINT8 regVal  _LGS_DEVICEHANDLEC_);

typedef LGS_RESULT (*LGS_REGISTER_READ_MULTIBYTE)(UINT8 secAddr, UINT8 regAddr, UINT8 *pregVal, UINT32 len  _LGS_DEVICEHANDLEC_);
typedef LGS_RESULT (*LGS_REGISTER_WRITE_MULTIBYTE)(UINT8 secAddr, UINT8 regAddr, UINT8 *pregVal, UINT32 len  _LGS_DEVICEHANDLEC_);

typedef void (*LGS_WAIT)(UINT16 millisecond);


#endif
#endif //_TYPES_C631FEF2_89A8_4AE5_B22A_04122BA8B12D_H_
