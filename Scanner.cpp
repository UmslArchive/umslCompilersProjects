//Author:   Colby Ackerman
//Class:    CS4280 Program Translations
//Assign:   Project 1
//Date:     10/20/19
//-----------------------------------------------------------------------------

#include "Scanner.h"

Table Scanner::FSA = Table();

Scanner::Scanner() {

}

Token Scanner::getNextToken() {
    return Token(EOF_tk, "hi", 3);
}