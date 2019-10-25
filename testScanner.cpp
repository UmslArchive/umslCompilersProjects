//Author:   Colby Ackerman
//Class:    CS4280 Program Translations
//Assign:   Project 1
//Date:     10/20/19
//-----------------------------------------------------------------------------
#include "TestScanner.h"

//Scanner tests
void TestScanner::testScanner() {
    
}

//Run all token tests
void TestScanner::runTokenTests() {
    testTokenKeywords();
}

//Test to ensure that static member keywords is being initialized only once.
void TestScanner::testTokenKeywords() {
    std::cout << "\nTest: Token keywords vector is static" << std::endl <<
    "Should see 3 sets of the same words separated by an extra newline." << 
    std::endl << "---------" << std::endl;
    Token a(IDENTIFIER, "TokenA", 3);
    Token b(DIGIT, "TokenB", 4);
    Token c(EOF___, "TokenC", 5);

    std::cout << a.getInstance() << ": ";
    a.printKeywords();
    std::cout << std::endl;
    std::cout << b.getInstance() << ": ";
    b.printKeywords();
    std::cout << std::endl;
    std::cout << c.getInstance() << ": ";
    c.printKeywords();
    std::cout << std::endl;
}