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

static KEYEVENT _ZUI_TBLSEG _Source_Input_Items_Keymap[] =
{
{VK_SELECT, EN_EXE_SWITCH_INPUTSOURCE},
//{VK_SELECT, EN_EXE_CLOSE_CURRENT_OSD},
{VK_SELECT, EN_EXE_SHOW_BRIEF_CH_INFO},
{VK_INPUT_SOURCE, EN_EXE_NAV_KEY_DOWN},
{VK_INPUT_SOURCE, EN_EXE_EFFECT_POPUP},
{VK_DOWN, EN_EXE_NOTIFY_PARENT_KEY_DOWN },
{VK_DOWN, EN_EXE_EFFECT_POPUP},
{VK_UP, EN_EXE_NOTIFY_PARENT_KEY_UP},
{VK_UP, EN_EXE_EFFECT_POPUP},
{VK_NULL, 0},
};

static KEYEVENT _ZUI_TBLSEG _Source_Input_Items_Keymap_radio[] =
{
{VK_SELECT, EN_EXE_SWITCH_INPUTSOURCE},
//{VK_SELECT, EN_EXE_CLOSE_CURRENT_OSD},
#if (ENABLE_FM_RADIO)
{VK_SELECT, EN_EXE_GOTO_RADIO},
#endif
{VK_INPUT_SOURCE, EN_EXE_NAV_KEY_DOWN},
{VK_INPUT_SOURCE, EN_EXE_EFFECT_POPUP},
{VK_DOWN, EN_EXE_NOTIFY_PARENT_KEY_DOWN },
{VK_DOWN, EN_EXE_EFFECT_POPUP},
{VK_UP, EN_EXE_NOTIFY_PARENT_KEY_UP},
{VK_UP, EN_EXE_EFFECT_POPUP},
{VK_NULL, 0},
};

//_PVR_SOURCE_CHANGE_CHECK_CONFIRM_BTN_Keymap
static KEYEVENT _ZUI_TBLSEG _PVR_SOURCE_CHANGE_CHECK_CONFIRM_BTN_OK_Keymap[] =
{
#if ENABLE_PVR
{VK_SELECT, EN_EXE_SWITCH_INPUTSOURCE_CONFIRM_OK},
#endif
{VK_DOWN, EN_EXE_NOTIFY_PARENT_KEY_DOWN },
{VK_UP, EN_EXE_NOTIFY_PARENT_KEY_UP},
{VK_NULL, 0},
};

//_PVR_SOURCE_CHANGE_CHECK_CONFIRM_BTN_Keymap
static KEYEVENT _ZUI_TBLSEG _PVR_SOURCE_CHANGE_CHECK_CONFIRM_BTN_CANCEL_Keymap[] =
{
#if ENABLE_PVR
{VK_SELECT, EN_EXE_SWITCH_INPUTSOURCE_CONFIRM_CANCEL},
#endif
{VK_DOWN, EN_EXE_NOTIFY_PARENT_KEY_DOWN },
{VK_UP, EN_EXE_NOTIFY_PARENT_KEY_UP},
{VK_NULL, 0},
};

//_PVR_SOURCE_CHANGE_CHECK_CONFIRM_BTN_Keymap
static KEYEVENT _ZUI_TBLSEG _PVR_SOURCE_CHANGE_CHECK_CONFIRM_BTN_Keymap[] =
{
#if ENABLE_PVR
{VK_LEFT, EN_EXE_SWITCH_INPUTSOURCE_CONFIRM_OK},
{VK_RIGHT, EN_EXE_SWITCH_INPUTSOURCE_CONFIRM_CANCEL},
#endif
{VK_NULL, 0},
};

