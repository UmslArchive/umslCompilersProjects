//Author:   Colby Ackerman
//Class:    CS4280 Program Translations
//Assign:   Project 1
//Date:     10/20/19
//-----------------------------------------------------------------------------

#ifndef TEST_SCANNER_H
#define TEST_SCANNER_H

#include "Token.h"
#include "Scanner.h"

class TestScanner {
public:
    //Primary scanner test
    void testScanner();

    //Other tests
    void runTokenTests();
    void testTokenKeywords();
    void testPrintToken();
};

#endif