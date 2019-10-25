//Author:   Colby Ackerman
//Class:    CS4280 Program Translations
//Assign:   Project 1
//Date:     10/20/19
//-----------------------------------------------------------------------------
#include "TestScanner.h"

//Primary scanner test
void TestScanner::testScanner() {

}

//Run all token tests
void TestScanner::runTokenTests() {
    testTokenKeywords();
    testPrintToken();
}

//Test to ensure that static member keywords is being initialized only once
void TestScanner::testTokenKeywords() {

    //Arbitrarily declare 3 tokens
    Token a(IDENTIFIER, "TokenA", 3);
    Token b(INTEGER, "TokenB", 4);
    Token c(EOF___, "TokenC", 5);

    //Print Test info
    std::cout << "\nTEST: Token keywords vector is static" << std::endl <<
    "Should see 3 sets of the same words separated by an extra newline." << 
    std::endl << "---------" << std::endl;

    //Print each token's keyword string vector
    std::cout << a.getInstance() << ": ";
    a.printKeywords();
    std::cout << b.getInstance() << ": ";
    b.printKeywords();
    std::cout << c.getInstance() << ": ";
    c.printKeywords();
    std::cout << "=========" << std::endl;
    std::cout << "=========" << std::endl;

    return;
}

void TestScanner::testPrintToken() {
    //Print test info
    std::cout << "\nTEST: Tokens are properly being assigned values\n---------\n";

    //Arbitrarily declare 3 tokens
    Token a(IDENTIFIER, "TokenA", 3);
    Token b(INTEGER, "TokenB", 4);
    Token c(EOF___, "TokenC", 5);

    a.printToken();
    b.printToken();
    c.printToken();
    std::cout << std::endl;
}