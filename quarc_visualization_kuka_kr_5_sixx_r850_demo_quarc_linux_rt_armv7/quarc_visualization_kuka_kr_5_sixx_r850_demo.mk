###########################################################################
## Makefile generated for component 'quarc_visualization_kuka_kr_5_sixx_r850_demo'. 
## 
## Makefile     : quarc_visualization_kuka_kr_5_sixx_r850_demo.mk
## Generated on : Tue Sep 24 18:06:18 2024
## Final product: $(RELATIVE_PATH_TO_ANCHOR)/quarc_visualization_kuka_kr_5_sixx_r850_demo.rt-linux_rt_armv7
## Product type : executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile

PRODUCT_NAME              = quarc_visualization_kuka_kr_5_sixx_r850_demo
MAKEFILE                  = quarc_visualization_kuka_kr_5_sixx_r850_demo.mk
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2023b
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2023b/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = E:/MTLB/SAFEOPTMA
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 1
TGT_FCN_LIB               = None
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0
RELATIVE_PATH_TO_ANCHOR   = ..
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          QUARC linux_rt_armv7 | gmake (64-bit Windows)
# Supported Version(s):    1.6.1
# ToolchainInfo Version:   2021b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# MINGW_DIR
# ldebug

#-----------
# MACROS
#-----------

TOOL_ROOT           = $(MINGW_DIR)/1.6.1
SYSROOT             = --sysroot=$(TOOL_ROOT)/sysroots/armv7a-vfp-neon-poky-linux-gnueabi
TOOL_BIN            = $(TOOL_ROOT)/sysroots/i686-pokysdk-mingw32/usr/bin/arm-poky-linux-gnueabi
GCC_WARN_OPTS       = -Wc,-Wall -Wc,-W -Wc,-Wwrite-strings -Wc,-Winline -Wc,-Wstrict-prototypes -Wc,-Wnested-externs -Wc,-Wpointer-arith -Wc,-Wcast-align
GCC_WARN_OPTS_MAX   = $(GCC_WARN_OPTS) -Wc,-Wcast-qual -Wc,-Wshadow
REQ_OPTS            = $(SYSROOT) -c -march=armv7-a -mthumb-interwork -mfloat-abi=softfp -mfpu=neon -mtune=cortex-a9 -Wall -fmessage-length=0 -MMD -MP -fpic -pipe -feliminate-unused-debug-types
QUARC_REQ_OPTS      = -DVXWORKS -DQUARC -D_GNU_SOURCE -DTARGET_TYPE=linux_rt_armv7 -D__LINUX_RT_ARMV7__
CFLAGS_ADDITIONAL   = $(ANSI_OPTS)
CPPFLAGS_ADDITIONAL = $(CPP_ANSI_OPTS)
QUARC_LDFLAGS       = $(SYSROOT) -Wl,--hash-style=gnu -Wl,--as-needed -L$(QUARC)/lib/linux_rt_armv7
QUARC_LIBS          = -lextmode_quarc_r2013b -lquanser_communications -lquanser_runtime -lquanser_common
QUARC_SYS_LIBS      = -lusb-1.0 -ludev -lrt -lpthread -ldl -lm

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = $(QUARC_LIBS) $(QUARC_SYS_LIBS)

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: MinGW QUARC C Cross-Compiler
CC_PATH = $(TOOL_BIN)
CC = "$(CC_PATH)/arm-poky-linux-gnueabi-gcc"

# Linker: MinGW QUARC C/C++ Linker
LD_PATH = $(TOOL_BIN)
LD = "$(LD_PATH)/arm-poky-linux-gnueabi-g++"

# C++ Compiler: MinGW QUARC C++ Cross-Compiler
CPP_PATH = $(TOOL_BIN)
CPP = "$(CPP_PATH)/arm-poky-linux-gnueabi-g++"

# C++ Linker: MinGW QUARC C/C++ Linker
CPP_LD_PATH = $(TOOL_BIN)
CPP_LD = "$(CPP_LD_PATH)/arm-poky-linux-gnueabi-g++"

# Archiver: MinGW QUARC C/C++ Archiver
AR_PATH = $(TOOL_BIN)
AR = "$(AR_PATH)/arm-poky-linux-gnueabi-ar"

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%\bin\win64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @del /F
ECHO                = @echo
MV                  = @move
RUN                 =

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              = ruvs
CFLAGS               = $(REQ_OPTS) $(QUARC_REQ_OPTS) $(CFLAGS_ADDITIONAL) \
                       -O  -DNDEBUG
