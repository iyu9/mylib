###########################
# C/C++ makefile template
###########################

# Define Macros
PROGRAM = main
SRCS = main.cpp
OBJS = main.o
CC = g++
CFLAGS = -W

.SUFFIXES: .cpp .o

#Primary Target
$(PROGRAM):
	$(CC) $(PROGRAM) $^

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(PRORAM) $(OBJS)
