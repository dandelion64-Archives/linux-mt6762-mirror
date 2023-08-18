/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef __MT6765_PM_DOMAINS_H
#define __MT6765_PM_DOMAINS_H

#include "mtk-pm-domains.h"
#include <dt-bindings/power/mt6765-power.h>

/*
 * MT6765 power domain support
 */

static const struct scpsys_domain_data scpsys_domain_data_mt6765[] = {
	[MT6765_POWER_DOMAIN_MD1] = {
		.name = "md1",
		.sta_mask = BIT(0),
		.ctl_offs = 0x320,
		.pwr_sta_offs = 0x180,
		.pwr_sta2nd_offs = 0x184,
		.sram_pdn_bits = GENMASK(8, 8),
		.sram_pdn_ack_bits = 0,
		.bp_infracfg = {
			BUS_PROT_WR(MT6765_TOP_AXI_PROT_EN_MD1, MT8183_TOP_AXI_PROT_EN_SET,
				    MT8183_TOP_AXI_PROT_EN_CLR, MT8183_TOP_AXI_PROT_EN_STA1),
			BUS_PROT_WR(MT6765_TOP_AXI_PROT_EN_MD1_2ND, MT8183_TOP_AXI_PROT_EN_SET,
				    MT8183_TOP_AXI_PROT_EN_CLR, MT8183_TOP_AXI_PROT_EN_STA1),
			BUS_PROT_WR(MT6765_TOP_AXI_PROT_EN_1_MD1, MT8183_TOP_AXI_PROT_EN_1_SET,
				    MT8183_TOP_AXI_PROT_EN_1_CLR, MT8183_TOP_AXI_PROT_EN_STA1_1),
		},
	},
	[MT6765_POWER_DOMAIN_CONN] = {
		.name = "conn",
		.sta_mask = PWR_STATUS_CONN,
		.ctl_offs = 0x32c,
		.pwr_sta_offs = 0x180,
		.pwr_sta2nd_offs = 0x184,
		.sram_pdn_bits = 0,
		.sram_pdn_ack_bits = 0,
		.bp_infracfg = {
			BUS_PROT_WR(MT6765_TOP_AXI_PROT_EN_CONN, MT8183_TOP_AXI_PROT_EN_SET,
				    MT8183_TOP_AXI_PROT_EN_CLR, MT8183_TOP_AXI_PROT_EN_STA1),
			BUS_PROT_WR(MT6765_TOP_AXI_PROT_EN_1_CONN, MT8183_TOP_AXI_PROT_EN_1_SET,
				    MT8183_TOP_AXI_PROT_EN_1_CLR, MT8183_TOP_AXI_PROT_EN_STA1_1),
			BUS_PROT_WR(MT6765_TOP_AXI_PROT_EN_CONN_2ND, MT8183_TOP_AXI_PROT_EN_SET,
				    MT8183_TOP_AXI_PROT_EN_CLR, MT8183_TOP_AXI_PROT_EN_STA1),
		},
	},
	[MT6765_POWER_DOMAIN_DPY] = {
		.name = "dpy",
		.sta_mask = BIT(2),
		.ctl_offs = 0x31c,
		.pwr_sta_offs = 0x180,
		.pwr_sta2nd_offs = 0x184,
		.sram_pdn_bits = GENMASK(11, 8),
		.sram_pdn_ack_bits = GENMASK(15, 12),
		.bp_infracfg = {
			BUS_PROT_WR(MT6765_TOP_AXI_PROT_EN_DPY, MT8183_TOP_AXI_PROT_EN_SET,
				    MT8183_TOP_AXI_PROT_EN_CLR, MT8183_TOP_AXI_PROT_EN_STA1),
			BUS_PROT_WR(MT6765_TOP_AXI_PROT_EN_1_DPY, MT8183_TOP_AXI_PROT_EN_1_SET,
				    MT8183_TOP_AXI_PROT_EN_1_CLR, MT8183_TOP_AXI_PROT_EN_STA1_1),
			BUS_PROT_WR(MT6765_TOP_AXI_PROT_EN_DPY_2ND, MT8183_TOP_AXI_PROT_EN_SET,
				    MT8183_TOP_AXI_PROT_EN_CLR, MT8183_TOP_AXI_PROT_EN_STA1),
		},
	},
	[MT6765_POWER_DOMAIN_DISP] = {
		.name = "disp",
		.sta_mask = PWR_STATUS_DISP,
		.ctl_offs = 0x30c,
		.pwr_sta_offs = 0x180,
		.pwr_sta2nd_offs = 0x184,
		.sram_pdn_bits = GENMASK(8, 8),
		.sram_pdn_ack_bits = GENMASK(12, 12),
		.bp_infracfg = {
			BUS_PROT_WR(MT6765_TOP_AXI_PROT_EN_1_DISP, MT8183_TOP_AXI_PROT_EN_1_SET,
				    MT8183_TOP_AXI_PROT_EN_1_CLR, MT8183_TOP_AXI_PROT_EN_STA1_1),
			BUS_PROT_WR(MT6765_TOP_AXI_PROT_EN_1_DISP_2ND, MT8183_TOP_AXI_PROT_EN_1_SET,
				    MT8183_TOP_AXI_PROT_EN_1_CLR, MT8183_TOP_AXI_PROT_EN_STA1_1),
			BUS_PROT_WR(MT6765_TOP_AXI_PROT_EN_DISP, MT8183_TOP_AXI_PROT_EN_SET,
				    MT8183_TOP_AXI_PROT_EN_CLR, MT8183_TOP_AXI_PROT_EN_STA1),
			BUS_PROT_WR(MT6765_TOP_AXI_PROT_EN_DISP_2ND, MT8183_TOP_AXI_PROT_EN_SET,
				    MT8183_TOP_AXI_PROT_EN_CLR, MT8183_TOP_AXI_PROT_EN_STA1),
		},
	},
	[MT6765_POWER_DOMAIN_MFG] = {
		.name = "mfg",
		.sta_mask = PWR_STATUS_MFG,
		.ctl_offs = 0x338,
		.pwr_sta_offs = 0x180,
		.pwr_sta2nd_offs = 0x184,
		.sram_pdn_bits = GENMASK(8, 8),
		.sram_pdn_ack_bits = GENMASK(12, 12),
		.bp_infracfg = {
			BUS_PROT_WR(MT6765_TOP_AXI_PROT_EN_MFG, MT8183_TOP_AXI_PROT_EN_SET,
				    MT8183_TOP_AXI_PROT_EN_CLR, MT8183_TOP_AXI_PROT_EN_STA1),
			BUS_PROT_WR(MT6765_TOP_AXI_PROT_EN_MFG_2ND, MT8183_TOP_AXI_PROT_EN_SET,
				    MT8183_TOP_AXI_PROT_EN_CLR, MT8183_TOP_AXI_PROT_EN_STA1),
		},
	},
	[MT6765_POWER_DOMAIN_ISP] = {
		.name = "isp",
		.sta_mask = PWR_STATUS_ISP,
		.ctl_offs = 0x308,
		.pwr_sta_offs = 0x180,
		.pwr_sta2nd_offs = 0x184,
		.sram_pdn_bits = GENMASK(8, 8),
		.sram_pdn_ack_bits = GENMASK(12, 12),
		.bp_infracfg = {
			BUS_PROT_WR(MT6765_TOP_AXI_PROT_EN_1_ISP, MT8183_TOP_AXI_PROT_EN_1_SET,
				    MT8183_TOP_AXI_PROT_EN_1_CLR, MT8183_TOP_AXI_PROT_EN_STA1_1),
		},
		.bp_smi = {
			BUS_PROT_WR(MT8183_SMI_COMMON_SMI_CLAMP_ISP,
				    MT8183_SMI_COMMON_CLAMP_EN_SET,
				    MT8183_SMI_COMMON_CLAMP_EN_CLR,
				    MT8183_SMI_COMMON_CLAMP_EN),
		},
	},

	[MT6765_POWER_DOMAIN_IFR] = {
		.name = "isp",
		.sta_mask = BIT(6),
		.ctl_offs = 0x318,
		.pwr_sta_offs = 0x180,
		.pwr_sta2nd_offs = 0x184,
		.sram_pdn_bits = GENMASK(8, 8),
		.sram_pdn_ack_bits = GENMASK(12, 12),
	},
	[MT6765_POWER_DOMAIN_MFG_CORE0] = {
		.name = "mfg_core0",
		.sta_mask = BIT(7),
		.ctl_offs = 0x34c,
		.pwr_sta_offs = 0x180,
		.pwr_sta2nd_offs = 0x184,
		.sram_pdn_bits = GENMASK(8, 8),
		.sram_pdn_ack_bits = GENMASK(12, 12),
	},
	[MT6765_POWER_DOMAIN_MFG_ASYNC] = {
		.name = "mfg_async",
		.sta_mask = PWR_STATUS_MFG_ASYNC,
		.ctl_offs = 0x334,
		.pwr_sta_offs = 0x180,
		.pwr_sta2nd_offs = 0x184,
		.sram_pdn_bits = 0,
		.sram_pdn_ack_bits = 0,
	},
	[MT6765_POWER_DOMAIN_CAM] = {
		.name = "cam",
		.sta_mask = BIT(25),
		.ctl_offs = 0x344,
		.pwr_sta_offs = 0x180,
		.pwr_sta2nd_offs = 0x184,
		.sram_pdn_bits = GENMASK(9, 8),
		.sram_pdn_ack_bits = GENMASK(13, 12),
		.bp_infracfg = {
			BUS_PROT_WR(MT6765_TOP_AXI_PROT_EN_1_CAM, MT8183_TOP_AXI_PROT_EN_1_SET,
				    MT8183_TOP_AXI_PROT_EN_1_CLR, MT8183_TOP_AXI_PROT_EN_STA1_1),
			BUS_PROT_WR(MT6765_TOP_AXI_PROT_EN_CAM, MT8183_TOP_AXI_PROT_EN_SET,
				    MT8183_TOP_AXI_PROT_EN_CLR, MT8183_TOP_AXI_PROT_EN_STA1),
		},
		.bp_smi = {
			BUS_PROT_WR(MT6765_SMI_COMMON_SMI_CLAMP_CAM,
				    MT8183_SMI_COMMON_CLAMP_EN_SET,
				    MT8183_SMI_COMMON_CLAMP_EN_CLR,
				    MT8183_SMI_COMMON_CLAMP_EN),
		},
	},
	[MT6765_POWER_DOMAIN_VCODEC] = {
		.name = "vcodec",
		.sta_mask = BIT(26),
		.ctl_offs = 0x300,
		.pwr_sta_offs = 0x180,
		.pwr_sta2nd_offs = 0x184,
		.sram_pdn_bits = GENMASK(8, 8),
		.sram_pdn_ack_bits = GENMASK(12, 12),
    },
};

static const struct scpsys_soc_data mt6765_scpsys_data = {
	.domains_data = scpsys_domain_data_mt6765,
	.num_domains = ARRAY_SIZE(scpsys_domain_data_mt6765),
};

#endif /* __MT6765_PM_DOMAINS_H */
