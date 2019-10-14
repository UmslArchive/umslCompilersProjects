//Author:   Colby Ackerman
//Class:    CS4280 Program Translations
//Assign:   Project 1
//Date:     10/20/19
//-----------------------------------------------------------------------------

#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include <map>
#include <string>

enum TokenID {
    DIGIT,
    IDENTIFIER,
    EOF___,
    OPERATOR,
    TOTAL
};

class Token {
private:
    int id, instance, lineNum;
    std::string tokStr;
    static std::map<std::string, int> instanceManager;

    void setInstance();

public:
    Token(int id, int lineNum, std::string tokStr);

    void printInstanceManager();
};

#endif