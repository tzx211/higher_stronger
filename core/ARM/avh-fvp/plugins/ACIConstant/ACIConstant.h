/*!
 * \file    ACIConstant.h
 * \brief   A simple ACI library implementation example for CDE
 * \date    Copyright 2023 Arm Limited. All rights reserved.
 */

#ifndef ACI_CONSTANT_LIBRARY
#define ACI_CONSTANT_LIBRARY

#include "ct/CDE/ACILibraryAPI.h"

class ACIConstant
{
private:
    ACIMnemonics mnemonics {
        "CONST1",       // cx1
        "CONST1A",      // cx1a
        "CONST1D",      // cx1d
        "CONST1DA",     // cx1da
        "CONST2",       // cx2
        "CONST2A",      // cx2a
        "CONST2D",      // cx2d
        "CONST2DA",     // cx2da
        "CONST3",       // cx3
        "CONST3A",      // cx3a
        "CONST3D",      // cx3d
        "CONST3DA",     // cx3da
        "VCONST1",      // vcx1_s
        "VCONST1A",     // vcx1a_s
        "VCONST1",      // vcx1_d
        "VCONST1A",     // vcx1a_d
        "VCONST1",      // vcx1_v
        "VCONST1A",     // vcx1a_v
        "VCONST2",      // vcx2_s
        "VCONST2A",     // vcx2a_s
        "VCONST2",      // vcx2_d
        "VCONST2A",     // vcx2a_d
        "VCONST2",      // vcx2_v
        "VCONST2A",     // vcx2a_v
        "VCONST3",      // vcx3_s
        "VCONST3A",     // vcx3a_s
        "VCONST3",      // vcx3_d
        "VCONST3A",     // vcx3a_d
        "VCONST3",      // vcx3_v
        "VCONST3A"      // vcx3a_v
    };

public:
    ACIMnemonics get_mnemonics() { return mnemonics; };

    uint8_t getCDECoprocessorMask()  { return 0xFF; };

    ACI_Status exec_cx1(const ACICX1DecodeInfo* decode_info,
                        uint32_t                rd_val,
                        uint32_t*               result);

    ACI_Status exec_cx1_d(const ACICX1DecodeInfo* decode_info,
                        uint64_t                rfd_val,
                        uint64_t*               result);

    ACI_Status exec_cx2(const ACICX2DecodeInfo*  decode_info,
                        uint32_t                 rd_val,
                        uint32_t                 rn_val,
                        uint32_t*                result);

    ACI_Status exec_cx2_d(const ACICX2DecodeInfo* decode_info,
                          uint64_t                rfd_val,
                          uint64_t                rn_val,
                          uint64_t*               result);

    ACI_Status exec_cx3(const ACICX3DecodeInfo* decode_info,
                        uint32_t                rd_val,
                        uint32_t                rn_val,
                        uint32_t                rm_val,
                        uint32_t*               result);

    ACI_Status exec_cx3_d(const ACICX3DecodeInfo* decode_info,
                          uint64_t                rfd_val,
                          uint64_t                rn_val,
                          uint64_t                rm_val,
                          uint64_t*               result);

    ACI_Status exec_vcx1_s(const ACIVCX1DecodeInfo* decode_info,
                           uint32_t                 sd_val,
                           uint32_t*                result);

    ACI_Status exec_vcx1_d(const ACIVCX1DecodeInfo* decode_info,
                           uint64_t                 dd_val,
                           uint64_t*                result);

    ACI_Status exec_vcx1_beatwise(const ACIVCX1DecodeInfo* decode_info,
                                  uint32_t                 d_val,
                                  uint8_t                  beat,
                                  uint8_t                  elmt_mask,
                                  uint32_t*                result);

    ACI_Status exec_vcx2_s(const ACIVCX2DecodeInfo* decode_info,
                           uint32_t                 sd_val,
                           uint32_t                 sm_val,
                           uint32_t*                result);

    ACI_Status exec_vcx2_d(const ACIVCX2DecodeInfo* decode_info,
                           uint64_t                 dd_val,
                           uint64_t                 dm_val,
                           uint64_t*                result);

    ACI_Status exec_vcx2_beatwise(const ACIVCX2DecodeInfo* decode_info,
                                  uint32_t                 d_val,
                                  uint32_t                 m_val,
                                  uint8_t                  beat,
                                  uint8_t                  elmt_mask,
                                  uint32_t*                result);

    ACI_Status exec_vcx3_s(const ACIVCX3DecodeInfo* decode_info,
                           uint32_t                 sd_val,
                           uint32_t                 sn_val,
                           uint32_t                 sm_val,
                           uint32_t*                result);

    ACI_Status exec_vcx3_d(const ACIVCX3DecodeInfo* decode_info,
                           uint64_t                 dd_val,
                           uint64_t                 dn_val,
                           uint64_t                 dm_val,
                           uint64_t*                result);

    ACI_Status exec_vcx3_beatwise(const ACIVCX3DecodeInfo* decode_info,
                                  uint32_t                 d_val,
                                  uint32_t                 n_val,
                                  uint32_t                 m_val,
                                  uint8_t                  beat,
                                  uint8_t                  elmt_mask,
                                  uint32_t*                result);
};

#endif // ACI_CONSTANT_LIBRARY
