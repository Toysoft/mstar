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

static KEYEVENT _ZUI_TBLSEG _ProgramEdit_Items_Keymap[] =
{
{VK_SELECT, EN_EXE_PREDIT_SELECT},
{VK_UP, EN_EXE_PREDIT_UP},
{VK_DOWN, EN_EXE_PREDIT_DOWN},
{VK_CHANNEL_MINUS, EN_EXE_PREDIT_PAGE_DOWN},
{VK_CHANNEL_PLUS, EN_EXE_PREDIT_PAGE_UP},
{VK_RED, EN_EXE_PREDIT_DELETE},
{VK_GREEN, EN_EXE_PREDIT_RENAME},
{VK_GREEN, EN_EXE_PREDIT_LOCK},
{VK_YELLOW, EN_EXE_PREDIT_MOVE},
{VK_BLUE, EN_EXE_PREDIT_SKIP},
{VK_CHANNEL_FAV_LIST, EN_EXE_PREDIT_FAV},
{VK_MENU, EN_EXE_PREDIT_MENU},
{VK_NULL, 0},
};

static KEYEVENT _ZUI_TBLSEG _ProgramEdit_Keyboard_GRID_KEY[] =
{
{VK_MENU,EN_EXE_PREDIT_MENU},
{VK_UP,EN_EXE_NOTIFY_PARENT_KEY_UP},
{VK_DOWN,EN_EXE_NOTIFY_PARENT_KEY_DOWN},
{VK_LEFT,EN_EXE_NOTIFY_PARENT_KEY_LEFT},
{VK_RIGHT,EN_EXE_NOTIFY_PARENT_KEY_RIGHT},
{VK_GREEN,EN_EXE_PREDIT_MENU},
{VK_SELECT,EN_EXE_NOTIFY_PARENT_KEY_SELECT},
{VK_NULL,0},
};


static KEYEVENT _ZUI_TBLSEG _ProgramEdit_Rename_Chars_Keymap[] =
{
{VK_SELECT, EN_EXE_PREDIT_MENU},
{VK_MENU, EN_EXE_PREDIT_MENU},
{VK_GREEN, EN_EXE_PREDIT_MENU},
{VK_NULL, 0},
};

GUI_DATA_KEYBOARD_VARDATA _PROGRAMEDIT_KEYBOARD_GRID_VARDATA;

static GUI_DATA_KEYBOARD _ZUI_TBLSEG _PROGRAMEDIT_KEYBOARD_DATA =
{
0,      //U8 u8curIndex;
4,      //U8 u8Rows;
10,      //U8 u8Columns;
0,      //U8 charidx
0,      //U8 charMax
0,      //U8 chartype
NULL,   //HWND charlist
NULL,   //get edit text
NULL,   //set edit text
&_PROGRAMEDIT_KEYBOARD_GRID_VARDATA,
};


/// @Keymap_Table_End

/////////////////////////////////////////////////////

// Navigation Table

/////////////////////////////////////////////////////

//////////////////////////////////////////////////////
// Window List

