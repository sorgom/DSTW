# Alternative GNU Make workspace makefile autogenerated by Premake

ifndef config
  config=ci
endif

ifndef verbose
  SILENT = @
endif

ifeq ($(config),ci)
  dstw_gen_config = ci
  dstw_run_config = ci

else ifeq ($(config),debug)
  dstw_gen_config = debug
  dstw_run_config = debug

else
  $(error "invalid configuration $(config)")
endif

PROJECTS := dstw_gen dstw_run

.PHONY: all clean help $(PROJECTS) 

all: $(PROJECTS)

dstw_gen:
ifneq (,$(dstw_gen_config))
	@echo "==== Building dstw_gen ($(dstw_gen_config)) ===="
	@${MAKE} --no-print-directory -C . -f dstw_gen.make config=$(dstw_gen_config)
endif

dstw_run:
ifneq (,$(dstw_run_config))
	@echo "==== Building dstw_run ($(dstw_run_config)) ===="
	@${MAKE} --no-print-directory -C . -f dstw_run.make config=$(dstw_run_config)
endif

clean:
	@${MAKE} --no-print-directory -C . -f dstw_gen.make clean
	@${MAKE} --no-print-directory -C . -f dstw_run.make clean

help:
	@echo "Usage: make [config=name] [target]"
	@echo ""
	@echo "CONFIGURATIONS:"
	@echo "  ci"
	@echo "  debug"
	@echo ""
	@echo "TARGETS:"
	@echo "   all (default)"
	@echo "   clean"
	@echo "   dstw_gen"
	@echo "   dstw_run"
	@echo ""
	@echo "For more information, see https://github.com/premake/premake-core/wiki"