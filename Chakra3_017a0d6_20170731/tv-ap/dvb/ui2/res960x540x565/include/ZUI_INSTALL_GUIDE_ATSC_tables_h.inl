////////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2006-2010 MStar Semiconductor, Inc.
// All rights reserved.
//
// Unless otherwise stipulated in writing, any and all information contained
// herein regardless in any format shall remain the sole proprietary of
// MStar Semiconductor Inc. and be kept in strict confidence
// (''MStar Confidential Information'') by the recipient.
// Any unauthorized act including without limitation unauthorized disclosure,
// copying, use, reproduction, sale, distribution, modification, disassembling,
// reverse engineering and compiling of the contents of MStar Confidential
// Information is unlawful and strictly prohibited. MStar hereby reserves the
// rights to any and all damages, losses, costs and expenses resulting therefrom.
//
////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////
// This file is automatically generated by SkinTool [Version:0.2.3][Build:Dec 18 2014 17:25:00]
/////////////////////////////////////////////////////////////////////////////


typedef enum
{
    HWND_INSTALL_BACKGROUND_ATSC = 1,
    HWND_INSTALL_BACKGROUND_BG_L = 2,
    HWND_INSTALL_BACKGROUND_BG_C = 3,
    HWND_INSTALL_BACKGROUND_BG_R = 4,
    HWND_INSTALL_BACKGROUND_MENU = 5,
    HWND_INSTALL_BACKGROUND_OK = 6,
    HWND_INSTALL_MAIN_PAGE_ATSC = 7,
    HWND_INSTALL_MAIN_TITLE_ATSC = 8,
    HWND_INSTALL_MAIN_PAGE_LANGUAGE = 9,
    HWND_INSTALL_MAIN_OSD_LANGUAGE_TITLE = 10,
    HWND_INSTALL_MAIN_OSD_LANGUAGE_TITLE_TEXT = 11,
    HWND_INSTALL_MAIN_OSD_LANGUAGE = 12,
    HWND_INSTALL_MAIN_OSD_LANGUAGE_FOCUS_BG = 13,
    HWND_INSTALL_MAIN_OSD_LANGUAGE_TEXT = 14,
    HWND_INSTALL_MAIN_OSD_LANGUAGE_OPTION = 15,
    HWND_INSTALL_MAIN_OSD_LANGUAGE_LEFT_ARROW = 16,
    HWND_INSTALL_MAIN_OSD_LANGUAGE_RIGHT_ARROW = 17,
    HWND_INSTALL_MAIN_OSD_LANGUAGE_NEXT = 18,
    HWND_INSTALL_MAIN_OSD_LANGUAGE_NEXT_RIGHT_ARROW = 19,
    HWND_INSTALL_MAIN_OSD_LANGUAGE_NEXT_TEXT = 20,
    HWND_INSTALL_MAIN_PAGE_TIME = 21,
    HWND_INSTALL_MAIN_OSD_TIME_TITLE = 22,
    HWND_INSTALL_MAIN_OSD_TIME_TITLE_TEXT = 23,
    HWND_INSTALL_MAIN_OSD_TIME = 24,
    HWND_INSTALL_MAIN_OSD_TIME_FOCUS_BG = 25,
    HWND_INSTALL_MAIN_OSD_TIME_TEXT = 26,
    HWND_INSTALL_MAIN_OSD_TIME_OPTION = 27,
    HWND_INSTALL_MAIN_OSD_TIME_LEFT_ARROW = 28,
    HWND_INSTALL_MAIN_OSD_TIME_RIGHT_ARROW = 29,
    HWND_INSTALL_MAIN_OSD_TIME_NEXT = 30,
    HWND_INSTALL_MAIN_OSD_TIME_NEXT_RIGHT_ARROW = 31,
    HWND_INSTALL_MAIN_OSD_TIME_NEXT_TEXT = 32,
    HWND_INSTALL_MAIN_OSD_TIME_FORMAT = 33,
    HWND_INSTALL_MAIN_OSD_TIME_FORMAT_FOCUS_BG = 34,
    HWND_INSTALL_MAIN_OSD_TIME_FORMAT_TEXT = 35,
    HWND_INSTALL_MAIN_OSD_TIME_FORMAT_OPTION = 36,
    HWND_INSTALL_MAIN_OSD_TIME_FORMAT_LEFT_ARROW = 37,
    HWND_INSTALL_MAIN_OSD_TIME_FORMAT_RIGHT_ARROW = 38,
    HWND_INSTALL_MAIN_PAGE_ANT = 39,
    HWND_INSTALL_MAIN_OSD_ANT_TITLE = 40,
    HWND_INSTALL_MAIN_OSD_ANT_TITLE_TEXT = 41,
    HWND_INSTALL_MAIN_OSD_ANT = 42,
    HWND_INSTALL_MAIN_OSD_ANT_FOCUS_BG = 43,
    HWND_INSTALL_MAIN_OSD_ANT_TEXT = 44,
    HWND_INSTALL_MAIN_OSD_ANT_OPTION = 45,
    HWND_INSTALL_MAIN_OSD_ANT_LEFT_ARROW = 46,
    HWND_INSTALL_MAIN_OSD_ANT_RIGHT_ARROW = 47,
    HWND_INSTALL_MAIN_OSD_ANT_NEXT = 48,
    HWND_INSTALL_MAIN_OSD_ANT_NEXT_RIGHT_ARROW = 49,
    HWND_INSTALL_MAIN_OSD_ANT_NEXT_TEXT = 50,
    HWND_INSTALL_SCAN_RESULT_SUB_PAGE = 51,
    HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_FOUND = 52,
    HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_FOUND_TEXT = 53,
    HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_FOUND_VALUE = 54,
    HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_FOUND_PROGRAM = 55,
    HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_ANALOG = 56,
    HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_ANALOG_TEXT = 57,
    HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_ANALOG_VALUE = 58,
    HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_ANALOG_PROGRAM = 59,
    HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_DIGITAL = 60,
    HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_DIGITAL_TEXT = 61,
    HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_DIGITAL_VALUE = 62,
    HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_DIGITAL_PROGRAM = 63,
    HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_RFCH = 64,
    HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_PERCENT = 65,
    HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_PERCENT_TEXT = 66,
    HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_RFCH_TEXT = 67,
    HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_RFCH_VALUE = 68,
    HWND_INSTALL_SCAN_RESULT_SUB_PAGE_ITEM_CH_TYPE = 69,
    HWND_INSTALL_SCAN_RESULT_SUB_PAGE_PROGRESSBAR = 70,
    HWND_INSTALL_GUIDE_ATSC_MAX = 71,
} HWND_WINDOW_INSTALL_GUIDE_ATSC_ID;

extern WINDOWDRAWSTYLEDATA _MP_TBLSEG _GUI_WindowsDrawStyleList_Zui_Install_Guide_Atsc[];
//extern WINDOWVARDATA _GUI_WindowsRWDataList_Zui_Install_Guide_Atsc[];
extern WINDOWDATA _MP_TBLSEG _GUI_WindowList_Zui_Install_Guide_Atsc[];
extern WINDOWPOSDATA _MP_TBLSEG _GUI_WindowPositionList_Zui_Install_Guide_Atsc[];
extern WINDOWALPHADATA _MP_TBLSEG _GUI_WindowsAlphaList_Zui_Install_Guide_Atsc[];

#define ZUI_INSTALL_GUIDE_ATSC_XSTART   258
#define ZUI_INSTALL_GUIDE_ATSC_YSTART   93
#define ZUI_INSTALL_GUIDE_ATSC_WIDTH   334
#define ZUI_INSTALL_GUIDE_ATSC_HEIGHT   264

