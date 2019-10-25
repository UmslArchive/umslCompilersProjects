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

std::string Token::idName(int id) {
    switch(id) {
        case DIGIT: return "DIGIT";
        case IDENTIFIER: return "IDENTIFIER";
        case EOF___: return "EOF___";
        case OPERATOR: return "OPERATOR";
        case KEYWORD: return "KEYWORD";
        
        default:
            std::cerr << "ERROR: Invalid selection made in function idName(int id)" << std::endl;
            return "INVALID";
    }
}

//Debug
void Token::printToken() {
    int columnSpacing = 23;

    std::stringstream ss;
    std::string idString;
    std::string instanceString;
    std::string lineNumString;

    //Create idString
    ss << "ID { " << id << ", " << idName(id) << " }";
    idString = ss.str();

    ss.str(""); //Clear ss buffer

    //Create instanceString
    ss << "INSTANCE { " << instance << " }";
    instanceString = ss.str();

    ss.str(""); //Clear ss buffer

    //Create lineNumString
    ss << "LINE# " << lineNum;
    lineNumString=  ss.str();

    //Print token
    std::cout << std::left << std::setw(columnSpacing) << idString;
    std::cout << std::left << std::setw(columnSpacing) << instanceString;
    std::cout << std::left << std::setw(columnSpacing) << lineNumString;
    std::cout << std::endl;
}

void Token::printKeywords() {
    for(int i = 0; i < keywords.size(); ++i) {
        std::cout << keywords.at(i) << " ";
    }
    std::cout << std::endl;

    return;
}
