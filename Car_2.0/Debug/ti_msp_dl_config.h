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




/* Defines for JY61P */
#define JY61P_INST                                                          I2C0
#define JY61P_INST_IRQHandler                                    I2C0_IRQHandler
#define JY61P_INST_INT_IRQN                                        I2C0_INT_IRQn
#define JY61P_BUS_SPEED_HZ                                                100000
#define GPIO_JY61P_SDA_PORT                                                GPIOA
#define GPIO_JY61P_SDA_PIN                                         DL_GPIO_PIN_0
#define GPIO_JY61P_IOMUX_SDA                                      (IOMUX_PINCM1)
#define GPIO_JY61P_IOMUX_SDA_FUNC                       IOMUX_PINCM1_PF_I2C0_SDA
#define GPIO_JY61P_SCL_PORT                                                GPIOA
#define GPIO_JY61P_SCL_PIN                                         DL_GPIO_PIN_1
#define GPIO_JY61P_IOMUX_SCL                                      (IOMUX_PINCM2)
#define GPIO_JY61P_IOMUX_SCL_FUNC                       IOMUX_PINCM2_PF_I2C0_SCL


/* Defines for BLE05 */
#define BLE05_INST                                                         UART1
#define BLE05_INST_FREQUENCY                                  13333333.333333334
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
#define BLE05_IBRD_13_MHZ_115200_BAUD                                        (7)
#define BLE05_FBRD_13_MHZ_115200_BAUD                                       (15)
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





/* Port definition for Pin Group BSL */
#define BSL_PORT                                                         (GPIOA)

/* Defines for PIN_18: GPIOA.18 with pinCMx 40 on package pin 11 */
#define BSL_PIN_18_PIN                                          (DL_GPIO_PIN_18)
#define BSL_PIN_18_IOMUX                                         (IOMUX_PINCM40)
/* Port definition for Pin Group test */
#define test_PORT                                                        (GPIOB)

/* Defines for PIN_0: GPIOB.20 with pinCMx 48 on package pin 19 */
#define test_PIN_0_PIN                                          (DL_GPIO_PIN_20)
#define test_PIN_0_IOMUX                                         (IOMUX_PINCM48)
/* Port definition for Pin Group I2C */
#define I2C_PORT                                                         (GPIOA)

/* Defines for SDA: GPIOA.28 with pinCMx 3 on package pin 35 */
#define I2C_SDA_PIN                                             (DL_GPIO_PIN_28)
#define I2C_SDA_IOMUX                                             (IOMUX_PINCM3)
/* Defines for SCL: GPIOA.31 with pinCMx 6 on package pin 39 */
#define I2C_SCL_PIN                                             (DL_GPIO_PIN_31)
#define I2C_SCL_IOMUX                                             (IOMUX_PINCM6)



/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_JY61P_init(void);
void SYSCFG_DL_BLE05_init(void);
void SYSCFG_DL_OPENMV_init(void);

void SYSCFG_DL_SYSTICK_init(void);

bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
