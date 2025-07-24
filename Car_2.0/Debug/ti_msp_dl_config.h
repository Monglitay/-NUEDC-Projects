/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X
#define CONFIG_MSPM0G3507

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)



#define CPUCLK_FREQ                                                     80000000



/* Defines for BEEZ */
#define BEEZ_INST                                                          TIMA0
#define BEEZ_INST_IRQHandler                                    TIMA0_IRQHandler
#define BEEZ_INST_INT_IRQN                                      (TIMA0_INT_IRQn)
#define BEEZ_INST_CLK_FREQ                                              10000000
/* GPIO defines for channel 2 */
#define GPIO_BEEZ_C2_PORT                                                  GPIOB
#define GPIO_BEEZ_C2_PIN                                          DL_GPIO_PIN_20
#define GPIO_BEEZ_C2_IOMUX                                       (IOMUX_PINCM48)
#define GPIO_BEEZ_C2_IOMUX_FUNC                      IOMUX_PINCM48_PF_TIMA0_CCP2
#define GPIO_BEEZ_C2_IDX                                     DL_TIMER_CC_2_INDEX

/* Defines for AIN */
#define AIN_INST                                                           TIMG6
#define AIN_INST_IRQHandler                                     TIMG6_IRQHandler
#define AIN_INST_INT_IRQN                                       (TIMG6_INT_IRQn)
#define AIN_INST_CLK_FREQ                                               40000000
/* GPIO defines for channel 0 */
#define GPIO_AIN_C0_PORT                                                   GPIOA
#define GPIO_AIN_C0_PIN                                           DL_GPIO_PIN_29
#define GPIO_AIN_C0_IOMUX                                         (IOMUX_PINCM4)
#define GPIO_AIN_C0_IOMUX_FUNC                        IOMUX_PINCM4_PF_TIMG6_CCP0
#define GPIO_AIN_C0_IDX                                      DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_AIN_C1_PORT                                                   GPIOB
#define GPIO_AIN_C1_PIN                                           DL_GPIO_PIN_27
#define GPIO_AIN_C1_IOMUX                                        (IOMUX_PINCM58)
#define GPIO_AIN_C1_IOMUX_FUNC                       IOMUX_PINCM58_PF_TIMG6_CCP1
#define GPIO_AIN_C1_IDX                                      DL_TIMER_CC_1_INDEX

/* Defines for BIN */
#define BIN_INST                                                           TIMG8
#define BIN_INST_IRQHandler                                     TIMG8_IRQHandler
#define BIN_INST_INT_IRQN                                       (TIMG8_INT_IRQn)
#define BIN_INST_CLK_FREQ                                               40000000
/* GPIO defines for channel 0 */
#define GPIO_BIN_C0_PORT                                                   GPIOA
#define GPIO_BIN_C0_PIN                                            DL_GPIO_PIN_7
#define GPIO_BIN_C0_IOMUX                                        (IOMUX_PINCM14)
#define GPIO_BIN_C0_IOMUX_FUNC                       IOMUX_PINCM14_PF_TIMG8_CCP0
#define GPIO_BIN_C0_IDX                                      DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_BIN_C1_PORT                                                   GPIOB
#define GPIO_BIN_C1_PIN                                           DL_GPIO_PIN_11
#define GPIO_BIN_C1_IOMUX                                        (IOMUX_PINCM28)
#define GPIO_BIN_C1_IOMUX_FUNC                       IOMUX_PINCM28_PF_TIMG8_CCP1
#define GPIO_BIN_C1_IDX                                      DL_TIMER_CC_1_INDEX

/* Defines for Servo_1 */
#define Servo_1_INST                                                       TIMA1
#define Servo_1_INST_IRQHandler                                 TIMA1_IRQHandler
#define Servo_1_INST_INT_IRQN                                   (TIMA1_INT_IRQn)
#define Servo_1_INST_CLK_FREQ                                              50000
/* GPIO defines for channel 0 */
#define GPIO_Servo_1_C0_PORT                                               GPIOB
#define GPIO_Servo_1_C0_PIN                                        DL_GPIO_PIN_0
#define GPIO_Servo_1_C0_IOMUX                                    (IOMUX_PINCM12)
#define GPIO_Servo_1_C0_IOMUX_FUNC                   IOMUX_PINCM12_PF_TIMA1_CCP0
#define GPIO_Servo_1_C0_IDX                                  DL_TIMER_CC_0_INDEX



