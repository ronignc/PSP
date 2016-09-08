##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=Project
ConfigurationName      :=Release
WorkspacePath          :=C:/Users/Thales/Documents/GitHub/PSP
ProjectPath            :=C:/Users/Thales/Documents/GitHub/PSP/Project
IntermediateDirectory  :=./Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Thales
Date                   :=07/09/2016
CodeLitePath           :="C:/Program Files (x86)/CodeLite"
LinkerName             :=C:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/PSP-UFU
Preprocessors          :=$(PreprocessorSwitch)NDEBUG $(PreprocessorSwitch)UNICODE 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Project.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := $(shell wx-config --rcflags)
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  $(shell wx-config --libs gl) -mwindows
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -O2 -Wall $(shell wx-config --cflags) $(Preprocessors)
CFLAGS   :=  -O2 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files (x86)\CodeLite
UNIT_TEST_PP_SRC_DIR:=C:\UnitTest++-1.3
WXWIN:=C:\wxWidgets-3.1.0
WXCFG:=gcc_dll\mswu
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/win_resources.rc$(ObjectSuffix) $(IntermediateDirectory)/Element.cpp$(ObjectSuffix) $(IntermediateDirectory)/ArtMetro.cpp$(ObjectSuffix) $(IntermediateDirectory)/MainFrame.cpp$(ObjectSuffix) $(IntermediateDirectory)/Workspace.cpp$(ObjectSuffix) $(IntermediateDirectory)/MainFrameBitmaps.cpp$(ObjectSuffix) $(IntermediateDirectory)/WorkspaceBitmaps.cpp$(ObjectSuffix) $(IntermediateDirectory)/MainFrameBase.cpp$(ObjectSuffix) $(IntermediateDirectory)/WorkspaceBase.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/Bus.cpp$(ObjectSuffix) $(IntermediateDirectory)/Line.cpp$(ObjectSuffix) $(IntermediateDirectory)/Transformer.cpp$(ObjectSuffix) $(IntermediateDirectory)/Machines.cpp$(ObjectSuffix) $(IntermediateDirectory)/SyncGenerator.cpp$(ObjectSuffix) $(IntermediateDirectory)/IndMotor.cpp$(ObjectSuffix) $(IntermediateDirectory)/Branch.cpp$(ObjectSuffix) $(IntermediateDirectory)/SyncMotor.cpp$(ObjectSuffix) $(IntermediateDirectory)/Shunt.cpp$(ObjectSuffix) $(IntermediateDirectory)/Load.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/Inductor.cpp$(ObjectSuffix) $(IntermediateDirectory)/Capacitor.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Release"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Release"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thales/Documents/GitHub/PSP/Project/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix)main.cpp

$(IntermediateDirectory)/win_resources.rc$(ObjectSuffix): win_resources.rc
	$(RcCompilerName) -i "C:/Users/Thales/Documents/GitHub/PSP/Project/win_resources.rc" $(RcCmpOptions)   $(ObjectSwitch)$(IntermediateDirectory)/win_resources.rc$(ObjectSuffix) $(RcIncludePath)
$(IntermediateDirectory)/Element.cpp$(ObjectSuffix): Element.cpp $(IntermediateDirectory)/Element.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thales/Documents/GitHub/PSP/Project/Element.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Element.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Element.cpp$(DependSuffix): Element.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Element.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Element.cpp$(DependSuffix) -MM Element.cpp

$(IntermediateDirectory)/Element.cpp$(PreprocessSuffix): Element.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Element.cpp$(PreprocessSuffix)Element.cpp

$(IntermediateDirectory)/ArtMetro.cpp$(ObjectSuffix): ArtMetro.cpp $(IntermediateDirectory)/ArtMetro.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thales/Documents/GitHub/PSP/Project/ArtMetro.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ArtMetro.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ArtMetro.cpp$(DependSuffix): ArtMetro.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ArtMetro.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ArtMetro.cpp$(DependSuffix) -MM ArtMetro.cpp

$(IntermediateDirectory)/ArtMetro.cpp$(PreprocessSuffix): ArtMetro.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ArtMetro.cpp$(PreprocessSuffix)ArtMetro.cpp

$(IntermediateDirectory)/MainFrame.cpp$(ObjectSuffix): MainFrame.cpp $(IntermediateDirectory)/MainFrame.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thales/Documents/GitHub/PSP/Project/MainFrame.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MainFrame.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MainFrame.cpp$(DependSuffix): MainFrame.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MainFrame.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MainFrame.cpp$(DependSuffix) -MM MainFrame.cpp

$(IntermediateDirectory)/MainFrame.cpp$(PreprocessSuffix): MainFrame.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MainFrame.cpp$(PreprocessSuffix)MainFrame.cpp

$(IntermediateDirectory)/Workspace.cpp$(ObjectSuffix): Workspace.cpp $(IntermediateDirectory)/Workspace.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thales/Documents/GitHub/PSP/Project/Workspace.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Workspace.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Workspace.cpp$(DependSuffix): Workspace.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Workspace.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Workspace.cpp$(DependSuffix) -MM Workspace.cpp

$(IntermediateDirectory)/Workspace.cpp$(PreprocessSuffix): Workspace.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Workspace.cpp$(PreprocessSuffix)Workspace.cpp

$(IntermediateDirectory)/MainFrameBitmaps.cpp$(ObjectSuffix): MainFrameBitmaps.cpp $(IntermediateDirectory)/MainFrameBitmaps.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thales/Documents/GitHub/PSP/Project/MainFrameBitmaps.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MainFrameBitmaps.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MainFrameBitmaps.cpp$(DependSuffix): MainFrameBitmaps.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MainFrameBitmaps.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MainFrameBitmaps.cpp$(DependSuffix) -MM MainFrameBitmaps.cpp

$(IntermediateDirectory)/MainFrameBitmaps.cpp$(PreprocessSuffix): MainFrameBitmaps.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MainFrameBitmaps.cpp$(PreprocessSuffix)MainFrameBitmaps.cpp

$(IntermediateDirectory)/WorkspaceBitmaps.cpp$(ObjectSuffix): WorkspaceBitmaps.cpp $(IntermediateDirectory)/WorkspaceBitmaps.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thales/Documents/GitHub/PSP/Project/WorkspaceBitmaps.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/WorkspaceBitmaps.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/WorkspaceBitmaps.cpp$(DependSuffix): WorkspaceBitmaps.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/WorkspaceBitmaps.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/WorkspaceBitmaps.cpp$(DependSuffix) -MM WorkspaceBitmaps.cpp

$(IntermediateDirectory)/WorkspaceBitmaps.cpp$(PreprocessSuffix): WorkspaceBitmaps.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/WorkspaceBitmaps.cpp$(PreprocessSuffix)WorkspaceBitmaps.cpp

$(IntermediateDirectory)/MainFrameBase.cpp$(ObjectSuffix): MainFrameBase.cpp $(IntermediateDirectory)/MainFrameBase.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thales/Documents/GitHub/PSP/Project/MainFrameBase.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MainFrameBase.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MainFrameBase.cpp$(DependSuffix): MainFrameBase.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MainFrameBase.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MainFrameBase.cpp$(DependSuffix) -MM MainFrameBase.cpp

$(IntermediateDirectory)/MainFrameBase.cpp$(PreprocessSuffix): MainFrameBase.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MainFrameBase.cpp$(PreprocessSuffix)MainFrameBase.cpp

$(IntermediateDirectory)/WorkspaceBase.cpp$(ObjectSuffix): WorkspaceBase.cpp $(IntermediateDirectory)/WorkspaceBase.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thales/Documents/GitHub/PSP/Project/WorkspaceBase.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/WorkspaceBase.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/WorkspaceBase.cpp$(DependSuffix): WorkspaceBase.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/WorkspaceBase.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/WorkspaceBase.cpp$(DependSuffix) -MM WorkspaceBase.cpp

$(IntermediateDirectory)/WorkspaceBase.cpp$(PreprocessSuffix): WorkspaceBase.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/WorkspaceBase.cpp$(PreprocessSuffix)WorkspaceBase.cpp

$(IntermediateDirectory)/Bus.cpp$(ObjectSuffix): Bus.cpp $(IntermediateDirectory)/Bus.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thales/Documents/GitHub/PSP/Project/Bus.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Bus.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Bus.cpp$(DependSuffix): Bus.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Bus.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Bus.cpp$(DependSuffix) -MM Bus.cpp

$(IntermediateDirectory)/Bus.cpp$(PreprocessSuffix): Bus.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Bus.cpp$(PreprocessSuffix)Bus.cpp

$(IntermediateDirectory)/Line.cpp$(ObjectSuffix): Line.cpp $(IntermediateDirectory)/Line.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thales/Documents/GitHub/PSP/Project/Line.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Line.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Line.cpp$(DependSuffix): Line.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Line.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Line.cpp$(DependSuffix) -MM Line.cpp

$(IntermediateDirectory)/Line.cpp$(PreprocessSuffix): Line.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Line.cpp$(PreprocessSuffix)Line.cpp

$(IntermediateDirectory)/Transformer.cpp$(ObjectSuffix): Transformer.cpp $(IntermediateDirectory)/Transformer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thales/Documents/GitHub/PSP/Project/Transformer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Transformer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Transformer.cpp$(DependSuffix): Transformer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Transformer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Transformer.cpp$(DependSuffix) -MM Transformer.cpp

$(IntermediateDirectory)/Transformer.cpp$(PreprocessSuffix): Transformer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Transformer.cpp$(PreprocessSuffix)Transformer.cpp

$(IntermediateDirectory)/Machines.cpp$(ObjectSuffix): Machines.cpp $(IntermediateDirectory)/Machines.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thales/Documents/GitHub/PSP/Project/Machines.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Machines.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Machines.cpp$(DependSuffix): Machines.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Machines.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Machines.cpp$(DependSuffix) -MM Machines.cpp

$(IntermediateDirectory)/Machines.cpp$(PreprocessSuffix): Machines.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Machines.cpp$(PreprocessSuffix)Machines.cpp

$(IntermediateDirectory)/SyncGenerator.cpp$(ObjectSuffix): SyncGenerator.cpp $(IntermediateDirectory)/SyncGenerator.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thales/Documents/GitHub/PSP/Project/SyncGenerator.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/SyncGenerator.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SyncGenerator.cpp$(DependSuffix): SyncGenerator.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SyncGenerator.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/SyncGenerator.cpp$(DependSuffix) -MM SyncGenerator.cpp

$(IntermediateDirectory)/SyncGenerator.cpp$(PreprocessSuffix): SyncGenerator.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SyncGenerator.cpp$(PreprocessSuffix)SyncGenerator.cpp

$(IntermediateDirectory)/IndMotor.cpp$(ObjectSuffix): IndMotor.cpp $(IntermediateDirectory)/IndMotor.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thales/Documents/GitHub/PSP/Project/IndMotor.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/IndMotor.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/IndMotor.cpp$(DependSuffix): IndMotor.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/IndMotor.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/IndMotor.cpp$(DependSuffix) -MM IndMotor.cpp

$(IntermediateDirectory)/IndMotor.cpp$(PreprocessSuffix): IndMotor.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/IndMotor.cpp$(PreprocessSuffix)IndMotor.cpp

$(IntermediateDirectory)/Branch.cpp$(ObjectSuffix): Branch.cpp $(IntermediateDirectory)/Branch.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thales/Documents/GitHub/PSP/Project/Branch.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Branch.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Branch.cpp$(DependSuffix): Branch.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Branch.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Branch.cpp$(DependSuffix) -MM Branch.cpp

$(IntermediateDirectory)/Branch.cpp$(PreprocessSuffix): Branch.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Branch.cpp$(PreprocessSuffix)Branch.cpp

$(IntermediateDirectory)/SyncMotor.cpp$(ObjectSuffix): SyncMotor.cpp $(IntermediateDirectory)/SyncMotor.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thales/Documents/GitHub/PSP/Project/SyncMotor.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/SyncMotor.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SyncMotor.cpp$(DependSuffix): SyncMotor.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SyncMotor.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/SyncMotor.cpp$(DependSuffix) -MM SyncMotor.cpp

$(IntermediateDirectory)/SyncMotor.cpp$(PreprocessSuffix): SyncMotor.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SyncMotor.cpp$(PreprocessSuffix)SyncMotor.cpp

$(IntermediateDirectory)/Shunt.cpp$(ObjectSuffix): Shunt.cpp $(IntermediateDirectory)/Shunt.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thales/Documents/GitHub/PSP/Project/Shunt.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Shunt.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Shunt.cpp$(DependSuffix): Shunt.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Shunt.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Shunt.cpp$(DependSuffix) -MM Shunt.cpp

$(IntermediateDirectory)/Shunt.cpp$(PreprocessSuffix): Shunt.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Shunt.cpp$(PreprocessSuffix)Shunt.cpp

$(IntermediateDirectory)/Load.cpp$(ObjectSuffix): Load.cpp $(IntermediateDirectory)/Load.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thales/Documents/GitHub/PSP/Project/Load.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Load.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Load.cpp$(DependSuffix): Load.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Load.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Load.cpp$(DependSuffix) -MM Load.cpp

$(IntermediateDirectory)/Load.cpp$(PreprocessSuffix): Load.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Load.cpp$(PreprocessSuffix)Load.cpp

$(IntermediateDirectory)/Inductor.cpp$(ObjectSuffix): Inductor.cpp $(IntermediateDirectory)/Inductor.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thales/Documents/GitHub/PSP/Project/Inductor.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Inductor.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Inductor.cpp$(DependSuffix): Inductor.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Inductor.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Inductor.cpp$(DependSuffix) -MM Inductor.cpp

$(IntermediateDirectory)/Inductor.cpp$(PreprocessSuffix): Inductor.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Inductor.cpp$(PreprocessSuffix)Inductor.cpp

$(IntermediateDirectory)/Capacitor.cpp$(ObjectSuffix): Capacitor.cpp $(IntermediateDirectory)/Capacitor.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Thales/Documents/GitHub/PSP/Project/Capacitor.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Capacitor.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Capacitor.cpp$(DependSuffix): Capacitor.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Capacitor.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Capacitor.cpp$(DependSuffix) -MM Capacitor.cpp

$(IntermediateDirectory)/Capacitor.cpp$(PreprocessSuffix): Capacitor.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Capacitor.cpp$(PreprocessSuffix)Capacitor.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Release/


