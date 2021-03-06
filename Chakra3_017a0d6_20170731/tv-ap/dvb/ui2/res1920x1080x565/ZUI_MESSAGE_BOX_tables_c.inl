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


/// @Keymap_Table_Begin
static KEYEVENT _ZUI_TBLSEG _Msgbox_Btn_Ok_Item_Keymap[] =
{
#if (ENABLE_UPDATE_MULTIPLEX_VIA_NIT)
{VK_SELECT, EN_EXE_MESSAGE_BOX_BTN_SELECT_OK},
#ifdef ENABLE_DELETE_PROGRAM_CONTROL
{VK_LEFT, EN_EXE_MESSAGE_BOX_BTN_SELECT_YES},
{VK_RIGHT, EN_EXE_MESSAGE_BOX_BTN_SELECT_NO},
#endif
#endif
{VK_NULL, 0},
};

static KEYEVENT _ZUI_TBLSEG _Msgbox_USB_List_Item_Keymap[] =
{
{VK_SELECT, EN_EXE_USB_LIST_SEL},
{VK_NULL, 0},
};
/// @Keymap_Table_End

/////////////////////////////////////////////////////

// Navigation Table

/////////////////////////////////////////////////////

static HWND _MP_TBLSEG _MSGBOX_USB_LIST_ITEM0_Navigation[] = {HWND_MSGBOX_USB_LIST_ITEM3, HWND_MSGBOX_USB_LIST_ITEM1, HWND_MSGBOX_USB_LIST_ITEM0, HWND_MSGBOX_USB_LIST_ITEM0};

static HWND _MP_TBLSEG _MSGBOX_USB_LIST_ITEM1_Navigation[] = {HWND_MSGBOX_USB_LIST_ITEM0, HWND_MSGBOX_USB_LIST_ITEM2, HWND_MSGBOX_USB_LIST_ITEM1, HWND_MSGBOX_USB_LIST_ITEM1};

static HWND _MP_TBLSEG _MSGBOX_USB_LIST_ITEM2_Navigation[] = {HWND_MSGBOX_USB_LIST_ITEM1, HWND_MSGBOX_USB_LIST_ITEM3, HWND_MSGBOX_USB_LIST_ITEM2, HWND_MSGBOX_USB_LIST_ITEM2};

static HWND _MP_TBLSEG _MSGBOX_USB_LIST_ITEM3_Navigation[] = {HWND_MSGBOX_USB_LIST_ITEM2, HWND_MSGBOX_USB_LIST_ITEM1, HWND_MSGBOX_USB_LIST_ITEM3, HWND_MSGBOX_USB_LIST_ITEM3};

static HWND _MP_TBLSEG _EWS_FRAME_WASPADA_Navigation[] = {HWND_EWS_FRAME, HWND_EWS_FRAME, HWND_EWS_FRAME, HWND_EWS_FRAME};

static HWND _MP_TBLSEG _DISASTER_SYMBOL2_Navigation[] = {HWND_DISASTER_SYMBOL, HWND_DISASTER_SYMBOL, HWND_DISASTER_SYMBOL, HWND_DISASTER_SYMBOL};

static HWND _MP_TBLSEG _AUTHOR_SYMBOL2_Navigation[] = {HWND_AUTHOR_SYMBOL, HWND_AUTHOR_SYMBOL, HWND_AUTHOR_SYMBOL, HWND_AUTHOR_SYMBOL};

static HWND _MP_TBLSEG _DISASTER_LOCATION_STATUS_TXT2_Navigation[] = {HWND_DISASTER_LOCATION_STATUS_TXT, HWND_DISASTER_LOCATION_STATUS_TXT, HWND_DISASTER_LOCATION_STATUS_TXT, HWND_DISASTER_LOCATION_STATUS_TXT};

static HWND _MP_TBLSEG _LOCATION_OF_DISASTER2_Navigation[] = {HWND_LOCATION_OF_DISASTER, HWND_LOCATION_OF_DISASTER, HWND_LOCATION_OF_DISASTER, HWND_LOCATION_OF_DISASTER};

static HWND _MP_TBLSEG _REMARK_DESCRIPTION2_Navigation[] = {HWND_REMARK_DESCRIPTION, HWND_REMARK_DESCRIPTION, HWND_REMARK_DESCRIPTION, HWND_REMARK_DESCRIPTION};

static HWND _MP_TBLSEG _EWS_FRAME_WASPADA_SCROLL_BAR_Navigation[] = {HWND_EWS_FRAME_WASPADA, HWND_EWS_FRAME_WASPADA, HWND_EWS_FRAME_WASPADA, HWND_EWS_FRAME_WASPADA};

static HWND _MP_TBLSEG _EWS_FRAME_WASPADA_SCROLL_BAR_1_Navigation[] = {HWND_EWS_FRAME_WASPADA, HWND_EWS_FRAME_WASPADA, HWND_EWS_FRAME_WASPADA, HWND_EWS_FRAME_WASPADA};

//////////////////////////////////////////////////////
// Window List