static KEYEVENT _ZUI_TBLSEG _Source_Input_Items_Keymap_Game[] =
{
#if GAME_ENABLE
{ VK_SELECT, EN_EXE_GOTO_GAME_PAGE},
#endif
{ VK_UP, EN_EXE_NOTIFY_PARENT_KEY_UP },
{ VK_DOWN, EN_EXE_NOTIFY_PARENT_KEY_DOWN },
{ VK_UP, EN_EXE_EFFECT_SLIDEITEM },
{ VK_DOWN, EN_EXE_EFFECT_SLIDEITEM },
{ VK_NULL, 0 },
};


///////////////////////////////////////////////
// dynamic list

GUI_DATA_DYNAMIC_LIST_VARDATA _INPUT_SOURCE_LIST_VARDATA;

static GUI_DATA_DYNAMIC_LIST _ZUI_TBLSEG _INPUT_SOURCE_LIST_DATA =
{
HWND_SOURCE_INPUT_ITEM_S2,
HWND_SOURCE_INPUT_ITEM_COMPONENT1,
&_INPUT_SOURCE_LIST_VARDATA
};


/// @Keymap_Table_End

/////////////////////////////////////////////////////

// Navigation Table

/////////////////////////////////////////////////////

static HWND _MP_TBLSEG _SOURCE_INPUT_ITEM_S2_Navigation[] = {HWND_SOURCE_INPUT_ITEM_SVIDEO2, HWND_SOURCE_INPUT_ITEM_ATSC, HWND_SOURCE_INPUT_ITEM_S2, HWND_SOURCE_INPUT_ITEM_S2};

static HWND _MP_TBLSEG _SOURCE_INPUT_ITEM_ATSC_Navigation[] = {HWND_SOURCE_INPUT_ITEM_S2, HWND_SOURCE_INPUT_ITEM_DVBT, HWND_SOURCE_INPUT_ITEM_ATSC, HWND_SOURCE_INPUT_ITEM_ATSC};

static HWND _MP_TBLSEG _SOURCE_INPUT_ITEM_DVBT_Navigation[] = {HWND_SOURCE_INPUT_ITEM_ATSC, HWND_SOURCE_INPUT_ITEM_DVBC, HWND_SOURCE_INPUT_ITEM_DVBT, HWND_SOURCE_INPUT_ITEM_DVBT};

static HWND _MP_TBLSEG _SOURCE_INPUT_ITEM_DVBC_Navigation[] = {HWND_SOURCE_INPUT_ITEM_DVBT, HWND_SOURCE_INPUT_ITEM_ISDB, HWND_SOURCE_INPUT_ITEM_DVBC, HWND_SOURCE_INPUT_ITEM_DVBC};

static HWND _MP_TBLSEG _SOURCE_INPUT_ITEM_ISDB_Navigation[] = {HWND_SOURCE_INPUT_ITEM_DVBC, HWND_SOURCE_INPUT_ITEM_DTMB, HWND_SOURCE_INPUT_ITEM_ISDB, HWND_SOURCE_INPUT_ITEM_ISDB};

static HWND _MP_TBLSEG _SOURCE_INPUT_ITEM_DTMB_Navigation[] = {HWND_SOURCE_INPUT_ITEM_ISDB, HWND_SOURCE_INPUT_ITEM_ATV, HWND_SOURCE_INPUT_ITEM_DTMB, HWND_SOURCE_INPUT_ITEM_DTMB};

static HWND _MP_TBLSEG _SOURCE_INPUT_ITEM_ATV_Navigation[] = {HWND_SOURCE_INPUT_ITEM_DTMB, HWND_SOURCE_INPUT_ITEM_SCART1, HWND_SOURCE_INPUT_ITEM_ATV, HWND_SOURCE_INPUT_ITEM_ATV};

static HWND _MP_TBLSEG _SOURCE_INPUT_ITEM_SCART1_Navigation[] = {HWND_SOURCE_INPUT_ITEM_ATV, HWND_SOURCE_INPUT_ITEM_SCART2, HWND_SOURCE_INPUT_ITEM_SCART1, HWND_SOURCE_INPUT_ITEM_SCART1};

