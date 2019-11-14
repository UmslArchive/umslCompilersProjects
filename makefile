# Author:	Colby Ackerman
# Class:	CS4280 Program Translations
# Assign:	Project 2
# Date:		11/15/19
##################################################

CC = g++
CFLAGS =
TARGET = frontEnd
OBJS = main.o Scanner.o Table.o Tester.o Token.o TestTree.o ParseTree.o Parser.o
.SUFFIXES: .cpp .o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

.cpp.o:
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	rm -f *.o $(TARGET)