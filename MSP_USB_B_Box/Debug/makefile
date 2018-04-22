################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/CCS/ccsv7/tools/compiler/ti-cgt-msp430_16.9.6.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./main.obj" \
"./usbConstructs.obj" \
"./usbEventHandling.obj" \
"./F5xx_F6xx_Core_Lib/HAL_FLASH.obj" \
"./F5xx_F6xx_Core_Lib/HAL_PMAP.obj" \
"./F5xx_F6xx_Core_Lib/HAL_PMM.obj" \
"./F5xx_F6xx_Core_Lib/HAL_TLV.obj" \
"./F5xx_F6xx_Core_Lib/HAL_UCS.obj" \
"./USB_API/USB_CDC_API/UsbCdc.obj" \
"./USB_API/USB_Common/dma.obj" \
"./USB_API/USB_Common/usb.obj" \
"./USB_API/USB_HID_API/UsbHid.obj" \
"./USB_API/USB_HID_API/UsbHidReportHandler.obj" \
"./USB_API/USB_HID_API/UsbHidReq.obj" \
"./USB_API/USB_MSC_API/UsbMscReq.obj" \
"./USB_API/USB_MSC_API/UsbMscScsi.obj" \
"./USB_API/USB_MSC_API/UsbMscStateMachine.obj" \
"./USB_config/UsbIsr.obj" \
"./USB_config/descriptors.obj" \
"../lnk_msp430f5529.cmd" \
"../msp430USB.cmd" \
$(GEN_CMDS__FLAG) \
-llibmath.a \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include F5xx_F6xx_Core_Lib/subdir_vars.mk
-include USB_API/USB_CDC_API/subdir_vars.mk
-include USB_API/USB_Common/subdir_vars.mk
-include USB_API/USB_HID_API/subdir_vars.mk
-include USB_API/USB_MSC_API/subdir_vars.mk
-include USB_config/subdir_vars.mk
-include subdir_rules.mk
-include F5xx_F6xx_Core_Lib/subdir_rules.mk
-include USB_API/USB_CDC_API/subdir_rules.mk
-include USB_API/USB_Common/subdir_rules.mk
-include USB_API/USB_HID_API/subdir_rules.mk
-include USB_API/USB_MSC_API/subdir_rules.mk
-include USB_config/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
MSP_USB_B_Box.out \

EXE_OUTPUTS__QUOTED += \
"MSP_USB_B_Box.out" \

BIN_OUTPUTS += \
MSP_USB_B_Box.hex \

BIN_OUTPUTS__QUOTED += \
"MSP_USB_B_Box.hex" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "MSP_USB_B_Box.out"

# Tool invocations
MSP_USB_B_Box.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: MSP430 Linker'
	"C:/CCS/ccsv7/tools/compiler/ti-cgt-msp430_16.9.6.LTS/bin/cl430" -vmspx --data_model=restricted --use_hw_mpy=F5 --advice:power=all --define=__MSP430F5529__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 -z -m"MSP_USB_B_Box.map" --heap_size=160 --stack_size=160 --cinit_hold_wdt=on -i"C:/CCS/ccsv7/ccs_base/msp430/include" -i"C:/CCS/ccsv7/ccs_base/msp430/lib/5xx_6xx_FRxx" -i"C:/CCS/ccsv7/tools/compiler/ti-cgt-msp430_16.9.6.LTS/lib" -i"C:/CCS/ccsv7/tools/compiler/ti-cgt-msp430_16.9.6.LTS/include" --reread_libs --diag_wrap=off --display_error_number --warn_sections --xml_link_info="MSP_USB_B_Box_linkInfo.xml" --use_hw_mpy=F5 --rom_model -o "MSP_USB_B_Box.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

MSP_USB_B_Box.hex: $(EXE_OUTPUTS)
	@echo 'Building files: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo 'Invoking: MSP430 Hex Utility'
	"C:/CCS/ccsv7/tools/compiler/ti-cgt-msp430_16.9.6.LTS/bin/hex430" --memwidth=8 --romwidth=8 -o "MSP_USB_B_Box.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "main.obj" "usbConstructs.obj" "usbEventHandling.obj" "F5xx_F6xx_Core_Lib\HAL_FLASH.obj" "F5xx_F6xx_Core_Lib\HAL_PMAP.obj" "F5xx_F6xx_Core_Lib\HAL_PMM.obj" "F5xx_F6xx_Core_Lib\HAL_TLV.obj" "F5xx_F6xx_Core_Lib\HAL_UCS.obj" "USB_API\USB_CDC_API\UsbCdc.obj" "USB_API\USB_Common\dma.obj" "USB_API\USB_Common\usb.obj" "USB_API\USB_HID_API\UsbHid.obj" "USB_API\USB_HID_API\UsbHidReportHandler.obj" "USB_API\USB_HID_API\UsbHidReq.obj" "USB_API\USB_MSC_API\UsbMscReq.obj" "USB_API\USB_MSC_API\UsbMscScsi.obj" "USB_API\USB_MSC_API\UsbMscStateMachine.obj" "USB_config\UsbIsr.obj" "USB_config\descriptors.obj" 
	-$(RM) "main.d" "usbConstructs.d" "usbEventHandling.d" "F5xx_F6xx_Core_Lib\HAL_FLASH.d" "F5xx_F6xx_Core_Lib\HAL_PMAP.d" "F5xx_F6xx_Core_Lib\HAL_PMM.d" "F5xx_F6xx_Core_Lib\HAL_TLV.d" "F5xx_F6xx_Core_Lib\HAL_UCS.d" "USB_API\USB_CDC_API\UsbCdc.d" "USB_API\USB_Common\dma.d" "USB_API\USB_Common\usb.d" "USB_API\USB_HID_API\UsbHid.d" "USB_API\USB_HID_API\UsbHidReportHandler.d" "USB_API\USB_HID_API\UsbHidReq.d" "USB_API\USB_MSC_API\UsbMscReq.d" "USB_API\USB_MSC_API\UsbMscScsi.d" "USB_API\USB_MSC_API\UsbMscStateMachine.d" "USB_config\UsbIsr.d" "USB_config\descriptors.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

