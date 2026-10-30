TOP      := tb_yana_top
VLT      := tb_yana_top.vlt
FILELIST := tb_yana_top.f

FAST_DIR  := obj_dir_fast
TRACE_DIR := obj_dir_trace

FAST_EXE  := $(FAST_DIR)/V$(TOP)
TRACE_EXE := $(TRACE_DIR)/V$(TOP)

# Simulator plusargs:
#   make run-fast DATASETS=shd_0,other_dir NUM_SAMPLES=2
#   make run-trace DATASETS=shd_0
#   make run-fast ARGS="+datasets=shd_0 +num_samples=1"
#   make run-fast TIMEOUT=60000000
#   make run-fast DATASETS=nmnist_conv_stress NUM_SAMPLES=10 HAS_CONV=1
#   make run-fast DATASETS=shd_conv1d_0 NUM_SAMPLES=1 HAS_CONV1D=1
DATASETS    ?=
NUM_SAMPLES ?=
TIMEOUT     ?=
ARGS        ?=
HAS_CONV    ?= 0
HAS_CONV1D  ?= 0

# Number of parallel jobs for Verilator's C++ build step.
# Override with: make build JOBS=4
JOBS ?= $(shell nproc)

SIM_ARGS := $(strip $(ARGS) \
    $(if $(DATASETS),+datasets=$(DATASETS)) \
    $(if $(NUM_SAMPLES),+num_samples=$(NUM_SAMPLES)) \
    $(if $(TIMEOUT),+timeout_ns=$(TIMEOUT)))

# Elaboration-time CONV / CONV1D PE enable (mutually exclusive).
GFLAGS := \
    $(if $(filter 1,$(HAS_CONV)),-GHAS_CONV=1,) \
    $(if $(filter 1,$(HAS_CONV1D)),-GHAS_CONV1D=1,)

COMMON_FLAGS := \
    $(VLT) \
    -sv \
    --timing \
    -f $(FILELIST) \
    --top-module $(TOP) \
    --binary \
    $(GFLAGS) \
    -j $(JOBS)

# Fast build: no waveform support
FAST_FLAGS := \
    $(COMMON_FLAGS) \
    --Mdir $(FAST_DIR)

# Trace build: FST + structs
TRACE_FLAGS := \
    $(COMMON_FLAGS) \
    --Mdir $(TRACE_DIR) \
    --trace-fst \
    --trace-structs

.PHONY: all build build-fast build-trace run-fast run-trace wave surfer clean clean-fast clean-trace

all: build

build: build-fast

build-fast:
	verilator $(FAST_FLAGS)

build-trace:
	verilator $(TRACE_FLAGS)

# Fast run, no waveform dumping (uses obj_dir_fast/Vtb_yana_top)
run-fast: build-fast
	./$(FAST_EXE) $(SIM_ARGS)

# Trace run with FST dump (uses obj_dir_trace/Vtb_yana_top)
run-trace: build-trace
	./$(TRACE_EXE) +trace $(SIM_ARGS)

# Open in GTKWave
wave:
	gtkwave waveform.fst gtkwave_setup.gtkw &

# Open in Surfer
surfer:
	surfer -s tb_yana_top.surf.ron waveform.fst &

clean-fast:
	rm -rf $(FAST_DIR)

clean-trace:
	rm -rf $(TRACE_DIR)

clean:
	rm -rf $(FAST_DIR) $(TRACE_DIR) waveform.fst waveform.vcd
