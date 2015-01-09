MODULE_NAME := azkfs

MODULE_NAME_TEST := ${MODULE_NAME}_test
TEST_FILES := $(shell find test -name '*.bats' | xargs)

all: test

clean:
	@echo "Cleaning azkfs kernel module..."
	@cd modkernel; \
		make clean; \
		make MODULE_NAME=${MODULE_NAME_TEST} clean

test: modkernel/${MODULE_NAME_TEST}.ko
	@echo "Running azkfs tests..."
	@bash ./deps/bats/bin/bats ${TEST_FILES}

modkernel/${MODULE_NAME_TEST}.ko: build_test modkernel

deps/bats/bin/bats: get-deps

build_test: MODULE_NAME := ${MODULE_NAME_TEST}
build_test: build

build:
	@echo "Building azkfs kernel module..."
	@cd modkernel; make MODULE_NAME=${MODULE_NAME}

get-deps:
	@mkdir -p deps
	@cd deps; git clone https://github.com/sstephenson/bats; echo

.PHONY: all build build_test clean test get-deps
