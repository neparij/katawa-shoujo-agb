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

ifndef LIBSAVGBAABS
	export LIBSAVGBAABS	:=	$(realpath ../libsavgba)
endif

TARGET      	:=  $(notdir $(CURDIR))
LANGUAGE		?=  en
BUILD       	:=  build
LIBBUTANO   	:=  ../butano/butano
PYTHON      	:=  python3
GRIT      		:=  grit
SOURCES     	:=  ../butano/common/src \
					../libsavgba/src \
					allure-agb/src \
					../tests \
					../tests/suites \
		    		src \
                    src/displayables \
                    src/smart_characters \
                    src/ulcv \
                    src/events \
                    src/fonts \
                    src/openings \
                    src/sound \
                    src/sound/libulc \
                    src/videoplayer \
                    src/menu \
                    src/savefile \
                    src/scripts \
                    src/shaders \
                    src/tl/$(LANGUAGE) \
		    		src/utils \
                    src/utils/gbfs
INCLUDES    	:=  include \
					include/fonts \
					include/definitions \
					include/background_metas \
					include/vfx_metas \
					include/sprite_metas \
					include/smart_characters \
					include/displayables \
					allure-agb/include \
					../libsavgba/include \
					../butano/common/include \
					../butano/butano/include
DATA        	:=  video \
					tl/$(LANGUAGE)
GRAPHICS    	:=  graphics \
					graphics/common_palettes \
					graphics/fonts/$(LANGUAGE) \
					graphics/fonts \
					graphics/bgs \
					graphics/bgs/thumbs \
					graphics/event \
					graphics/event/thumbs \
					graphics/event/custom \
					graphics/huge/thumbs \
					graphics/vfx \
					graphics/opening \
					graphics/characters/akira \
					graphics/characters/emi \
					graphics/characters/emicas \
					graphics/characters/eminude \
					graphics/characters/emiwheel \
					graphics/characters/hanagown \
					graphics/characters/hanako \
					graphics/characters/hideaki \
					graphics/characters/jigoro \
					graphics/characters/kenji \
					graphics/characters/lilly \
					graphics/characters/meiko \
					graphics/characters/miki \
					graphics/characters/misha \
					graphics/characters/mishashort \
					graphics/characters/muto \
					graphics/characters/nomiya \
					graphics/characters/nurse \
					graphics/characters/rin \
					graphics/characters/rinpan \
					graphics/characters/sae \
					graphics/characters/shizu \
					graphics/characters/shizuyu \
					graphics/characters/shopkeep \
					graphics/characters/yuuko \
					graphics/characters/yuukoshang \
					graphics/displayables/crowd \
					../butano/common/graphics
HUGE_GRAPHICS   :=  graphics/huge \
					graphics/huge/$(LANGUAGE)
AUDIO       	:=  audio
DMGAUDIO    	:=  dmg_audio
ROMTITLE    	:=  KATAWASHOUJO
ROMCODE     	:=  NPKS
USERFLAGS   	:=  -std=gnu11 -DBN_CFG_SPRITES_MAX_ITEMS=256 -DRUN_TESTS -DSAVE_TYPE=SAVE_TYPE_SRAM
USERCXXFLAGS	:=
USERASFLAGS 	:=  
USERLDFLAGS 	:=  -Wl,--print-memory-usage
USERLIBDIRS 	:=  $(DEVKITPRO)/libgba
USERLIBS    	:=  -lmm -lgba
DEFAULTLIBS 	:=  false
STACKTRACE		:=  true
USERBUILD   	:=  
EXTTOOL     	:= @$(PYTHON) -B tools/build_info.py --compiler=$(CXX); \
				   $(PYTHON) -B tools/ks_assets_tool.py --grit="$(GRIT)" --graphics="$(HUGE_GRAPHICS)" --build=$(BUILD)

#---------------------------------------------------------------------------------------------------------------------
# Export absolute butano path:
#---------------------------------------------------------------------------------------------------------------------
ifndef LIBBUTANOABS
	export LIBBUTANOABS	:=	$(realpath $(LIBBUTANO))
endif

#---------------------------------------------------------------------------------
# This rule links in binary data with the .ulcv extension
#---------------------------------------------------------------------------------
%.ulcv.o %_ulcv.h :	%.ulcv
#---------------------------------------------------------------------------------
		@echo $(notdir $<)
		@$(bin2o)

#---------------------------------------------------------------------------------
# This rule links in binary data with the .tl extension
#---------------------------------------------------------------------------------
%.tl.o %_tl.h :	%.tl
		@echo $(notdir $<)
		@$(bin2o)

#---------------------------------------------------------------------------------------------------------------------
# Include main makefile:
#---------------------------------------------------------------------------------------------------------------------
include $(LIBBUTANOABS)/butano.mak

HUGEGRAPHICSFILES	:=	$(foreach dir,	$(HUGE_GRAPHICS),	$(notdir $(wildcard $(dir)/*.bmp)))
export OFILES_HUGEGRAPHICS	:=  $(HUGEGRAPHICSFILES:.bmp=_bn_gfx.o)
export OFILES           :=  $(OFILES) $(OFILES_HUGEGRAPHICS)

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