static HWND _MP_TBLSEG _SOURCE_INPUT_ITEM_SCART2_Navigation[] = {HWND_SOURCE_INPUT_ITEM_SCART1, HWND_SOURCE_INPUT_ITEM_COMPONENT1, HWND_SOURCE_INPUT_ITEM_SCART2, HWND_SOURCE_INPUT_ITEM_SCART2};

static HWND _MP_TBLSEG _SOURCE_INPUT_ITEM_COMPONENT1_Navigation[] = {HWND_SOURCE_INPUT_ITEM_SCART2, HWND_SOURCE_INPUT_ITEM_COMPONENT2, HWND_SOURCE_INPUT_ITEM_COMPONENT1, HWND_SOURCE_INPUT_ITEM_COMPONENT1};

static HWND _MP_TBLSEG _SOURCE_INPUT_ITEM_COMPONENT2_Navigation[] = {HWND_SOURCE_INPUT_ITEM_COMPONENT1, HWND_SOURCE_INPUT_ITEM_PC, HWND_SOURCE_INPUT_ITEM_COMPONENT2, HWND_SOURCE_INPUT_ITEM_COMPONENT2};

static HWND _MP_TBLSEG _SOURCE_INPUT_ITEM_PC_Navigation[] = {HWND_SOURCE_INPUT_ITEM_COMPONENT2, HWND_SOURCE_INPUT_ITEM_HDMI1, HWND_SOURCE_INPUT_ITEM_PC, HWND_SOURCE_INPUT_ITEM_PC};

static HWND _MP_TBLSEG _SOURCE_INPUT_ITEM_HDMI1_Navigation[] = {HWND_SOURCE_INPUT_ITEM_PC, HWND_SOURCE_INPUT_ITEM_HDMI2, HWND_SOURCE_INPUT_ITEM_HDMI1, HWND_SOURCE_INPUT_ITEM_HDMI1};

static HWND _MP_TBLSEG _SOURCE_INPUT_ITEM_HDMI2_Navigation[] = {HWND_SOURCE_INPUT_ITEM_HDMI1, HWND_SOURCE_INPUT_ITEM_HDMI3, HWND_SOURCE_INPUT_ITEM_HDMI2, HWND_SOURCE_INPUT_ITEM_HDMI2};

static HWND _MP_TBLSEG _SOURCE_INPUT_ITEM_HDMI3_Navigation[] = {HWND_SOURCE_INPUT_ITEM_HDMI2, HWND_SOURCE_INPUT_ITEM_HDMI4, HWND_SOURCE_INPUT_ITEM_HDMI3, HWND_SOURCE_INPUT_ITEM_HDMI3};

static HWND _MP_TBLSEG _SOURCE_INPUT_ITEM_HDMI4_Navigation[] = {HWND_SOURCE_INPUT_ITEM_HDMI3, HWND_SOURCE_INPUT_ITEM_AV1, HWND_SOURCE_INPUT_ITEM_HDMI4, HWND_SOURCE_INPUT_ITEM_HDMI4};

static HWND _MP_TBLSEG _SOURCE_INPUT_ITEM_AV1_Navigation[] = {HWND_SOURCE_INPUT_ITEM_HDMI4, HWND_SOURCE_INPUT_ITEM_AV2, HWND_SOURCE_INPUT_ITEM_AV1, HWND_SOURCE_INPUT_ITEM_AV1};

static HWND _MP_TBLSEG _SOURCE_INPUT_ITEM_AV2_Navigation[] = {HWND_SOURCE_INPUT_ITEM_AV1, HWND_SOURCE_INPUT_ITEM_AV3, HWND_SOURCE_INPUT_ITEM_AV2, HWND_SOURCE_INPUT_ITEM_AV2};

