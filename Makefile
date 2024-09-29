# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

# Source files
SOURCES = main.c utils.c

# Object files (the .o files generated from source files)
OBJECTS = $(SOURCES:.c=.o)

# Executable name
EXECUTABLE = my_program

# Default target to build your program
all: $(EXECUTABLE)

# Rule to link the object files to create the executable
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE)

# Rule to compile source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule to remove generated files
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

# Phony targets
.PHONY: all clean