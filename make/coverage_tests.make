# Alternative GNU Make project makefile autogenerated by Premake

ifndef config
  config=ci
endif

ifndef verbose
  SILENT = @
endif

.PHONY: clean prebuild

SHELLTYPE := posix
ifeq ($(shell echo "test"), "test")
	SHELLTYPE := msdos
endif

# Configurations
# #############################################

RESCOMP = windres
TARGETDIR = bin
TARGET = $(TARGETDIR)/coverage_tests
OBJDIR = obj/coverage_tests
DEFINES += -DDEBUG -DCPPUTEST_USE_LONG_LONG=0 -DCAPACITY_TSW=11 -DCAPACITY_SIG=10 -DCAPACITY_LCR=9 -DCAPACITY_SEG=22
INCLUDES += -I../testing/testenv -I../devel -I../BuildCppUTest/CppUTest/include -I../CppUTestSteps/TestSteps/include -I../specification -I../application -I../application/components
FORCE_INCLUDE +=
ALL_CPPFLAGS += $(CPPFLAGS) -MD -MP $(DEFINES) $(INCLUDES)
ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -g -std=c++17 -pedantic-errors
ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -g -std=c++17 -pedantic-errors
ALL_RESFLAGS += $(RESFLAGS) $(DEFINES) $(INCLUDES)
LIBS += lib/libcoverage_app.a -lgcov -lCppUTest -lCppUTestExt
LDDEPS += lib/libcoverage_app.a
ALL_LDFLAGS += $(LDFLAGS) -Llib -L../BuildCppUTest/lib --coverage
LINKCMD = $(CXX) -o "$@" $(OBJECTS) $(RESOURCES) $(ALL_LDFLAGS) $(LIBS)
define PREBUILDCMDS
endef
define PRELINKCMDS
endef
define POSTBUILDCMDS
endef

# Per File Configurations
# #############################################


# File sets
# #############################################

GENERATED :=
OBJECTS :=

GENERATED += $(OBJDIR)/BAS_01.o
GENERATED += $(OBJDIR)/BAS_02.o
GENERATED += $(OBJDIR)/Comparator.o
GENERATED += $(OBJDIR)/IL.o
GENERATED += $(OBJDIR)/LCR_01.o
GENERATED += $(OBJDIR)/LCR_02.o
GENERATED += $(OBJDIR)/LCR_03.o
GENERATED += $(OBJDIR)/M_Instances.o
GENERATED += $(OBJDIR)/SIG_01.o
GENERATED += $(OBJDIR)/SIG_02.o
GENERATED += $(OBJDIR)/SIG_03.o
GENERATED += $(OBJDIR)/SYS_01.o
GENERATED += $(OBJDIR)/SYS_02.o
GENERATED += $(OBJDIR)/SYS_03.o
GENERATED += $(OBJDIR)/TSW_01.o
GENERATED += $(OBJDIR)/TSW_02.o
GENERATED += $(OBJDIR)/TSW_03.o
GENERATED += $(OBJDIR)/TestGroupBase.o
GENERATED += $(OBJDIR)/TestLib.o
GENERATED += $(OBJDIR)/TestLiterals.o
GENERATED += $(OBJDIR)/TestMain.o
GENERATED += $(OBJDIR)/TestSteps.o
GENERATED += $(OBJDIR)/TestStepsPlugin.o
GENERATED += $(OBJDIR)/installComparators.o
GENERATED += $(OBJDIR)/ostreamHelpers.o
GENERATED += $(OBJDIR)/ostreams.o
OBJECTS += $(OBJDIR)/BAS_01.o
OBJECTS += $(OBJDIR)/BAS_02.o
OBJECTS += $(OBJDIR)/Comparator.o
OBJECTS += $(OBJDIR)/IL.o
OBJECTS += $(OBJDIR)/LCR_01.o
OBJECTS += $(OBJDIR)/LCR_02.o
OBJECTS += $(OBJDIR)/LCR_03.o
OBJECTS += $(OBJDIR)/M_Instances.o
OBJECTS += $(OBJDIR)/SIG_01.o
OBJECTS += $(OBJDIR)/SIG_02.o
OBJECTS += $(OBJDIR)/SIG_03.o
OBJECTS += $(OBJDIR)/SYS_01.o
OBJECTS += $(OBJDIR)/SYS_02.o
OBJECTS += $(OBJDIR)/SYS_03.o
OBJECTS += $(OBJDIR)/TSW_01.o
OBJECTS += $(OBJDIR)/TSW_02.o
OBJECTS += $(OBJDIR)/TSW_03.o
OBJECTS += $(OBJDIR)/TestGroupBase.o
OBJECTS += $(OBJDIR)/TestLib.o
OBJECTS += $(OBJDIR)/TestLiterals.o
OBJECTS += $(OBJDIR)/TestMain.o
OBJECTS += $(OBJDIR)/TestSteps.o
OBJECTS += $(OBJDIR)/TestStepsPlugin.o
OBJECTS += $(OBJDIR)/installComparators.o
OBJECTS += $(OBJDIR)/ostreamHelpers.o
OBJECTS += $(OBJDIR)/ostreams.o

# Rules
# #############################################

all: $(TARGET)
	@:

$(TARGET): $(GENERATED) $(OBJECTS) $(LDDEPS) | $(TARGETDIR)
	$(PRELINKCMDS)
	@echo Linking coverage_tests
	$(SILENT) $(LINKCMD)
	$(POSTBUILDCMDS)

$(TARGETDIR):
	@echo Creating $(TARGETDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) mkdir -p $(TARGETDIR)
else
	$(SILENT) mkdir $(subst /,\\,$(TARGETDIR))
endif

$(OBJDIR):
	@echo Creating $(OBJDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) mkdir -p $(OBJDIR)
else
	$(SILENT) mkdir $(subst /,\\,$(OBJDIR))
endif

clean:
	@echo Cleaning coverage_tests
ifeq (posix,$(SHELLTYPE))
	$(SILENT) rm -f  $(TARGET)
	$(SILENT) rm -rf $(GENERATED)
	$(SILENT) rm -rf $(OBJDIR)
else
	$(SILENT) if exist $(subst /,\\,$(TARGET)) del $(subst /,\\,$(TARGET))
	$(SILENT) if exist $(subst /,\\,$(GENERATED)) del /s /q $(subst /,\\,$(GENERATED))
	$(SILENT) if exist $(subst /,\\,$(OBJDIR)) rmdir /s /q $(subst /,\\,$(OBJDIR))
endif

prebuild: | $(OBJDIR)
	$(PREBUILDCMDS)

ifneq (,$(PCH))
$(OBJECTS): $(GCH) | $(PCH_PLACEHOLDER)
$(GCH): $(PCH) | prebuild
	@echo $(notdir $<)
	$(SILENT) $(CXX) -x c++-header $(ALL_CXXFLAGS) -o "$@" -MF "$(@:%.gch=%.d)" -c "$<"
$(PCH_PLACEHOLDER): $(GCH) | $(OBJDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) touch "$@"
else
	$(SILENT) echo $null >> "$@"
endif
else
$(OBJECTS): | prebuild
endif


# File Rules
# #############################################

$(OBJDIR)/TestSteps.o: ../CppUTestSteps/TestSteps/src/TestSteps.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/TestStepsPlugin.o: ../CppUTestSteps/TestSteps/src/TestStepsPlugin.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/IL.o: ../testing/testenv/SYS/src/IL.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/Comparator.o: ../testing/testenv/comparators/src/Comparator.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/installComparators.o: ../testing/testenv/comparators/src/installComparators.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/ostreamHelpers.o: ../testing/testenv/comparators/src/ostreamHelpers.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/ostreams.o: ../testing/testenv/comparators/src/ostreams.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/M_Instances.o: ../testing/testenv/mocks/src/M_Instances.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/TestGroupBase.o: ../testing/testenv/testlib/src/TestGroupBase.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/TestLib.o: ../testing/testenv/testlib/src/TestLib.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/TestLiterals.o: ../testing/testenv/testlib/src/TestLiterals.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/TestMain.o: ../testing/testenv/testlib/src/TestMain.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/BAS_01.o: ../testing/tests/moduletests/BAS/BAS_01.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/BAS_02.o: ../testing/tests/moduletests/BAS/BAS_02.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/LCR_01.o: ../testing/tests/moduletests/LCR/LCR_01.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/LCR_02.o: ../testing/tests/moduletests/LCR/LCR_02.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/LCR_03.o: ../testing/tests/moduletests/LCR/LCR_03.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/SIG_01.o: ../testing/tests/moduletests/SIG/SIG_01.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/SIG_02.o: ../testing/tests/moduletests/SIG/SIG_02.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/SIG_03.o: ../testing/tests/moduletests/SIG/SIG_03.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/SYS_01.o: ../testing/tests/moduletests/SYS/SYS_01.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/SYS_02.o: ../testing/tests/moduletests/SYS/SYS_02.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/SYS_03.o: ../testing/tests/moduletests/SYS/SYS_03.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/TSW_01.o: ../testing/tests/moduletests/TSW/TSW_01.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/TSW_02.o: ../testing/tests/moduletests/TSW/TSW_02.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/TSW_03.o: ../testing/tests/moduletests/TSW/TSW_03.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"

-include $(OBJECTS:%.o=%.d)
ifneq (,$(PCH))
  -include $(PCH_PLACEHOLDER).d
endif