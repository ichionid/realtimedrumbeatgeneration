#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/State.o \
	${OBJECTDIR}/RawNote.o \
	${OBJECTDIR}/RAtestMain.o \
	${OBJECTDIR}/MarkovEngineConsumer.o \
	${OBJECTDIR}/Calibrator.o \
	${OBJECTDIR}/Rhythm_automata.o \
	${OBJECTDIR}/CustomNumberDist.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/MidiHandlerProducer.o \
	${OBJECTDIR}/LetterPattern.o \
	${OBJECTDIR}/Helper.o \
	${OBJECTDIR}/DrumMachine.o \
	${OBJECTDIR}/Letter.o \
	${OBJECTDIR}/Meter.o \
	${OBJECTDIR}/RealTimeIOMain.o \
	${OBJECTDIR}/DrumMachineMain.o \
	${OBJECTDIR}/CRC.o \
	${OBJECTDIR}/VOMC.o \
	${OBJECTDIR}/Metronome.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f9

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-D__LINUX_ALSA__ -D__LITTLE_ENDIAN__ -I/usr/local -L/usr/local/lib/ -L/alsa/ -lasound -lpthread -lstk
CXXFLAGS=-D__LINUX_ALSA__ -D__LITTLE_ENDIAN__ -I/usr/local -L/usr/local/lib/ -L/alsa/ -lasound -lpthread -lstk

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/usr/local/lib -L/usr/local/rtmidi-2.0.1/include -L/usr/local/rtmidi-2.0.1/tests/Release -lboost_thread -lboost_system /lib/i386-linux-gnu/libpthread-2.15.so /lib/i386-linux-gnu/libthread_db.so.1 -lrtmidi /usr/lib/libstk.a

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${TESTDIR}/TestFiles/f8

${TESTDIR}/TestFiles/f8: /lib/i386-linux-gnu/libpthread-2.15.so

${TESTDIR}/TestFiles/f8: /lib/i386-linux-gnu/libthread_db.so.1

${TESTDIR}/TestFiles/f8: /usr/lib/libstk.a

${TESTDIR}/TestFiles/f8: ${OBJECTFILES}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f8 ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/State.o: State.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local -I/usr/local/rtmidi-2.0.1 -I/usr/local/rtmidi-2.0.1/include -I/usr/local/stk-4.4.3/include -I/usr/local/stk-4.4.3/src/include -I/usr/local/stk-4.4.3 -I. -I. -I. -I. -I. -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/State.o State.cpp

${OBJECTDIR}/RawNote.o: RawNote.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local -I/usr/local/rtmidi-2.0.1 -I/usr/local/rtmidi-2.0.1/include -I/usr/local/stk-4.4.3/include -I/usr/local/stk-4.4.3/src/include -I/usr/local/stk-4.4.3 -I. -I. -I. -I. -I. -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/RawNote.o RawNote.cpp

${OBJECTDIR}/RAtestMain.o: RAtestMain.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local -I/usr/local/rtmidi-2.0.1 -I/usr/local/rtmidi-2.0.1/include -I/usr/local/stk-4.4.3/include -I/usr/local/stk-4.4.3/src/include -I/usr/local/stk-4.4.3 -I. -I. -I. -I. -I. -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/RAtestMain.o RAtestMain.cpp

${OBJECTDIR}/MarkovEngineConsumer.o: MarkovEngineConsumer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local -I/usr/local/rtmidi-2.0.1 -I/usr/local/rtmidi-2.0.1/include -I/usr/local/stk-4.4.3/include -I/usr/local/stk-4.4.3/src/include -I/usr/local/stk-4.4.3 -I. -I. -I. -I. -I. -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/MarkovEngineConsumer.o MarkovEngineConsumer.cpp

${OBJECTDIR}/Calibrator.o: Calibrator.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local -I/usr/local/rtmidi-2.0.1 -I/usr/local/rtmidi-2.0.1/include -I/usr/local/stk-4.4.3/include -I/usr/local/stk-4.4.3/src/include -I/usr/local/stk-4.4.3 -I. -I. -I. -I. -I. -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Calibrator.o Calibrator.cpp

