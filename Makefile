#---------------------------------------------------------------------------------------------------------------------
# TARGET is the name of the output.
# BUILD is the directory where object files & intermediate files will be placed.
# LIBBUTANO is the main directory of butano library (https://github.com/GValiente/butano).
# PYTHON is the path to the python interpreter.
# SOURCES is a list of directories containing source code.
# INCLUDES is a list of directories containing extra header files.
# DATA is a list of directories containing binary data.
# GRAPHICS is a list of files and directories containing files to be processed by grit.
# AUDIO is a list of files and directories containing files to be processed by mmutil.
# DMGAUDIO is a list of files and directories containing files to be processed by mod2gbt and s3m2gbt.
# ROMTITLE is a uppercase ASCII, max 12 characters text string containing the output ROM title.
# ROMCODE is a uppercase ASCII, max 4 characters text string containing the output ROM code.
# USERFLAGS is a list of additional compiler flags:
#     Pass -flto to enable link-time optimization.
#     Pass -O0 or -Og to try to make debugging work.
# USERCXXFLAGS is a list of additional compiler flags for C++ code only.
# USERASFLAGS is a list of additional assembler flags.
# USERLDFLAGS is a list of additional linker flags:
#     Pass -flto=<number_of_cpu_cores> to enable parallel link-time optimization.
# USERLIBDIRS is a list of additional directories containing libraries.
#     Each libraries directory must contains include and lib subdirectories.
# USERLIBS is a list of additional libraries to link with the project.
# DEFAULTLIBS links standard system libraries when it is not empty.
# STACKTRACE enables stack trace logging when it is not empty.
# USERBUILD is a list of additional directories to remove when cleaning the project.
# EXTTOOL is an optional command executed before processing audio, graphics and code files.
#
# All directories are specified relative to the project directory where the makefile is found.
#---------------------------------------------------------------------------------------------------------------------
TARGET      	:=  $(notdir $(CURDIR))
BUILD       	:=  build
LIBBUTANO   	:=  ../afska_butano/butano
PYTHON      	:=  python3
SOURCES     	:=  ../butano/common/src \
		    src \
                    src/gsmplayer \
                    src/gsmplayer/core \
                    src/savefile \
                    src/scripts \
		    src/sequence \
		    src/utils \
                    src/utils/gbfs
INCLUDES    	:=  include \
					include/sprite_metas \
					../butano/common/include
DATA        	:=  video
VIDEO			:=  video
GRAPHICS    	:=  graphics \
					graphics/bgs \
					graphics/event \
					graphics/characters/shizu \
					graphics/characters/misha \
                                        graphics/characters/emi \
					graphics/characters/rin \
                                        graphics/characters/lilly \
                                        graphics/characters/hanako \
                                        graphics/characters/kenji \
                                        graphics/characters/nurse \
                                        graphics/characters/yuuko \
					graphics/video/temp_emi_imgs/converted \
					../butano/common/graphics
AUDIO       	:=  audio
DMGAUDIO    	:=  dmg_audio
ROMTITLE    	:=  KATAWASHOUJO
ROMCODE     	:=  NPKS
USERFLAGS   	:=  # -Ofast -DBN_CFG_BGS_MAX_ITEMS=4 # -Ofast -Wno-unused-parameter -g0 -ffunction-sections -fdata-sections
USERCXXFLAGS	:=  # -fno-rtti -fno-exceptions -ffunction-sections -fdata-sections
USERASFLAGS 	:=  
USERLDFLAGS 	:=  -Wl,--print-memory-usage #-Wl,--gc-sections -Wl,--print-memory-usage
USERLIBDIRS 	:=  $(DEVKITPRO)/libgba
USERLIBS    	:=  -lmm -lgba
DEFAULTLIBS 	:=  false
STACKTRACE	:=	
USERBUILD   	:=  
EXTTOOL     	:=  

#---------------------------------------------------------------------------------------------------------------------
# Export absolute butano path:
#---------------------------------------------------------------------------------------------------------------------
ifndef LIBBUTANOABS
	export LIBBUTANOABS	:=	$(realpath $(LIBBUTANO))
endif

VIDEOBINFILES	:=	$(foreach dir,$(VIDEO),$(notdir $(wildcard $(dir)/*.*)))
# export OFILES_BIN := $(addsuffix .o,$(VIDEOBINFILES))
# export OFILES_SOURCES := $(CPPFILES:.cpp=.o) $(CFILES:.c=.o) $(SFILES:.s=.o)




#---------------------------------------------------------------------------------------------------------------------
# Include main makefile:
#---------------------------------------------------------------------------------------------------------------------
include $(LIBBUTANOABS)/butano.mak
# export OFILES := $(OFILES_BIN) $(OFILES)
# export OFILES := $(OFILES_BIN) $(OFILES)

#---------------------------------------------------------------------------------
# use CXX for linking C++ projects, CC for standard C
#---------------------------------------------------------------------------------
ifeq ($(strip $(CPPFILES)),)
#---------------------------------------------------------------------------------
	export LD	:=	$(CC)
#---------------------------------------------------------------------------------
else
#---------------------------------------------------------------------------------
	export LD	:=	$(CXX)
#---------------------------------------------------------------------------------
endif
#---------------------------------------------------------------------------------


#---------------------------------------------------------------------------------
# This rule links in binary data with the .bin extension
#---------------------------------------------------------------------------------
%.agmv.o %_agmv.h :	%.agmv
#---------------------------------------------------------------------------------
		@echo $(notdir $<)
		@$(bin2o)
