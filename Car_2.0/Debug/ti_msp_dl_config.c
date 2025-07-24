/*
 * Copyright (c) 2023, Texas Instruments Incorporated
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
 *  ============ ti_msp_dl_config.c =============
 *  Configured MSPM0 DriverLib module definitions
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */

#include "ti_msp_dl_config.h"

DL_TimerA_backupConfig gBEEZBackup;
DL_TimerG_backupConfig gAINBackup;
DL_TimerA_backupConfig gServo_1Backup;
DL_TimerG_backupConfig gTIMER_Encoder_UpdateBackup;
DL_UART_Main_backupConfig gOPENMVBackup;
DL_SPI_backupConfig gW25Q128Backup;

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform any initialization needed before using any board APIs
 */
SYSCONFIG_WEAK void SYSCFG_DL_init(void)
{
    SYSCFG_DL_initPower();
    SYSCFG_DL_GPIO_init();
    /* Module-Specific Initializations*/
    SYSCFG_DL_SYSCTL_init();
    SYSCFG_DL_BEEZ_init();
    SYSCFG_DL_AIN_init();
    SYSCFG_DL_BIN_init();
    SYSCFG_DL_Servo_1_init();
    SYSCFG_DL_TIMER_Encoder_Update_init();
    SYSCFG_DL_TIMER_Control_init();
    SYSCFG_DL_BLE05_init();
    SYSCFG_DL_OPENMV_init();
    SYSCFG_DL_CKP_init();
    SYSCFG_DL_W25Q128_init();
    SYSCFG_DL_ADC_VOLTAGE_init();
    SYSCFG_DL_SYSTICK_init();
    /* Ensure backup structures have no valid state */
	gBEEZBackup.backupRdy 	= false;
	gAINBackup.backupRdy 	= false;
	gServo_1Backup.backupRdy 	= false;
	gTIMER_Encoder_UpdateBackup.backupRdy 	= false;
	gOPENMVBackup.backupRdy 	= false;
	gW25Q128Backup.backupRdy 	= false;

}
/*
 * User should take care to save and restore register configuration in application.
 * See Retention Configuration section for more details.
 */
SYSCONFIG_WEAK bool SYSCFG_DL_saveConfiguration(void)
{
    bool retStatus = true;

	retStatus &= DL_TimerA_saveConfiguration(BEEZ_INST, &gBEEZBackup);
	retStatus &= DL_TimerG_saveConfiguration(AIN_INST, &gAINBackup);
	retStatus &= DL_TimerA_saveConfiguration(Servo_1_INST, &gServo_1Backup);
	retStatus &= DL_TimerG_saveConfiguration(TIMER_Encoder_Update_INST, &gTIMER_Encoder_UpdateBackup);
	retStatus &= DL_UART_Main_saveConfiguration(OPENMV_INST, &gOPENMVBackup);
	retStatus &= DL_SPI_saveConfiguration(W25Q128_INST, &gW25Q128Backup);

    return retStatus;
}


SYSCONFIG_WEAK bool SYSCFG_DL_restoreConfiguration(void)
{
    bool retStatus = true;

	retStatus &= DL_TimerA_restoreConfiguration(BEEZ_INST, &gBEEZBackup, false);
	retStatus &= DL_TimerG_restoreConfiguration(AIN_INST, &gAINBackup, false);
	retStatus &= DL_TimerA_restoreConfiguration(Servo_1_INST, &gServo_1Backup, false);
	retStatus &= DL_TimerG_restoreConfiguration(TIMER_Encoder_Update_INST, &gTIMER_Encoder_UpdateBackup, false);
	retStatus &= DL_UART_Main_restoreConfiguration(OPENMV_INST, &gOPENMVBackup);
	retStatus &= DL_SPI_restoreConfiguration(W25Q128_INST, &gW25Q128Backup);

    return retStatus;
}

SYSCONFIG_WEAK void SYSCFG_DL_initPower(void)
{
    DL_GPIO_reset(GPIOA);
    DL_GPIO_reset(GPIOB);
    DL_TimerA_reset(BEEZ_INST);
    DL_TimerG_reset(AIN_INST);
    DL_TimerG_reset(BIN_INST);
    DL_TimerA_reset(Servo_1_INST);
    DL_TimerG_reset(TIMER_Encoder_Update_INST);
    DL_TimerG_reset(TIMER_Control_INST);
    DL_UART_Main_reset(BLE05_INST);
    DL_UART_Main_reset(OPENMV_INST);
    DL_UART_Main_reset(CKP_INST);
    DL_SPI_reset(W25Q128_INST);
    DL_ADC12_reset(ADC_VOLTAGE_INST);


    DL_GPIO_enablePower(GPIOA);
    DL_GPIO_enablePower(GPIOB);
    DL_TimerA_enablePower(BEEZ_INST);
    DL_TimerG_enablePower(AIN_INST);
    DL_TimerG_enablePower(BIN_INST);
    DL_TimerA_enablePower(Servo_1_INST);
    DL_TimerG_enablePower(TIMER_Encoder_Update_INST);
    DL_TimerG_enablePower(TIMER_Control_INST);
    DL_UART_Main_enablePower(BLE05_INST);
    DL_UART_Main_enablePower(OPENMV_INST);
    DL_UART_Main_enablePower(CKP_INST);
    DL_SPI_enablePower(W25Q128_INST);
    DL_ADC12_enablePower(ADC_VOLTAGE_INST);

    delay_cycles(POWER_STARTUP_DELAY);
}