/* Defines for TIMER_Encoder_Update */
#define TIMER_Encoder_Update_INST                                        (TIMG7)
#define TIMER_Encoder_Update_INST_IRQHandler                        TIMG7_IRQHandler
#define TIMER_Encoder_Update_INST_INT_IRQN                        (TIMG7_INT_IRQn)
#define TIMER_Encoder_Update_INST_LOAD_VALUE                                (15999U)
/* Defines for TIMER_Control */
#define TIMER_Control_INST                                               (TIMG0)
#define TIMER_Control_INST_IRQHandler                           TIMG0_IRQHandler
#define TIMER_Control_INST_INT_IRQN                             (TIMG0_INT_IRQn)
#define TIMER_Control_INST_LOAD_VALUE                                   (19999U)



/* Defines for BLE05 */
#define BLE05_INST                                                         UART1
#define BLE05_INST_FREQUENCY                                            40000000
#define BLE05_INST_IRQHandler                                   UART1_IRQHandler
#define BLE05_INST_INT_IRQN                                       UART1_INT_IRQn
#define GPIO_BLE05_RX_PORT                                                 GPIOB
#define GPIO_BLE05_TX_PORT                                                 GPIOB
#define GPIO_BLE05_RX_PIN                                          DL_GPIO_PIN_5
#define GPIO_BLE05_TX_PIN                                          DL_GPIO_PIN_4
#define GPIO_BLE05_IOMUX_RX                                      (IOMUX_PINCM18)
#define GPIO_BLE05_IOMUX_TX                                      (IOMUX_PINCM17)
#define GPIO_BLE05_IOMUX_RX_FUNC                       IOMUX_PINCM18_PF_UART1_RX
#define GPIO_BLE05_IOMUX_TX_FUNC                       IOMUX_PINCM17_PF_UART1_TX
#define BLE05_BAUD_RATE                                                 (115200)
#define BLE05_IBRD_40_MHZ_115200_BAUD                                       (21)
#define BLE05_FBRD_40_MHZ_115200_BAUD                                       (45)
/* Defines for OPENMV */
#define OPENMV_INST                                                        UART3
#define OPENMV_INST_FREQUENCY                                           80000000
#define OPENMV_INST_IRQHandler                                  UART3_IRQHandler
#define OPENMV_INST_INT_IRQN                                      UART3_INT_IRQn
#define GPIO_OPENMV_RX_PORT                                                GPIOB
#define GPIO_OPENMV_TX_PORT                                                GPIOB
#define GPIO_OPENMV_RX_PIN                                        DL_GPIO_PIN_13
#define GPIO_OPENMV_TX_PIN                                        DL_GPIO_PIN_12
#define GPIO_OPENMV_IOMUX_RX                                     (IOMUX_PINCM30)
#define GPIO_OPENMV_IOMUX_TX                                     (IOMUX_PINCM29)
#define GPIO_OPENMV_IOMUX_RX_FUNC                      IOMUX_PINCM30_PF_UART3_RX
#define GPIO_OPENMV_IOMUX_TX_FUNC                      IOMUX_PINCM29_PF_UART3_TX
#define OPENMV_BAUD_RATE                                                (115200)
#define OPENMV_IBRD_80_MHZ_115200_BAUD                                      (43)
#define OPENMV_FBRD_80_MHZ_115200_BAUD                                      (26)
/* Defines for CKP */
#define CKP_INST                                                           UART0
#define CKP_INST_FREQUENCY                                              40000000
#define CKP_INST_IRQHandler                                     UART0_IRQHandler
#define CKP_INST_INT_IRQN                                         UART0_INT_IRQn
#define GPIO_CKP_RX_PORT                                                   GPIOA
#define GPIO_CKP_TX_PORT                                                   GPIOA
#define GPIO_CKP_RX_PIN                                           DL_GPIO_PIN_31
#define GPIO_CKP_TX_PIN                                           DL_GPIO_PIN_28
#define GPIO_CKP_IOMUX_RX                                         (IOMUX_PINCM6)
#define GPIO_CKP_IOMUX_TX                                         (IOMUX_PINCM3)
#define GPIO_CKP_IOMUX_RX_FUNC                          IOMUX_PINCM6_PF_UART0_RX
#define GPIO_CKP_IOMUX_TX_FUNC                          IOMUX_PINCM3_PF_UART0_TX
#define CKP_BAUD_RATE                                                     (9600)
#define CKP_IBRD_40_MHZ_9600_BAUD                                          (260)
#define CKP_FBRD_40_MHZ_9600_BAUD                                           (27)




/* Defines for W25Q128 */
#define W25Q128_INST                                                       SPI1
#define W25Q128_INST_IRQHandler                                 SPI1_IRQHandler
#define W25Q128_INST_INT_IRQN                                     SPI1_INT_IRQn
#define GPIO_W25Q128_PICO_PORT                                            GPIOB
#define GPIO_W25Q128_PICO_PIN                                     DL_GPIO_PIN_8
#define GPIO_W25Q128_IOMUX_PICO                                 (IOMUX_PINCM25)
#define GPIO_W25Q128_IOMUX_PICO_FUNC                 IOMUX_PINCM25_PF_SPI1_PICO
#define GPIO_W25Q128_POCI_PORT                                            GPIOB
#define GPIO_W25Q128_POCI_PIN                                     DL_GPIO_PIN_7
#define GPIO_W25Q128_IOMUX_POCI                                 (IOMUX_PINCM24)
#define GPIO_W25Q128_IOMUX_POCI_FUNC                 IOMUX_PINCM24_PF_SPI1_POCI
/* GPIO configuration for W25Q128 */
#define GPIO_W25Q128_SCLK_PORT                                            GPIOB
#define GPIO_W25Q128_SCLK_PIN                                     DL_GPIO_PIN_9
#define GPIO_W25Q128_IOMUX_SCLK                                 (IOMUX_PINCM26)
#define GPIO_W25Q128_IOMUX_SCLK_FUNC                 IOMUX_PINCM26_PF_SPI1_SCLK



/* Defines for ADC_VOLTAGE */
#define ADC_VOLTAGE_INST                                                    ADC0
#define ADC_VOLTAGE_INST_IRQHandler                              ADC0_IRQHandler
#define ADC_VOLTAGE_INST_INT_IRQN                                (ADC0_INT_IRQn)
#define ADC_VOLTAGE_ADCMEM_ADC_CH4                            DL_ADC12_MEM_IDX_0
#define ADC_VOLTAGE_ADCMEM_ADC_CH4_REF           DL_ADC12_REFERENCE_VOLTAGE_VDDA
#define ADC_VOLTAGE_ADCMEM_ADC_CH4_REF_VOLTAGE_V                                     3.3
#define GPIO_ADC_VOLTAGE_C4_PORT                                           GPIOB
#define GPIO_ADC_VOLTAGE_C4_PIN                                   DL_GPIO_PIN_25



/* Port definition for Pin Group BSL */
#define BSL_PORT                                                         (GPIOA)

/* Defines for PIN_18: GPIOA.18 with pinCMx 40 on package pin 11 */
#define BSL_PIN_18_PIN                                          (DL_GPIO_PIN_18)
#define BSL_PIN_18_IOMUX                                         (IOMUX_PINCM40)
/* Port definition for Pin Group W25Q128_CS */
#define W25Q128_CS_PORT                                                  (GPIOB)

