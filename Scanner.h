//Author:   Colby Ackerman
//Class:    CS4280 Program Translations
//Assign:   Project 1
//Date:     10/20/19
//-----------------------------------------------------------------------------

#ifndef SCANNER_H
#define SCANNER_H

#include "Table.h"
#include "Token.h"

class Scanner {
private:
    static Table FSA;

    char readNextCharacter();
public:
    Scanner();
    Token getNextToken();
};

#endif