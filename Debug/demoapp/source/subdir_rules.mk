################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
demoapp/source/adc_demos.obj: ../demoapp/source/adc_demos.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.0.LTS/bin/armcl" -mv7R5 --code_state=32 --float_support=VFPv3D16 -me --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.0.LTS/include" --include_path="C:/Users/bob/Documents/Projects/induct_forge/RM57Lx_test/Project1_LAUNCHXL2_RM57L/hcg/include" --include_path="C:/Users/bob/Documents/Projects/induct_forge/RM57Lx_test/Project1_LAUNCHXL2_RM57L/demoapp/include" --include_path="C:/ti/Hercules/SafeTI Diagnostic Library/2.2.0/hal/include" --include_path="C:/ti/Hercules/SafeTI Diagnostic Library/2.2.0/safety_library/include" --define=_RM57Lx_ -g --diag_warning=225 --diag_wrap=off --display_error_number --enum_type=packed --abi=eabi --preproc_with_compile --preproc_dependency="demoapp/source/adc_demos.d" --obj_directory="demoapp/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

demoapp/source/app_main_NoOS.obj: ../demoapp/source/app_main_NoOS.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.0.LTS/bin/armcl" -mv7R5 --code_state=32 --float_support=VFPv3D16 -me --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.0.LTS/include" --include_path="C:/Users/bob/Documents/Projects/induct_forge/RM57Lx_test/Project1_LAUNCHXL2_RM57L/hcg/include" --include_path="C:/Users/bob/Documents/Projects/induct_forge/RM57Lx_test/Project1_LAUNCHXL2_RM57L/demoapp/include" --include_path="C:/ti/Hercules/SafeTI Diagnostic Library/2.2.0/hal/include" --include_path="C:/ti/Hercules/SafeTI Diagnostic Library/2.2.0/safety_library/include" --define=_RM57Lx_ -g --diag_warning=225 --diag_wrap=off --display_error_number --enum_type=packed --abi=eabi --preproc_with_compile --preproc_dependency="demoapp/source/app_main_NoOS.d" --obj_directory="demoapp/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

demoapp/source/esm_application_callback.obj: ../demoapp/source/esm_application_callback.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.0.LTS/bin/armcl" -mv7R5 --code_state=32 --float_support=VFPv3D16 -me --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.0.LTS/include" --include_path="C:/Users/bob/Documents/Projects/induct_forge/RM57Lx_test/Project1_LAUNCHXL2_RM57L/hcg/include" --include_path="C:/Users/bob/Documents/Projects/induct_forge/RM57Lx_test/Project1_LAUNCHXL2_RM57L/demoapp/include" --include_path="C:/ti/Hercules/SafeTI Diagnostic Library/2.2.0/hal/include" --include_path="C:/ti/Hercules/SafeTI Diagnostic Library/2.2.0/safety_library/include" --define=_RM57Lx_ -g --diag_warning=225 --diag_wrap=off --display_error_number --enum_type=packed --abi=eabi --preproc_with_compile --preproc_dependency="demoapp/source/esm_application_callback.d" --obj_directory="demoapp/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

demoapp/source/misc.obj: ../demoapp/source/misc.asm $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.0.LTS/bin/armcl" -mv7R5 --code_state=32 --float_support=VFPv3D16 -me --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.0.LTS/include" --include_path="C:/Users/bob/Documents/Projects/induct_forge/RM57Lx_test/Project1_LAUNCHXL2_RM57L/hcg/include" --include_path="C:/Users/bob/Documents/Projects/induct_forge/RM57Lx_test/Project1_LAUNCHXL2_RM57L/demoapp/include" --include_path="C:/ti/Hercules/SafeTI Diagnostic Library/2.2.0/hal/include" --include_path="C:/ti/Hercules/SafeTI Diagnostic Library/2.2.0/safety_library/include" --define=_RM57Lx_ -g --diag_warning=225 --diag_wrap=off --display_error_number --enum_type=packed --abi=eabi --preproc_with_compile --preproc_dependency="demoapp/source/misc.d" --obj_directory="demoapp/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

demoapp/source/support_functions.obj: ../demoapp/source/support_functions.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.0.LTS/bin/armcl" -mv7R5 --code_state=32 --float_support=VFPv3D16 -me --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.0.LTS/include" --include_path="C:/Users/bob/Documents/Projects/induct_forge/RM57Lx_test/Project1_LAUNCHXL2_RM57L/hcg/include" --include_path="C:/Users/bob/Documents/Projects/induct_forge/RM57Lx_test/Project1_LAUNCHXL2_RM57L/demoapp/include" --include_path="C:/ti/Hercules/SafeTI Diagnostic Library/2.2.0/hal/include" --include_path="C:/ti/Hercules/SafeTI Diagnostic Library/2.2.0/safety_library/include" --define=_RM57Lx_ -g --diag_warning=225 --diag_wrap=off --display_error_number --enum_type=packed --abi=eabi --preproc_with_compile --preproc_dependency="demoapp/source/support_functions.d" --obj_directory="demoapp/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


