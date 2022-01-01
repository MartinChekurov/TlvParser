# Operating system - linux/windows
OS = linux
# Executable
TARGET = TlvTool
# Build folder
BUILD = out

# UI files
UISRC =
UIINC = $(patsubst %.ui, %.h, $(UISRC))

# MOC files
MOCINC = Src/MainWindow/MainWindow.h\
		 Src/TlvParserWindow/TlvParserWindow.h
MOCSRC = $(patsubst %.h, %.moc.cpp, $(MOCINC))

# Source files
SRC := $(wildcard Src/*.cpp)
SRC += $(wildcard Src/MainWindow/*.cpp)
SRC += $(wildcard Src/TlvParserWindow/*.cpp)
SRC += $(wildcard Src/TlvParser/*.cpp)
SRC += $(wildcard Src/TlvInfo/*.cpp)
SRC := $(filter-out %.moc.cpp, $(SRC))
SRC += $(MOCSRC)
# Include files
INC = $(patsubst %, -I%, $(dir $(SRC)))
# QT includes
ifeq ($(OS),windows)
INC += -IC:\Qt\6.2.2\mingw_64\include\
	   -IC:\Qt\6.2.2\mingw_64\include\QtCore\
	   -IC:\Qt\6.2.2\mingw_64\include\QtGui\
	   -IC:\Qt\6.2.2\mingw_64\include\QtWidgets
else
INC += -I/home/marti/Qt/6.2.2/gcc_64/include\
	   -I/home/marti/Qt/6.2.2/gcc_64/include/QtCore\
	   -I/home/marti/Qt/6.2.2/gcc_64/include/QtGui\
	   -I/home/marti/Qt/6.2.2/gcc_64/include/QtWidgets
endif

# Object files
OBJS = $(patsubst %.cpp, $(BUILD)/%.o, $(SRC))

# Dependencies
DEPS = $(OBJS:%.o=%.d)

# Compiler
CC = g++
# Compiler flags
CFLAGS = $(INC) -std=c++17 -fPIC

# Linker
LD = g++

# Linker flags
LDFLAGS =
ifeq ($(OS),windows)
# Disables console under windows
LDFLAGS += -mwindows
endif
# QT Libs path
ifeq ($(OS),windows)
LDFLAGS += -LC:\Qt\6.2.2\mingw_64\lib
else
LDFLAGS += -L/home/marti/Qt/6.2.2/gcc_64/lib
endif

# Libraries
LIBS =
# QT Libs
LIBS += -lQt6Core -lQt6Gui -lQt6Widgets

# UIC
UIC = uic

# MOC
MOC = moc

all : $(UIINC) $(BUILD)/$(TARGET)

# Linking phase
$(BUILD)/$(TARGET) : $(OBJS)
	@echo LINKING...$^
	@$(LD) $(LDFLAGS) -o $@ $(OBJS) $(LIBS)

# Compilation phase
$(BUILD)/%.o : %.cpp
	@echo COMPILING...$<
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# QT Moc conversion phase
%.moc.cpp: %.h
	@echo COMPILING...$<
	@$(MOC) $(INC) $< -o $@

# QT UI conversion phase
%.h : %.ui
	@echo COMPILING...$<
	@$(UIC) -o $@ $<

# Dependencies generation phase
$(BUILD)/%.d: %.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -MM -MT $(patsubst %.cpp, $(@:%.d=%.o), $<) -MF $@ $<

-include $(DEPS)

.PHONY : clean

# Cleaning phase
clean :
	@echo CLEANING...
	@rm -rf $(BUILD)/$(OBJS) $(BUILD)/$(DEPS) $(BUILD)/test
