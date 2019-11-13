//Author:   Colby Ackerman
//Class:    CS4280 Program Translations
//Assign:   Project 2
//Date:     11/15/19
//-----------------------------------------------------------------------------

#ifndef PARSER_H
#define PARSER_H

#include "Scanner.h"

class Parser  {
private:
    Scanner scanner;
    Token currentToken;

    //Nonterminal functions
    void program();
    void block();
    void vars();
    void expr();
    void A();
    void N();
    void M();
    void R();
    void stats();
    void mStat();
    void stat();
    void in();
    void out();
    void IF();
    void loop();
    void assign();
    void RO();


public:
    
};

#endif