CPPFLAGS             = $(REQ_OPTS) $(QUARC_REQ_OPTS) $(CPPFLAGS_ADDITIONAL) \
                       -O  -DNDEBUG
CPP_LDFLAGS          = $(ldebug) $(QUARC_LDFLAGS)
CPP_SHAREDLIB_LDFLAGS  = $(ldebug) $(QUARC_LDFLAGS) \
                         -shared
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              = $(ldebug) $(QUARC_LDFLAGS)
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = $(ldebug) $(QUARC_LDFLAGS) \
                       -shared



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/quarc_visualization_kuka_kr_5_sixx_r850_demo.rt-linux_rt_armv7
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR) -I$(START_DIR)/quarc_visualization_kuka_kr_5_sixx_r850_demo_quarc_linux_rt_armv7 -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include -I$(MATLAB_ROOT)/rtw/c/src -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common -I$(MATLAB_ROOT)/toolbox/coder/rtiostream/src -I$(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils -IC:/PROGRA~1/Quanser/QUARC/include

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_BUILD_ARGS = -DCLASSIC_INTERFACE=1 -DALLOCATIONFCN=0 -DEXT_MODE=1 -DMAT_FILE=0 -DONESTEPFCN=0 -DTERMFCN=1 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0
DEFINES_CUSTOM = 
DEFINES_OPTS = -DON_TARGET_WAIT_FOR_START=1 -DTID01EQ=0
DEFINES_QUARC = -DASSERTIONS=1 -DDOASSERTS
DEFINES_STANDARD = -DMODEL=quarc_visualization_kuka_kr_5_sixx_r850_demo -DNUMST=1 -DNCSTATES=0 -DHAVESTDIO -DRT -DUSE_RTMODEL

DEFINES = $(DEFINES_BUILD_ARGS) $(DEFINES_CUSTOM) $(DEFINES_OPTS) $(DEFINES_QUARC) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/quarc_visualization_kuka_kr_5_sixx_r850_demo_quarc_linux_rt_armv7/quarc_visualization_kuka_kr_5_sixx_r850_demo.c $(START_DIR)/quarc_visualization_kuka_kr_5_sixx_r850_demo_quarc_linux_rt_armv7/quarc_visualization_kuka_kr_5_sixx_r850_demo_data.c $(START_DIR)/quarc_visualization_kuka_kr_5_sixx_r850_demo_quarc_linux_rt_armv7/quarc_visualization_kuka_kr_5_sixx_r850_demo_main.c $(START_DIR)/quarc_visualization_kuka_kr_5_sixx_r850_demo_quarc_linux_rt_armv7/rtGetInf.c $(START_DIR)/quarc_visualization_kuka_kr_5_sixx_r850_demo_quarc_linux_rt_armv7/rtGetNaN.c $(START_DIR)/quarc_visualization_kuka_kr_5_sixx_r850_demo_quarc_linux_rt_armv7/rt_nonfinite.c $(MATLAB_ROOT)/rtw/c/src/rt_sim.c C:/PROGRA~1/Quanser/QUARC/quarc/src/ext_svr.c C:/PROGRA~1/Quanser/QUARC/quarc/src/updown.c C:/PROGRA~1/Quanser/QUARC/quarc/src/ext_work.c

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = quarc_visualization_kuka_kr_5_sixx_r850_demo.o quarc_visualization_kuka_kr_5_sixx_r850_demo_data.o quarc_visualization_kuka_kr_5_sixx_r850_demo_main.o rtGetInf.o rtGetNaN.o rt_nonfinite.o rt_sim.o ext_svr.o updown.o ext_work.o

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = C:/PROGRA~1/Quanser/QUARC/lib/LI8EF6~1/LI5A2F~1.A C:/PROGRA~1/Quanser/QUARC/lib/LI8EF6~1/LIBQUA~4.A C:/PROGRA~1/Quanser/QUARC/lib/LI8EF6~1/LIBQUA~1.A C:/PROGRA~1/Quanser/QUARC/lib/LI8EF6~1/LIBQUA~2.A C:/PROGRA~1/Quanser/QUARC/lib/LI8EF6~1/LID6D3~1.A C:/PROGRA~1/Quanser/QUARC/lib/LI8EF6~1/LIBQUA~3.A

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################


include $(QUARC)/include/gcc_c_dialect.mk


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS) $(LIBS)
	@echo "### Successfully generated all binary outputs."