/* Defines for PIN: GPIOB.6 with pinCMx 23 on package pin 58 */
#define W25Q128_CS_PIN_PIN                                       (DL_GPIO_PIN_6)
#define W25Q128_CS_PIN_IOMUX                                     (IOMUX_PINCM23)
/* Defines for K1: GPIOB.15 with pinCMx 32 on package pin 3 */
#define BUTTONS_K1_PORT                                                  (GPIOB)
#define BUTTONS_K1_PIN                                          (DL_GPIO_PIN_15)
#define BUTTONS_K1_IOMUX                                         (IOMUX_PINCM32)
/* Defines for K2: GPIOA.9 with pinCMx 20 on package pin 55 */
#define BUTTONS_K2_PORT                                                  (GPIOA)
#define BUTTONS_K2_PIN                                           (DL_GPIO_PIN_9)
#define BUTTONS_K2_IOMUX                                         (IOMUX_PINCM20)
/* Defines for K3: GPIOA.8 with pinCMx 19 on package pin 54 */
#define BUTTONS_K3_PORT                                                  (GPIOA)
#define BUTTONS_K3_PIN                                           (DL_GPIO_PIN_8)
#define BUTTONS_K3_IOMUX                                         (IOMUX_PINCM19)
/* Defines for R_A: GPIOA.12 with pinCMx 34 on package pin 5 */
#define Encoder_R_A_PORT                                                 (GPIOA)
// pins affected by this interrupt request:["R_A","R_B"]
#define Encoder_GPIOA_INT_IRQN                                  (GPIOA_INT_IRQn)
#define Encoder_GPIOA_INT_IIDX                  (DL_INTERRUPT_GROUP1_IIDX_GPIOA)
#define Encoder_R_A_IIDX                                    (DL_GPIO_IIDX_DIO12)
#define Encoder_R_A_PIN                                         (DL_GPIO_PIN_12)
#define Encoder_R_A_IOMUX                                        (IOMUX_PINCM34)
/* Defines for R_B: GPIOA.13 with pinCMx 35 on package pin 6 */
#define Encoder_R_B_PORT                                                 (GPIOA)
#define Encoder_R_B_IIDX                                    (DL_GPIO_IIDX_DIO13)
#define Encoder_R_B_PIN                                         (DL_GPIO_PIN_13)
#define Encoder_R_B_IOMUX                                        (IOMUX_PINCM35)
/* Defines for L_A: GPIOB.2 with pinCMx 15 on package pin 50 */
#define Encoder_L_A_PORT                                                 (GPIOB)
// pins affected by this interrupt request:["L_A","L_B"]
#define Encoder_GPIOB_INT_IRQN                                  (GPIOB_INT_IRQn)
#define Encoder_GPIOB_INT_IIDX                  (DL_INTERRUPT_GROUP1_IIDX_GPIOB)
#define Encoder_L_A_IIDX                                     (DL_GPIO_IIDX_DIO2)
#define Encoder_L_A_PIN                                          (DL_GPIO_PIN_2)
#define Encoder_L_A_IOMUX                                        (IOMUX_PINCM15)
/* Defines for L_B: GPIOB.3 with pinCMx 16 on package pin 51 */
#define Encoder_L_B_PORT                                                 (GPIOB)
#define Encoder_L_B_IIDX                                     (DL_GPIO_IIDX_DIO3)
#define Encoder_L_B_PIN                                          (DL_GPIO_PIN_3)
#define Encoder_L_B_IOMUX                                        (IOMUX_PINCM16)
/* Port definition for Pin Group IIC_Software */
#define IIC_Software_PORT                                                (GPIOA)

/* Defines for SCL: GPIOA.1 with pinCMx 2 on package pin 34 */
#define IIC_Software_SCL_PIN                                     (DL_GPIO_PIN_1)
#define IIC_Software_SCL_IOMUX                                    (IOMUX_PINCM2)
/* Defines for SDA: GPIOA.0 with pinCMx 1 on package pin 33 */
#define IIC_Software_SDA_PIN                                     (DL_GPIO_PIN_0)
#define IIC_Software_SDA_IOMUX                                    (IOMUX_PINCM1)
#define GPIOA_EVENT_PUBLISHER_0_CHANNEL                                      (1)
#define GPIOB_EVENT_PUBLISHER_0_CHANNEL                                      (2)



/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_BEEZ_init(void);
void SYSCFG_DL_AIN_init(void);
void SYSCFG_DL_BIN_init(void);
void SYSCFG_DL_Servo_1_init(void);
void SYSCFG_DL_TIMER_Encoder_Update_init(void);
void SYSCFG_DL_TIMER_Control_init(void);
void SYSCFG_DL_BLE05_init(void);
void SYSCFG_DL_OPENMV_init(void);
void SYSCFG_DL_CKP_init(void);
void SYSCFG_DL_W25Q128_init(void);
void SYSCFG_DL_ADC_VOLTAGE_init(void);

void SYSCFG_DL_SYSTICK_init(void);

bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
