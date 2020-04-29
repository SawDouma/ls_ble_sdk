#ifndef REG_LSQSPI_TYPE_H_
#define REG_LSQSPI_TYPE_H_
#include <stdint.h>

typedef struct
{
    volatile uint32_t CFG;             // 0x00
    volatile uint32_t RDINS;        // 0x04
    volatile uint32_t WRINS;        // 0x08
    volatile uint32_t DLY;            // 0x0c
    volatile uint32_t RDCAP;        // 0x10
    volatile uint32_t SIZE;            // 0x14
    volatile uint32_t RESERVED0[3];
    volatile uint32_t REMAP_ADDR;    // 0x24
    volatile uint32_t MODE_BITS;    // 0x28
    volatile uint32_t CSTIM;        // 0x2c
    volatile uint32_t DACWR_BYTES;    // 0x30
    volatile uint32_t DACWR_STAT;    // 0x34
    volatile uint32_t RESERVED1[2];
    volatile uint32_t INT_STAT;        // 0x40
    volatile uint32_t INT_MASK;        // 0x44
    volatile uint32_t RESERVED2[2];    
    volatile uint32_t LWP;            // 0x50
    volatile uint32_t UWP;            // 0x54
    volatile uint32_t WP;            // 0x58
    volatile uint32_t RESERVED3[13];
    volatile uint32_t STIG_CMD;        // 0x90
    volatile uint32_t STIG_GO;        // 0x94
    volatile uint32_t STIG_ADDR;    // 0x98
    volatile uint32_t RESERVED4[1];
    volatile uint32_t STIG_RD[2];    // 0xa0 0xa4
    volatile uint32_t STIG_WR[2];    // 0xa8 0xac
}reg_lsqspi_t;

enum LSQSPI_REG_CFG_FIELD
{
    LSQSPI_ENABLE_MASK = 0x1,
    LSQSPI_ENABLE_POS = 0,
    LSQSPI_CPOL_MASK = 0x2,
    LSQSPI_CPOL_POS = 1,
    LSQSPI_CPHA_MASK = 0x4,
    LSQSPI_CPHA_POS = 2,
    LSQSPI_DAC_ENABLE_MASK = 0x80,
    LSQSPI_DAC_ENABLE_POS = 7,
    LSQSPI_WP_PIN_MASK = 0x4000,
    LSQSPI_WP_PIN_POS = 14,
    LSQSPI_REMAP_MASK = 0x10000,
    LSQSPI_REMAP_POS = 16,
    LSQSPI_BAUDRATE_MASK = 0x780000,
    LSQSPI_BAUDRATE_POS = 19,
    LSQSPI_IDLE_MASK = (int)0x80000000,
    LSQSPI_IDLE_POS = 31,
};

enum LSQSPI_REG_RDINS_FIELD
{
    LSQSPI_RD_OPCODE_MASK = 0xff,
    LSQSPI_RD_OPCODE_POS = 0,
    LSQSPI_RD_INSTRUCTION_TYPE_MASK = 0x100,
    LSQSPI_RD_INSTRUCTION_TYPE_POS = 8,
    LSQSPI_RD_ADDR_TRANS_TYPE_MASK = 0x1000,
    LSQSPI_RD_ADDR_TRANS_TYPE_POS = 12,
    LSQSPI_RD_DATA_TRANS_TYPE_MASK = 0x10000,
    LSQSPI_RD_DATA_TRANS_TYPE_POS = 16,
    LSQSPI_RD_MODE_BIT_EN_MASK = 0x100000,
    LSQSPI_RD_MODE_BIT_EN_POS = 20,
    LSQSPI_RD_NUM_DUMMY_MASK = 0x3000000,
    LSQSPI_RD_NUM_DUMMY_POS = 24,
};

enum LSQSPI_REG_WRINS_FIELD
{
    LSQSPI_WR_OPCODE_MASK = 0xff,
    LSQSPI_WR_OPCODE_POS = 0,
    LSQSPI_WR_ADDR_TRANS_TYPE_MASK = 0x1000,
    LSQSPI_WR_ADDR_TRANS_TYPE_POS = 12,
    LSQSPI_WR_DATA_TRANS_TYPE_MASK = 0x10000,
    LSQSPI_WR_DATA_TRANS_TYPE_POS = 16,
    LSQSPI_WR_NUM_DUMMY_MASK = 0x3000000,
    LSQSPI_WR_NUM_DUMMY_POS = 24,
};

enum LSQSPI_REG_DLY_FIELD
{
    LSQSPI_DLY_INIT_MASK = 0xff,
    LSQSPI_DLY_INIT_POS = 0,
    LSQSPI_DLY_AFTER_MASK = 0xff00,
    LSQSPI_DLY_AFTER_POS = 8,
    LSQSPI_DLY_NSS_MASK = 0xff0000,
    LSQSPI_DLY_NSS_POS = 16,
};