prebuild : 


download : $(PRODUCT)


execute : download
	@echo "### Invoking postbuild tool "Execute" ..."
	$(EXECUTE) $(EXECUTE_FLAGS)
	@echo "### Done invoking postbuild tool."


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(LIBS)
	@echo "### Creating standalone executable "$(PRODUCT)" ..."
	$(LD) $(LDFLAGS) -o$(PRODUCT) $(OBJS) $(LIBS) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.o : %.c
	$(CC) $(CFLAGS) -o"$@" "$<"


%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o"$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o"$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o"$@" "$<"


%.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o"$@" "$<"


%.o : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o"$@" "$<"


%.o : $(START_DIR)/quarc_visualization_kuka_kr_5_sixx_r850_demo_quarc_linux_rt_armv7/%.c
	$(CC) $(CFLAGS) -o"$@" "$<"


%.o : $(START_DIR)/quarc_visualization_kuka_kr_5_sixx_r850_demo_quarc_linux_rt_armv7/%.cpp
	$(CPP) $(CPPFLAGS) -o"$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) -o"$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) $(CPPFLAGS) -o"$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(CFLAGS) -o"$@" "$<"


%.o : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CPP) $(CPPFLAGS) -o"$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.c
	$(CC) $(CFLAGS) -o"$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.cpp
	$(CPP) $(CPPFLAGS) -o"$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/%.c
	$(CC) $(CFLAGS) -o"$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/%.cpp
	$(CPP) $(CPPFLAGS) -o"$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/%.c
	$(CC) $(CFLAGS) -o"$@" "$<"


%.o : $(MATLAB_ROOT)/toolbox/coder/rtiostream/src/utils/%.cpp
	$(CPP) $(CPPFLAGS) -o"$@" "$<"


quarc_visualization_kuka_kr_5_sixx_r850_demo.o : $(START_DIR)/quarc_visualization_kuka_kr_5_sixx_r850_demo_quarc_linux_rt_armv7/quarc_visualization_kuka_kr_5_sixx_r850_demo.c
	$(CC) $(CFLAGS) -o"$@" "$<"


quarc_visualization_kuka_kr_5_sixx_r850_demo_data.o : $(START_DIR)/quarc_visualization_kuka_kr_5_sixx_r850_demo_quarc_linux_rt_armv7/quarc_visualization_kuka_kr_5_sixx_r850_demo_data.c
	$(CC) $(CFLAGS) -o"$@" "$<"


quarc_visualization_kuka_kr_5_sixx_r850_demo_main.o : $(START_DIR)/quarc_visualization_kuka_kr_5_sixx_r850_demo_quarc_linux_rt_armv7/quarc_visualization_kuka_kr_5_sixx_r850_demo_main.c
	$(CC) $(CFLAGS) -o"$@" "$<"


rtGetInf.o : $(START_DIR)/quarc_visualization_kuka_kr_5_sixx_r850_demo_quarc_linux_rt_armv7/rtGetInf.c
	$(CC) $(CFLAGS) -o"$@" "$<"


rtGetNaN.o : $(START_DIR)/quarc_visualization_kuka_kr_5_sixx_r850_demo_quarc_linux_rt_armv7/rtGetNaN.c
	$(CC) $(CFLAGS) -o"$@" "$<"


rt_nonfinite.o : $(START_DIR)/quarc_visualization_kuka_kr_5_sixx_r850_demo_quarc_linux_rt_armv7/rt_nonfinite.c
	$(CC) $(CFLAGS) -o"$@" "$<"


rt_sim.o : $(MATLAB_ROOT)/rtw/c/src/rt_sim.c
	$(CC) $(CFLAGS) -o"$@" "$<"


ext_svr.o : C:/PROGRA~1/Quanser/QUARC/quarc/src/ext_svr.c
	$(CC) $(CFLAGS) -o"$@" "$<"


updown.o : C:/PROGRA~1/Quanser/QUARC/quarc/src/updown.c
	$(CC) $(CFLAGS) -o"$@" "$<"


ext_work.o : C:/PROGRA~1/Quanser/QUARC/quarc/src/ext_work.c
	$(CC) $(CFLAGS) -o"$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files ..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(ECHO) "### Deleted all derived files."


