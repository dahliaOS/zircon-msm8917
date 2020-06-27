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
        .length = 0x4­0­000000,  // 1 gig (for now)
    },
    {
        .type = ZBI_MEM_RANGE_PERIPHERAL,
        .paddr = 0x00000000,
        .length = 0x40000000,
    },
    {
        .type = ZBI_MEM_RANGE_RESERVED,
        .paddr = 0x85800000,
        .length = 0xEF00000,
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
