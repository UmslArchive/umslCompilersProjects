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
    //Finite State Automaton transition table
    static Table FSA;
    
    //File data to be parsed.
    std::string fileData;
    int lineCount;

    //Stream objects
    char currentChar;
    std::stringstream fileDataParser;

    char readNextCharacter();

    State currentState;
public:
    Scanner();
    Token getNextToken();
    void loadFileData(std::string fileData);
};

#endif