# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c99

# List of source files
SRCS = src/main.c src/bank.c src/account.c

# List of object files (derived from source files)
OBJS = $(SRCS:.c=.o)

# Name of the final executable
TARGET = bank_app

# Default target to build the executable
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean up the build
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean

