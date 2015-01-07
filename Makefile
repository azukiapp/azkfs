build:
	@echo "Building azkfs kernel module..."
	@bash azk shell -c "cd modkernel && make"

test: deps/bats/bin/bats
	@echo "Running azkfs tests..."
	@bash ./deps/bats/bin/bats ${TEST_FILES}

get-deps:
	@mkdir -p deps
	@cd deps; git clone https://github.com/sstephenson/bats; echo

.PHONY: test get-deps
