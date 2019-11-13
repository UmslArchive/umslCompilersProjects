//Author:   Colby Ackerman
//Class:    CS4280 Program Translations
//Assign:   Project 2
//Date:     11/15/19
//-----------------------------------------------------------------------------

#ifndef TESTER_H
#define TESTER_H

#include "Scanner.h"
#include "Parser.h"

class TestScanner {
private:

public:
    Scanner scanner;
    //Constructor
    TestScanner();

    //Primary scanner test
    void primaryScannerTest(std::string fileData);

    //Other tests
    void runTokenTests();
    void testTokenKeywords();
    void testPrintToken();
};

#endif