WINDOWDATA _MP_TBLSEG _GUI_WindowList_Zui_Message_Box[] =
{
    // HWND_MAINFRAME
    {
        EN_ZUI_MAINFRAMEWINPROC, NULL, WS_VISIBLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_MSGBOX_COMMON
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_MSGBOX_COMMON_BG
    {
        EN_ZUI_AUTOCLOSE_WINPROC, (void*)MESSAGE_BOX_TIME_OUT_MS, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_MSGBOX_COMMON_BG_TOP
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_MSGBOX_COMMON_NEW_BG_L
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_MSGBOX_COMMON_NEW_BG_C
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_MSGBOX_COMMON_NEW_BG_R
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_MSGBOX_COMMON_BG_L
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_MSGBOX_COMMON_BG_C
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_MSGBOX_COMMON_BG_R
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_MSGBOX_COMMON_TITLE
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_MSGBOX_TEXT_PANE
    {
        EN_ZUI_MSGBOXTEXTPANE_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_MSGBOX_COMMON_TEXT1
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_MSGBOX_COMMON_TEXT2
    {
        EN_ZUI_DYNAMICEPGPUNCTEXT_WINPROC, (void*)2, WS_VISIBLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_MSGBOX_PASSWORD_PANE
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_MSGBOX_PASSWORD_INPUT_1
    {
        EN_ZUI_MSGBOX_PWDINPUT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_MSGBOX_PASSWORD_INPUT_2
    {
        EN_ZUI_MSGBOX_PWDINPUT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_MSGBOX_PASSWORD_INPUT_3
    {
        EN_ZUI_MSGBOX_PWDINPUT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_MSGBOX_PASSWORD_INPUT_4
    {
        EN_ZUI_MSGBOX_PWDINPUT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_MSGBOX_PASSWORD_PRESSED_PANE
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_MSGBOX_PASSWORD_PRESSED_1
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_MSGBOX_PASSWORD_PRESSED_2
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_MSGBOX_PASSWORD_PRESSED_3
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_MSGBOX_PASSWORD_PRESSED_4
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_MSGBOX_COMMON_BTN_PANE
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_MSGBOX_COMMON_BTN_CLEAR
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_MSGBOX_COMMON_BTN_CLEAR_LEFT_ARROW
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_MSGBOX_COMMON_BTN_CLEAR_TEXT
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_MSGBOX_COMMON_BTN_OK
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_MSGBOX_COMMON_BTN_CANCEL_RIGHT_ARROW
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_MSGBOX_COMMON_BTN_CANCEL_TEXT
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_MSGBOX_COMMON_MSG_OK
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _Msgbox_Btn_Ok_Item_Keymap,
    },

    // HWND_MSGBOX_USB_LIST_PANE
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_MSGBOX_USB_LIST_ITEM0
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _MSGBOX_USB_LIST_ITEM0_Navigation,
        _Msgbox_USB_List_Item_Keymap,
    },

    // HWND_MSGBOX_USB_LIST_ITEM0_TEXT
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_MSGBOX_USB_LIST_ITEM1
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _MSGBOX_USB_LIST_ITEM1_Navigation,
        _Msgbox_USB_List_Item_Keymap,
    },

    // HWND_MSGBOX_USB_LIST_ITEM1_TEXT
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_MSGBOX_USB_LIST_ITEM2
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _MSGBOX_USB_LIST_ITEM2_Navigation,
        _Msgbox_USB_List_Item_Keymap,
    },

    // HWND_MSGBOX_USB_LIST_ITEM2_TEXT
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_MSGBOX_USB_LIST_ITEM3
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _MSGBOX_USB_LIST_ITEM3_Navigation,
        _Msgbox_USB_List_Item_Keymap,
    },

    // HWND_MSGBOX_USB_LIST_ITEM3_TEXT
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_EWS_FRAME
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_DISASTER_SYMBOL
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_AUTHOR_SYMBOL
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_DISASTER_LOCATION_STATUS_TXT
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_LOCATION_OF_DISASTER
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_DISASTER_TYPE
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_TYPE_TITLE
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_TYPE_CONTENT
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_DISASTER_DATE_AND_TIME
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_DATE_TITLE
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_DATE_CONTENT
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_DISASTER_LONGITUDE
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_LONGITUDE_TITLE
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_LONGITUDE_CONTENT
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_DISASTER_CHARACTER
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_CHARACTER_TITLE
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_CHARACTER_CONTENT
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_REMARK
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_REMARK_TITLE
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_REMARK_CONTENT
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_REMARK_DESCRIPTION
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_EWS_FRAME_WASPADA
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _EWS_FRAME_WASPADA_Navigation,
        NULL,
    },

    // HWND_DISASTER_SYMBOL2
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _DISASTER_SYMBOL2_Navigation,
        NULL,
    },

    // HWND_AUTHOR_SYMBOL2
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _AUTHOR_SYMBOL2_Navigation,
        NULL,
    },

    // HWND_DISASTER_LOCATION_STATUS_TXT2
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _DISASTER_LOCATION_STATUS_TXT2_Navigation,
        NULL,
    },

    // HWND_LOCATION_OF_DISASTER2
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _LOCATION_OF_DISASTER2_Navigation,
        NULL,
    },

    // HWND_REMARK_DESCRIPTION2
    {
        EN_ZUI_DYNAMIC_SCROL_EPGPUNCTEXT_WINPROC, (void*)4, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _REMARK_DESCRIPTION2_Navigation,
        NULL,
    },

    // HWND_EWS_FRAME_WASPADA_SCROLL_BG
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_EWS_FRAME_WASPADA_SCROLL_BG_1
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_EWS_FRAME_WASPADA_SCROLL_BAR
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _EWS_FRAME_WASPADA_SCROLL_BAR_Navigation,
        NULL,
    },

    // HWND_EWS_FRAME_WASPADA_SCROLL_BAR_1
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _EWS_FRAME_WASPADA_SCROLL_BAR_1_Navigation,
        NULL,
    },

};
