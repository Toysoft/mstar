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



/////////////////////////////////////////////////////
// MAINFRAME styles..


/////////////////////////////////////////////////////
// TEMP_OVERTOP_WARNING_WINDOW styles..

static DRAWSTYLE _MP_TBLSEG _Zui_Temp_Overtop_Warning_Window_Normal_DrawStyle[] =
{
    { CP_FILL_RECT, CP_ZUI_FILL_RECT_INDEX_0 },
    { CP_NOON, 0 },
};

/////////////////////////////////////////////////////
// TEMP_OVERTOP_HINT_ICON styles..

static DRAWSTYLE _MP_TBLSEG _Zui_Temp_Overtop_Hint_Icon_Normal_DrawStyle[] =
{
    { CP_BITMAP, CP_ZUI_BITMAP_INDEX_377 },
    { CP_NOON, 0 },
};

//////////////////////////////////////////////////////
// Window Draw Style List  (normal, focused, disable)

WINDOWDRAWSTYLEDATA _MP_TBLSEG _GUI_WindowsDrawStyleList_Zui_Temp_Overtop[] =
{
    // HWND_MAINFRAME
    { NULL, NULL, NULL     },

    // HWND_TEMP_OVERTOP_WARNING_WINDOW
    { _Zui_Temp_Overtop_Warning_Window_Normal_DrawStyle, NULL, NULL     },

    // HWND_TEMP_OVERTOP_HINT_ICON
    { _Zui_Temp_Overtop_Hint_Icon_Normal_DrawStyle, NULL, NULL     },

};
