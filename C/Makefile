# Competitive Programming Makefile with Performance Analysis
.PHONY: clean create open run bench mem help

# Default to current directory name if TARGET not set
TARGET ?= $(notdir $(CURDIR))

# Validate TARGET
ifeq ($(TARGET),)
$(error Please define TARGET, e.g., make TARGET=hello create)
endif

# Input file (optional): use make run INPUT=test.in
INPUT ?= /dev/null

# Number of benchmark iterations (default: 1, increase for micro-benchmarks)
ITERATIONS ?= 1

# Compiler flags (competitive programming friendly)
CFLAGS = -O2 -Wall -Wextra -std=c11 -g

# Template for new files
TEMPLATE = \#include <stdio.h>\n\nint main(void) {\n    printf(\"Hello, World!\\n\");\n    return 0;\n}\n

# Create directory and file, then open in Neovim
create:
	mkdir -p $(TARGET)
	printf '$(TEMPLATE)' > $(TARGET)/$(TARGET).c
	cd $(TARGET) && nvim $(TARGET).c

# Open existing file
open:
	cd $(TARGET) && nvim $(TARGET).c

# Compile and run (with optional input redirection)
run:
	cd $(TARGET) && gcc $(CFLAGS) $(TARGET).c -o $(TARGET)
	cd $(TARGET) && ./$(TARGET) < $(INPUT)

# 🔥 BENCHMARK: Time execution (real, user, sys)
# Usage: make bench TARGET=solution [INPUT=test.in] [ITERATIONS=1000]
bench:
	@echo "=== BENCHMARKING $(TARGET) ==="
	@echo "Input: $(INPUT)"
	@echo "Iterations: $(ITERATIONS)"
	@echo "Compiling with $(CFLAGS)..."
	cd $(TARGET) && gcc $(CFLAGS) $(TARGET).c -o $(TARGET)
	@echo "Running time test..."
	@# Use /usr/bin/time for detailed timing (real, user, sys)
	@# -p = portable format; repeat ITERATIONS times
	@bash -c 'for i in $$(seq 1 $(ITERATIONS)); do \
		/usr/bin/time -f "Run $$i: %E real, %U user, %S sys, %M KB max RSS" \
		$(TARGET)/$(TARGET) < $(INPUT) >/dev/null 2>/dev/null; \
	done'
	@# Aggregate timing (optional: use awk to compute average)
	@echo "=== BENCHMARK COMPLETE ==="

# 🧠 MEMORY: Profile heap usage with Valgrind Massif
# Usage: make mem TARGET=solution [INPUT=test.in]
# Output: massif.out.<pid> → analyze with `ms_print massif.out.*`
mem:
	@echo "=== MEMORY PROFILING $(TARGET) ==="
	@echo "Input: $(INPUT)"
	cd $(TARGET) && gcc $(CFLAGS) $(TARGET).c -o $(TARGET)
	@echo "Running Valgrind Massif..."
	valgrind --tool=massif --massif-out-file=$(TARGET)/massif.out \
		$(TARGET)/$(TARGET) < $(INPUT) >/dev/null
	@echo "Memory profile saved to: $(TARGET)/massif.out"
	@echo "Analyze with: ms_print $(TARGET)/massif.out"

# Clean build artifacts and memory profiles
clean:
	rm -rf $(TARGET)

# Help
help:
	@echo "Competitive Programming Makefile"
	@echo ""
	@echo "Targets:"
	@echo "  make create TARGET=name   – create ./name/name.c and open in nvim"
	@echo "  make open   TARGET=name   – open ./name/name.c"
	@echo "  make run    TARGET=name   – compile and run (add INPUT=file.in)"
	@echo "  make bench  TARGET=name   – benchmark timing (add ITERATIONS=N, INPUT=file.in)"
	@echo "  make mem    TARGET=name   – profile memory with Valgrind (add INPUT=file.in)"
	@echo "  make clean  TARGET=name   – remove binary and profile data"
	@echo ""
	@echo "Examples:"
	@echo "  make create TARGET=power2"
	@echo "  make run TARGET=power2 INPUT=big.in"
	@echo "  make bench TARGET=power2 ITERATIONS=10000"
	@echo "  make mem TARGET=power2 INPUT=huge.in"