${OBJECTDIR}/Rhythm_automata.o: Rhythm_automata.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local -I/usr/local/rtmidi-2.0.1 -I/usr/local/rtmidi-2.0.1/include -I/usr/local/stk-4.4.3/include -I/usr/local/stk-4.4.3/src/include -I/usr/local/stk-4.4.3 -I. -I. -I. -I. -I. -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Rhythm_automata.o Rhythm_automata.cpp

${OBJECTDIR}/CustomNumberDist.o: CustomNumberDist.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local -I/usr/local/rtmidi-2.0.1 -I/usr/local/rtmidi-2.0.1/include -I/usr/local/stk-4.4.3/include -I/usr/local/stk-4.4.3/src/include -I/usr/local/stk-4.4.3 -I. -I. -I. -I. -I. -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/CustomNumberDist.o CustomNumberDist.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local -I/usr/local/rtmidi-2.0.1 -I/usr/local/rtmidi-2.0.1/include -I/usr/local/stk-4.4.3/include -I/usr/local/stk-4.4.3/src/include -I/usr/local/stk-4.4.3 -I. -I. -I. -I. -I. -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/MidiHandlerProducer.o: MidiHandlerProducer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local -I/usr/local/rtmidi-2.0.1 -I/usr/local/rtmidi-2.0.1/include -I/usr/local/stk-4.4.3/include -I/usr/local/stk-4.4.3/src/include -I/usr/local/stk-4.4.3 -I. -I. -I. -I. -I. -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/MidiHandlerProducer.o MidiHandlerProducer.cpp

${OBJECTDIR}/LetterPattern.o: LetterPattern.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local -I/usr/local/rtmidi-2.0.1 -I/usr/local/rtmidi-2.0.1/include -I/usr/local/stk-4.4.3/include -I/usr/local/stk-4.4.3/src/include -I/usr/local/stk-4.4.3 -I. -I. -I. -I. -I. -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/LetterPattern.o LetterPattern.cpp

${OBJECTDIR}/Helper.o: Helper.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local -I/usr/local/rtmidi-2.0.1 -I/usr/local/rtmidi-2.0.1/include -I/usr/local/stk-4.4.3/include -I/usr/local/stk-4.4.3/src/include -I/usr/local/stk-4.4.3 -I. -I. -I. -I. -I. -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Helper.o Helper.cpp

${OBJECTDIR}/DrumMachine.o: DrumMachine.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local -I/usr/local/rtmidi-2.0.1 -I/usr/local/rtmidi-2.0.1/include -I/usr/local/stk-4.4.3/include -I/usr/local/stk-4.4.3/src/include -I/usr/local/stk-4.4.3 -I. -I. -I. -I. -I. -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/DrumMachine.o DrumMachine.cpp

${OBJECTDIR}/Letter.o: Letter.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local -I/usr/local/rtmidi-2.0.1 -I/usr/local/rtmidi-2.0.1/include -I/usr/local/stk-4.4.3/include -I/usr/local/stk-4.4.3/src/include -I/usr/local/stk-4.4.3 -I. -I. -I. -I. -I. -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Letter.o Letter.cpp

${OBJECTDIR}/Meter.o: Meter.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local -I/usr/local/rtmidi-2.0.1 -I/usr/local/rtmidi-2.0.1/include -I/usr/local/stk-4.4.3/include -I/usr/local/stk-4.4.3/src/include -I/usr/local/stk-4.4.3 -I. -I. -I. -I. -I. -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Meter.o Meter.cpp

${OBJECTDIR}/RealTimeIOMain.o: RealTimeIOMain.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local -I/usr/local/rtmidi-2.0.1 -I/usr/local/rtmidi-2.0.1/include -I/usr/local/stk-4.4.3/include -I/usr/local/stk-4.4.3/src/include -I/usr/local/stk-4.4.3 -I. -I. -I. -I. -I. -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/RealTimeIOMain.o RealTimeIOMain.cpp