SYSCONFIG_WEAK void SYSCFG_DL_GPIO_init(void)
{

    DL_GPIO_initPeripheralOutputFunction(GPIO_BEEZ_C2_IOMUX,GPIO_BEEZ_C2_IOMUX_FUNC);
    DL_GPIO_enableOutput(GPIO_BEEZ_C2_PORT, GPIO_BEEZ_C2_PIN);
    DL_GPIO_initPeripheralOutputFunction(GPIO_AIN_C0_IOMUX,GPIO_AIN_C0_IOMUX_FUNC);
    DL_GPIO_enableOutput(GPIO_AIN_C0_PORT, GPIO_AIN_C0_PIN);
    DL_GPIO_initPeripheralOutputFunction(GPIO_AIN_C1_IOMUX,GPIO_AIN_C1_IOMUX_FUNC);
    DL_GPIO_enableOutput(GPIO_AIN_C1_PORT, GPIO_AIN_C1_PIN);
    
	DL_GPIO_initPeripheralOutputFunctionFeatures(
		 GPIO_AIN_C0_IOMUX, GPIO_AIN_C0_IOMUX_FUNC,
		 DL_GPIO_INVERSION_ENABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_DRIVE_STRENGTH_LOW, DL_GPIO_HIZ_DISABLE);
	DL_GPIO_initPeripheralOutputFunctionFeatures(
		 GPIO_AIN_C1_IOMUX, GPIO_AIN_C1_IOMUX_FUNC,
		 DL_GPIO_INVERSION_ENABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_DRIVE_STRENGTH_LOW, DL_GPIO_HIZ_DISABLE);
    DL_GPIO_initPeripheralOutputFunction(GPIO_BIN_C0_IOMUX,GPIO_BIN_C0_IOMUX_FUNC);
    DL_GPIO_enableOutput(GPIO_BIN_C0_PORT, GPIO_BIN_C0_PIN);
    DL_GPIO_initPeripheralOutputFunction(GPIO_BIN_C1_IOMUX,GPIO_BIN_C1_IOMUX_FUNC);
    DL_GPIO_enableOutput(GPIO_BIN_C1_PORT, GPIO_BIN_C1_PIN);
    
	DL_GPIO_initPeripheralOutputFunctionFeatures(
		 GPIO_BIN_C0_IOMUX, GPIO_BIN_C0_IOMUX_FUNC,
		 DL_GPIO_INVERSION_ENABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_DRIVE_STRENGTH_LOW, DL_GPIO_HIZ_DISABLE);
	DL_GPIO_initPeripheralOutputFunctionFeatures(
		 GPIO_BIN_C1_IOMUX, GPIO_BIN_C1_IOMUX_FUNC,
		 DL_GPIO_INVERSION_ENABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_DRIVE_STRENGTH_LOW, DL_GPIO_HIZ_DISABLE);
    DL_GPIO_initPeripheralOutputFunction(GPIO_Servo_1_C0_IOMUX,GPIO_Servo_1_C0_IOMUX_FUNC);
    DL_GPIO_enableOutput(GPIO_Servo_1_C0_PORT, GPIO_Servo_1_C0_PIN);

    
	DL_GPIO_initPeripheralOutputFunctionFeatures(
		 GPIO_BLE05_IOMUX_TX, GPIO_BLE05_IOMUX_TX_FUNC,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_DRIVE_STRENGTH_LOW, DL_GPIO_HIZ_DISABLE);
	DL_GPIO_initPeripheralInputFunctionFeatures(
		 GPIO_BLE05_IOMUX_RX, GPIO_BLE05_IOMUX_RX_FUNC,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);
    DL_GPIO_initPeripheralOutputFunction(
        GPIO_OPENMV_IOMUX_TX, GPIO_OPENMV_IOMUX_TX_FUNC);
    DL_GPIO_initPeripheralInputFunction(
        GPIO_OPENMV_IOMUX_RX, GPIO_OPENMV_IOMUX_RX_FUNC);
    DL_GPIO_initPeripheralOutputFunction(
        GPIO_CKP_IOMUX_TX, GPIO_CKP_IOMUX_TX_FUNC);
    DL_GPIO_initPeripheralInputFunction(
        GPIO_CKP_IOMUX_RX, GPIO_CKP_IOMUX_RX_FUNC);

    DL_GPIO_initPeripheralOutputFunction(
        GPIO_W25Q128_IOMUX_SCLK, GPIO_W25Q128_IOMUX_SCLK_FUNC);
    DL_GPIO_initPeripheralOutputFunction(
        GPIO_W25Q128_IOMUX_PICO, GPIO_W25Q128_IOMUX_PICO_FUNC);
    DL_GPIO_initPeripheralInputFunction(
        GPIO_W25Q128_IOMUX_POCI, GPIO_W25Q128_IOMUX_POCI_FUNC);

    DL_GPIO_initDigitalOutput(BSL_PIN_18_IOMUX);

    DL_GPIO_initDigitalOutput(W25Q128_CS_PIN_IOMUX);

    DL_GPIO_initDigitalInputFeatures(BUTTONS_K1_IOMUX,
		 DL_GPIO_INVERSION_ENABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(BUTTONS_K2_IOMUX,
		 DL_GPIO_INVERSION_ENABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(BUTTONS_K3_IOMUX,
		 DL_GPIO_INVERSION_ENABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(Encoder_R_A_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(Encoder_R_B_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_PULL_UP,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(Encoder_L_A_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_NONE,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalInputFeatures(Encoder_L_B_IOMUX,
		 DL_GPIO_INVERSION_DISABLE, DL_GPIO_RESISTOR_NONE,
		 DL_GPIO_HYSTERESIS_DISABLE, DL_GPIO_WAKEUP_DISABLE);

    DL_GPIO_initDigitalOutput(IIC_Software_SCL_IOMUX);

    DL_GPIO_initDigitalOutput(IIC_Software_SDA_IOMUX);

    DL_GPIO_clearPins(GPIOA, BSL_PIN_18_PIN);
    DL_GPIO_setPins(GPIOA, IIC_Software_SCL_PIN |
		IIC_Software_SDA_PIN);
    DL_GPIO_enableOutput(GPIOA, BSL_PIN_18_PIN |
		IIC_Software_SCL_PIN |
		IIC_Software_SDA_PIN);
    DL_GPIO_setLowerPinsPolarity(GPIOA, DL_GPIO_PIN_12_EDGE_RISE |
		DL_GPIO_PIN_13_EDGE_RISE);
    DL_GPIO_clearInterruptStatus(GPIOA, Encoder_R_A_PIN |
		Encoder_R_B_PIN);
    DL_GPIO_enableInterrupt(GPIOA, Encoder_R_A_PIN |
		Encoder_R_B_PIN);
    DL_GPIO_setPublisherChanID(GPIOA, DL_GPIO_PUBLISHER_INDEX_0, GPIOA_EVENT_PUBLISHER_0_CHANNEL);
    DL_GPIO_enableEvents(GPIOA, DL_GPIO_EVENT_ROUTE_1, Encoder_R_A_PIN |
		Encoder_R_B_PIN);
    DL_GPIO_clearPins(GPIOB, W25Q128_CS_PIN_PIN);
    DL_GPIO_enableOutput(GPIOB, W25Q128_CS_PIN_PIN);
    DL_GPIO_setLowerPinsPolarity(GPIOB, DL_GPIO_PIN_2_EDGE_RISE |
		DL_GPIO_PIN_3_EDGE_RISE);
    DL_GPIO_clearInterruptStatus(GPIOB, Encoder_L_A_PIN |
		Encoder_L_B_PIN);
    DL_GPIO_enableInterrupt(GPIOB, Encoder_L_A_PIN |
		Encoder_L_B_PIN);
    DL_GPIO_setPublisherChanID(GPIOB, DL_GPIO_PUBLISHER_INDEX_0, GPIOB_EVENT_PUBLISHER_0_CHANNEL);
    DL_GPIO_enableEvents(GPIOB, DL_GPIO_EVENT_ROUTE_1, Encoder_L_A_PIN |
		Encoder_L_B_PIN);

}


static const DL_SYSCTL_SYSPLLConfig gSYSPLLConfig = {
    .inputFreq              = DL_SYSCTL_SYSPLL_INPUT_FREQ_16_32_MHZ,
	.rDivClk2x              = 3,
	.rDivClk1               = 0,
	.rDivClk0               = 0,
	.enableCLK2x            = DL_SYSCTL_SYSPLL_CLK2X_ENABLE,
	.enableCLK1             = DL_SYSCTL_SYSPLL_CLK1_DISABLE,
	.enableCLK0             = DL_SYSCTL_SYSPLL_CLK0_DISABLE,
	.sysPLLMCLK             = DL_SYSCTL_SYSPLL_MCLK_CLK2X,
	.sysPLLRef              = DL_SYSCTL_SYSPLL_REF_SYSOSC,
	.qDiv                   = 9,
	.pDiv                   = DL_SYSCTL_SYSPLL_PDIV_2
};
SYSCONFIG_WEAK void SYSCFG_DL_SYSCTL_init(void)
{

	//Low Power Mode is configured to be SLEEP0
    DL_SYSCTL_setBORThreshold(DL_SYSCTL_BOR_THRESHOLD_LEVEL_0);
    DL_SYSCTL_setFlashWaitState(DL_SYSCTL_FLASH_WAIT_STATE_2);

    
	DL_SYSCTL_setSYSOSCFreq(DL_SYSCTL_SYSOSC_FREQ_BASE);
	/* Set default configuration */
	DL_SYSCTL_disableHFXT();
	DL_SYSCTL_disableSYSPLL();
    DL_SYSCTL_configSYSPLL((DL_SYSCTL_SYSPLLConfig *) &gSYSPLLConfig);
    DL_SYSCTL_setULPCLKDivider(DL_SYSCTL_ULPCLK_DIV_2);
    DL_SYSCTL_setMCLKSource(SYSOSC, HSCLK, DL_SYSCTL_HSCLK_SOURCE_SYSPLL);
    /* INT_GROUP1 Priority */
    NVIC_SetPriority(GPIOB_INT_IRQn, 0);

}


/*
 * Timer clock configuration to be sourced by  / 8 (10000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   10000000 Hz = 10000000 Hz / (8 * (0 + 1))
 */
static const DL_TimerA_ClockConfig gBEEZClockConfig = {
    .clockSel = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_8,
    .prescale = 0U
};

static const DL_TimerA_PWMConfig gBEEZConfig = {
    .pwmMode = DL_TIMER_PWM_MODE_EDGE_ALIGN,
    .period = 1000,
    .isTimerWithFourCC = true,
    .startTimer = DL_TIMER_START,
};

SYSCONFIG_WEAK void SYSCFG_DL_BEEZ_init(void) {

    DL_TimerA_setClockConfig(
        BEEZ_INST, (DL_TimerA_ClockConfig *) &gBEEZClockConfig);

    DL_TimerA_initPWMMode(
        BEEZ_INST, (DL_TimerA_PWMConfig *) &gBEEZConfig);

    // Set Counter control to the smallest CC index being used
    DL_TimerA_setCounterControl(BEEZ_INST,DL_TIMER_CZC_CCCTL2_ZCOND,DL_TIMER_CAC_CCCTL2_ACOND,DL_TIMER_CLC_CCCTL2_LCOND);

    DL_TimerA_setCaptureCompareOutCtl(BEEZ_INST, DL_TIMER_CC_OCTL_INIT_VAL_HIGH,
		DL_TIMER_CC_OCTL_INV_OUT_DISABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL,
		DL_TIMERA_CAPTURE_COMPARE_2_INDEX);

    DL_TimerA_setCaptCompUpdateMethod(BEEZ_INST, DL_TIMER_CC_UPDATE_METHOD_IMMEDIATE, DL_TIMERA_CAPTURE_COMPARE_2_INDEX);
    DL_TimerA_setCaptureCompareValue(BEEZ_INST, 1000, DL_TIMER_CC_2_INDEX);

    DL_TimerA_enableClock(BEEZ_INST);


    
    DL_TimerA_setCCPDirection(BEEZ_INST , DL_TIMER_CC2_OUTPUT );


}
/*
 * Timer clock configuration to be sourced by  / 2 (40000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   40000000 Hz = 40000000 Hz / (2 * (0 + 1))
 */
static const DL_TimerG_ClockConfig gAINClockConfig = {
    .clockSel = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_2,
    .prescale = 0U
};

static const DL_TimerG_PWMConfig gAINConfig = {
    .pwmMode = DL_TIMER_PWM_MODE_EDGE_ALIGN,
    .period = 1000,
    .isTimerWithFourCC = false,
    .startTimer = DL_TIMER_START,
};

SYSCONFIG_WEAK void SYSCFG_DL_AIN_init(void) {

    DL_TimerG_setClockConfig(
        AIN_INST, (DL_TimerG_ClockConfig *) &gAINClockConfig);

    DL_TimerG_initPWMMode(
        AIN_INST, (DL_TimerG_PWMConfig *) &gAINConfig);

    // Set Counter control to the smallest CC index being used
    DL_TimerG_setCounterControl(AIN_INST,DL_TIMER_CZC_CCCTL0_ZCOND,DL_TIMER_CAC_CCCTL0_ACOND,DL_TIMER_CLC_CCCTL0_LCOND);

    DL_TimerG_setCaptureCompareOutCtl(AIN_INST, DL_TIMER_CC_OCTL_INIT_VAL_LOW,
		DL_TIMER_CC_OCTL_INV_OUT_ENABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL,
		DL_TIMERG_CAPTURE_COMPARE_0_INDEX);

    DL_TimerG_setCaptCompUpdateMethod(AIN_INST, DL_TIMER_CC_UPDATE_METHOD_IMMEDIATE, DL_TIMERG_CAPTURE_COMPARE_0_INDEX);
    DL_TimerG_setCaptureCompareValue(AIN_INST, 1000, DL_TIMER_CC_0_INDEX);

    DL_TimerG_setCaptureCompareOutCtl(AIN_INST, DL_TIMER_CC_OCTL_INIT_VAL_LOW,
		DL_TIMER_CC_OCTL_INV_OUT_ENABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL,
		DL_TIMERG_CAPTURE_COMPARE_1_INDEX);

    DL_TimerG_setCaptCompUpdateMethod(AIN_INST, DL_TIMER_CC_UPDATE_METHOD_IMMEDIATE, DL_TIMERG_CAPTURE_COMPARE_1_INDEX);
    DL_TimerG_setCaptureCompareValue(AIN_INST, 1000, DL_TIMER_CC_1_INDEX);

    DL_TimerG_enableClock(AIN_INST);


    
    DL_TimerG_setCCPDirection(AIN_INST , DL_TIMER_CC0_OUTPUT | DL_TIMER_CC1_OUTPUT );


}
/*
 * Timer clock configuration to be sourced by  / 1 (40000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   40000000 Hz = 40000000 Hz / (1 * (0 + 1))
 */
static const DL_TimerG_ClockConfig gBINClockConfig = {
    .clockSel = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_1,
    .prescale = 0U
};

static const DL_TimerG_PWMConfig gBINConfig = {
    .pwmMode = DL_TIMER_PWM_MODE_EDGE_ALIGN,
    .period = 1000,
    .isTimerWithFourCC = false,
    .startTimer = DL_TIMER_START,
};

SYSCONFIG_WEAK void SYSCFG_DL_BIN_init(void) {

    DL_TimerG_setClockConfig(
        BIN_INST, (DL_TimerG_ClockConfig *) &gBINClockConfig);

    DL_TimerG_initPWMMode(
        BIN_INST, (DL_TimerG_PWMConfig *) &gBINConfig);

    // Set Counter control to the smallest CC index being used
    DL_TimerG_setCounterControl(BIN_INST,DL_TIMER_CZC_CCCTL0_ZCOND,DL_TIMER_CAC_CCCTL0_ACOND,DL_TIMER_CLC_CCCTL0_LCOND);

    DL_TimerG_setCaptureCompareOutCtl(BIN_INST, DL_TIMER_CC_OCTL_INIT_VAL_LOW,
		DL_TIMER_CC_OCTL_INV_OUT_ENABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL,
		DL_TIMERG_CAPTURE_COMPARE_0_INDEX);

    DL_TimerG_setCaptCompUpdateMethod(BIN_INST, DL_TIMER_CC_UPDATE_METHOD_IMMEDIATE, DL_TIMERG_CAPTURE_COMPARE_0_INDEX);
    DL_TimerG_setCaptureCompareValue(BIN_INST, 1000, DL_TIMER_CC_0_INDEX);

    DL_TimerG_setCaptureCompareOutCtl(BIN_INST, DL_TIMER_CC_OCTL_INIT_VAL_LOW,
		DL_TIMER_CC_OCTL_INV_OUT_ENABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL,
		DL_TIMERG_CAPTURE_COMPARE_1_INDEX);

    DL_TimerG_setCaptCompUpdateMethod(BIN_INST, DL_TIMER_CC_UPDATE_METHOD_IMMEDIATE, DL_TIMERG_CAPTURE_COMPARE_1_INDEX);
    DL_TimerG_setCaptureCompareValue(BIN_INST, 1000, DL_TIMER_CC_1_INDEX);

    DL_TimerG_enableClock(BIN_INST);


    
    DL_TimerG_setCCPDirection(BIN_INST , DL_TIMER_CC0_OUTPUT | DL_TIMER_CC1_OUTPUT );


}
/*
 * Timer clock configuration to be sourced by  / 8 (10000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   50000 Hz = 10000000 Hz / (8 * (199 + 1))
 */
static const DL_TimerA_ClockConfig gServo_1ClockConfig = {
    .clockSel = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_8,
    .prescale = 199U
};

static const DL_TimerA_PWMConfig gServo_1Config = {
    .pwmMode = DL_TIMER_PWM_MODE_EDGE_ALIGN,
    .period = 1000,
    .isTimerWithFourCC = false,
    .startTimer = DL_TIMER_START,
};

SYSCONFIG_WEAK void SYSCFG_DL_Servo_1_init(void) {

    DL_TimerA_setClockConfig(
        Servo_1_INST, (DL_TimerA_ClockConfig *) &gServo_1ClockConfig);

    DL_TimerA_initPWMMode(
        Servo_1_INST, (DL_TimerA_PWMConfig *) &gServo_1Config);

    // Set Counter control to the smallest CC index being used
    DL_TimerA_setCounterControl(Servo_1_INST,DL_TIMER_CZC_CCCTL0_ZCOND,DL_TIMER_CAC_CCCTL0_ACOND,DL_TIMER_CLC_CCCTL0_LCOND);

    DL_TimerA_setCaptureCompareOutCtl(Servo_1_INST, DL_TIMER_CC_OCTL_INIT_VAL_LOW,
		DL_TIMER_CC_OCTL_INV_OUT_ENABLED, DL_TIMER_CC_OCTL_SRC_FUNCVAL,
		DL_TIMERA_CAPTURE_COMPARE_0_INDEX);

    DL_TimerA_setCaptCompUpdateMethod(Servo_1_INST, DL_TIMER_CC_UPDATE_METHOD_IMMEDIATE, DL_TIMERA_CAPTURE_COMPARE_0_INDEX);
    DL_TimerA_setCaptureCompareValue(Servo_1_INST, 1000, DL_TIMER_CC_0_INDEX);

    DL_TimerA_enableClock(Servo_1_INST);


    
    DL_TimerA_setCCPDirection(Servo_1_INST , DL_TIMER_CC0_OUTPUT );


}



/*
 * Timer clock configuration to be sourced by BUSCLK /  (80000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   800000 Hz = 80000000 Hz / (1 * (99 + 1))
 */
static const DL_TimerG_ClockConfig gTIMER_Encoder_UpdateClockConfig = {
    .clockSel    = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_1,
    .prescale    = 99U,
};

/*
 * Timer load value (where the counter starts from) is calculated as (timerPeriod * timerClockFreq) - 1
 * TIMER_Encoder_Update_INST_LOAD_VALUE = (20ms * 800000 Hz) - 1
 */
static const DL_TimerG_TimerConfig gTIMER_Encoder_UpdateTimerConfig = {
    .period     = TIMER_Encoder_Update_INST_LOAD_VALUE,
    .timerMode  = DL_TIMER_TIMER_MODE_PERIODIC,
    .startTimer = DL_TIMER_START,
};

SYSCONFIG_WEAK void SYSCFG_DL_TIMER_Encoder_Update_init(void) {

    DL_TimerG_setClockConfig(TIMER_Encoder_Update_INST,
        (DL_TimerG_ClockConfig *) &gTIMER_Encoder_UpdateClockConfig);

    DL_TimerG_initTimerMode(TIMER_Encoder_Update_INST,
        (DL_TimerG_TimerConfig *) &gTIMER_Encoder_UpdateTimerConfig);
    DL_TimerG_enableInterrupt(TIMER_Encoder_Update_INST , DL_TIMERG_INTERRUPT_ZERO_EVENT);
	NVIC_SetPriority(TIMER_Encoder_Update_INST_INT_IRQN, 0);
    DL_TimerG_enableClock(TIMER_Encoder_Update_INST);





}

/*
 * Timer clock configuration to be sourced by BUSCLK /  (40000000 Hz)
 * timerClkFreq = (timerClkSrc / (timerClkDivRatio * (timerClkPrescale + 1)))
 *   2000000 Hz = 40000000 Hz / (1 * (19 + 1))
 */
static const DL_TimerG_ClockConfig gTIMER_ControlClockConfig = {
    .clockSel    = DL_TIMER_CLOCK_BUSCLK,
    .divideRatio = DL_TIMER_CLOCK_DIVIDE_1,
    .prescale    = 19U,
};

/*
 * Timer load value (where the counter starts from) is calculated as (timerPeriod * timerClockFreq) - 1
 * TIMER_Control_INST_LOAD_VALUE = (10ms * 2000000 Hz) - 1
 */
static const DL_TimerG_TimerConfig gTIMER_ControlTimerConfig = {
    .period     = TIMER_Control_INST_LOAD_VALUE,
    .timerMode  = DL_TIMER_TIMER_MODE_PERIODIC,
    .startTimer = DL_TIMER_START,
};

SYSCONFIG_WEAK void SYSCFG_DL_TIMER_Control_init(void) {

    DL_TimerG_setClockConfig(TIMER_Control_INST,
        (DL_TimerG_ClockConfig *) &gTIMER_ControlClockConfig);

    DL_TimerG_initTimerMode(TIMER_Control_INST,
        (DL_TimerG_TimerConfig *) &gTIMER_ControlTimerConfig);
    DL_TimerG_enableInterrupt(TIMER_Control_INST , DL_TIMERG_INTERRUPT_ZERO_EVENT);
	NVIC_SetPriority(TIMER_Control_INST_INT_IRQN, 1);
    DL_TimerG_enableClock(TIMER_Control_INST);





}



static const DL_UART_Main_ClockConfig gBLE05ClockConfig = {
    .clockSel    = DL_UART_MAIN_CLOCK_BUSCLK,
    .divideRatio = DL_UART_MAIN_CLOCK_DIVIDE_RATIO_1
};

static const DL_UART_Main_Config gBLE05Config = {
    .mode        = DL_UART_MAIN_MODE_NORMAL,
    .direction   = DL_UART_MAIN_DIRECTION_TX_RX,
    .flowControl = DL_UART_MAIN_FLOW_CONTROL_NONE,
    .parity      = DL_UART_MAIN_PARITY_NONE,
    .wordLength  = DL_UART_MAIN_WORD_LENGTH_8_BITS,
    .stopBits    = DL_UART_MAIN_STOP_BITS_ONE
};

SYSCONFIG_WEAK void SYSCFG_DL_BLE05_init(void)
{
    DL_UART_Main_setClockConfig(BLE05_INST, (DL_UART_Main_ClockConfig *) &gBLE05ClockConfig);

    DL_UART_Main_init(BLE05_INST, (DL_UART_Main_Config *) &gBLE05Config);
    /*
     * Configure baud rate by setting oversampling and baud rate divisors.
     *  Target baud rate: 115200
     *  Actual baud rate: 115190.78
     */
    DL_UART_Main_setOversampling(BLE05_INST, DL_UART_OVERSAMPLING_RATE_16X);
    DL_UART_Main_setBaudRateDivisor(BLE05_INST, BLE05_IBRD_40_MHZ_115200_BAUD, BLE05_FBRD_40_MHZ_115200_BAUD);


    /* Configure Interrupts */
    DL_UART_Main_enableInterrupt(BLE05_INST,
                                 DL_UART_MAIN_INTERRUPT_RX);
    /* Setting the Interrupt Priority */
    NVIC_SetPriority(BLE05_INST_INT_IRQN, 0);

    /* Configure FIFOs */
    DL_UART_Main_enableFIFOs(BLE05_INST);
    DL_UART_Main_setRXFIFOThreshold(BLE05_INST, DL_UART_RX_FIFO_LEVEL_1_2_FULL);
    DL_UART_Main_setTXFIFOThreshold(BLE05_INST, DL_UART_TX_FIFO_LEVEL_1_2_EMPTY);

    DL_UART_Main_enable(BLE05_INST);
}

static const DL_UART_Main_ClockConfig gOPENMVClockConfig = {
    .clockSel    = DL_UART_MAIN_CLOCK_BUSCLK,
    .divideRatio = DL_UART_MAIN_CLOCK_DIVIDE_RATIO_1
};

static const DL_UART_Main_Config gOPENMVConfig = {
    .mode        = DL_UART_MAIN_MODE_NORMAL,
    .direction   = DL_UART_MAIN_DIRECTION_TX_RX,
    .flowControl = DL_UART_MAIN_FLOW_CONTROL_NONE,
    .parity      = DL_UART_MAIN_PARITY_NONE,
    .wordLength  = DL_UART_MAIN_WORD_LENGTH_8_BITS,
    .stopBits    = DL_UART_MAIN_STOP_BITS_ONE
};

SYSCONFIG_WEAK void SYSCFG_DL_OPENMV_init(void)
{
    DL_UART_Main_setClockConfig(OPENMV_INST, (DL_UART_Main_ClockConfig *) &gOPENMVClockConfig);

    DL_UART_Main_init(OPENMV_INST, (DL_UART_Main_Config *) &gOPENMVConfig);
    /*
     * Configure baud rate by setting oversampling and baud rate divisors.
     *  Target baud rate: 115200
     *  Actual baud rate: 115190.78
     */
    DL_UART_Main_setOversampling(OPENMV_INST, DL_UART_OVERSAMPLING_RATE_16X);
    DL_UART_Main_setBaudRateDivisor(OPENMV_INST, OPENMV_IBRD_80_MHZ_115200_BAUD, OPENMV_FBRD_80_MHZ_115200_BAUD);


    /* Configure Interrupts */
    DL_UART_Main_enableInterrupt(OPENMV_INST,
                                 DL_UART_MAIN_INTERRUPT_RX);
    /* Setting the Interrupt Priority */
    NVIC_SetPriority(OPENMV_INST_INT_IRQN, 1);

    /* Configure FIFOs */
    DL_UART_Main_enableFIFOs(OPENMV_INST);
    DL_UART_Main_setRXFIFOThreshold(OPENMV_INST, DL_UART_RX_FIFO_LEVEL_1_2_FULL);
    DL_UART_Main_setTXFIFOThreshold(OPENMV_INST, DL_UART_TX_FIFO_LEVEL_1_2_EMPTY);

    DL_UART_Main_enable(OPENMV_INST);
}

static const DL_UART_Main_ClockConfig gCKPClockConfig = {
    .clockSel    = DL_UART_MAIN_CLOCK_BUSCLK,
    .divideRatio = DL_UART_MAIN_CLOCK_DIVIDE_RATIO_1
};

static const DL_UART_Main_Config gCKPConfig = {
    .mode        = DL_UART_MAIN_MODE_NORMAL,
    .direction   = DL_UART_MAIN_DIRECTION_TX_RX,
    .flowControl = DL_UART_MAIN_FLOW_CONTROL_NONE,
    .parity      = DL_UART_MAIN_PARITY_NONE,
    .wordLength  = DL_UART_MAIN_WORD_LENGTH_8_BITS,
    .stopBits    = DL_UART_MAIN_STOP_BITS_ONE
};

SYSCONFIG_WEAK void SYSCFG_DL_CKP_init(void)
{
    DL_UART_Main_setClockConfig(CKP_INST, (DL_UART_Main_ClockConfig *) &gCKPClockConfig);

    DL_UART_Main_init(CKP_INST, (DL_UART_Main_Config *) &gCKPConfig);
    /*
     * Configure baud rate by setting oversampling and baud rate divisors.
     *  Target baud rate: 9600
     *  Actual baud rate: 9599.81
     */
    DL_UART_Main_setOversampling(CKP_INST, DL_UART_OVERSAMPLING_RATE_16X);
    DL_UART_Main_setBaudRateDivisor(CKP_INST, CKP_IBRD_40_MHZ_9600_BAUD, CKP_FBRD_40_MHZ_9600_BAUD);


    /* Configure Interrupts */
    DL_UART_Main_enableInterrupt(CKP_INST,
                                 DL_UART_MAIN_INTERRUPT_RX);
    /* Setting the Interrupt Priority */
    NVIC_SetPriority(CKP_INST_INT_IRQN, 0);

    /* Configure FIFOs */
    DL_UART_Main_enableFIFOs(CKP_INST);
    DL_UART_Main_setRXFIFOThreshold(CKP_INST, DL_UART_RX_FIFO_LEVEL_1_2_FULL);
    DL_UART_Main_setTXFIFOThreshold(CKP_INST, DL_UART_TX_FIFO_LEVEL_1_2_EMPTY);

    DL_UART_Main_enable(CKP_INST);
}

static const DL_SPI_Config gW25Q128_config = {
    .mode        = DL_SPI_MODE_CONTROLLER,
    .frameFormat = DL_SPI_FRAME_FORMAT_MOTO3_POL0_PHA0,
    .parity      = DL_SPI_PARITY_NONE,
    .dataSize    = DL_SPI_DATA_SIZE_8,
    .bitOrder    = DL_SPI_BIT_ORDER_MSB_FIRST,
};

static const DL_SPI_ClockConfig gW25Q128_clockConfig = {
    .clockSel    = DL_SPI_CLOCK_BUSCLK,
    .divideRatio = DL_SPI_CLOCK_DIVIDE_RATIO_1
};

SYSCONFIG_WEAK void SYSCFG_DL_W25Q128_init(void) {
    DL_SPI_setClockConfig(W25Q128_INST, (DL_SPI_ClockConfig *) &gW25Q128_clockConfig);

    DL_SPI_init(W25Q128_INST, (DL_SPI_Config *) &gW25Q128_config);

    /* Configure Controller mode */
    /*
     * Set the bit rate clock divider to generate the serial output clock
     *     outputBitRate = (spiInputClock) / ((1 + SCR) * 2)
     *     4000000 = (80000000)/((1 + 9) * 2)
     */
    DL_SPI_setBitRateSerialClockDivider(W25Q128_INST, 9);
    /* Set RX and TX FIFO threshold levels */
    DL_SPI_setFIFOThreshold(W25Q128_INST, DL_SPI_RX_FIFO_LEVEL_1_2_FULL, DL_SPI_TX_FIFO_LEVEL_1_2_EMPTY);

    /* Enable module */
    DL_SPI_enable(W25Q128_INST);
}

/* ADC_VOLTAGE Initialization */
static const DL_ADC12_ClockConfig gADC_VOLTAGEClockConfig = {
    .clockSel       = DL_ADC12_CLOCK_SYSOSC,
    .divideRatio    = DL_ADC12_CLOCK_DIVIDE_8,
    .freqRange      = DL_ADC12_CLOCK_FREQ_RANGE_24_TO_32,
};
SYSCONFIG_WEAK void SYSCFG_DL_ADC_VOLTAGE_init(void)
{
    DL_ADC12_setClockConfig(ADC_VOLTAGE_INST, (DL_ADC12_ClockConfig *) &gADC_VOLTAGEClockConfig);
    DL_ADC12_configConversionMem(ADC_VOLTAGE_INST, ADC_VOLTAGE_ADCMEM_ADC_CH4,
        DL_ADC12_INPUT_CHAN_4, DL_ADC12_REFERENCE_VOLTAGE_VDDA, DL_ADC12_SAMPLE_TIMER_SOURCE_SCOMP0, DL_ADC12_AVERAGING_MODE_DISABLED,
        DL_ADC12_BURN_OUT_SOURCE_DISABLED, DL_ADC12_TRIGGER_MODE_AUTO_NEXT, DL_ADC12_WINDOWS_COMP_MODE_DISABLED);
    DL_ADC12_setPowerDownMode(ADC_VOLTAGE_INST,DL_ADC12_POWER_DOWN_MODE_MANUAL);
    DL_ADC12_setSampleTime0(ADC_VOLTAGE_INST,500);
    /* Enable ADC12 interrupt */
    DL_ADC12_clearInterruptStatus(ADC_VOLTAGE_INST,(DL_ADC12_INTERRUPT_MEM0_RESULT_LOADED));
    DL_ADC12_enableInterrupt(ADC_VOLTAGE_INST,(DL_ADC12_INTERRUPT_MEM0_RESULT_LOADED));
    DL_ADC12_enableConversions(ADC_VOLTAGE_INST);
}

SYSCONFIG_WEAK void SYSCFG_DL_SYSTICK_init(void)
{
    /*
     * Initializes the SysTick period to 1.00 ms,
     * enables the interrupt, and starts the SysTick Timer
     */
    DL_SYSTICK_config(80000);
}

