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
#ifndef ADAPTER_CHANNEL_DECODER_H
#define ADAPTER_CHANNEL_DECODER_H

#include "frontend.h"
#include "databus.h"

#ifdef __cplusplus
extern "C" {
#endif

struct dibChannelDecoderMonitor;
struct dibDemodChannelProfile;
struct dibDVBSignalStatus;
struct dibFrontend;
struct dibChannel;

//! generic description of a Channel decoder
/**
 * This struct describes a channel decoder in a generic way. Each channel decoder driver has to implement one.
 */
struct dibChannelDecoderInfo {
    const char name[MAX_INFO_NAME_LENGTH]; /*! Keeps a human-readable name as a string. */
    uint32_t caps; /*! Defines the capabilities (currently unused). */
    uint16_t pid_filter_count; /*! Defines the maximum number of PIDs which can be filtered by the channel decoder */

    struct {
        int (*reset) (struct dibFrontend *);

        int (*wakeup) (struct dibFrontend *);
        int (*sleep) (struct dibFrontend *, uint8_t deep);

        int (*tune) (struct dibFrontend *, struct dibChannel *channel);

        int (*get_channel) (struct dibFrontend *, struct dibChannel *);

        int (*set_output_mode) (struct dibFrontend *, int mode);
        int (*set_input) (struct dibFrontend *, int input);

        int (*pid_filter_ctrl) (struct dibFrontend *, uint8_t onoff);
        int (*pid_filter) (struct dibFrontend *, uint8_t id, uint16_t pid, uint8_t onoff);

        /**
         * Get detailed monitoring information
         */
        int (*generic_monitoring) (struct dibFrontend *, uint32_t type, uint8_t *buff, uint32_t size, uint32_t offset);
        int (*set_viterbi) (struct dibFrontend *, int);
        int (*get_carrier_power) (struct dibFrontend *, int, double[3], double[3]);
        int (*reset_pe_count) (struct dibFrontend *);

        int (*release) (struct dibFrontend *);

        int (*get_signal_status) (struct dibFrontend *, struct dibDVBSignalStatus *);
    } ops;

    struct dibDataBusClient data_bus_client; /*! structure the channel decoder uses to read from and write to itself (how to access the register) */

    uint8_t ber_rs_len;
    uint32_t callback_time;
};

#define channel_decoder_get_name(fe) fe->channel_decoder_info->name
#define channel_decoder_get_caps(fe) fe->channel_decoder_info->caps

/* stable API for dibDemodOps - use this instead of the function pointers directly */
#define FE_CHANNEL_DECODER_FUNC_CHECK(obj, func)  FE_FUNC_CHECK(obj, channel_decoder_info, func)
#ifndef FE_CHANNEL_DECODER_FUNC_CALL
#define FE_CHANNEL_DECODER_FUNC_CALL(obj, func)   FE_FUNC_CALL(obj,  channel_decoder_info, func)
#endif

//! Reset a channel decoder
#define channel_decoder_reset(d) (FE_CHANNEL_DECODER_FUNC_CHECK(d, reset) ? FE_CHANNEL_DECODER_FUNC_CALL(d, reset)(d) : DIB_RETURN_SUCCESS)

//! Wake up a channel decoder
/**
 * Has to be called after sleep and before each tune - to put the channel decoder into a defined state
 *
 * \param d pointer to a valid struct dibFrontend
 */
extern int channel_decoder_wakeup(struct dibFrontend *fe);
#define channel_decoder_init channel_decoder_wakeup

//! Software-suspend a channel decoder.
/**
 * Put the channel decoder to sleep per software. Note that the power consumption is
 * still higher than doing it by hardware. Temporary low-power-mode during
 * runtime.
 *
 * \param d pointer to a valid struct dibFrontend
 */
extern int channel_decoder_sleep(struct dibFrontend *);

//! Deep-sleep a channel decoder.
/**
 * When the external power supply is shutdown one needs to call this
 * function to tell the channel decoder-driver to do the right thing in order to
 * be able to wake up again. After resuming from a deep-sleep the
 * channel decoder has to be reset.
 *
 * \param d pointer to a valid struct dibFrontend
 */
extern int channel_decoder_deep_sleep(struct dibFrontend *);

//! Tune and autosearch the channel decoder
/**
 * Tune the channel decoder to a channel with known parameters. See common.h for all fields of struct dibChannel.
 *
 * \param channel decoder pointer to a valid struct dibFrontend
 * \param ch pointer to a valid struct dibChannel
 */
extern int channel_decoder_tune(struct dibFrontend * fe, struct dibChannel *ch);

//! Request the channel parameters (TPS, TMCC, other)
/**
 * After successfully finishing the autosearch (or at any time after
 * tuning successfully) the channel parameters can be querried calling
 * this function. Note that RF_kHz and the bandwidth are not returned everytime.
 *
 * \param d pointer to a valid struct dibFrontend
 * \param c pointer to a valid struct dibChannel. Except RF_kHz and bandwidth_kHz all fields will be overwritten.
 */
#define channel_decoder_get_channel(d,c) (FE_CHANNEL_DECODER_FUNC_CHECK(d, get_channel) ? FE_CHANNEL_DECODER_FUNC_CALL(d, get_channel)(d, c) : DIB_RETURN_ERROR)

//! Set the output mode of a channel decoder
/**
 * Set up the output_mode of a channel decoder. Valid modes can be found in common.h . (e.g. OUTMODE_DIVERSITY, OUTMODE_MPEG2_SERIAL).
 *
 * \param d pointer to a valid struct dibFrontend
 * \param m output mode (default: OUTMODE_MPEG2_FIFO)
 */
#define channel_decoder_set_output_mode(d,m) (FE_CHANNEL_DECODER_FUNC_CHECK(d, set_output_mode) ? FE_CHANNEL_DECODER_FUNC_CALL(d, set_output_mode)(d, m) : DIB_RETURN_ERROR)

//! Set the input of a channel decoder
/**
 * Set up the input of a channel decoder. Valid modes can be found in ....
 *
 * \param d pointer to a valid struct dibFrontend
 * \param m input (default: )
 */
#define channel_decoder_set_input(d,m) (FE_CHANNEL_DECODER_FUNC_CHECK(d, set_input) ? FE_CHANNEL_DECODER_FUNC_CALL(d, set_input)(d, m) : DIB_RETURN_ERROR)

//! PID filter control
/**
 * Enables or disabled the internal PID filter of a channel decoder. If it is disabled,
 * the complete MPEG2 Transport is put out otherwise only selected PIDs are
 * passed through (see channel decoder_pid_filter).
 *
 * \param d pointer to a valid struct dibFrontend
 * \param o 0 = disable PID filter (default), 1 = enable
 */
#define channel_decoder_pid_filter_ctrl(d,o) (FE_CHANNEL_DECODER_FUNC_CHECK(d, pid_filter_ctrl) ? FE_CHANNEL_DECODER_FUNC_CALL(d, pid_filter_ctrl)(d, o) : DIB_RETURN_ERROR)

//! PID filter table
/**
 * Enable a PID to be filtered. Disable the consideration of a position of the internal table.
 *
 * \param d pointer to a valid struct dibFrontend
 * \param i index of the internal table
 * \param p PID to be filtered
 * \param o activate de-activate the given table index
 */
#define channel_decoder_pid_filter(d,i,p,o) (FE_CHANNEL_DECODER_FUNC_CHECK(d, pid_filter) ? FE_CHANNEL_DECODER_FUNC_CALL(d, pid_filter)(d,i,p,o) : DIB_RETURN_ERROR)

//! PID filter count
#define channel_decoder_pid_filter_count(d) ((d) != NULL && (d)->channel_decoder_info != NULL ? (d)->channel_decoder_info->pid_filter_count : 0)

/* for monitoring */
//#define channel_decoder_get_monitoring(d,m) (FE_CHANNEL_DECODER_FUNC_CHECK(d, get_monitoring) ? FE_CHANNEL_DECODER_FUNC_CALL(d, get_monitoring)(d,m) : DIB_RETURN_ERROR)
#define channel_decoder_set_viterbi(d,o) (FE_CHANNEL_DECODER_FUNC_CHECK(d, set_viterbi) ? FE_CHANNEL_DECODER_FUNC_CALL(d, set_viterbi)(d,o) : DIB_RETURN_ERROR)
#define channel_decoder_get_carrier_power(d,f,chan,noise) (FE_CHANNEL_DECODER_FUNC_CHECK(d, get_carrier_power)  ? FE_CHANNEL_DECODER_FUNC_CALL(d, get_carrier_power)(d,f,chan,noise) : DIB_RETURN_ERROR)
#define channel_decoder_reset_packet_error_count(d) (FE_CHANNEL_DECODER_FUNC_CHECK(d, reset_pe_count) ? FE_CHANNEL_DECODER_FUNC_CALL(d, reset_pe_count)(d) : DIB_RETURN_ERROR)
#define channel_decoder_set_ber_rs_len(d, l) do { if ((d) != NULL && (d)->channel_decoder_info != NULL) (d)->channel_decoder_info->ber_rs_len = l; } while (0)


//! Get tuning information
/**
 * To retrieve very basic information about the tuned signal this function can be used.
 *
 * \param d pointer to a valid struct dibFrontend
 * \param s pointer to a valid struct dibDVBSignalStatus
 */
#define channel_decoder_get_signal_status(d,s) (FE_CHANNEL_DECODER_FUNC_CHECK(d, get_signal_status) ? FE_CHANNEL_DECODER_FUNC_CALL(d, get_signal_status)(d,s) : DIB_RETURN_ERROR)

//! Free channel decoder memory
/**
 * Calling the function cleans up and frees private memory.
 *
 * \param d pointer to a valid struct dibFrontend
 */
#define channel_decoder_release(d) do { if (FE_CHANNEL_DECODER_FUNC_CHECK(d, release)) FE_CHANNEL_DECODER_FUNC_CALL(d, release)(d); } while (0)
#define channel_decoder_get_data_bus_client(d) ((d) != NULL && (d)->channel_decoder_info != NULL ? &(d)->channel_decoder_info->data_bus_client : NULL)
#define channel_decoder_get_register_access(d) channel_decoder_get_data_bus_client(d)

extern int channel_decoder_post_tune(struct dibFrontend *fe, struct dibChannel *ch);
extern int channel_decoder_get_monitoring(struct dibFrontend *, struct dibChannelDecoderMonitor *);
#ifdef __cplusplus
}
#endif

#endif
