# === CONFIGURATION ===
CC := gcc
CFLAGS := -Wall -Wextra -Iinclude -std=c243
LIBS := -lm
SRC_DIR := src
BUILD_DIR := build
BIN := $(BUILD_DIR)/main

# Find all source files in src/** and main.c
SRC := $(wildcard $(SRC_DIR)/**/*.c) main.c
OBJ := $(SRC:%.c=$(BUILD_DIR)/%.o)

# === BUILD RULES ===

all: $(BIN)

$(BIN): $(OBJ)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

# Pattern rule to compile .c to .o
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# === CLEAN ===
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean


