# TARGET name must be from inside the directory
TARGET=main

# all .cpp files in this directory are my sources
SOURCES=$(wildcard *.cpp)

OBJS=$(SOURCES:.cpp=.o)

INC_DIR=../include

# CC is a a reserved word, the compiler you use, gcc for C and g++ for C++
CC=g++

# CFLAGS is C specific keyword while CXXFLAGS is for C++
CFLAGS=-pedantic -Wall -Werror -Wconversion -ansi -g -I$(INC_DIR)
CXXFLAGS=$(CFLAGS)
LDFLAGS= -g

# If there is a file that you want to compile that is in your directory named clearn run gdb, it will ignore when calling makefile
.PHONY: clean run gdb

# Does the compiling automatically
$(TARGET): $(OBJS)

include .depends

.depends:
	$(CC) -MM -I$(INC_DIR) $(SOURCES) > .depends

clean:
	rm -f $(OBJS) $(TARGET) .depends

run: $(TARGET)
	./$(TARGET)

# Do not forget to add '-g' to CFLAGS
gdb: $(TARGET)
	gdb -q ./$(TARGET)

check: $(TARGET)
	valgrind ./$(TARGET)
