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



/////////////////////////////////////////////////////
// MAINFRAME styles..


/////////////////////////////////////////////////////
// SCREEN_SAVER_BG_PANE styles..


/////////////////////////////////////////////////////
// SCREEN_SAVER_FRAME styles..

static DRAWSTYLE _MP_TBLSEG _Zui_Screen_Saver_Frame_Normal_DrawStyle[] =
{
    { CP_RECT, CP_ZUI_RECT_INDEX_3 },
    { CP_NOON, 0 },
};

/////////////////////////////////////////////////////
// SCREEN_SAVER_BG styles..

static DRAWSTYLE _MP_TBLSEG _Zui_Screen_Saver_Bg_Normal_DrawStyle[] =
{
    { CP_RECT, CP_ZUI_RECT_INDEX_4 },
    { CP_NOON, 0 },
};

/////////////////////////////////////////////////////
// SCREEN_SAVER_TEXT styles..

static DRAWSTYLE _MP_TBLSEG _Zui_Screen_Saver_Text_Normal_DrawStyle[] =
{
    { CP_TEXT_OUT, CP_ZUI_TEXT_OUT_INDEX_660 },
    { CP_NOON, 0 },
};
static DRAWSTYLE _MP_TBLSEG _Zui_Screen_Saver_Text_Focus_DrawStyle[] =
{
    { CP_TEXT_OUT, CP_ZUI_TEXT_OUT_INDEX_661 },
    { CP_NOON, 0 },
};

/////////////////////////////////////////////////////
// SUB_SCREEN_SAVER_FRAME_L styles..

static DRAWSTYLE _MP_TBLSEG _Zui_Sub_Screen_Saver_Frame_L_Normal_DrawStyle[] =
{
    { CP_RECT, CP_ZUI_RECT_INDEX_5 },
    { CP_NOON, 0 },
};

/////////////////////////////////////////////////////
// SUB_SCREEN_SAVER_BG_L styles..

static DRAWSTYLE _MP_TBLSEG _Zui_Sub_Screen_Saver_Bg_L_Normal_DrawStyle[] =
{
    { CP_RECT, CP_ZUI_RECT_INDEX_6 },
    { CP_NOON, 0 },
};

/////////////////////////////////////////////////////
// SUB_SCREEN_SAVER_TEXT_L styles..

static DRAWSTYLE _MP_TBLSEG _Zui_Sub_Screen_Saver_Text_L_Normal_DrawStyle[] =
{
    { CP_TEXT_OUT, CP_ZUI_TEXT_OUT_INDEX_662 },
    { CP_NOON, 0 },
};
#define _Zui_Sub_Screen_Saver_Text_L_Focus_DrawStyle _Zui_Sub_Screen_Saver_Text_L_Normal_DrawStyle

/////////////////////////////////////////////////////
// SUB_SCREEN_SAVER_FRAME_R styles..

static DRAWSTYLE _MP_TBLSEG _Zui_Sub_Screen_Saver_Frame_R_Normal_DrawStyle[] =
{
    { CP_RECT, CP_ZUI_RECT_INDEX_7 },
    { CP_NOON, 0 },
};

/////////////////////////////////////////////////////
// SUB_SCREEN_SAVER_BG_R styles..

#define _Zui_Sub_Screen_Saver_Bg_R_Normal_DrawStyle _Zui_Sub_Screen_Saver_Bg_L_Normal_DrawStyle

/////////////////////////////////////////////////////
// SUB_SCREEN_SAVER_TEXT_R styles..

#define _Zui_Sub_Screen_Saver_Text_R_Normal_DrawStyle _Zui_Sub_Screen_Saver_Text_L_Normal_DrawStyle
#define _Zui_Sub_Screen_Saver_Text_R_Focus_DrawStyle _Zui_Sub_Screen_Saver_Text_L_Normal_DrawStyle

//////////////////////////////////////////////////////
// Window Draw Style List  (normal, focused, disable)

WINDOWDRAWSTYLEDATA _MP_TBLSEG _GUI_WindowsDrawStyleList_Zui_Screen_Saver[] =
{
    // HWND_MAINFRAME
    { NULL, NULL, NULL     },

    // HWND_SCREEN_SAVER_BG_PANE
    { NULL, NULL, NULL     },

    // HWND_SCREEN_SAVER_FRAME
    { _Zui_Screen_Saver_Frame_Normal_DrawStyle, NULL, NULL     },

    // HWND_SCREEN_SAVER_BG
    { _Zui_Screen_Saver_Bg_Normal_DrawStyle, NULL, NULL     },

    // HWND_SCREEN_SAVER_TEXT
    { _Zui_Screen_Saver_Text_Normal_DrawStyle, _Zui_Screen_Saver_Text_Focus_DrawStyle, NULL     },

    // HWND_SUB_SCREEN_SAVER_FRAME_L
    { _Zui_Sub_Screen_Saver_Frame_L_Normal_DrawStyle, NULL, NULL     },

    // HWND_SUB_SCREEN_SAVER_BG_L
    { _Zui_Sub_Screen_Saver_Bg_L_Normal_DrawStyle, NULL, NULL     },

    // HWND_SUB_SCREEN_SAVER_TEXT_L
    { _Zui_Sub_Screen_Saver_Text_L_Normal_DrawStyle, _Zui_Sub_Screen_Saver_Text_L_Focus_DrawStyle, NULL     },

    // HWND_SUB_SCREEN_SAVER_FRAME_R
    { _Zui_Sub_Screen_Saver_Frame_R_Normal_DrawStyle, NULL, NULL     },

    // HWND_SUB_SCREEN_SAVER_BG_R
    { _Zui_Sub_Screen_Saver_Bg_R_Normal_DrawStyle, NULL, NULL     },

    // HWND_SUB_SCREEN_SAVER_TEXT_R
    { _Zui_Sub_Screen_Saver_Text_R_Normal_DrawStyle, _Zui_Sub_Screen_Saver_Text_R_Focus_DrawStyle, NULL     },

};
