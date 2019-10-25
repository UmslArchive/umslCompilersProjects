//Author:   Colby Ackerman
//Class:    CS4280 Program Translations
//Assign:   Project 1
//Date:     10/20/19
//-----------------------------------------------------------------------------

#ifndef TEST_SCANNER_H
#define TEST_SCANNER_H

#include "Scanner.h"

class TestScanner {
private:
    Scanner scanner;

public:
    //Constructor
    TestScanner();

    //Primary scanner test
    void primaryScannerTest();

    //Other tests
    void runTokenTests();
    void testTokenKeywords();
    void testPrintToken();
};

#endif