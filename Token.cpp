//Author:   Colby Ackerman
//Class:    CS4280 Program Translations
//Assign:   Project 1
//Date:     10/20/19
//-----------------------------------------------------------------------------

#include "Token.h"

//Static init
bool Token::isInitialized = false;
std::vector<std::string> Token::keywords;

//Constructor
Token::Token(TokenID id, std::string instance, int lineNum) 
    : id(id), instance(instance), lineNum(lineNum)
{
    if(!isInitialized) {
        keywords.push_back("start");
        keywords.push_back("stop");
        keywords.push_back("iterate");
        keywords.push_back("void");
        keywords.push_back("var");
        keywords.push_back("return");
        keywords.push_back("in");
        keywords.push_back("out");
        keywords.push_back("program");
        keywords.push_back("cond");
        keywords.push_back("then");
        keywords.push_back("let");

        isInitialized = true;
    }
}

//Accessors
TokenID Token::getID() { return id; }
int Token::getLineNum() { return lineNum; }
std::string Token::getInstance() { return instance; }

//Debug
void Token::printKeywords() {
    for(int i = 0; i < keywords.size(); ++i) {
        std::cout << keywords.at(i) << " ";
    }
    std::cout << std::endl;

    return;
}