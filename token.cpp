//Author:   Colby Ackerman
//Class:    CS4280 Program Translations
//Assign:   Project 1
//Date:     10/20/19
//-----------------------------------------------------------------------------

#include "token.h"

//Init instanceManager
std::map<std::string, int> Token::instanceManager = std::map<std::string, int>();

Token::Token(int id, int lineNum, std::string tokStr) :
id(id), lineNum(lineNum), tokStr(tokStr) {
    setInstance();
}

void Token::setInstance() {
    //Search tokenInstanceManager for an occurence of tokString
    std::map<std::string, int>::iterator it = instanceManager.find(tokStr);
    if(it == instanceManager.end()) {
        //first instance
        instanceManager.insert(std::pair<std::string, int>(tokStr, 0));
    }
    else {
        //2nd or higher instance
        it->second += 1;
    }
    return;
}

void Token::printInstanceManager() {
    std::map<std::string, int>::iterator beginning = instanceManager.begin();
    std::map<std::string, int>::iterator ending = instanceManager.end();

    std::cout << "INSTANCE MANAGER:\n";
    for(std::map<std::string, int>::iterator it = beginning; it != ending; ++it) {
        std::cout << it->first << "=>" << it->second << "\n";
    }
    std::cout << std::endl;
}