${OBJECTDIR}/DrumMachineMain.o: DrumMachineMain.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local -I/usr/local/rtmidi-2.0.1 -I/usr/local/rtmidi-2.0.1/include -I/usr/local/stk-4.4.3/include -I/usr/local/stk-4.4.3/src/include -I/usr/local/stk-4.4.3 -I. -I. -I. -I. -I. -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/DrumMachineMain.o DrumMachineMain.cpp

${OBJECTDIR}/CRC.o: CRC.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local -I/usr/local/rtmidi-2.0.1 -I/usr/local/rtmidi-2.0.1/include -I/usr/local/stk-4.4.3/include -I/usr/local/stk-4.4.3/src/include -I/usr/local/stk-4.4.3 -I. -I. -I. -I. -I. -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/CRC.o CRC.cpp

${OBJECTDIR}/VOMC.o: VOMC.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local -I/usr/local/rtmidi-2.0.1 -I/usr/local/rtmidi-2.0.1/include -I/usr/local/stk-4.4.3/include -I/usr/local/stk-4.4.3/src/include -I/usr/local/stk-4.4.3 -I. -I. -I. -I. -I. -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/VOMC.o VOMC.cpp

${OBJECTDIR}/Metronome.o: Metronome.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local -I/usr/local/rtmidi-2.0.1 -I/usr/local/rtmidi-2.0.1/include -I/usr/local/stk-4.4.3/include -I/usr/local/stk-4.4.3/src/include -I/usr/local/stk-4.4.3 -I. -I. -I. -I. -I. -I. -I. -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Metronome.o Metronome.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f9: ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f9 $^ ${LDLIBSOPTIONS} 


${OBJECTDIR}/State_nomain.o: ${OBJECTDIR}/State.o State.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/State.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local -I/usr/local/rtmidi-2.0.1 -I/usr/local/rtmidi-2.0.1/include -I/usr/local/stk-4.4.3/include -I/usr/local/stk-4.4.3/src/include -I/usr/local/stk-4.4.3 -I. -I. -I. -I. -I. -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/State_nomain.o State.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/State.o ${OBJECTDIR}/State_nomain.o;\
	fi

${OBJECTDIR}/RawNote_nomain.o: ${OBJECTDIR}/RawNote.o RawNote.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/RawNote.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local -I/usr/local/rtmidi-2.0.1 -I/usr/local/rtmidi-2.0.1/include -I/usr/local/stk-4.4.3/include -I/usr/local/stk-4.4.3/src/include -I/usr/local/stk-4.4.3 -I. -I. -I. -I. -I. -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/RawNote_nomain.o RawNote.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/RawNote.o ${OBJECTDIR}/RawNote_nomain.o;\
	fi

${OBJECTDIR}/RAtestMain_nomain.o: ${OBJECTDIR}/RAtestMain.o RAtestMain.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/RAtestMain.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local -I/usr/local/rtmidi-2.0.1 -I/usr/local/rtmidi-2.0.1/include -I/usr/local/stk-4.4.3/include -I/usr/local/stk-4.4.3/src/include -I/usr/local/stk-4.4.3 -I. -I. -I. -I. -I. -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/RAtestMain_nomain.o RAtestMain.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/RAtestMain.o ${OBJECTDIR}/RAtestMain_nomain.o;\
	fi

${OBJECTDIR}/MarkovEngineConsumer_nomain.o: ${OBJECTDIR}/MarkovEngineConsumer.o MarkovEngineConsumer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/MarkovEngineConsumer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local -I/usr/local/rtmidi-2.0.1 -I/usr/local/rtmidi-2.0.1/include -I/usr/local/stk-4.4.3/include -I/usr/local/stk-4.4.3/src/include -I/usr/local/stk-4.4.3 -I. -I. -I. -I. -I. -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/MarkovEngineConsumer_nomain.o MarkovEngineConsumer.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/MarkovEngineConsumer.o ${OBJECTDIR}/MarkovEngineConsumer_nomain.o;\
	fi

${OBJECTDIR}/Calibrator_nomain.o: ${OBJECTDIR}/Calibrator.o Calibrator.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Calibrator.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local -I/usr/local/rtmidi-2.0.1 -I/usr/local/rtmidi-2.0.1/include -I/usr/local/stk-4.4.3/include -I/usr/local/stk-4.4.3/src/include -I/usr/local/stk-4.4.3 -I. -I. -I. -I. -I. -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Calibrator_nomain.o Calibrator.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Calibrator.o ${OBJECTDIR}/Calibrator_nomain.o;\
	fi

