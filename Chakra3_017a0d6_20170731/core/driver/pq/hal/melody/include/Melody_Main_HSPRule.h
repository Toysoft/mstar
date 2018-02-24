#define PQ_HSPRule_ID_Main 2
#define PQ_HSPRule_IP_NUM_Main 3
#define PQ_HSPRule_NUM_Main 24


typedef enum
{
PQ_HSPRule_PreV_ScalingDown_Interlace_Main,
PQ_HSPRule_PreV_ScalingDown_Progressive_Main,
PQ_HSPRule_ScalingDown_00x_YUV_Main,
PQ_HSPRule_ScalingDown_00x_RGB_Main,
PQ_HSPRule_ScalingDown_01x_YUV_Main,
PQ_HSPRule_ScalingDown_01x_RGB_Main,
PQ_HSPRule_ScalingDown_02x_YUV_Main,
PQ_HSPRule_ScalingDown_02x_RGB_Main,
PQ_HSPRule_ScalingDown_03x_YUV_Main,
PQ_HSPRule_ScalingDown_03x_RGB_Main,
PQ_HSPRule_ScalingDown_04x_YUV_Main,
PQ_HSPRule_ScalingDown_04x_RGB_Main,
PQ_HSPRule_ScalingDown_05x_YUV_Main,
PQ_HSPRule_ScalingDown_05x_RGB_Main,
PQ_HSPRule_ScalingDown_06x_YUV_Main,
PQ_HSPRule_ScalingDown_06x_RGB_Main,
PQ_HSPRule_ScalingDown_07x_YUV_Main,
PQ_HSPRule_ScalingDown_07x_RGB_Main,
PQ_HSPRule_ScalingDown_08x_YUV_Main,
PQ_HSPRule_ScalingDown_08x_RGB_Main,
PQ_HSPRule_ScalingDown_09x_YUV_Main,
PQ_HSPRule_ScalingDown_09x_RGB_Main,
PQ_HSPRule_ScalingDown_10x_YUV_Main,
PQ_HSPRule_ScalingDown_10x_RGB_Main,
}
MST_HSPRule_Index_Main;
extern code U8 MST_HSPRule_IP_Index_Main[PQ_HSPRule_IP_NUM_Main];
extern code U8 MST_HSPRule_Array_Main[PQ_HSPRule_NUM_Main][PQ_HSPRule_IP_NUM_Main];

