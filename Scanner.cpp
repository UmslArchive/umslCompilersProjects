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
: fileDataParser(std::stringstream()), fileData(""), lineCount(0)
{}


Token Scanner::getNextToken() {
    std::string tokenInstance = "";

    //Reset state
    currentState = START_st;

    //Loop until a finish state is reached
    bool finish = false;
    while(!finish) {
        char currentChar = readNextCharacter();
        tokenInstance.push_back(currentChar);
        currentState = FSA.lookup(currentState, currentChar);
        finish = true;
    }
    
    return Token(EOF_tk, tokenInstance , 3);
}

char Scanner::readNextCharacter() {
    char c;
    if(fileDataParser.get(c)) {
        std::cout << c;
        return c;
    }

    if(fileDataParser.eof()) {
        std::cout << "EOF\n";
        return -1;
    }
    
   return 0;
    
}

void Scanner::loadFileData(std::string fileData) {
    this->fileData = fileData;
    fileDataParser.str(this->fileData);
}