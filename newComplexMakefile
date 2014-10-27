## -*- Makefile -*-
##
## User: akhilthampy
## Time: Oct 27, 2014 1:42:21 PM
## Makefile created by Oracle Solaris Studio.
##
## This file is generated automatically.
##


#### Compiler and tool definitions shared by all build targets #####
CCC = g++
CXX = g++
BASICOPTS = -g
CCFLAGS = $(BASICOPTS)
CXXFLAGS = $(BASICOPTS)
CCADMIN = 


# Define the target directories.
TARGETDIR_chip8=GNU-x86_64-MacOSX


all: $(TARGETDIR_chip8)/chip8

## Target: chip8
OBJS_chip8 =  \
	$(TARGETDIR_chip8)/chip8.o \
	$(TARGETDIR_chip8)/main.o
USERLIBS_chip8 = $(SYSLIBS_chip8) 
DEPLIBS_chip8 =  
LDLIBS_chip8 = $(USERLIBS_chip8)


# Link or archive
$(TARGETDIR_chip8)/chip8: $(TARGETDIR_chip8) $(OBJS_chip8) $(DEPLIBS_chip8)
	$(LINK.cc) $(CCFLAGS_chip8) $(CPPFLAGS_chip8) -o $@ $(OBJS_chip8) $(LDLIBS_chip8)


# Compile source files into .o files
$(TARGETDIR_chip8)/chip8.o: $(TARGETDIR_chip8) chip8.cpp
	$(COMPILE.cc) $(CCFLAGS_chip8) $(CPPFLAGS_chip8) -o $@ chip8.cpp

$(TARGETDIR_chip8)/main.o: $(TARGETDIR_chip8) main.cpp
	$(COMPILE.cc) $(CCFLAGS_chip8) $(CPPFLAGS_chip8) -o $@ main.cpp



#### Clean target deletes all generated files ####
clean:
	rm -f \
		$(TARGETDIR_chip8)/chip8 \
		$(TARGETDIR_chip8)/chip8.o \
		$(TARGETDIR_chip8)/main.o
	$(CCADMIN)
	rm -f -r $(TARGETDIR_chip8)


# Create the target directory (if needed)
$(TARGETDIR_chip8):
	mkdir -p $(TARGETDIR_chip8)


# Enable dependency checking
.KEEP_STATE:
.KEEP_STATE_FILE:.make.state.GNU-x86_64-MacOSX