${OBJECTDIR}/Rhythm_automata_nomain.o: ${OBJECTDIR}/Rhythm_automata.o Rhythm_automata.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Rhythm_automata.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local -I/usr/local/rtmidi-2.0.1 -I/usr/local/rtmidi-2.0.1/include -I/usr/local/stk-4.4.3/include -I/usr/local/stk-4.4.3/src/include -I/usr/local/stk-4.4.3 -I. -I. -I. -I. -I. -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Rhythm_automata_nomain.o Rhythm_automata.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Rhythm_automata.o ${OBJECTDIR}/Rhythm_automata_nomain.o;\
	fi

${OBJECTDIR}/CustomNumberDist_nomain.o: ${OBJECTDIR}/CustomNumberDist.o CustomNumberDist.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/CustomNumberDist.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local -I/usr/local/rtmidi-2.0.1 -I/usr/local/rtmidi-2.0.1/include -I/usr/local/stk-4.4.3/include -I/usr/local/stk-4.4.3/src/include -I/usr/local/stk-4.4.3 -I. -I. -I. -I. -I. -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/CustomNumberDist_nomain.o CustomNumberDist.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/CustomNumberDist.o ${OBJECTDIR}/CustomNumberDist_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local -I/usr/local/rtmidi-2.0.1 -I/usr/local/rtmidi-2.0.1/include -I/usr/local/stk-4.4.3/include -I/usr/local/stk-4.4.3/src/include -I/usr/local/stk-4.4.3 -I. -I. -I. -I. -I. -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/main_nomain.o main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

${OBJECTDIR}/MidiHandlerProducer_nomain.o: ${OBJECTDIR}/MidiHandlerProducer.o MidiHandlerProducer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/MidiHandlerProducer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local -I/usr/local/rtmidi-2.0.1 -I/usr/local/rtmidi-2.0.1/include -I/usr/local/stk-4.4.3/include -I/usr/local/stk-4.4.3/src/include -I/usr/local/stk-4.4.3 -I. -I. -I. -I. -I. -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/MidiHandlerProducer_nomain.o MidiHandlerProducer.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/MidiHandlerProducer.o ${OBJECTDIR}/MidiHandlerProducer_nomain.o;\
	fi

${OBJECTDIR}/LetterPattern_nomain.o: ${OBJECTDIR}/LetterPattern.o LetterPattern.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/LetterPattern.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local -I/usr/local/rtmidi-2.0.1 -I/usr/local/rtmidi-2.0.1/include -I/usr/local/stk-4.4.3/include -I/usr/local/stk-4.4.3/src/include -I/usr/local/stk-4.4.3 -I. -I. -I. -I. -I. -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/LetterPattern_nomain.o LetterPattern.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/LetterPattern.o ${OBJECTDIR}/LetterPattern_nomain.o;\
	fi

${OBJECTDIR}/Helper_nomain.o: ${OBJECTDIR}/Helper.o Helper.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Helper.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local -I/usr/local/rtmidi-2.0.1 -I/usr/local/rtmidi-2.0.1/include -I/usr/local/stk-4.4.3/include -I/usr/local/stk-4.4.3/src/include -I/usr/local/stk-4.4.3 -I. -I. -I. -I. -I. -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Helper_nomain.o Helper.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Helper.o ${OBJECTDIR}/Helper_nomain.o;\
	fi

${OBJECTDIR}/DrumMachine_nomain.o: ${OBJECTDIR}/DrumMachine.o DrumMachine.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/DrumMachine.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local -I/usr/local/rtmidi-2.0.1 -I/usr/local/rtmidi-2.0.1/include -I/usr/local/stk-4.4.3/include -I/usr/local/stk-4.4.3/src/include -I/usr/local/stk-4.4.3 -I. -I. -I. -I. -I. -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/DrumMachine_nomain.o DrumMachine.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/DrumMachine.o ${OBJECTDIR}/DrumMachine_nomain.o;\
	fi

