TEST_FILES := $(shell find test -name '*.bats' | xargs)

build:
	@echo "Building azkfs kernel module..."
	make -C modkernel

test: deps/bats/bin/bats
	@echo "Running azkfs tests..."
	@bash ./deps/bats/bin/bats ${TEST_FILES}

get-deps:
	@mkdir -p deps
	@cd deps; git clone https://github.com/sstephenson/bats; echo

.PHONY: build test get-deps
