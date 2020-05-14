#ifndef SDK_DEFAULT_CONFIG_H_
#define SDK_DEFAULT_CONFIG_H_

#ifndef SDK_SW_TIMER_MAX
#define SDK_SW_TIMER_MAX 5
#endif

#ifndef SDK_DCDC_BYPASS
#define SDK_DCDC_BYPASS 0
#endif

#ifndef SDK_DEEP_SLEEP_ENABLE
#define SDK_DEEP_SLEEP_ENABLE 1
#endif

#ifndef SDK_BLE_STORAGE_PEER_MAX
#define SDK_BLE_STORAGE_PEER_MAX 3
#endif

#ifndef SDK_USER_TINYFS_NODE_MAX
#define SDK_USER_TINYFS_NODE_MAX 5
#endif

#ifndef SDK_USER_TASK_NUM
#define SDK_USER_TASK_NUM 0
#endif

#ifndef SDK_MAX_CONN_NUM
#define SDK_MAX_CONN_NUM 1
#endif

#ifndef SDK_MAX_PROFILE_NUM
#define SDK_MAX_PROFILE_NUM 1
#endif

#ifndef SDK_MAX_RAL_NUM
#define SDK_MAX_RAL_NUM 1
#endif

#define MHZ(x) ((x)*1000000)

#ifndef SDK_HCLK
#define SDK_HCLK MHZ(16)
#endif

#ifndef SDK_PCLK_DIV
#define SDK_PCLK_DIV 1
#endif

#ifndef FPGA
#define FPGA 0
#endif

#define SDK_PCLK (SDK_HCLK/SDK_PCLK_DIV)
#define SDK_MAX_ACT_NUM    (SDK_MAX_CONN_NUM + 1)
#define SDK_BUILTIN_TASK_NUM 1
#define SDK_MAX_USER_TASK_NUM (SDK_BUILTIN_TASK_NUM + SDK_USER_TASK_NUM)

#endif

