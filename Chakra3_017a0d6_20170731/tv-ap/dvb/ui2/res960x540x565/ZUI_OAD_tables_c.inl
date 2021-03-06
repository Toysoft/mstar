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


/// @Keymap_Table_Begin

static KEYEVENT _ZUI_TBLSEG _ConfirmSetting_Item_Keymap[] =
{
#if (ENABLE_OAD)
{VK_LEFT, EN_EXE_OAD_BTN_YES},
{VK_RIGHT, EN_EXE_OAD_BTN_NO},
#endif
{VK_NULL, 0},
};

static KEYEVENT _ZUI_TBLSEG _ExitDownload_Item_Keymap[] =
{
#if (ENABLE_OAD)
{VK_EXIT, EN_EXE_OAD_EXIT},
#endif
{VK_NULL, 0},
};
/// @Keymap_Table_End

/////////////////////////////////////////////////////

// Navigation Table

/////////////////////////////////////////////////////

//////////////////////////////////////////////////////
// Window List

WINDOWDATA _MP_TBLSEG _GUI_WindowList_Zui_Oad[] =
{
    // HWND_MAINFRAME
    {
        EN_ZUI_MAINFRAMEWINPROC, NULL, WS_VISIBLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_OAD_BG
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_OAD_BG_TOP
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_OAD_BG_L
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_OAD_BG_C
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_OAD_BG_R
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_OAD_BTN_PANE
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ConfirmSetting_Item_Keymap,
    },

    // HWND_OAD_BTN_YES
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_OAD_BTN_YES_LEFT_ARROW
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_OAD_BTN_YES_TEXT
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_OAD_BTN_NO
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_OAD_BTN_NO_RIGHT_ARROW
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_OAD_BTN_NO_TEXT
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_OAD_BTN_EXIT
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ExitDownload_Item_Keymap,
    },

    // HWND_OAD_BTN_EXIT_TEXT
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_OAD_TEXT_PANE
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_OAD_TEXT1
    {
        EN_ZUI_DYNAMICEPGPUNCTEXT_WINPROC, (void*)6, WS_VISIBLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_OAD_TEXT2
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_OAD_TEXT3
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_OAD_VERSION_PANE
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_OAD_TV_VERSION
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_OAD_TS_VERSION
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_OAD_YES_TO_UPGRADE
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_OAD_IGNORE_UPGRADE
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_NZ_OAD_VERSION_PANE
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_NZ_OAD_TV_VERSION
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_NZ_OAD_TS_VERSION
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

};
