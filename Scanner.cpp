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

    //Bool to store if first call to this function
    static bool first = true;

    //Reset state
    currentState = START_st;

    //Get first character of file
    if(first) {
        currentChar = readNextCharacter();
        first = false;
    }
        
    int count = 0;

    //Loop until a finish state is reached
    while(1) {
        //Check for a final state:
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

        //DEBUG
        //std::cout << "currentState:" << currentState << std::endl;;
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
            fileDataParser.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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