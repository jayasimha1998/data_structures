# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = helloworld

# Source files
SRCS = helloworld.c
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean

