#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Final.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Final.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=PostBuildConfig.c main.c MCAL/Dio.c MCAL/Gpt.c MCAL/I2c.c MCAL/Port.c MCAL/Pwm.c MCAL/adc.c MCAL/interrupt.c EcuAL/Disp.c EcuAL/Eeprom.c EcuAL/TempSensor.c EcuAL/TempSystem.c OS/OS.c MCAL/Uart.c Det.c OS/OS2.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/PostBuildConfig.p1 ${OBJECTDIR}/main.p1 ${OBJECTDIR}/MCAL/Dio.p1 ${OBJECTDIR}/MCAL/Gpt.p1 ${OBJECTDIR}/MCAL/I2c.p1 ${OBJECTDIR}/MCAL/Port.p1 ${OBJECTDIR}/MCAL/Pwm.p1 ${OBJECTDIR}/MCAL/adc.p1 ${OBJECTDIR}/MCAL/interrupt.p1 ${OBJECTDIR}/EcuAL/Disp.p1 ${OBJECTDIR}/EcuAL/Eeprom.p1 ${OBJECTDIR}/EcuAL/TempSensor.p1 ${OBJECTDIR}/EcuAL/TempSystem.p1 ${OBJECTDIR}/OS/OS.p1 ${OBJECTDIR}/MCAL/Uart.p1 ${OBJECTDIR}/Det.p1 ${OBJECTDIR}/OS/OS2.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/PostBuildConfig.p1.d ${OBJECTDIR}/main.p1.d ${OBJECTDIR}/MCAL/Dio.p1.d ${OBJECTDIR}/MCAL/Gpt.p1.d ${OBJECTDIR}/MCAL/I2c.p1.d ${OBJECTDIR}/MCAL/Port.p1.d ${OBJECTDIR}/MCAL/Pwm.p1.d ${OBJECTDIR}/MCAL/adc.p1.d ${OBJECTDIR}/MCAL/interrupt.p1.d ${OBJECTDIR}/EcuAL/Disp.p1.d ${OBJECTDIR}/EcuAL/Eeprom.p1.d ${OBJECTDIR}/EcuAL/TempSensor.p1.d ${OBJECTDIR}/EcuAL/TempSystem.p1.d ${OBJECTDIR}/OS/OS.p1.d ${OBJECTDIR}/MCAL/Uart.p1.d ${OBJECTDIR}/Det.p1.d ${OBJECTDIR}/OS/OS2.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/PostBuildConfig.p1 ${OBJECTDIR}/main.p1 ${OBJECTDIR}/MCAL/Dio.p1 ${OBJECTDIR}/MCAL/Gpt.p1 ${OBJECTDIR}/MCAL/I2c.p1 ${OBJECTDIR}/MCAL/Port.p1 ${OBJECTDIR}/MCAL/Pwm.p1 ${OBJECTDIR}/MCAL/adc.p1 ${OBJECTDIR}/MCAL/interrupt.p1 ${OBJECTDIR}/EcuAL/Disp.p1 ${OBJECTDIR}/EcuAL/Eeprom.p1 ${OBJECTDIR}/EcuAL/TempSensor.p1 ${OBJECTDIR}/EcuAL/TempSystem.p1 ${OBJECTDIR}/OS/OS.p1 ${OBJECTDIR}/MCAL/Uart.p1 ${OBJECTDIR}/Det.p1 ${OBJECTDIR}/OS/OS2.p1