${OBJECTDIR}/Letter_nomain.o: ${OBJECTDIR}/Letter.o Letter.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Letter.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local -I/usr/local/rtmidi-2.0.1 -I/usr/local/rtmidi-2.0.1/include -I/usr/local/stk-4.4.3/include -I/usr/local/stk-4.4.3/src/include -I/usr/local/stk-4.4.3 -I. -I. -I. -I. -I. -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Letter_nomain.o Letter.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Letter.o ${OBJECTDIR}/Letter_nomain.o;\
	fi

${OBJECTDIR}/Meter_nomain.o: ${OBJECTDIR}/Meter.o Meter.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Meter.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local -I/usr/local/rtmidi-2.0.1 -I/usr/local/rtmidi-2.0.1/include -I/usr/local/stk-4.4.3/include -I/usr/local/stk-4.4.3/src/include -I/usr/local/stk-4.4.3 -I. -I. -I. -I. -I. -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Meter_nomain.o Meter.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Meter.o ${OBJECTDIR}/Meter_nomain.o;\
	fi

${OBJECTDIR}/RealTimeIOMain_nomain.o: ${OBJECTDIR}/RealTimeIOMain.o RealTimeIOMain.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/RealTimeIOMain.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local -I/usr/local/rtmidi-2.0.1 -I/usr/local/rtmidi-2.0.1/include -I/usr/local/stk-4.4.3/include -I/usr/local/stk-4.4.3/src/include -I/usr/local/stk-4.4.3 -I. -I. -I. -I. -I. -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/RealTimeIOMain_nomain.o RealTimeIOMain.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/RealTimeIOMain.o ${OBJECTDIR}/RealTimeIOMain_nomain.o;\
	fi

${OBJECTDIR}/DrumMachineMain_nomain.o: ${OBJECTDIR}/DrumMachineMain.o DrumMachineMain.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/DrumMachineMain.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local -I/usr/local/rtmidi-2.0.1 -I/usr/local/rtmidi-2.0.1/include -I/usr/local/stk-4.4.3/include -I/usr/local/stk-4.4.3/src/include -I/usr/local/stk-4.4.3 -I. -I. -I. -I. -I. -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/DrumMachineMain_nomain.o DrumMachineMain.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/DrumMachineMain.o ${OBJECTDIR}/DrumMachineMain_nomain.o;\
	fi

${OBJECTDIR}/CRC_nomain.o: ${OBJECTDIR}/CRC.o CRC.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/CRC.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local -I/usr/local/rtmidi-2.0.1 -I/usr/local/rtmidi-2.0.1/include -I/usr/local/stk-4.4.3/include -I/usr/local/stk-4.4.3/src/include -I/usr/local/stk-4.4.3 -I. -I. -I. -I. -I. -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/CRC_nomain.o CRC.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/CRC.o ${OBJECTDIR}/CRC_nomain.o;\
	fi

${OBJECTDIR}/VOMC_nomain.o: ${OBJECTDIR}/VOMC.o VOMC.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/VOMC.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local -I/usr/local/rtmidi-2.0.1 -I/usr/local/rtmidi-2.0.1/include -I/usr/local/stk-4.4.3/include -I/usr/local/stk-4.4.3/src/include -I/usr/local/stk-4.4.3 -I. -I. -I. -I. -I. -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/VOMC_nomain.o VOMC.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/VOMC.o ${OBJECTDIR}/VOMC_nomain.o;\
	fi

${OBJECTDIR}/Metronome_nomain.o: ${OBJECTDIR}/Metronome.o Metronome.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Metronome.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local -I/usr/local/rtmidi-2.0.1 -I/usr/local/rtmidi-2.0.1/include -I/usr/local/stk-4.4.3/include -I/usr/local/stk-4.4.3/src/include -I/usr/local/stk-4.4.3 -I. -I. -I. -I. -I. -I. -I. -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Metronome_nomain.o Metronome.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Metronome.o ${OBJECTDIR}/Metronome_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f9 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${TESTDIR}/TestFiles/f8

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
