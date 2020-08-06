
BUILD = Build

### SOURCES ###
SRC = Src/Main\
	  Src/TlvWindow/TlvWindow

### MOC SOURCES ###
MOC_SRC = Src/TlvWindow/TlvWindow

### OBJECTS ###
OBJ = $(addsuffix .o, $(addprefix $(BUILD)/, $(SRC))) 
OBJ += $(addsuffix .moc.o, $(addprefix $(BUILD)/, $(MOC_SRC)))

### INCLUDES ###
INC = -IC:/Qt/5.15.0/mingw81_32/include\
    -IC:/Qt/5.15.0/mingw81_32/include/Qt3DAnimation\
	-IC:/Qt/5.15.0/mingw81_32/include/Qt3DCore\
	-IC:/Qt/5.15.0/mingw81_32/include/Qt3DExtras\
	-IC:/Qt/5.15.0/mingw81_32/include/Qt3DInput\
	-IC:/Qt/5.15.0/mingw81_32/include/Qt3DLogic\
	-IC:/Qt/5.15.0/mingw81_32/include/Qt3DQuick\
	-IC:/Qt/5.15.0/mingw81_32/include/Qt3DQuickAnimation\
	-IC:/Qt/5.15.0/mingw81_32/include/Qt3DQuickExtras\
	-IC:/Qt/5.15.0/mingw81_32/include/Qt3DQuickInput\
	-IC:/Qt/5.15.0/mingw81_32/include/Qt3DQuickRender\
	-IC:/Qt/5.15.0/mingw81_32/include/Qt3DQuickScene2D\
	-IC:/Qt/5.15.0/mingw81_32/include/Qt3DRender\
	-IC:/Qt/5.15.0/mingw81_32/include/QtAccessibilitySupport\
	-IC:/Qt/5.15.0/mingw81_32/include/QtANGLE\
	-IC:/Qt/5.15.0/mingw81_32/include/QtBluetooth\
	-IC:/Qt/5.15.0/mingw81_32/include/QtBodymovin\
	-IC:/Qt/5.15.0/mingw81_32/include/QtCharts\
	-IC:/Qt/5.15.0/mingw81_32/include/QtConcurrent\
	-IC:/Qt/5.15.0/mingw81_32/include/QtCore\
	-IC:/Qt/5.15.0/mingw81_32/include/QtDataVisualization\
	-IC:/Qt/5.15.0/mingw81_32/include/QtDBus\
	-IC:/Qt/5.15.0/mingw81_32/include/QtDesigner\
	-IC:/Qt/5.15.0/mingw81_32/include/QtDesignerComponents\
	-IC:/Qt/5.15.0/mingw81_32/include/QtDeviceDiscoverySupport\
	-IC:/Qt/5.15.0/mingw81_32/include/QtEdidSupport\
	-IC:/Qt/5.15.0/mingw81_32/include/QtEglSupport\
	-IC:/Qt/5.15.0/mingw81_32/include/QtEventDispatcherSupport\
	-IC:/Qt/5.15.0/mingw81_32/include/QtFbSupport\
	-IC:/Qt/5.15.0/mingw81_32/include/QtFontDatabaseSupport\
	-IC:/Qt/5.15.0/mingw81_32/include/QtGamepad\
	-IC:/Qt/5.15.0/mingw81_32/include/QtGui\
	-IC:/Qt/5.15.0/mingw81_32/include/QtHelp\
	-IC:/Qt/5.15.0/mingw81_32/include/QtLocation\
	-IC:/Qt/5.15.0/mingw81_32/include/QtMultimedia\
	-IC:/Qt/5.15.0/mingw81_32/include/QtMultimediaQuick\
	-IC:/Qt/5.15.0/mingw81_32/include/QtMultimediaWidgets\
	-IC:/Qt/5.15.0/mingw81_32/include/QtNetwork\
	-IC:/Qt/5.15.0/mingw81_32/include/QtNetworkAuth\
	-IC:/Qt/5.15.0/mingw81_32/include/QtNfc\
	-IC:/Qt/5.15.0/mingw81_32/include/QtOpenGL\
	-IC:/Qt/5.15.0/mingw81_32/include/QtOpenGLExtensions\
	-IC:/Qt/5.15.0/mingw81_32/include/QtPacketProtocol\
	-IC:/Qt/5.15.0/mingw81_32/include/QtPlatformCompositorSupport\
	-IC:/Qt/5.15.0/mingw81_32/include/QtPlatformHeaders\
	-IC:/Qt/5.15.0/mingw81_32/include/QtPositioning\
	-IC:/Qt/5.15.0/mingw81_32/include/QtPositioningQuick\
	-IC:/Qt/5.15.0/mingw81_32/include/QtPrintSupport\
	-IC:/Qt/5.15.0/mingw81_32/include/QtPurchasing\
	-IC:/Qt/5.15.0/mingw81_32/include/QtQml\
	-IC:/Qt/5.15.0/mingw81_32/include/QtQmlDebug\
	-IC:/Qt/5.15.0/mingw81_32/include/QtQmlModels\
	-IC:/Qt/5.15.0/mingw81_32/include/QtQmlWorkerScript\
	-IC:/Qt/5.15.0/mingw81_32/include/QtQuick\
	-IC:/Qt/5.15.0/mingw81_32/include/QtQuick3D\
	-IC:/Qt/5.15.0/mingw81_32/include/QtQuick3DAssetImport\
	-IC:/Qt/5.15.0/mingw81_32/include/QtQuick3DRender\
	-IC:/Qt/5.15.0/mingw81_32/include/QtQuick3DRuntimeRender\
	-IC:/Qt/5.15.0/mingw81_32/include/QtQuick3DUtils\
	-IC:/Qt/5.15.0/mingw81_32/include/QtQuickControls2\
	-IC:/Qt/5.15.0/mingw81_32/include/QtQuickParticles\
	-IC:/Qt/5.15.0/mingw81_32/include/QtQuickShapes\
	-IC:/Qt/5.15.0/mingw81_32/include/QtQuickTemplates2\
	-IC:/Qt/5.15.0/mingw81_32/include/QtQuickTest\
	-IC:/Qt/5.15.0/mingw81_32/include/QtQuickWidgets\
	-IC:/Qt/5.15.0/mingw81_32/include/QtRemoteObjects\
	-IC:/Qt/5.15.0/mingw81_32/include/QtRepParser\
	-IC:/Qt/5.15.0/mingw81_32/include/QtScript\
	-IC:/Qt/5.15.0/mingw81_32/include/QtScriptTools\
	-IC:/Qt/5.15.0/mingw81_32/include/QtScxml\
	-IC:/Qt/5.15.0/mingw81_32/include/QtSensors\
	-IC:/Qt/5.15.0/mingw81_32/include/QtSerialBus\
	-IC:/Qt/5.15.0/mingw81_32/include/QtSerialPort\
	-IC:/Qt/5.15.0/mingw81_32/include/QtSql\
	-IC:/Qt/5.15.0/mingw81_32/include/QtSvg\
	-IC:/Qt/5.15.0/mingw81_32/include/QtTest\
	-IC:/Qt/5.15.0/mingw81_32/include/QtTextToSpeech\
	-IC:/Qt/5.15.0/mingw81_32/include/QtThemeSupport\
	-IC:/Qt/5.15.0/mingw81_32/include/QtUiPlugin\
	-IC:/Qt/5.15.0/mingw81_32/include/QtUiTools\
	-IC:/Qt/5.15.0/mingw81_32/include/QtVirtualKeyboard\
	-IC:/Qt/5.15.0/mingw81_32/include/QtWebChannel\
	-IC:/Qt/5.15.0/mingw81_32/include/QtWebSockets\
	-IC:/Qt/5.15.0/mingw81_32/include/QtWidgets\
	-IC:/Qt/5.15.0/mingw81_32/include/QtWindowsUIAutomationSupport\
	-IC:/Qt/5.15.0/mingw81_32/include/QtWinExtras\
	-IC:/Qt/5.15.0/mingw81_32/include/QtXml\
	-IC:/Qt/5.15.0/mingw81_32/include/QtXmlPatterns\
	-IC:/Qt/5.15.0/mingw81_32/include/QtZlib\
	-ISrc/TlvWindow

### LINKER FLAGS ###
LDFLAGS = -LC:/Qt/5.15.0/mingw81_32/lib

LDLIBS = -lQt5Quick  -lQt5PrintSupport -lQt5Qml -lQt5Network -lQt5Widgets -lQt5Gui -lQt5Core
		  
### COMPILER FLAGS
CFLAGS = $(INC)

### COMPILER ###
CC = g++

### QT MOC ###
MOC = moc

all: $(BUILD)/test.exe

$(BUILD)/test.exe: $(OBJ)
	@echo LINKING $^
	@$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)
	
$(BUILD)/%.o: %.cpp
	@echo COMPILING $<
	@mkdir -p $(subst /,\,$(dir $@))
	@$(CC) $(CFLAGS) -M -MT $@ -o $(patsubst %.o, %.d, $@) $<
	@$(CC) $(CFLAGS) -o $@ -c $<

$(BUILD)/%.moc.o: $(BUILD)/%.moc.cpp
	@echo COMPILING MOC $<
	@mkdir -p $(subst /,\,$(dir $@))
	@$(CC) $(CFLAGS) -M -MT $@ -o $(patsubst %.o, %.d, $@) $<
	@$(CC) $(CFLAGS) -o $@ -c $<
					    
$(BUILD)/%.moc.cpp: %.h
	@echo GENERATING MOC $<
	@$(MOC) $< -o $@

-include $(OBJ:.o=.d) 
	
.PHONY: clean

clean:
	@echo CLEANING......
	@rm -rf $(BUILD)/Src $(BUILD)/test.exe
