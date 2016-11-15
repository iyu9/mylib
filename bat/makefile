###########################
# C/C++ makefile template
###########################

# Define Macros
PROGRAM = main
SRCS = main.cpp
OBJS = main.o
CC = g++
CFLAGS = -W

# Suffix Rule
.SUFFIXES: .cpp .o

# Primary Target
$(PROGRAM): $(OBJS)
		$(CC) -o $(PROGRAM) $^

.c.o:
		$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
		$(RM) $(PRORAM) $(OBJS)
