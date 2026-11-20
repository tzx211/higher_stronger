/*!
 * \file    ACIConstant.cpp
 * \brief   A simple ACI library implementation example for CDE
 * \date    Copyright 2023 Arm Limited. All rights reserved.
 */

#include "ACIConstant.h"

/*
 * CONSTANT is generated as:
 * CONSTANT[31:24]: 0x55 for CX1, 0x66 for CX2, 0x99 for CX3.
 * 0xAA for VCX1, 0xCC for VCX2, 0xFF for VCX3
 * CONSTANT[23:16]: 0x00 for "normal", 0xAA for Accumulate version,
 * 0xDD for Dual version, 0xAD for AccumulateDual version
 * CONSTANT[15:12] = [11:8]: n is the copro
 * CONSTANT[7:0]: Index of the line in the table
 */

ACI_Status ACIConstant::exec_cx1(const ACICX1DecodeInfo* decode_info,
                                 uint32_t                rd_val,
                                 uint32_t*               result)
{
    const auto coproc_bits = decode_info->coproc << 8 | decode_info->coproc << 12;
    if (decode_info->accumulate)
    {
        *result = decode_info->imm ^ rd_val ^ (0x55AA0001 | coproc_bits);
    }
    else
    {
        *result = decode_info->imm ^ (0x55000000 | coproc_bits);
    }

    return ACI_STATUS_OK;
}

ACI_Status ACIConstant::exec_cx1_d(const ACICX1DecodeInfo* decode_info,
                                   uint64_t                rfd_val,
                                   uint64_t*               result)
{
    uint64_t val_hi = 0, val_lo = 0u;
    const auto coproc_bits = decode_info->coproc << 8 | decode_info->coproc << 12;

    if (decode_info->accumulate)
    {
        val_hi = decode_info->imm ^ (rfd_val >> 32) ^ (0x55AD0004 | coproc_bits);
        val_lo = decode_info->imm ^ (rfd_val & 0xFFFFFFFF) ^ (0x55AD0005 | coproc_bits);

    }
    else
    {
        val_hi = decode_info->imm ^ (0x55DD0002 | coproc_bits);
        val_lo = decode_info->imm ^ (0x55DD0003 | coproc_bits);
    }

    *result = (val_hi << 32 | val_lo);

    return ACI_STATUS_OK;
}

ACI_Status ACIConstant::exec_cx2(const ACICX2DecodeInfo*  decode_info,
                                 uint32_t                 rd_val,
                                 uint32_t                 rn_val,
                                 uint32_t*                result)
{
    const auto coproc_bits = decode_info->coproc << 8 | decode_info->coproc << 12;
    if (decode_info->accumulate)
    {
        *result = decode_info->imm ^ rd_val ^ rn_val ^ (0x66AA0007 | coproc_bits);
    }
    else
    {
        *result = decode_info->imm ^ rn_val ^ (0x66000006 | coproc_bits);
    }

    return ACI_STATUS_OK;

}

ACI_Status ACIConstant::exec_cx2_d(const ACICX2DecodeInfo* decode_info,
                                   uint64_t                rfd_val,
                                   uint64_t                rn_val,
                                   uint64_t*               result)
{
    uint64_t val_hi = 0, val_lo = 0u;
    const auto coproc_bits = decode_info->coproc << 8 | decode_info->coproc << 12;

    if (decode_info->accumulate)
    {
        val_hi = decode_info->imm ^ (rfd_val >> 32) ^ rn_val ^ (0x66AD000a | coproc_bits);
        val_lo = decode_info->imm ^ (rfd_val & 0xFFFFFFFF) ^ rn_val ^ (0x66AD000b | coproc_bits);

    }
    else
    {
        val_hi = decode_info->imm ^ rn_val ^ (0x66DD0008 | coproc_bits);
        val_lo = decode_info->imm ^ rn_val ^ (0x66DD0009 | coproc_bits);
    }

    *result = (val_hi << 32 | val_lo);

    return ACI_STATUS_OK;
}

ACI_Status ACIConstant::exec_cx3(const ACICX3DecodeInfo* decode_info,
                                 uint32_t                rd_val,
                                 uint32_t                rn_val,
                                 uint32_t                rm_val,
                                 uint32_t*               result)
{
    const auto coproc_bits = decode_info->coproc << 8 | decode_info->coproc << 12;
    if (decode_info->accumulate)
    {
        *result = decode_info->imm ^ rd_val ^ rm_val ^ rn_val ^ (0x99AA000d | coproc_bits);
    }
    else
    {
        *result = decode_info->imm ^ rm_val ^ rn_val ^ (0x9900000c | coproc_bits);
    }

    return ACI_STATUS_OK;
}

ACI_Status ACIConstant::exec_cx3_d(const ACICX3DecodeInfo* decode_info,
                                   uint64_t                rfd_val,
                                   uint64_t                rn_val,
                                   uint64_t                rm_val,
                                   uint64_t*               result)
{
    uint64_t val_hi = 0, val_lo = 0u;
    const auto coproc_bits = decode_info->coproc << 8 | decode_info->coproc << 12;

    if (decode_info->accumulate)
    {
        val_hi = decode_info->imm ^ (rfd_val >> 32) ^ rn_val ^ rm_val ^ (0x99AD0010 | coproc_bits);
        val_lo = decode_info->imm ^ (rfd_val & 0xFFFFFFFF) ^ rn_val ^ rm_val ^ (0x99AD0011 | coproc_bits);
    }
    else
    {
        val_hi = decode_info->imm ^ rn_val ^ rm_val ^ (0x99DD000E | coproc_bits);
        val_lo = decode_info->imm ^ rn_val ^ rm_val ^ (0x99DD000F | coproc_bits);
    }

    *result = (val_hi << 32 | val_lo);

    return ACI_STATUS_OK;
}

ACI_Status ACIConstant::exec_vcx1_s(const ACIVCX1DecodeInfo* decode_info,
                                    uint32_t                 sd_val,
                                    uint32_t*                result)
{
    const auto coproc_bits = decode_info->coproc << 8 | decode_info->coproc << 12;

    if (decode_info->accumulate)
    {
        *result = decode_info->imm ^ sd_val ^ (0xAAAA0001 | coproc_bits);
    }
    else
    {
        *result = decode_info->imm ^ (0xAA000000 | coproc_bits);
    }

    return ACI_STATUS_OK;
}

ACI_Status ACIConstant::exec_vcx1_d(const ACIVCX1DecodeInfo* decode_info,
                                    uint64_t                 dd_val,
                                    uint64_t*                result)
{
    return ACI_STATUS_NOT_IMPLEMENTED;
}

ACI_Status ACIConstant::exec_vcx1_beatwise(const ACIVCX1DecodeInfo* decode_info,
                                           uint32_t                 d_val,
                                           uint8_t                  beat,
                                           uint8_t                  elmt_mask,
                                           uint32_t*                result)
{
    return ACI_STATUS_NOT_IMPLEMENTED;
}

ACI_Status ACIConstant::exec_vcx2_s(const ACIVCX2DecodeInfo* decode_info,
                                    uint32_t                 sd_val,
                                    uint32_t                 sm_val,
                                    uint32_t*                result)
{
    const auto coproc_bits = decode_info->coproc << 8 | decode_info->coproc << 12;

    if (decode_info->accumulate)
    {
        *result = decode_info->imm ^ sd_val ^ sm_val ^ (0xCCAA0003 | coproc_bits);
    }
    else
    {
        *result = decode_info->imm ^ sm_val ^ (0xCC000002 | coproc_bits);
    }

    return ACI_STATUS_OK;
}

ACI_Status ACIConstant::exec_vcx2_d(const ACIVCX2DecodeInfo* decode_info,
                                    uint64_t                 dd_val,
                                    uint64_t                 dm_val,
                                    uint64_t*                result)
{
    return ACI_STATUS_NOT_IMPLEMENTED;
}

ACI_Status ACIConstant::exec_vcx2_beatwise(const ACIVCX2DecodeInfo* decode_info,
                                           uint32_t                 d_val,
                                           uint32_t                 m_val,
                                           uint8_t                  beat,
                                           uint8_t                  elmt_mask,
                                           uint32_t*                result)
{
    return ACI_STATUS_NOT_IMPLEMENTED;
}

ACI_Status ACIConstant::exec_vcx3_s(const ACIVCX3DecodeInfo* decode_info,
                                    uint32_t                 sd_val,
                                    uint32_t                 sn_val,
                                    uint32_t                 sm_val,
                                    uint32_t*                result)
{
    const auto coproc_bits = decode_info->coproc << 8 | decode_info->coproc << 12;

    if (decode_info->accumulate)
    {
        *result = decode_info->imm ^ sd_val ^ sn_val ^ sm_val ^ (0xFFAA0005 | coproc_bits);
    }
    else
    {
        *result = decode_info->imm ^ sn_val ^ sm_val ^ (0xFF000004 | coproc_bits);
    }

    return ACI_STATUS_OK;
}

ACI_Status ACIConstant::exec_vcx3_d(const ACIVCX3DecodeInfo* decode_info,
                                    uint64_t                 dd_val,
                                    uint64_t                 dn_val,
                                    uint64_t                 dm_val,
                                    uint64_t*                result)
{
    return ACI_STATUS_NOT_IMPLEMENTED;
}

ACI_Status ACIConstant::exec_vcx3_beatwise(const ACIVCX3DecodeInfo* decode_info,
                                           uint32_t                 d_val,
                                           uint32_t                 n_val,
                                           uint32_t                 m_val,
                                           uint8_t                  beat,
                                           uint8_t                  elmt_mask,
                                           uint32_t*                result)
{
    return ACI_STATUS_NOT_IMPLEMENTED;
}
