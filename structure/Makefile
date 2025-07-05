CC = gcc
CFLAGS = -Wall -Wextra -g -I./include
LDFLAGS = 

SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj

# List all source files
SOURCES = $(wildcard $(SRC_DIR)/*.c)
# Generate object file names from source files
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

# Main target
TARGET = tcp_db

.PHONY: all
all: $(TARGET)

# Rule to create the output directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Main target depends on objects
$(TARGET): $(OBJ_DIR) $(OBJECTS)
	@echo "Linking $@..."
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJECTS)
	@echo "Build complete: $(TARGET)"

# Generic rule for building object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	@echo "Cleaning up..."
	rm -rf $(OBJ_DIR) $(TARGET)

# Additional useful targets
.PHONY: debug
debug: CFLAGS += -DDEBUG -g3
debug: all

.PHONY: run
run: $(TARGET)
	./$(TARGET) a.db 8080

.PHONY: clean
