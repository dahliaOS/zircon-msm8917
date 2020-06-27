// Copyright 2019 The Fuchsia Authors
//
// Use of this source code is governed by a MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT

#define HAS_DEVICE_TREE 1

static const zbi_cpu_config_t cpu_config = {
    .cluster_count = 1,
    .clusters =
        {
            {
                .cpu_count = 1,
            }, 
        },
};

static const zbi_mem_range_t mem_config[] = {
    {
        .type = ZBI_MEM_RANGE_RAM,
        .paddr = 0x80000000,
        .length = 0x40000000,  // 1 gig (for now)
    },
    {
        .type = ZBI_MEM_RANGE_PERIPHERAL,
        .paddr = 0x00000000,
        .length = 0x40000000,
    },
    {
        // sec_debug_region@0
        .type = ZBI_MEM_RANGE_RESERVED,
        .paddr = 0x85000000,
        .length = 0x800000,
    },
    {
        // klog_region@0
        .type = ZBI_MEM_RANGE_RESERVED,
        .paddr = 0x851ff000,
        .length = 0x201000,
    },
    {
        // ss_plog@85C00000
        .type = ZBI_MEM_RANGE_RESERVED,
        .paddr = 0x85c00000,
        .length = 0x400000,
    },
    {
        // other_ext_region@0
        .type = ZBI_MEM_RANGE_RESERVED,
        .paddr = 0x86100000,
        .length = 0x700000,
    },
    {
        // modem_region@0
        .type = ZBI_MEM_RANGE_RESERVED,
        .paddr = 0x86800000,
        .length = 0x5a00000,
    },
    {
        // adsp_fw_region@0
        .type = ZBI_MEM_RANGE_RESERVED,
        .paddr = 0x8c200000,
        .length = 0x1800000,
    },
    {
        // wcnss_fw_region@0
        .type = ZBI_MEM_RANGE_RESERVED,
        .paddr = 0x8da00000,
        .length = 0x700000,
    },
    {
        // lk_region@0
        .type = ZBI_MEM_RANGE_RESERVED,
        .paddr = 0x8f600000,
        .length = 0x300000,
    },
    {
        // venus_region@0
        .type = ZBI_MEM_RANGE_RESERVED,
        .paddr = 0x8fc00000,
        .length = 0x400000,
    },
    {
        // modem_shared_mem_region@0x93000000
        .type = ZBI_MEM_RANGE_RESERVED,
        .paddr = 0x93000000,
        .length = 0x6000000,
    },
    {
        // tzapp_region@0
        .type = ZBI_MEM_RANGE_RESERVED,
        .paddr = 0x95000000,
        .length = 0x2800000,
    },
};

static const dcfg_arm_psci_driver_t psci_driver = {
    .use_hvc = false,
};

/*
static const dcfg_msm_power_driver_t power_driver = {
    .soc_imem_phys = 0x8600000,
    .soc_imem_offset = 0x65c,
};
*/

static const zbi_platform_id_t platform_id = {
    .vid = PDEV_VID_QUALCOMM,
    .pid = PDEV_PID_QUALCOMM_MSM8917,
    .board_name = "msm8917",
};

static void append_board_boot_item(zbi_header_t* bootdata) {
  // add CPU configuration
  append_boot_item(bootdata, ZBI_TYPE_CPU_CONFIG, 0, &cpu_config,
                   sizeof(zbi_cpu_config_t) + sizeof(zbi_cpu_cluster_t) * cpu_config.cluster_count);

  // add memory configuration
  append_boot_item(bootdata, ZBI_TYPE_MEM_CONFIG, 0, &mem_config,
                   sizeof(zbi_mem_range_t) * countof(mem_config));

  // add platform ID
  append_boot_item(bootdata, ZBI_TYPE_PLATFORM_ID, 0, &platform_id, sizeof(platform_id));
}