enum LSQSPI_REG_RDCAP_FIELD
{
    LSQSPI_DLY_RD_CAP_MASK = 0x1E,
    LSQSPI_DLY_RD_CAP_POS = 1,
    LSQSPI_SAMPLE_EDGE_MASK = 0x20,
    LSQSPI_SAMPLE_EDGE_POS = 5,
};

enum LSQSPI_REG_SIZE_FIELD
{
    LSQSPI_NUM_BYTES_PER_BLOCK_MASK = 0x1f0000,
    LSQSPI_NUM_BYTES_PER_BLOCK_POS = 16,
};

enum LSQSPI_REG_MODE_BITS_FIELD
{
    LSQSPI_MODE_BITS_MASK = 0xff,
    LSQSPI_MODE_BITS_POS = 0,
};

enum LSQSPI_REG_CSTIM_FIELD
{
    LSQSPI_CS_TIMEOUT_MASK = 0xff,
    LSQSPI_CS_TIMEOUT_POS = 0,
    LSQPSI_AUTO_CS_HOLD_MASK = 0x100,
    LSQSPI_AUTO_CS_HOLD_POS = 8,
};

enum LSQSPI_REG_DACWR_BYTES_FIELD
{
    LSQSPI_DACWR_BYTES_MASK = 0xfff,
    LSQSPI_DACWR_BYTES_POS = 0,
    LSQSPI_DACWR_BYTES_SET_MASK = 0x8000,
    LSQSPI_DACWR_BYTES_SET_POS = 15,
};

enum LSQSPI_REG_DACWR_STAT_FIELD
{
    LSQSPI_DAC_WIP_CLR_MASK = 0x1,
    LSQSPI_DAC_WIP_CLR_POS = 0,
    LSQSPI_DACWR_WIP_MASK = 0x2,
    LSQSPI_DACWR_WIP_POS = 1,
    LSQSPI_DACWR_PAGE_BK_MASK = 0x4,
    LSQSPI_DACWR_PAGE_BK_POS = 2,
};

enum LSQSPI_REG_INT_FIELD
{
    LSQSPI_INVALID_TRANS_MASK = 0x1,
    LSQSPI_INVALID_TRANS_POS = 0,
    LSQSPI_WR_PROT_ERR_MASK = 0x2,
    LSQSPI_WR_PROT_ERR_POS = 1,
    LSQSPI_WR_OVERFLOW_MASK = 0x4,
    LSQSPI_WR_OVERFLOW_POS = 2,
};

enum LSQSPI_REG_WP_FIELD
{
    LSQSPI_WP_INV_MASK = 0x1,
    LSQSPI_WP_INV_POS = 0,
    LSQSPI_WP_EN_MASK = 0x2,
    LSQSPI_WP_EN_POS = 1,
};

enum LSQSPI_REG_STIG_CMD_FIELD
{
    LSQSPI_OPCODE_EN_MASK = 0x1,
    LSQSPI_OPCODE_EN_POS = 0,
    LSQSPI_ADDR_EN_MASK = 0x2,
    LSQSPI_ADDR_EN_POS = 1,
    LSQSPI_MODE_EN_MASK = 0x4,
    LSQSPI_MODE_EN_POS = 2,
    LSQSPI_DUMMY_EN_MASK = 0x8,
    LSQSPI_DUMMY_EN_POS = 3,
    LSQSPI_RDATA_EN_MASK = 0x10,
    LSQSPI_RDATA_EN_POS = 4,
    LSQSPI_WDATA_EN_MASK = 0x20,
    LSQSPI_WDATA_EN_POS = 5,
    LSQSPI_OP_XFER_TYPE_MASK = 0x100,
    LSQSPI_OP_XFER_TYPE_POS = 8,
    LSQSPI_ADDR_XFER_TYPE_MASK = 0x200,
    LSQSPI_ADDR_XFER_TYPE_POS = 9,
    LSQSPI_DATA_XFER_TYPE_MASK = 0x400,
    LSQSPI_DATA_XFER_TYPE_POS = 10,
    LSQSPI_NUM_DUMMY_BYTES_MASK = 0xC000,
    LSQSPI_NUM_DUMMY_BYTES_POS = 14,
    LSQSPI_NUM_RDATA_BYTES_MASK = 0x70000,
    LSQSPI_NUM_RDATA_BYTES_POS = 16,
    LSQSPI_NUM_WDATA_BYTES_MASK = 0x700000,
    LSQSPI_NUM_WDATA_BYTES_POS = 20,
    LSQSPI_CMD_OPCODE_MASK = (int)0xff000000,
    LSQSPI_CMD_OPCODE_POS = 24,
};

enum LSQSPI_REG_STIG_GO_FIELD
{
    LSQSPI_STIG_GO_MASK = 0x1,
    LSQSPI_STIG_GO_POS = 0,
    LSQSPI_STIG_HOLD_CS_MASK = 0x10,
    LSQSPI_STIG_HOLD_CS_POS = 4,
};



#endif

