#include "platform.h"
#include "ARMCM3.h"
#include "reg_sysc_awo.h"
#include "field_manipulate.h"
#include "io_config.h"
void modem_rf_init(void);

__attribute__((weak)) void SystemInit(){}

static void irq_priority()
{
    __NVIC_SetPriority(SVCall_IRQn,1);
    __NVIC_SetPriority(PendSV_IRQn,7);

    __NVIC_SetPriority(RTC1_IRQn,7);
    __NVIC_SetPriority(IWDT_IRQn,7);
    __NVIC_SetPriority(RTC2_IRQn,7);
    __NVIC_SetPriority(EXT_IRQn,7);
    __NVIC_SetPriority(LVD33_IRQn,7);
    __NVIC_SetPriority(MAC_LP_IRQn,0);
    __NVIC_SetPriority(MAC1_IRQn,0);
    __NVIC_SetPriority(DMA_IRQn,7);
    __NVIC_SetPriority(QSPI_IRQn,7);
    __NVIC_SetPriority(SWINT1_IRQn,1);
    __NVIC_SetPriority(CACHE_IRQn,7);
    __NVIC_SetPriority(I8080_IRQn,7);
    __NVIC_SetPriority(TRNG_IRQn,7);
    __NVIC_SetPriority(ECC_IRQn,7);
    __NVIC_SetPriority(CRYPT_IRQn,7);
    __NVIC_SetPriority(BSTIM1_IRQn,7);
    __NVIC_SetPriority(GPTIMA1_IRQn,7);
    __NVIC_SetPriority(GPTIMB1_IRQn,7);
    __NVIC_SetPriority(GPTIMC1_IRQn,7);
    __NVIC_SetPriority(ADTIM1_IRQn,7);
    __NVIC_SetPriority(I2C1_IRQn,7);
    __NVIC_SetPriority(I2C2_IRQn,7);
    __NVIC_SetPriority(I2C3_IRQn,7);
    __NVIC_SetPriority(UART1_IRQn,7);
    __NVIC_SetPriority(UART2_IRQn,7);
    __NVIC_SetPriority(UART3_IRQn,7);
    __NVIC_SetPriority(SPI1_IRQn,7);
    __NVIC_SetPriority(SPI2_IRQn,7);
    __NVIC_SetPriority(PDM_IRQn,7);
    __NVIC_SetPriority(GPIO_IRQn,7);
    __NVIC_SetPriority(WWDT_IRQn,7);
    __NVIC_SetPriority(SWINT2_IRQn,1);
    __NVIC_SetPriority(LCD_IRQn,7);
    __NVIC_SetPriority(ADC_IRQn,7);
    __NVIC_SetPriority(DAC_IRQn,7);
    __NVIC_SetPriority(MAC2_IRQn,2);
    __NVIC_SetPriority(ADC24_IRQn,7);

}

void iob_output_enable(uint8_t i)
{
    SYSC_AWO->IO[1].OE_DOT |= 1<<(i+16);
}

void sys_init_itf()
{
    *(volatile uint32_t *)0x50089020 = 3<<8 | 4 <<0; //uart pin_sel
    *(volatile uint32_t *)0x5000d044 = 3<<16; // uart pin_sel
    SYSC_AWO->PIN_SEL3 = FIELD_BUILD(SYSC_AWO_MAC_DBG_EN, 0xFFFF);
    SCB->CCR |= SCB_CCR_UNALIGN_TRP_Msk;
    irq_priority();
    __NVIC_EnableIRQ(MAC1_IRQn);
    __NVIC_EnableIRQ(SWINT1_IRQn);
    __NVIC_EnableIRQ(SWINT2_IRQn);
    modem_rf_init();
    io_cfg_output(PB02);
    io_cfg_output(PB03);
    io_cfg_output(PB04);
    iob_output_enable(2);
    iob_output_enable(3);
    iob_output_enable(4);
}

void ble_pkt_irq_mask()
{
    __NVIC_DisableIRQ(MAC1_IRQn);
}

void ble_pkt_irq_unmask()
{
    __NVIC_EnableIRQ(MAC1_IRQn);
}

void swint2_set()
{
    __NVIC_SetPendingIRQ(SWINT2_IRQn);
}

void iob_output_set(uint8_t i)
{
    SYSC_AWO->IO[1].OE_DOT |= 1<<i;
}

void iob_output_clr(uint8_t i)
{
    SYSC_AWO->IO[1].OE_DOT &= ~(1<<i);
}
