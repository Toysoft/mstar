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
// This file is automatically generated by SkinTool [Version:0.2.3][Build:Jun 14 2017 09:17:51]
/////////////////////////////////////////////////////////////////////////////


typedef enum
{
    HWND_TUNE_TITLE_PANE = 1,
    HWND_TUNE_TITLE_TEXT = 2,
    HWND_TUNE_BG_PANE = 3,
    HWND_TUNE_BG_PANE_L = 4,
    HWND_TUNE_BG_PANE_C = 5,
    HWND_TUNE_BG_PANE_R = 6,
    HWND_TUNE_SCAN_PROGRESS_PANE = 7,
    HWND_TUNE_SCAN_PROGRESS_ATV_ITEM = 8,
    HWND_TUNE_SCAN_PROGRESS_ATV_TEXT = 9,
    HWND_TUNE_SCAN_PROGRESS_ATV_COLON = 10,
    HWND_TUNE_SCAN_PROGRESS_ATV_COUNT = 11,
    HWND_TUNE_SCAN_PROGRESS_ATV_PROG = 12,
    HWND_TUNE_SCAN_PROGRESS_DTV_ITEM = 13,
    HWND_TUNE_SCAN_PROGRESS_DTV_TEXT = 14,
    HWND_TUNE_SCAN_PROGRESS_DTV_COLON = 15,
    HWND_TUNE_SCAN_PROGRESS_DTV_COUNT = 16,
    HWND_TUNE_SCAN_PROGRESS_DTV_PROG = 17,
    HWND_TUNE_SCAN_PROGRESS_RADIO_ITEM = 18,
    HWND_TUNE_SCAN_PROGRESS_RADIO_TEXT = 19,
    HWND_TUNE_SCAN_PROGRESS_RADIO_COLON = 20,
    HWND_TUNE_SCAN_PROGRESS_RADIO_COUNT = 21,
    HWND_TUNE_SCAN_PROGRESS_RADIO_PROG = 22,
    HWND_TUNE_SCAN_PROGRESS_DATA_ITEM = 23,
    HWND_TUNE_SCAN_PROGRESS_DATA_TEXT = 24,
    HWND_TUNE_SCAN_PROGRESS_DATA_COLON = 25,
    HWND_TUNE_SCAN_PROGRESS_DATA_COUNT = 26,
    HWND_TUNE_SCAN_PROGRESS_DATA_PROG = 27,
    HWND_TUNE_SCAN_PROGRESS_CATV_TEXT = 28,
    HWND_TUNE_SCAN_PROGRESS_CATV_COLON = 29,
    HWND_TUNE_SCAN_PROGRESS_CATV_COUNT = 30,
    HWND_TUNE_SCAN_PROGRESS_CATV_PROG = 31,
    HWND_SAT_SCAN_PROGRESS_INFO_ITEM = 32,
    HWND_SAT_SCAN_PROGRESS_SEARCH_NUM = 33,
    HWND_SAT_SCAN_PROGRESS_SAT_NAME = 34,
    HWND_SAT_SCAN_PROGRESS_BAR = 35,
    HWND_TUNE_SCAN_PROGRESS_INFO_ITEM = 36,
    HWND_TUNE_SCAN_PROGRESS_PERCENT = 37,
    HWND_TUNE_SCAN_PROGRESS_PERCENT_TEXT = 38,
    HWND_TUNE_SCAN_PROGRESS_CH_UHF = 39,
    HWND_TUNE_SCAN_PROGRESS_CH_NAME = 40,
    HWND_TUNE_SCAN_PROGRESS_ATV_FREQ = 41,
    HWND_TUNE_SCAN_PROGRESS_CH_TYPE = 42,
    HWND_TUNE_SCAN_PROGRESS_BAR = 43,
    HWND_TUNE_SCAN_CONFIRM_MSG = 44,
    HWND_TUNE_SCAN_CONFIRM_CLEAR_BG = 45,
    HWND_TUNE_SCAN_CONFIRM_MSG_BG = 46,
    HWND_TUNE_SCAN_CONFIRM_MSG_BG_TOP = 47,
    HWND_TUNE_SCAN_CONFIRM_MSG_BG_L = 48,
    HWND_TUNE_SCAN_CONFIRM_MSG_BG_C = 49,
    HWND_TUNE_SCAN_CONFIRM_MSG_BG_R = 50,
    HWND_TUNE_SCAN_CONFIRM_MSG_BAR = 51,
    HWND_TUNE_SCAN_CONFIRM_BTN_YES = 52,
    HWND_TUNE_SCAN_CONFIRM_BTN_YES_LEFT_ARROW = 53,
    HWND_TUNE_SCAN_CONFIRM_BTN_YES_TEXT = 54,
    HWND_TUNE_SCAN_CONFIRM_BTN_NO = 55,
    HWND_TUNE_SCAN_CONFIRM_BTN_NO_RIGHT_ARROW = 56,
    HWND_TUNE_SCAN_CONFIRM_BTN_NO_TEXT = 57,
    HWND_TUNE_SCAN_CONFIRM_HELP_MSG = 58,
    HWND_TUNE_SCAN_SKIP_ATV_CONFIRM_MSG = 59,
    HWND_TUNE_SCAN_SKIP_ATV_CONFIRM_CLEAR_BG = 60,
    HWND_TUNE_SCAN_SKIP_ATV_CONFIRM_MSG_BG = 61,
    HWND_TUNE_SCAN_SKIP_ATV_CONFIRM_MSG_BG_TOP = 62,
    HWND_TUNE_SCAN_SKIP_ATV_CONFIRM_MSG_BG_L = 63,
    HWND_TUNE_SCAN_SKIP_ATV_CONFIRM_MSG_BG_C = 64,
    HWND_TUNE_SCAN_SKIP_ATV_CONFIRM_MSG_BG_R = 65,
    HWND_TUNE_SCAN_SKIP_ATV_CONFIRM_MSG_BAR = 66,
    HWND_TUNE_SCAN_SKIP_ATV_CONFIRM_BTN_YES = 67,
    HWND_TUNE_SCAN_SKIP_ATV_CONFIRM_BTN_YES_LEFT_ARROW = 68,
    HWND_TUNE_SCAN_SKIP_ATV_CONFIRM_BTN_YES_TEXT = 69,
    HWND_TUNE_SCAN_SKIP_ATV_CONFIRM_BTN_NO = 70,
    HWND_TUNE_SCAN_SKIP_ATV_CONFIRM_BTN_NO_RIGHT_ARROW = 71,
    HWND_TUNE_SCAN_SKIP_ATV_CONFIRM_BTN_NO_TEXT = 72,
    HWND_TUNE_SCAN_SKIP_ATV_CONFIRM_HELP_MSG = 73,
    HWND_TUNE_SCAN_SKIP_DTV_CONFIRM_MSG = 74,
    HWND_TUNE_SCAN_SKIP_DTV_CONFIRM_CLEAR_BG = 75,
    HWND_TUNE_SCAN_SKIP_DTV_CONFIRM_MSG_BG = 76,
    HWND_TUNE_SCAN_SKIP_DTV_CONFIRM_MSG_BG_TOP = 77,
    HWND_TUNE_SCAN_SKIP_DTV_CONFIRM_MSG_BG_L = 78,
    HWND_TUNE_SCAN_SKIP_DTV_CONFIRM_MSG_BG_C = 79,
    HWND_TUNE_SCAN_SKIP_DTV_CONFIRM_MSG_BG_R = 80,
    HWND_TUNE_SCAN_SKIP_DTV_CONFIRM_MSG_BAR = 81,
    HWND_TUNE_SCAN_SKIP_DTV_CONFIRM_BTN_YES = 82,
    HWND_TUNE_SCAN_SKIP_DTV_CONFIRM_BTN_YES_LEFT_ARROW = 83,
    HWND_TUNE_SCAN_SKIP_DTV_CONFIRM_BTN_YES_TEXT = 84,
    HWND_TUNE_SCAN_SKIP_DTV_CONFIRM_BTN_NO = 85,
    HWND_TUNE_SCAN_SKIP_DTV_CONFIRM_BTN_NO_RIGHT_ARROW = 86,
    HWND_TUNE_SCAN_SKIP_DTV_CONFIRM_BTN_NO_TEXT = 87,
    HWND_TUNE_SCAN_SKIP_DTV_CONFIRM_HELP_MSG = 88,
    HWND_TUNE_SCAN_RESULT_MSG = 89,
    HWND_TUNE_SCAN_RESULT_CLEAR_BG = 90,
    HWND_TUNE_SCAN_RESULT_MSG_BG = 91,
    HWND_TUNE_SCAN_ATV_TEXT = 92,
    HWND_TUNE_SCAN_DTV_TEXT = 93,
    HWND_TUNE_SCAN_TV_PR_TEXT = 94,
    HWND_TUNE_SCAN_RADIO_TEXT = 95,
    HWND_TUNE_SCAN_ATV_NUM = 96,
    HWND_TUNE_SCAN_DTV_NUM = 97,
    HWND_TUNE_SCAN_RADIO_NUM = 98,
    HWND_TUNE_SCAN_RESULT_SAVING = 99,
    HWND_TUNE_SCAN_DTV_PR_TEXT = 100,
    HWND_TUNE_SCAN_RADIO_PR_TEXT = 101,
    HWND_TUNE_SCAN_DATA_TEXT = 102,
    HWND_TUNE_SCAN_DATA_NUM = 103,
    HWND_TUNE_SCAN_DATA_PR_TEXT = 104,
    HWND_TUNE_SCAN_CATV_TEXT = 105,
    HWND_TUNE_SCAN_CATV_NUM = 106,
    HWND_TUNE_SCAN_CATV_PR_TEXT = 107,
    HWND_TUNE_SCAN_SKIP_CATV_CONFIRM_MSG = 108,
    HWND_TUNE_SCAN_SKIP_CATV_CONFIRM_CLEAR_BG = 109,
    HWND_TUNE_SCAN_SKIP_CATV_CONFIRM_MSG_BG = 110,
    HWND_TUNE_SCAN_SKIP_CATV_CONFIRM_MSG_BG_TOP = 111,
    HWND_TUNE_SCAN_SKIP_CATV_CONFIRM_MSG_BG_L = 112,
    HWND_TUNE_SCAN_SKIP_CATV_CONFIRM_MSG_BG_C = 113,
    HWND_TUNE_SCAN_SKIP_CATV_CONFIRM_MSG_BG_R = 114,
    HWND_TUNE_SCAN_SKIP_CATV_CONFIRM_MSG_BAR = 115,
    HWND_TUNE_SCAN_SKIP_CATV_CONFIRM_BTN_YES = 116,
    HWND_TUNE_SCAN_SKIP_CATV_CONFIRM_BTN_YES_LEFT_ARROW = 117,
    HWND_TUNE_SCAN_SKIP_CATV_CONFIRM_BTN_YES_TEXT = 118,
    HWND_TUNE_SCAN_SKIP_CATV_CONFIRM_BTN_NO = 119,
    HWND_TUNE_SCAN_SKIP_CATV_CONFIRM_BTN_NO_RIGHT_ARROW = 120,
    HWND_TUNE_SCAN_SKIP_CATV_CONFIRM_BTN_NO_TEXT = 121,
    HWND_TUNE_SCAN_SKIP_CATV_CONFIRM_HELP_MSG = 122,
    HWND_MENU_CHANNEL_SET_TARGET_REGION_PAGE = 123,
    HWND_MENU_CHANNEL_SET_TARGET_REGION_PAGE_BG_TOP = 124,
    HWND_MENU_CHANNEL_SET_TARGET_REGION_PAGE_BG_L = 125,
    HWND_MENU_CHANNEL_SET_TARGET_REGION_PAGE_BG_C = 126,
    HWND_MENU_CHANNEL_SET_TARGET_REGION_PAGE_BG_R = 127,
    HWND_MENU_CHANNEL_SET_TARGET_REGION_PAGE_TITLE = 128,
    HWND_MENU_CHANNEL_SET_TARGET_REGION_PAGE_TITLE_TEXT = 129,
    HWND_MENU_CHANNEL_SET_TARGET_REGION_PAGE_LIST = 130,
    HWND_MENU_CHANNEL_SET_TARGET_REGION_COUNTRY_CODE = 131,
    HWND_MENU_CHANNEL_SET_TARGET_REGION_COUNTRY_CODE_OPTION = 132,
    HWND_MENU_CHANNEL_SET_TARGET_REGION_COUNTRY_CODE_LEFT_ARROW = 133,
    HWND_MENU_CHANNEL_SET_TARGET_REGION_COUNTRY_CODE_RIGHT_ARROW = 134,
    HWND_MENU_CHANNEL_SET_TARGET_REGION_COUNTRY_CODE_TXT = 135,
    HWND_MENU_CHANNEL_SET_TARGET_REGION_PRIMARY = 136,
    HWND_MENU_CHANNEL_SET_TARGET_REGION_PRIMARY_OPTION = 137,
    HWND_MENU_CHANNEL_SET_TARGET_REGION_PRIMARY_LEFT_ARROW = 138,
    HWND_MENU_CHANNEL_SET_TARGET_REGION_PRIMARY_RIGHT_ARROW = 139,
    HWND_MENU_CHANNEL_SET_TARGET_REGION_PRIMARY_TXT = 140,
    HWND_MENU_CHANNEL_SET_TARGET_REGION_SECONDARY = 141,
    HWND_MENU_CHANNEL_SET_TARGET_REGION_SECONDARY_OPTION = 142,
    HWND_MENU_CHANNEL_SET_TARGET_REGION_SECONDARY_LEFT_ARROW = 143,
    HWND_MENU_CHANNEL_SET_TARGET_REGION_SECONDARY_RIGHT_ARROW = 144,
    HWND_MENU_CHANNEL_SET_TARGET_REGION_SECONDARY_TXT = 145,
    HWND_MENU_CHANNEL_SET_TARGET_REGION_TERITARY = 146,
    HWND_MENU_CHANNEL_SET_TARGET_REGION_TERITARY_OPTION = 147,
    HWND_MENU_CHANNEL_SET_TARGET_REGION_TERITARY_LEFT_ARROW = 148,
    HWND_MENU_CHANNEL_SET_TARGET_REGION_TERITARY_RIGHT_ARROW = 149,
    HWND_MENU_CHANNEL_SET_TARGET_REGION_TERITARY_TXT = 150,
    HWND_MENU_CHANNEL_SET_TARGET_REGION_PAGE_MENU = 151,
    HWND_MENU_CHANNEL_ID_SET_PAGE = 152,
    HWND_MENU_CHANNEL_ID_SET_PAGE_BG_TOP = 153,
    HWND_MENU_CHANNEL_ID_SET_PAGE_BG_L = 154,
    HWND_MENU_CHANNEL_ID_SET_PAGE_BG_C = 155,
    HWND_MENU_CHANNEL_ID_SET_PAGE_BG_R = 156,
    HWND_MENU_CHANNEL_ID_SET_PAGE_TITLE = 157,
    HWND_MENU_CHANNEL_ID_SET_PAGE_TITLE_TEXT = 158,
    HWND_MENU_CHANNEL_ID_SET_PAGE_LIST = 159,
    HWND_MENU_CHANNEL_ID_SET_LIST_ITEM0 = 160,
    HWND_MENU_CHANNEL_ID_SET_LIST_ITEM0_TXT = 161,
    HWND_MENU_CHANNEL_ID_SET_LIST_ITEM1 = 162,
    HWND_MENU_CHANNEL_ID_SET_LIST_ITEM1_TXT = 163,
    HWND_MENU_CHANNEL_ID_SET_LIST_ITEM2 = 164,
    HWND_MENU_CHANNEL_ID_SET_LIST_ITEM2_TXT = 165,
    HWND_MENU_CHANNEL_ID_SET_LIST_ITEM3 = 166,
    HWND_MENU_CHANNEL_ID_SET_LIST_ITEM3_TXT = 167,
    HWND_MENU_CHANNEL_HAVE_LCN_CONFILICT_MSG = 168,
    HWND_MENU_CHANNEL_HAVE_LCN_CONFILICT_BG = 169,
    HWND_MENU_CHANNEL_HAVE_LCN_CONFILICT_BG_2 = 170,
    HWND_MENU_CHANNEL_HAVE_LCN_CONFILICT_BG_TOP = 171,
    HWND_MENU_CHANNEL_HAVE_LCN_CONFILICT_BG_L = 172,
    HWND_MENU_CHANNEL_HAVE_LCN_CONFILICT_BG_C = 173,
    HWND_MENU_CHANNEL_HAVE_LCN_CONFILICT_BG_R = 174,
    HWND_MENU_CHANNEL_HAVE_LCN_CONFILICT_BAR = 175,
    HWND_MENU_CHANNEL_HAVE_LCN_CONFILICT_CONFIRM_BTN_YES = 176,
    HWND_MENU_CHANNEL_HAVE_LCN_CONFILICT_BTN_YES_LEFT_ARROW = 177,
    HWND_MENU_CHANNEL_HAVE_LCN_CONFILICT_BTN_YES_TEXT = 178,
    HWND_MENU_CHANNEL_HAVE_LCN_CONFILICT_CONFIRM_BTN_NO = 179,
    HWND_MENU_CHANNEL_HAVE_LCN_CONFILICT_BTN_NO_RIGHT_ARROW = 180,
    HWND_MENU_CHANNEL_HAVE_LCN_CONFILICT_BTN_NO_TEXT = 181,
    HWND_MENU_CHANNEL_HAVE_LCN_CONFILICT_HELP_MSG = 182,
    HWND_MENU_CHANNEL_SET_LCN_CONFLIC_PAGE = 183,
    HWND_MENU_CHANNEL_SET_LCN_CONFLIC_PAGE_BG_TOP = 184,
    HWND_MENU_CHANNEL_SET_LCN_CONFLIC_PAGE_BG_L = 185,
    HWND_MENU_CHANNEL_SET_LCN_CONFLIC_PAGE_BG_C = 186,
    HWND_MENU_CHANNEL_SET_LCN_CONFLIC_PAGE_BG_R = 187,
    HWND_MENU_CHANNEL_SET_LCN_CONFLIC_PAGE_TITLE = 188,
    HWND_MENU_CHANNEL_SET_LCN_CONFLIC_PAGE_TITLE_TEXT = 189,
    HWND_MENU_CHANNEL_SET_LCN_CONFLIC_PAGE_LIST = 190,
    HWND_MENU_CHANNEL_SET_LCN_CONFLIC_CH_NUM = 191,
    HWND_MENU_CHANNEL_SET_LCN_CONFLIC_CH_NUM_TXT = 192,
    HWND_MENU_CHANNEL_SET_LCN_CONFLIC_CH_NUM_VALUE = 193,
    HWND_MENU_CHANNEL_LCN_CONFLIC_1ST = 194,
    HWND_MENU_CHANNEL_SET_LCN_CONFLIC_1ST_NAME = 195,
    HWND_MENU_CHANNEL_LCN_CONFLIC_2ND = 196,
    HWND_MENU_CHANNEL_SET_LCN_CONFLIC_2ND_NAME = 197,
    HWND_MENU_CHANNEL_LCN_CONFLIC_3RD = 198,
    HWND_MENU_CHANNEL_SET_LCN_CONFLIC_3RD_NAME = 199,
    HWND_MENU_CHANNEL_LCN_CONFLIC_4TH = 200,
    HWND_MENU_CHANNEL_SET_LCN_CONFLIC_4TH_NAME = 201,
    HWND_MENU_CHANNEL_LCN_CONFLIC_5TH = 202,
    HWND_MENU_CHANNEL_SET_LCN_CONFLIC_5TH_NAME = 203,
    HWND_MENU_CHANNEL_SET_LCN_CONFLIC_PAGE_MENU = 204,
    HWND_MENU_CHANNEL_ASTRAHD_LCN_CONFILICT_MSG = 205,
    HWND_MENU_CHANNEL_ASTRAHD_LCN_CONFILICT_BG = 206,
    HWND_MENU_CHANNEL_ASTRAHD_LCN_CONFILICT_BG_2 = 207,
    HWND_MENU_CHANNEL_ASTRAHD_LCN_CONFILICT_BG_TOP = 208,
    HWND_MENU_CHANNEL_ASTRAHD_LCN_CONFILICT_BG_L = 209,
    HWND_MENU_CHANNEL_ASTRAHD_LCN_CONFILICT_BG_C = 210,
    HWND_MENU_CHANNEL_ASTRAHD_LCN_CONFILICT_BG_R = 211,
    HWND_MENU_CHANNEL_ASTRAHD_LCN_CONFILICT_BAR = 212,
    HWND_MENU_CHANNEL_ASTRAHD_LCN_CONFILICT_CONFIRM_BTN_YES = 213,
    HWND_MENU_CHANNEL_ASTRAHD_LCN_CONFILICT_BTN_YES_LEFT_ARROW = 214,
    HWND_MENU_CHANNEL_ASTRAHD_LCN_CONFILICT_BTN_YES_TEXT = 215,
    HWND_MENU_CHANNEL_ASTRAHD_LCN_CONFILICT_CONFIRM_BTN_NO = 216,
    HWND_MENU_CHANNEL_ASTRAHD_LCN_CONFILICT_BTN_NO_RIGHT_ARROW = 217,
    HWND_MENU_CHANNEL_ASTRAHD_LCN_CONFILICT_BTN_NO_TEXT = 218,
    HWND_MENU_CHANNEL_ASTRAHD_LCN_CONFILICT_HELP_MSG = 219,
    HWND_OAD_TUNE = 220,
    HWND_OAD_TUNE_BG_PANE = 221,
    HWND_OAD_TUNE_SCAN_CONFIRM_MSG_BG = 222,
    HWND_OAD_TUNE_SCAN_CONFIRM_MSG_BG_TOP = 223,
    HWND_OAD_TUNE_SCAN_CONFIRM_MSG_BG_L = 224,
    HWND_OAD_TUNE_SCAN_CONFIRM_MSG_BG_C = 225,
    HWND_OAD_TUNE_SCAN_CONFIRM_MSG_BG_R = 226,
    HWND_OAD_TUNE_BG_TITLE = 227,
    HWND_OAD_TUNE_SCAN_PROGRESS_PANE = 228,
    HWND_OAD_TUNE_SCAN_PROGRESS_PERCENT = 229,
    HWND_OAD_TUNE_SCAN_PROGRESS_PERCENT_TEXT = 230,
    HWND_OAD_TUNE_SCAN_PROGRESS_CH_TYPE = 231,
    HWND_OAD_TUNE_SCAN_PROGRESS_CH_UHF = 232,
    HWND_OAD_TUNE_SCAN_PROGRESS_BAR = 233,
    HWND_FAVORITE_NETWORK_PAGE = 234,
    HWND_FAVORITE_NETWORK_BG_PANE = 235,
    HWND_FAVORITE_NETWORK_CONFIRM_MSG_BG = 236,
    HWND_FAVORITE_NETWORK_CONFIRM_MSG_BG_TOP = 237,
    HWND_FAVORITE_NETWORK_CONFIRM_MSG_BG_L = 238,
    HWND_FAVORITE_NETWORK_CONFIRM_MSG_BG_C = 239,
    HWND_FAVORITE_NETWORK_CONFIRM_MSG_BG_R = 240,
    HWND_FAVORITE_NETWORK_BG_TITLE = 241,
    HWND_FAVORITE_NETWORK_SEL_BAR = 242,
    HWND_FAVORITE_NETWORK_SEL_LEFT_ARW = 243,
    HWND_FAVORITE_NETWORK_SEL_RIGHT_ARW = 244,
    HWND_FAVORITE_NETWORK_SEL_OPTION = 245,
    HWND_FAVORITE_NETWORK_HELP_MSG = 246,
    HWND_FAVORITE_NETWORK_MSG1_LR_ICON = 247,
    HWND_FAVORITE_NETWORK_MSG1_L_ICON = 248,
    HWND_FAVORITE_NETWORK_MSG1_R_ICON = 249,
    HWND_FAVORITE_NETWORK_MSG1_SELECT_TEXT = 250,
    HWND_FAVORITE_NETWORK_MSG1_OK_ICON = 251,
    HWND_AUTO_TUNING_MAX = 252,
} HWND_WINDOW_AUTO_TUNING_ID;

extern WINDOWDRAWSTYLEDATA _MP_TBLSEG _GUI_WindowsDrawStyleList_Zui_Auto_Tuning[];
//extern WINDOWVARDATA _GUI_WindowsRWDataList_Zui_Auto_Tuning[];
extern WINDOWDATA _MP_TBLSEG _GUI_WindowList_Zui_Auto_Tuning[];
extern WINDOWPOSDATA _MP_TBLSEG _GUI_WindowPositionList_Zui_Auto_Tuning[];
extern WINDOWALPHADATA _MP_TBLSEG _GUI_WindowsAlphaList_Zui_Auto_Tuning[];

#define ZUI_AUTO_TUNING_XSTART   880
#define ZUI_AUTO_TUNING_YSTART   40
#define ZUI_AUTO_TUNING_WIDTH   446
#define ZUI_AUTO_TUNING_HEIGHT   432