# Source Files
SOURCEFILES=PostBuildConfig.c main.c MCAL/Dio.c MCAL/Gpt.c MCAL/I2c.c MCAL/Port.c MCAL/Pwm.c MCAL/adc.c MCAL/interrupt.c EcuAL/Disp.c EcuAL/Eeprom.c EcuAL/TempSensor.c EcuAL/TempSystem.c OS/OS.c MCAL/Uart.c Det.c OS/OS2.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Final.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=16F877A
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/PostBuildConfig.p1: PostBuildConfig.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/PostBuildConfig.p1.d 
	@${RM} ${OBJECTDIR}/PostBuildConfig.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -Os -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/PostBuildConfig.p1 PostBuildConfig.c 
	@-${MV} ${OBJECTDIR}/PostBuildConfig.d ${OBJECTDIR}/PostBuildConfig.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/PostBuildConfig.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -Os -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/main.p1 main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Dio.p1: MCAL/Dio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/MCAL" 
	@${RM} ${OBJECTDIR}/MCAL/Dio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Dio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -Os -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL/Dio.p1 MCAL/Dio.c 
	@-${MV} ${OBJECTDIR}/MCAL/Dio.d ${OBJECTDIR}/MCAL/Dio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Dio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Gpt.p1: MCAL/Gpt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/MCAL" 
	@${RM} ${OBJECTDIR}/MCAL/Gpt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Gpt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -Os -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL/Gpt.p1 MCAL/Gpt.c 
	@-${MV} ${OBJECTDIR}/MCAL/Gpt.d ${OBJECTDIR}/MCAL/Gpt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Gpt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/I2c.p1: MCAL/I2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/MCAL" 
	@${RM} ${OBJECTDIR}/MCAL/I2c.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/I2c.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -Os -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL/I2c.p1 MCAL/I2c.c 
	@-${MV} ${OBJECTDIR}/MCAL/I2c.d ${OBJECTDIR}/MCAL/I2c.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/I2c.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Port.p1: MCAL/Port.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/MCAL" 
	@${RM} ${OBJECTDIR}/MCAL/Port.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Port.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -Os -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL/Port.p1 MCAL/Port.c 
	@-${MV} ${OBJECTDIR}/MCAL/Port.d ${OBJECTDIR}/MCAL/Port.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Port.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Pwm.p1: MCAL/Pwm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/MCAL" 
	@${RM} ${OBJECTDIR}/MCAL/Pwm.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Pwm.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -Os -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL/Pwm.p1 MCAL/Pwm.c 
	@-${MV} ${OBJECTDIR}/MCAL/Pwm.d ${OBJECTDIR}/MCAL/Pwm.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Pwm.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/adc.p1: MCAL/adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/MCAL" 
	@${RM} ${OBJECTDIR}/MCAL/adc.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -Os -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL/adc.p1 MCAL/adc.c 
	@-${MV} ${OBJECTDIR}/MCAL/adc.d ${OBJECTDIR}/MCAL/adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/interrupt.p1: MCAL/interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/MCAL" 
	@${RM} ${OBJECTDIR}/MCAL/interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -Os -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL/interrupt.p1 MCAL/interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL/interrupt.d ${OBJECTDIR}/MCAL/interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/EcuAL/Disp.p1: EcuAL/Disp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/EcuAL" 
	@${RM} ${OBJECTDIR}/EcuAL/Disp.p1.d 
	@${RM} ${OBJECTDIR}/EcuAL/Disp.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -Os -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/EcuAL/Disp.p1 EcuAL/Disp.c 
	@-${MV} ${OBJECTDIR}/EcuAL/Disp.d ${OBJECTDIR}/EcuAL/Disp.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/EcuAL/Disp.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/EcuAL/Eeprom.p1: EcuAL/Eeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/EcuAL" 
	@${RM} ${OBJECTDIR}/EcuAL/Eeprom.p1.d 
	@${RM} ${OBJECTDIR}/EcuAL/Eeprom.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -Os -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/EcuAL/Eeprom.p1 EcuAL/Eeprom.c 
	@-${MV} ${OBJECTDIR}/EcuAL/Eeprom.d ${OBJECTDIR}/EcuAL/Eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/EcuAL/Eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/EcuAL/TempSensor.p1: EcuAL/TempSensor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/EcuAL" 
	@${RM} ${OBJECTDIR}/EcuAL/TempSensor.p1.d 
	@${RM} ${OBJECTDIR}/EcuAL/TempSensor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -Os -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/EcuAL/TempSensor.p1 EcuAL/TempSensor.c 
	@-${MV} ${OBJECTDIR}/EcuAL/TempSensor.d ${OBJECTDIR}/EcuAL/TempSensor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/EcuAL/TempSensor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/EcuAL/TempSystem.p1: EcuAL/TempSystem.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/EcuAL" 
	@${RM} ${OBJECTDIR}/EcuAL/TempSystem.p1.d 
	@${RM} ${OBJECTDIR}/EcuAL/TempSystem.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -Os -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/EcuAL/TempSystem.p1 EcuAL/TempSystem.c 
	@-${MV} ${OBJECTDIR}/EcuAL/TempSystem.d ${OBJECTDIR}/EcuAL/TempSystem.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/EcuAL/TempSystem.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/OS/OS.p1: OS/OS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/OS" 
	@${RM} ${OBJECTDIR}/OS/OS.p1.d 
	@${RM} ${OBJECTDIR}/OS/OS.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -Os -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/OS/OS.p1 OS/OS.c 
	@-${MV} ${OBJECTDIR}/OS/OS.d ${OBJECTDIR}/OS/OS.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/OS/OS.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Uart.p1: MCAL/Uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/MCAL" 
	@${RM} ${OBJECTDIR}/MCAL/Uart.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Uart.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -Os -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL/Uart.p1 MCAL/Uart.c 
	@-${MV} ${OBJECTDIR}/MCAL/Uart.d ${OBJECTDIR}/MCAL/Uart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Uart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Det.p1: Det.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Det.p1.d 
	@${RM} ${OBJECTDIR}/Det.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -Os -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/Det.p1 Det.c 
	@-${MV} ${OBJECTDIR}/Det.d ${OBJECTDIR}/Det.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Det.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/OS/OS2.p1: OS/OS2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/OS" 
	@${RM} ${OBJECTDIR}/OS/OS2.p1.d 
	@${RM} ${OBJECTDIR}/OS/OS2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -Os -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/OS/OS2.p1 OS/OS2.c 
	@-${MV} ${OBJECTDIR}/OS/OS2.d ${OBJECTDIR}/OS/OS2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/OS/OS2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/PostBuildConfig.p1: PostBuildConfig.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/PostBuildConfig.p1.d 
	@${RM} ${OBJECTDIR}/PostBuildConfig.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -Os -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/PostBuildConfig.p1 PostBuildConfig.c 
	@-${MV} ${OBJECTDIR}/PostBuildConfig.d ${OBJECTDIR}/PostBuildConfig.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/PostBuildConfig.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -Os -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/main.p1 main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Dio.p1: MCAL/Dio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/MCAL" 
	@${RM} ${OBJECTDIR}/MCAL/Dio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Dio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -Os -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL/Dio.p1 MCAL/Dio.c 
	@-${MV} ${OBJECTDIR}/MCAL/Dio.d ${OBJECTDIR}/MCAL/Dio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Dio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Gpt.p1: MCAL/Gpt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/MCAL" 
	@${RM} ${OBJECTDIR}/MCAL/Gpt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Gpt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -Os -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL/Gpt.p1 MCAL/Gpt.c 
	@-${MV} ${OBJECTDIR}/MCAL/Gpt.d ${OBJECTDIR}/MCAL/Gpt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Gpt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/I2c.p1: MCAL/I2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/MCAL" 
	@${RM} ${OBJECTDIR}/MCAL/I2c.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/I2c.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -Os -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL/I2c.p1 MCAL/I2c.c 
	@-${MV} ${OBJECTDIR}/MCAL/I2c.d ${OBJECTDIR}/MCAL/I2c.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/I2c.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Port.p1: MCAL/Port.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/MCAL" 
	@${RM} ${OBJECTDIR}/MCAL/Port.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Port.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -Os -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL/Port.p1 MCAL/Port.c 
	@-${MV} ${OBJECTDIR}/MCAL/Port.d ${OBJECTDIR}/MCAL/Port.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Port.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Pwm.p1: MCAL/Pwm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/MCAL" 
	@${RM} ${OBJECTDIR}/MCAL/Pwm.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Pwm.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -Os -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL/Pwm.p1 MCAL/Pwm.c 
	@-${MV} ${OBJECTDIR}/MCAL/Pwm.d ${OBJECTDIR}/MCAL/Pwm.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Pwm.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/adc.p1: MCAL/adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/MCAL" 
	@${RM} ${OBJECTDIR}/MCAL/adc.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -Os -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL/adc.p1 MCAL/adc.c 
	@-${MV} ${OBJECTDIR}/MCAL/adc.d ${OBJECTDIR}/MCAL/adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/interrupt.p1: MCAL/interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/MCAL" 
	@${RM} ${OBJECTDIR}/MCAL/interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -Os -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL/interrupt.p1 MCAL/interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL/interrupt.d ${OBJECTDIR}/MCAL/interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/EcuAL/Disp.p1: EcuAL/Disp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/EcuAL" 
	@${RM} ${OBJECTDIR}/EcuAL/Disp.p1.d 
	@${RM} ${OBJECTDIR}/EcuAL/Disp.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -Os -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/EcuAL/Disp.p1 EcuAL/Disp.c 
	@-${MV} ${OBJECTDIR}/EcuAL/Disp.d ${OBJECTDIR}/EcuAL/Disp.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/EcuAL/Disp.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/EcuAL/Eeprom.p1: EcuAL/Eeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/EcuAL" 
	@${RM} ${OBJECTDIR}/EcuAL/Eeprom.p1.d 
	@${RM} ${OBJECTDIR}/EcuAL/Eeprom.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -Os -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/EcuAL/Eeprom.p1 EcuAL/Eeprom.c 
	@-${MV} ${OBJECTDIR}/EcuAL/Eeprom.d ${OBJECTDIR}/EcuAL/Eeprom.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/EcuAL/Eeprom.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/EcuAL/TempSensor.p1: EcuAL/TempSensor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/EcuAL" 
	@${RM} ${OBJECTDIR}/EcuAL/TempSensor.p1.d 
	@${RM} ${OBJECTDIR}/EcuAL/TempSensor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -Os -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/EcuAL/TempSensor.p1 EcuAL/TempSensor.c 
	@-${MV} ${OBJECTDIR}/EcuAL/TempSensor.d ${OBJECTDIR}/EcuAL/TempSensor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/EcuAL/TempSensor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/EcuAL/TempSystem.p1: EcuAL/TempSystem.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/EcuAL" 
	@${RM} ${OBJECTDIR}/EcuAL/TempSystem.p1.d 
	@${RM} ${OBJECTDIR}/EcuAL/TempSystem.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -Os -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/EcuAL/TempSystem.p1 EcuAL/TempSystem.c 
	@-${MV} ${OBJECTDIR}/EcuAL/TempSystem.d ${OBJECTDIR}/EcuAL/TempSystem.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/EcuAL/TempSystem.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/OS/OS.p1: OS/OS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/OS" 
	@${RM} ${OBJECTDIR}/OS/OS.p1.d 
	@${RM} ${OBJECTDIR}/OS/OS.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -Os -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/OS/OS.p1 OS/OS.c 
	@-${MV} ${OBJECTDIR}/OS/OS.d ${OBJECTDIR}/OS/OS.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/OS/OS.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Uart.p1: MCAL/Uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/MCAL" 
	@${RM} ${OBJECTDIR}/MCAL/Uart.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Uart.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -Os -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL/Uart.p1 MCAL/Uart.c 
	@-${MV} ${OBJECTDIR}/MCAL/Uart.d ${OBJECTDIR}/MCAL/Uart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Uart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Det.p1: Det.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Det.p1.d 
	@${RM} ${OBJECTDIR}/Det.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -Os -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/Det.p1 Det.c 
	@-${MV} ${OBJECTDIR}/Det.d ${OBJECTDIR}/Det.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Det.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/OS/OS2.p1: OS/OS2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/OS" 
	@${RM} ${OBJECTDIR}/OS/OS2.p1.d 
	@${RM} ${OBJECTDIR}/OS/OS2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -Os -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall $(COMPARISON_BUILD)  -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/OS/OS2.p1 OS/OS2.c 
	@-${MV} ${OBJECTDIR}/OS/OS2.d ${OBJECTDIR}/OS/OS2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/OS/OS2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Final.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/Final.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -Os -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -std=c99 -gdwarf-3 -mstack=compiled:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/Final.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/Final.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Final.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/Final.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -Os -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -std=c99 -gdwarf-3 -mstack=compiled:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/Final.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
