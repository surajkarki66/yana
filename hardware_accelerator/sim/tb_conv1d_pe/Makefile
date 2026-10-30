TOP      := tb_conv1d_pe
VLT      := tb_conv1d_pe.vlt
FILELIST := tb_conv1d_pe.f

FAST_DIR  := obj_dir_fast
FAST_EXE  := $(FAST_DIR)/V$(TOP)
JOBS      ?= $(shell nproc)

COMMON_FLAGS := \
    $(VLT) \
    -sv \
    --timing \
    -f $(FILELIST) \
    --top-module $(TOP) \
    --binary \
    -j $(JOBS)

FAST_FLAGS := \
    $(COMMON_FLAGS) \
    --Mdir $(FAST_DIR)

.PHONY: all build run clean

all: run

build:
	verilator $(FAST_FLAGS)

run: build
	./$(FAST_EXE)

clean:
	rm -rf $(FAST_DIR)
