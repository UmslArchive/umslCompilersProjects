//Author:   Colby Ackerman
//Class:    CS4280 Program Translations
//Assign:   Project 1
//Date:     10/20/19
//-----------------------------------------------------------------------------

#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>

enum TokenID {
    INTEGER,
    IDENTIFIER,
    EOF___,
    OPERATOR,

    //Keywords
    KWD_START,
    KWD_STOP,
    KWD_ITERATE,
    KWD_VOID,
    KWD_VAR,
    KWD_RETURN,
    KWD_IN,
    KWD_OUT,
    KWD_PROGRAM,
    KWD_COND,
    KWD_THEN,
    KWD_LET,
    
    TOTAL
};

class Token {
private:
    TokenID id;
    int lineNum;
    std::string instance;

    //This is used to sortof cheeze the scanner in a way that I can make a simpler finite-state-automata.
    //After an the identifier token state is reached, the scanner will perform a check to see if it is
    //a keyword, then modify the token to be returned accordingly.
    static bool isInitialized;
    static std::vector<std::string> keywords; //had to do it this way because c++98

public:
    //Constructor
    Token(TokenID id, std::string instance, int lineNum);

    //Accessors
    TokenID getID();
    std::string idName(int id);
    int getLineNum();
    std::string getInstance();

    //Debug
    void printToken();
    void printKeywordVector();
};

#endif