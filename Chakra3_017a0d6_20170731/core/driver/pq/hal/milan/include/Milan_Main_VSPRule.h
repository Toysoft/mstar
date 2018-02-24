#define PQ_VSPRule_ID_Main 3
#define PQ_VSPRule_IP_NUM_Main 3
#define PQ_VSPRule_NUM_Main 24


typedef enum
{
PQ_VSPRule_PreV_ScalingDown_Interlace_Main,
PQ_VSPRule_PreV_ScalingDown_Progressive_Main,
PQ_VSPRule_ScalingDown_00x_YUV_Main,
PQ_VSPRule_ScalingDown_00x_RGB_Main,
PQ_VSPRule_ScalingDown_01x_YUV_Main,
PQ_VSPRule_ScalingDown_01x_RGB_Main,
PQ_VSPRule_ScalingDown_02x_YUV_Main,
PQ_VSPRule_ScalingDown_02x_RGB_Main,
PQ_VSPRule_ScalingDown_03x_YUV_Main,
PQ_VSPRule_ScalingDown_03x_RGB_Main,
PQ_VSPRule_ScalingDown_04x_YUV_Main,
PQ_VSPRule_ScalingDown_04x_RGB_Main,
PQ_VSPRule_ScalingDown_05x_YUV_Main,
PQ_VSPRule_ScalingDown_05x_RGB_Main,
PQ_VSPRule_ScalingDown_06x_YUV_Main,
PQ_VSPRule_ScalingDown_06x_RGB_Main,
PQ_VSPRule_ScalingDown_07x_YUV_Main,
PQ_VSPRule_ScalingDown_07x_RGB_Main,
PQ_VSPRule_ScalingDown_08x_YUV_Main,
PQ_VSPRule_ScalingDown_08x_RGB_Main,
PQ_VSPRule_ScalingDown_09x_YUV_Main,
PQ_VSPRule_ScalingDown_09x_RGB_Main,
PQ_VSPRule_ScalingDown_10x_YUV_Main,
PQ_VSPRule_ScalingDown_10x_RGB_Main,
}
MST_VSPRule_Index_Main;
extern code U8 MST_VSPRule_IP_Index_Main[PQ_VSPRule_IP_NUM_Main];
extern code U8 MST_VSPRule_Array_Main[PQ_VSPRule_NUM_Main][PQ_VSPRule_IP_NUM_Main];

