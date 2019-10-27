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
            tokenInstance = "EOF";
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
            std::cerr << "ERROR on line#" << lineCount << std::endl;
            break;
        }

        //Check table
        currentState = FSA.lookup(currentState, currentChar);

        //Only push onto tokenInstance string if exited start state
        if(currentState != START_st) {
            tokenInstance.push_back(currentChar);
        }

        //Read 
        currentChar = readNextCharacter();

        //Ignore comments
        while(currentChar == -1) {
            currentChar = readNextCharacter();
        }
        //std::cout << "currentState:" << currentState << std::endl;;

        /* count++;
        if(count > 30) finish = true; */
    }
    
    return Token(tid, tokenInstance , lineCount);
}

char Scanner::readNextCharacter() {
    char c;
    if(fileDataParser.get(c)) {

        //Ignore newlines
        if(c == '\n') {
            lineCount++;
            return -1;
        }

        //Ignore comments
        if(c == '#') {
            fileDataParser.ignore(500, '\n');
            lineCount++;
            return -1;
        }

        return c;
    }

    if(fileDataParser.eof()) {
        currentState = FIN_EOF_st;
        return c;
    }
    
   return 0;
    
}

void Scanner::loadFileData(std::string fileData) {
    this->fileData = fileData;
    fileDataParser.str(this->fileData);
}