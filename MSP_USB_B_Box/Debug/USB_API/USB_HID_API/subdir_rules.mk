################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
USB_API/USB_HID_API/UsbHid.obj: ../USB_API/USB_HID_API/UsbHid.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"C:/CCS/ccsv7/tools/compiler/ti-cgt-msp430_16.9.6.LTS/bin/cl430" -vmspx --data_model=restricted --use_hw_mpy=F5 --include_path="C:/CCS/ccsv7/ccs_base/msp430/include" --include_path="C:/Users/hugon/OneDrive/Documentos/UnB/Lab Sistemas Microprocessados/Projeto Final/MSP_USB_B_Box" --include_path="C:/CCS/ccsv7/tools/compiler/ti-cgt-msp430_16.9.6.LTS/include" --advice:power=all --define=__MSP430F5529__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --preproc_with_compile --preproc_dependency="USB_API/USB_HID_API/UsbHid.d_raw" --obj_directory="USB_API/USB_HID_API" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

USB_API/USB_HID_API/UsbHidReportHandler.obj: ../USB_API/USB_HID_API/UsbHidReportHandler.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"C:/CCS/ccsv7/tools/compiler/ti-cgt-msp430_16.9.6.LTS/bin/cl430" -vmspx --data_model=restricted --use_hw_mpy=F5 --include_path="C:/CCS/ccsv7/ccs_base/msp430/include" --include_path="C:/Users/hugon/OneDrive/Documentos/UnB/Lab Sistemas Microprocessados/Projeto Final/MSP_USB_B_Box" --include_path="C:/CCS/ccsv7/tools/compiler/ti-cgt-msp430_16.9.6.LTS/include" --advice:power=all --define=__MSP430F5529__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --preproc_with_compile --preproc_dependency="USB_API/USB_HID_API/UsbHidReportHandler.d_raw" --obj_directory="USB_API/USB_HID_API" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

USB_API/USB_HID_API/UsbHidReq.obj: ../USB_API/USB_HID_API/UsbHidReq.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"C:/CCS/ccsv7/tools/compiler/ti-cgt-msp430_16.9.6.LTS/bin/cl430" -vmspx --data_model=restricted --use_hw_mpy=F5 --include_path="C:/CCS/ccsv7/ccs_base/msp430/include" --include_path="C:/Users/hugon/OneDrive/Documentos/UnB/Lab Sistemas Microprocessados/Projeto Final/MSP_USB_B_Box" --include_path="C:/CCS/ccsv7/tools/compiler/ti-cgt-msp430_16.9.6.LTS/include" --advice:power=all --define=__MSP430F5529__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --preproc_with_compile --preproc_dependency="USB_API/USB_HID_API/UsbHidReq.d_raw" --obj_directory="USB_API/USB_HID_API" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