WINDOWDATA _MP_TBLSEG _GUI_WindowList_Zui_Program_Edit[] =
{
    // HWND_MAINFRAME
    {
        EN_ZUI_MAINFRAMEWINPROC, NULL, WS_VISIBLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_BG_PANE
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_RIGHT_TRANSPARENT_BG
    {
        EN_ZUI_BGTANSPARENT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_BG_C
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_BG_L
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_BG_R
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_TOP_HALF_TITLE
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_OK_BTN
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_MENU_BTN
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_BOTTOM_HALF_BTN_PANE
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_BOTTOM_HALF_RED_BTN
    {
        EN_ZUI_BUTTONANICLICK_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_BOTTOM_HALF_GREEN_BTN
    {
        EN_ZUI_BUTTONANICLICK_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_BOTTOM_HALF_YELLOW_BTN
    {
        EN_ZUI_BUTTONANICLICK_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_BOTTOM_HALF_BLUE_BTN
    {
        EN_ZUI_BUTTONANICLICK_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_BOTTOM_HALF_FAV_BTN
    {
        EN_ZUI_BUTTONANICLICK_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_BOTTOM_HALF_MENU_BTN
    {
        EN_ZUI_BUTTONANICLICK_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_BOTTOM_HALF_LOCK_BTN
    {
        EN_ZUI_BUTTONANICLICK_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_SELECTION_PANE
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_SELECTION_YELLOW_BG
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_SELECTION_BLUE_BG
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_SELECTION_RED_BG
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_SELECTION_GREEN_BG
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_SELECTION_RED_BTN
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_SELECTION_YELLOW_BTN
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_SELECTION_RENAME_BG
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_LIST_PANE
    {
        EN_ZUI_AUTOCLOSE_WINPROC, (void*)PROGRAM_EDIT_TIME_OUT_MS, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM0
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Items_Keymap,
    },

    // HWND_PREDIT_ITEM0_TYPE
    {
        EN_ZUI_DYNAMICBITMAP_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM0_FAV
    {
        EN_ZUI_DYNAMICBITMAP_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM0_LOCK
    {
        EN_ZUI_DYNAMICBITMAP_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM0_TEXT
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM0_SKIP
    {
        EN_ZUI_DYNAMICBITMAP_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM0_UPDOWN_ARROW
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM0_LCN_INPUT
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM1
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Items_Keymap,
    },

    // HWND_PREDIT_ITEM1_TYPE
    {
        EN_ZUI_DYNAMICBITMAP_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM1_FAV
    {
        EN_ZUI_DYNAMICBITMAP_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM1_LOCK
    {
        EN_ZUI_DYNAMICBITMAP_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM1_TEXT
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM1_SKIP
    {
        EN_ZUI_DYNAMICBITMAP_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM1_UPDOWN_ARROW
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM1_LCN_INPUT
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM2
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Items_Keymap,
    },

    // HWND_PREDIT_ITEM2_TYPE
    {
        EN_ZUI_DYNAMICBITMAP_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM2_FAV
    {
        EN_ZUI_DYNAMICBITMAP_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM2_LOCK
    {
        EN_ZUI_DYNAMICBITMAP_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM2_TEXT
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM2_SKIP
    {
        EN_ZUI_DYNAMICBITMAP_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM2_UPDOWN_ARROW
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM2_LCN_INPUT
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM3
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Items_Keymap,
    },

    // HWND_PREDIT_ITEM3_TYPE
    {
        EN_ZUI_DYNAMICBITMAP_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM3_FAV
    {
        EN_ZUI_DYNAMICBITMAP_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM3_LOCK
    {
        EN_ZUI_DYNAMICBITMAP_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM3_TEXT
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM3_SKIP
    {
        EN_ZUI_DYNAMICBITMAP_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM3_UPDOWN_ARROW
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM3_LCN_INPUT
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM4
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Items_Keymap,
    },

    // HWND_PREDIT_ITEM4_TYPE
    {
        EN_ZUI_DYNAMICBITMAP_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM4_FAV
    {
        EN_ZUI_DYNAMICBITMAP_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM4_LOCK
    {
        EN_ZUI_DYNAMICBITMAP_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM4_TEXT
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM4_SKIP
    {
        EN_ZUI_DYNAMICBITMAP_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM4_UPDOWN_ARROW
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM4_LCN_INPUT
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM5
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Items_Keymap,
    },

    // HWND_PREDIT_ITEM5_TYPE
    {
        EN_ZUI_DYNAMICBITMAP_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM5_FAV
    {
        EN_ZUI_DYNAMICBITMAP_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM5_LOCK
    {
        EN_ZUI_DYNAMICBITMAP_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM5_TEXT
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM5_SKIP
    {
        EN_ZUI_DYNAMICBITMAP_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM5_UPDOWN_ARROW
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM5_LCN_INPUT
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM6
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Items_Keymap,
    },

    // HWND_PREDIT_ITEM6_TYPE
    {
        EN_ZUI_DYNAMICBITMAP_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM6_FAV
    {
        EN_ZUI_DYNAMICBITMAP_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM6_LOCK
    {
        EN_ZUI_DYNAMICBITMAP_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM6_TEXT
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM6_SKIP
    {
        EN_ZUI_DYNAMICBITMAP_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM6_UPDOWN_ARROW
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM6_LCN_INPUT
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM7
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Items_Keymap,
    },

    // HWND_PREDIT_ITEM7_TYPE
    {
        EN_ZUI_DYNAMICBITMAP_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM7_FAV
    {
        EN_ZUI_DYNAMICBITMAP_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM7_LOCK
    {
        EN_ZUI_DYNAMICBITMAP_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM7_TEXT
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM7_SKIP
    {
        EN_ZUI_DYNAMICBITMAP_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM7_UPDOWN_ARROW
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM7_LCN_INPUT
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM8
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Items_Keymap,
    },

    // HWND_PREDIT_ITEM8_TYPE
    {
        EN_ZUI_DYNAMICBITMAP_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM8_FAV
    {
        EN_ZUI_DYNAMICBITMAP_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM8_LOCK
    {
        EN_ZUI_DYNAMICBITMAP_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM8_TEXT
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM8_SKIP
    {
        EN_ZUI_DYNAMICBITMAP_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM8_UPDOWN_ARROW
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM8_LCN_INPUT
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM9
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Items_Keymap,
    },

    // HWND_PREDIT_ITEM9_TYPE
    {
        EN_ZUI_DYNAMICBITMAP_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM9_FAV
    {
        EN_ZUI_DYNAMICBITMAP_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM9_LOCK
    {
        EN_ZUI_DYNAMICBITMAP_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM9_TEXT
    {
        EN_ZUI_DYNAMICCOLORTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM9_SKIP
    {
        EN_ZUI_DYNAMICBITMAP_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM9_UPDOWN_ARROW
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_ITEM9_LCN_INPUT
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_KEYBOARD
    {
        EN_ZUI_KEYBOARDINPUT_WINPROC, &_PROGRAMEDIT_KEYBOARD_DATA, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_KEY_0
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Keyboard_GRID_KEY,
    },

    // HWND_PREDIT_KEY_Q
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Keyboard_GRID_KEY,
    },

    // HWND_PREDIT_KEY_A
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Keyboard_GRID_KEY,
    },

    // HWND_PREDIT_KEY_Z
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Keyboard_GRID_KEY,
    },

    // HWND_PREDIT_KEY_1
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Keyboard_GRID_KEY,
    },

    // HWND_PREDIT_KEY_W
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Keyboard_GRID_KEY,
    },

    // HWND_PREDIT_KEY_S
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Keyboard_GRID_KEY,
    },

    // HWND_PREDIT_KEY_X
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Keyboard_GRID_KEY,
    },

    // HWND_PREDIT_KEY_2
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Keyboard_GRID_KEY,
    },

    // HWND_PREDIT_KEY_E
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Keyboard_GRID_KEY,
    },

    // HWND_PREDIT_KEY_D
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Keyboard_GRID_KEY,
    },

    // HWND_PREDIT_KEY_C
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Keyboard_GRID_KEY,
    },

    // HWND_PREDIT_KEY_3
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Keyboard_GRID_KEY,
    },

    // HWND_PREDIT_KEY_R
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Keyboard_GRID_KEY,
    },

    // HWND_PREDIT_KEY_F
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Keyboard_GRID_KEY,
    },

    // HWND_PREDIT_KEY_V
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Keyboard_GRID_KEY,
    },

    // HWND_PREDIT_KEY_4
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Keyboard_GRID_KEY,
    },

    // HWND_PREDIT_KEY_T
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Keyboard_GRID_KEY,
    },

    // HWND_PREDIT_KEY_G
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Keyboard_GRID_KEY,
    },

    // HWND_PREDIT_KEY_B
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Keyboard_GRID_KEY,
    },

    // HWND_PREDIT_KEY_5
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Keyboard_GRID_KEY,
    },

    // HWND_PREDIT_KEY_Y
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Keyboard_GRID_KEY,
    },

    // HWND_PREDIT_KEY_H
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Keyboard_GRID_KEY,
    },

    // HWND_PREDIT_KEY_N
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Keyboard_GRID_KEY,
    },

    // HWND_PREDIT_KEY_6
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Keyboard_GRID_KEY,
    },

    // HWND_PREDIT_KEY_U
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Keyboard_GRID_KEY,
    },

    // HWND_PREDIT_KEY_J
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Keyboard_GRID_KEY,
    },

    // HWND_PREDIT_KEY_M
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Keyboard_GRID_KEY,
    },

    // HWND_PREDIT_KEY_7
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Keyboard_GRID_KEY,
    },

    // HWND_PREDIT_KEY_I
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Keyboard_GRID_KEY,
    },

    // HWND_PREDIT_KEY_K
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Keyboard_GRID_KEY,
    },

    // HWND_PREDIT_KEY_SYMBOL
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Keyboard_GRID_KEY,
    },

    // HWND_PREDIT_KEY_8
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Keyboard_GRID_KEY,
    },

    // HWND_PREDIT_KEY_O
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Keyboard_GRID_KEY,
    },

    // HWND_PREDIT_KEY_L
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Keyboard_GRID_KEY,
    },

    // HWND_PREDIT_KEY_BLANK
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Keyboard_GRID_KEY,
    },

    // HWND_PREDIT_KEY_9
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Keyboard_GRID_KEY,
    },

    // HWND_PREDIT_KEY_P
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Keyboard_GRID_KEY,
    },

    // HWND_PREDIT_KEY_BACKSPACE
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Keyboard_GRID_KEY,
    },

    // HWND_PREDIT_KEY_SHIFT
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _ProgramEdit_Keyboard_GRID_KEY,
    },

    // HWND_PREDIT_INFO_MSG_BOX
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_INFO_CHAR0
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_INFO_CHAR1
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_INFO_CHAR2
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_INFO_CHAR3
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_INFO_CHAR4
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PREDIT_RENAME_PANE
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PREDIT_RENAME_CHAR0
    {
        EN_ZUI_PREDITRENAMEINPUT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        _ProgramEdit_Rename_Chars_Keymap,
    },

    // HWND_PREDIT_RENAME_CHAR1
    {
        EN_ZUI_PREDITRENAMEINPUT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        _ProgramEdit_Rename_Chars_Keymap,
    },

    // HWND_PREDIT_RENAME_CHAR2
    {
        EN_ZUI_PREDITRENAMEINPUT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        _ProgramEdit_Rename_Chars_Keymap,
    },

    // HWND_PREDIT_RENAME_CHAR3
    {
        EN_ZUI_PREDITRENAMEINPUT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        _ProgramEdit_Rename_Chars_Keymap,
    },

    // HWND_PREDIT_RENAME_CHAR4
    {
        EN_ZUI_PREDITRENAMEINPUT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        _ProgramEdit_Rename_Chars_Keymap,
    },

    // HWND_PREDIT_RENAME_CHAR_BLK
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

};
