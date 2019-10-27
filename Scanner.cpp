//Author:   Colby Ackerman
//Class:    CS4280 Program Translations
//Assign:   Project 1
//Date:     10/20/19
//-----------------------------------------------------------------------------

#include "Scanner.h"

//Static init
Table Scanner::FSA = Table();

//Constructor
Scanner::Scanner() 
:fileData(""), lineCount(0)
{}


Token Scanner::getNextToken() {

    //Token attributes
    TokenID tid;
    std::string tokenInstance = "";

    //Reset state
    currentState = START_st;
    char currentChar = readNextCharacter();
    int count = 0;

    //Loop until a finish state is reached
    while(1) {

        //Check for final states:
        if(currentState == FIN_EOF_st) {
            tid = EOF_tk;
            break;
        }

        if( currentState == FIN_IDENT_st) {
            tid = IDENTIFIER_tk;
            break;
        }

        if(currentState == FIN_OP_st ) {
            tid = OPERATOR_tk;
            break;
        }

        if(currentState == FIN_INT_st) {
            tid = INTEGER_tk;
            break;
        }

        if(currentState == ERROR_st) {
            std::cout << "ERROR\n";
            break;
        }

        tokenInstance.push_back(currentChar);
        currentState = FSA.lookup(currentState, currentChar);
        currentChar = readNextCharacter();
        //std::cout << "currentState:" << currentState << std::endl;;

        /* count++;
        if(count > 30) finish = true; */
    }
    
    return Token(tid, tokenInstance , lineCount);
}

char Scanner::readNextCharacter() {
    char c;
    if(fileDataParser.get(c)) {
        //std::cout << c;
        if(c == '\n')
            lineCount++;

        if(c == '#') {
            fileDataParser.ignore(500, '\n');
            lineCount++;
        }

        return c;
    }

    if(fileDataParser.eof()) {
        currentState = FIN_EOF_st;
        std::cout << "EOF\n";
        return -1;
    }
    
   return 0;
    
}

void Scanner::loadFileData(std::string fileData) {
    this->fileData = fileData;
    fileDataParser.str(this->fileData);
}