static HWND _MP_TBLSEG _SOURCE_INPUT_ITEM_AV3_Navigation[] = {HWND_SOURCE_INPUT_ITEM_AV2, HWND_SOURCE_INPUT_ITEM_SVIDEO1, HWND_SOURCE_INPUT_ITEM_AV3, HWND_SOURCE_INPUT_ITEM_AV3};

static HWND _MP_TBLSEG _SOURCE_INPUT_ITEM_SVIDEO1_Navigation[] = {HWND_SOURCE_INPUT_ITEM_AV3, HWND_SOURCE_INPUT_ITEM_SVIDEO2, HWND_SOURCE_INPUT_ITEM_SVIDEO1, HWND_SOURCE_INPUT_ITEM_SVIDEO1};

static HWND _MP_TBLSEG _SOURCE_INPUT_ITEM_SVIDEO2_Navigation[] = {HWND_SOURCE_INPUT_ITEM_SVIDEO1, HWND_SOURCE_INPUT_ITEM_RADIO, HWND_SOURCE_INPUT_ITEM_SVIDEO2, HWND_SOURCE_INPUT_ITEM_SVIDEO2};

static HWND _MP_TBLSEG _SOURCE_INPUT_ITEM_RADIO_Navigation[] = {HWND_SOURCE_INPUT_ITEM_SVIDEO2, HWND_SOURCE_INPUT_ITEM_GAME, HWND_SOURCE_INPUT_ITEM_RADIO, HWND_SOURCE_INPUT_ITEM_RADIO};

static HWND _MP_TBLSEG _SOURCE_INPUT_ITEM_GAME_Navigation[] = {HWND_SOURCE_INPUT_ITEM_RADIO, HWND_SOURCE_INPUT_ITEM_S2, HWND_SOURCE_INPUT_ITEM_GAME, HWND_SOURCE_INPUT_ITEM_GAME};

static HWND _MP_TBLSEG _PVR_SOURCE_CHANGE_CHECK_CONFIRM_EXIT_Navigation[] = {HWND_PVR_SOURCE_CHANGE_CHECK_CONFIRM_OK, HWND_PVR_SOURCE_CHANGE_CHECK_CONFIRM_OK, HWND_PVR_SOURCE_CHANGE_CHECK_CONFIRM_OK, HWND_PVR_SOURCE_CHANGE_CHECK_CONFIRM_OK};

//////////////////////////////////////////////////////
// Window List

WINDOWDATA _MP_TBLSEG _GUI_WindowList_Zui_Input_Source[] =
{
    // HWND_MAINFRAME
    {
        EN_ZUI_MAINFRAMEWINPROC, NULL, WS_VISIBLE,
        NULL,
        NULL,
    },

    // HWND_SOURCE_BG_PANE
    {
        EN_ZUI_AUTOCLOSE_WINPROC, (void*)INPUT_SOURCE_TIME_OUT_MS, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_SOURCE_TOP_HALF_BANNER_LEFT
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_SOURCE_TOP_HALF_BANNER_MID
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_SOURCE_TOP_HALF_BANNER_RIGHT
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_SOURCE_TOP_HALF_BANNER_TITLE
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_SOURCE_BOTTOM_OK_BTN
    {
        EN_ZUI_BUTTONANICLICK_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_SOURCE_INPUT_LIST
    {
        EN_ZUI_DYNAMICLIST_WINPROC, &_INPUT_SOURCE_LIST_DATA, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_SOURCE_INPUT_ITEM_S2
    {
        EN_ZUI_INPUT_SOURCE_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _SOURCE_INPUT_ITEM_S2_Navigation,
        _Source_Input_Items_Keymap,
    },

    // HWND_SOURCE_INPUT_ITEM_ATSC
    {
        EN_ZUI_INPUT_SOURCE_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _SOURCE_INPUT_ITEM_ATSC_Navigation,
        _Source_Input_Items_Keymap,
    },

    // HWND_SOURCE_INPUT_ITEM_DVBT
    {
        EN_ZUI_INPUT_SOURCE_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _SOURCE_INPUT_ITEM_DVBT_Navigation,
        _Source_Input_Items_Keymap,
    },

    // HWND_SOURCE_INPUT_ITEM_DVBC
    {
        EN_ZUI_INPUT_SOURCE_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _SOURCE_INPUT_ITEM_DVBC_Navigation,
        _Source_Input_Items_Keymap,
    },

    // HWND_SOURCE_INPUT_ITEM_ISDB
    {
        EN_ZUI_INPUT_SOURCE_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _SOURCE_INPUT_ITEM_ISDB_Navigation,
        _Source_Input_Items_Keymap,
    },

    // HWND_SOURCE_INPUT_ITEM_DTMB
    {
        EN_ZUI_INPUT_SOURCE_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _SOURCE_INPUT_ITEM_DTMB_Navigation,
        _Source_Input_Items_Keymap,
    },

    // HWND_SOURCE_INPUT_ITEM_ATV
    {
        EN_ZUI_INPUT_SOURCE_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _SOURCE_INPUT_ITEM_ATV_Navigation,
        _Source_Input_Items_Keymap,
    },

    // HWND_SOURCE_INPUT_ITEM_SCART1
    {
        EN_ZUI_INPUT_SOURCE_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _SOURCE_INPUT_ITEM_SCART1_Navigation,
        _Source_Input_Items_Keymap,
    },

    // HWND_SOURCE_INPUT_ITEM_SCART2
    {
        EN_ZUI_INPUT_SOURCE_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _SOURCE_INPUT_ITEM_SCART2_Navigation,
        _Source_Input_Items_Keymap,
    },

    // HWND_SOURCE_INPUT_ITEM_COMPONENT1
    {
        EN_ZUI_INPUT_SOURCE_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _SOURCE_INPUT_ITEM_COMPONENT1_Navigation,
        _Source_Input_Items_Keymap,
    },

    // HWND_SOURCE_INPUT_ITEM_COMPONENT1_AIS
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_SOURCE_INPUT_ITEM_COMPONENT1_AIS_ICON
    {
        EN_ZUI_DYNAMICBITMAP_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_SOURCE_INPUT_ITEM_COMPONENT2
    {
        EN_ZUI_INPUT_SOURCE_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _SOURCE_INPUT_ITEM_COMPONENT2_Navigation,
        _Source_Input_Items_Keymap,
    },

    // HWND_SOURCE_INPUT_ITEM_PC
    {
        EN_ZUI_INPUT_SOURCE_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _SOURCE_INPUT_ITEM_PC_Navigation,
        _Source_Input_Items_Keymap,
    },

    // HWND_SOUCE_INPUT_ITEM_PC_AIS
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_SOUCE_INPUT_ITEM_PC_AIS_ICON
    {
        EN_ZUI_DYNAMICBITMAP_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_SOURCE_INPUT_ITEM_HDMI1
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _SOURCE_INPUT_ITEM_HDMI1_Navigation,
        _Source_Input_Items_Keymap,
    },

    // HWND_SOURCE_INPUT_ITEM_HDMI2
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _SOURCE_INPUT_ITEM_HDMI2_Navigation,
        _Source_Input_Items_Keymap,
    },

    // HWND_SOURCE_INPUT_ITEM_HDMI3
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _SOURCE_INPUT_ITEM_HDMI3_Navigation,
        _Source_Input_Items_Keymap,
    },

    // HWND_SOURCE_INPUT_ITEM_HDMI4
    {
        EN_ZUI_DYNAMICTEXT_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _SOURCE_INPUT_ITEM_HDMI4_Navigation,
        _Source_Input_Items_Keymap,
    },

    // HWND_SOURCE_INPUT_ITEM_AV1
    {
        EN_ZUI_INPUT_SOURCE_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _SOURCE_INPUT_ITEM_AV1_Navigation,
        _Source_Input_Items_Keymap,
    },

    // HWND_SOURCE_INPUT_ITEM_AV1_AIS
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_SOURCE_INPUT_ITEM_AV1_AIS_ICON
    {
        EN_ZUI_DYNAMICBITMAP_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_SOURCE_INPUT_ITEM_AV2
    {
        EN_ZUI_INPUT_SOURCE_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _SOURCE_INPUT_ITEM_AV2_Navigation,
        _Source_Input_Items_Keymap,
    },

    // HWND_SOURCE_INPUT_ITEM_AV3
    {
        EN_ZUI_INPUT_SOURCE_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _SOURCE_INPUT_ITEM_AV3_Navigation,
        _Source_Input_Items_Keymap,
    },

    // HWND_SOURCE_INPUT_ITEM_SVIDEO1
    {
        EN_ZUI_INPUT_SOURCE_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _SOURCE_INPUT_ITEM_SVIDEO1_Navigation,
        _Source_Input_Items_Keymap,
    },

    // HWND_SOURCE_INPUT_ITEM_SVIDEO2
    {
        EN_ZUI_INPUT_SOURCE_WINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _SOURCE_INPUT_ITEM_SVIDEO2_Navigation,
        _Source_Input_Items_Keymap,
    },

    // HWND_SOURCE_INPUT_ITEM_RADIO
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _SOURCE_INPUT_ITEM_RADIO_Navigation,
        _Source_Input_Items_Keymap_radio,
    },

    // HWND_SOURCE_INPUT_ITEM_GAME
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _SOURCE_INPUT_ITEM_GAME_Navigation,
        _Source_Input_Items_Keymap_Game,
    },

    // HWND_PVR_SOURCE_CHANGE_CHECK_PANE
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE,
        NULL,
        NULL,
    },

    // HWND_PVR_SOURCE_CHANGE_CHECK_BG
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE,
        NULL,
        NULL,
    },

    // HWND_PVR_SOURCE_CHANGE_CHECK_BG_TOP
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PVR_SOURCE_CHANGE_CHECK_BG_L
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PVR_SOURCE_CHANGE_CHECK_BG_C
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PVR_SOURCE_CHANGE_CHECK_BG_R
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PVR_SOURCE_CHANGE_CHECK_TXT_1
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE,
        NULL,
        NULL,
    },

    // HWND_PVR_SOURCE_CHANGE_CHECK_TXT_2
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        _PVR_SOURCE_CHANGE_CHECK_CONFIRM_BTN_Keymap,
    },

    // HWND_PVR_SOURCE_CHANGE_CHECK_CONFIRM_BTN
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE,
        NULL,
        NULL,
    },

    // HWND_PVR_SOURCE_CHANGE_CHECK_CONFIRM_OK
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PVR_SOURCE_CHANGE_CHECK_CONFIRM_BTN_LEFT_ARROW
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PVR_SOURCE_CHANGE_CHECK_CONFIRM_BTN_OK
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _PVR_SOURCE_CHANGE_CHECK_CONFIRM_BTN_OK_Keymap,
    },

    // HWND_PVR_SOURCE_CHANGE_CHECK_CONFIRM_EXIT
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        _PVR_SOURCE_CHANGE_CHECK_CONFIRM_EXIT_Navigation,
        NULL,
    },

    // HWND_PVR_SOURCE_CHANGE_CHECK_CONFIRM_BTN_RIGHT_ARROW
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        NULL,
    },

    // HWND_PVR_SOURCE_CHANGE_CHECK_CONFIRM_BTN_CANCEL
    {
        EN_ZUI_DEFAULTWINPROC, NULL, WS_VISIBLE|WS_FOCUSABLE|WS_SRCALPHAREPLACEDSTALPHA,
        NULL,
        _PVR_SOURCE_CHANGE_CHECK_CONFIRM_BTN_CANCEL_Keymap,
    },

};
