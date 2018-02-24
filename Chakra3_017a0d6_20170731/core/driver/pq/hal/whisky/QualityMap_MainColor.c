////////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2008-2009 MStar Semiconductor, Inc.
// All rights reserved.
//
// Unless otherwise stipulated in writing, any and all information contained
// herein regardless in any format shall remain the sole proprietary of
// MStar Semiconductor Inc. and be kept in strict confidence
// ("MStar Confidential Information") by the recipient.
// Any unauthorized act including without limitation unauthorized disclosure,
// copying, use, reproduction, sale, distribution, modification, disassembling,
// reverse engineering and compiling of the contents of MStar Confidential
// Information is unlawful and strictly prohibited. MStar hereby reserves the
// rights to any and all damages, losses, costs and expenses resulting therefrom.
//
////////////////////////////////////////////////////////////////////////////////

#define PQTABLE_NAME    MAINCOLOR                // table config parameter

#include <pthread.h>

#include "MsTypes.h"
#include "drvXC_IOPort.h"
#include "apiXC.h"

#include "color_reg.h"
#include "drvPQ_Define.h"
#if ENABLE_PQ_CUSTOMER_MAIN_GRULE
#include "drvPQ_Declare.h"
#include "drvPQ.h"
#include "hwreg_utility2.h"

#define PQTBL_REGTYPE       PQTBL_COLOR       // table config parameter

#if(PQ_ONLY_SUPPORT_BIN == 0)
#include "Eden_Main_Color.c"                  // table config parameter
#include "Eden_Main_Color_1920.c"             // table config parameter

#include "Eden_Main_Color_GRule.c"            // table config parameter
#include "Eden_Main_Color_1920_GRule.c"       // table config parameter

#include "Eden_1_Main_Color_1.c"                  // table config parameter
#include "Eden_1_Main_Color_1_1366.c"             // table config parameter

#include "Eden_1_Main_Color_1_GRule.c"            // table config parameter
#include "Eden_1_Main_Color_1_1366_GRule.c"       // table config parameter
#endif

#include "QualityMode.h"
#include "drvPQ_Datatypes.h"
#include "mhal_pq.h"
#include "drvPQ_Template.h"
#endif
