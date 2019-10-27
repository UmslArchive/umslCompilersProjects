# Author:	Colby Ackerman
# Class:	CS4280 Program Translations
# Assign:	Project 1
# Date:		10/20/19
##################################################

CC = g++
CFLAGS = -g
TARGET = scanner
OBJS = main.o Scanner.o Table.o TestScanner.o Token.o
.SUFFIXES: .cpp .o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

.cpp.o:
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	rm -f *.o $(TARGET)