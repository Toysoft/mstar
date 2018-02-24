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
////////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2006-2009 MStar Semiconductor, Inc.
// All rights reserved.
//
// Unless otherwise stipulated in writing, any and all information contained
// herein regardless in any format shall remain the sole proprietary of
// MStar Semiconductor Inc. and be kept in strict confidence
// (��MStar Confidential Information��) by the recipient.
// Any unauthorized act including without limitation unauthorized disclosure,
// copying, use, reproduction, sale, distribution, modification, disassembling,
// reverse engineering and compiling of the contents of MStar Confidential
// Information is unlawful and strictly prohibited. MStar hereby reserves the
// rights to any and all damages, losses, costs and expenses resulting therefrom.
//
////////////////////////////////////////////////////////////////////////////////

#define MAPP_ZUI_CTL_BGTRANSPARENT_C
#define _ZUI_INTERNAL_INSIDE_ //NOTE: for ZUI internal


//-------------------------------------------------------------------------------------------------
// Include Files
//-------------------------------------------------------------------------------------------------
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "datatype.h"
#include "msAPI_OSD.h"
#include "MApp_ZUI_Main.h"
#include "MApp_ZUI_APIcommon.h"
#include "MApp_ZUI_APIstrings.h"
#include "MApp_ZUI_APIwindow.h"
#include "MApp_ZUI_APItables.h"
#include "MApp_ZUI_APIgdi.h"
#include "MApp_ZUI_APIdraw.h"
#include "MApp_ZUI_APIcontrols.h"
#include "MApp_ZUI_APIcomponent.h"
#include "MApp_ZUI_ACTglobal.h"
#include "OSDcp_Bitmap_EnumIndex.h"


///////////////////////////////////////////////////////////////////////////////
///  global  MApp_ZUI_CTL_BgTransparentWinProc
///  Window Proc for "transparent background" control, which shows a transparent color
///
///  @param [in]       hwnd HWND     window handle
///  @param [in]       pMsg PMSG     message type
///
///  @return S32 message execute result
///
///  @author MStarSemi @date 2007/1/29
///////////////////////////////////////////////////////////////////////////////
S32 MApp_ZUI_CTL_BgTransparentWinProc(HWND hwnd, PMSG pMsg)
{
    static DRAW_FILL_RECT _ZUI_TBLSEG _TopIconFillRectBg =
    {
        ZUI_COLOR_TRANSPARENT_RGB8888, //RcolorFrom;
        ZUI_COLOR_TRANSPARENT_RGB8888, //Rcolorto;
        OSD_GRADIENT_DISABLE //eRectGradient;
    };

    switch(pMsg->message)
    {
        case MSG_PAINT:
            {
                const PAINT_PARAM * param = (const PAINT_PARAM *)pMsg->wParam;
                _MApp_ZUI_API_DrawDynamicComponent(CP_FILL_RECT, &_TopIconFillRectBg, &param->dc, param->rect);
            }
            return 0; //stop doing default winproc
        default:
            break;
    }
    return DEFAULTWINPROC(hwnd, pMsg);

#if 0
    switch(pMsg->message)
    {

        case MSG_PAINT:
            {
                //get buffer GC for offline drawing...
                PAINT_PARAM * param = (PAINT_PARAM*)pMsg->wParam;
                RECT rcDraw;
                memcpy(&rcDraw, param->rect, sizeof(RECT));
                MApp_ZUI_API_IntersectRect(&rcDraw, param->rect_invalidate);
                if (rcDraw.width > 0 && rcDraw.height > 0)
                {
                    DRAW_FILL_RECT draw_rect;
                    draw_rect.fromColor = ZUI_COLOR_TRANSPARENT_RGB8888;
                    draw_rect.toColor = ZUI_COLOR_TRANSPARENT_RGB8888;
                    draw_rect.eGradient = OSD_GRADIENT_DISABLE;
                    _MApp_ZUI_API_DrawDynamicComponent(CP_FILL_RECT, &draw_rect, &param->dc, &rcDraw);
                }
            }
            return 0;


        //2008/4/18: note: draw second inv rect even if full screen...
        //   example: 1. we have a full screen transparent background,
        //            2. hide some controls, it maybe divided into 2 inv rect
        //            3. use first inv rect for transparent background (transparent bg will apply intersect rect)
        //            4. full screen = true but second region will not be drawn..
        ///  note: we use intersect rectangle for minimize drawing region,
        ///        so you need to disable full screen
        case MSG_CREATE:
        case MSG_NOTIFY_SHOW:
        case MSG_NOTIFY_HIDE:
            MApp_ZUI_API_EnableFullScreenRelease(
                !MApp_ZUI_API_IsWindowVisible(hwnd));
            break;
        case MSG_DESTROY:
            MApp_ZUI_API_EnableFullScreenRelease(TRUE);
            break;

        default:
            break;
    }

    return DEFAULTWINPROC(hwnd, pMsg);
#endif

}


#undef MAPP_ZUI_CTL_BGTRANSPARENT_C
