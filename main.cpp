//Author:   Colby Ackerman
//Class:    CS4280 Program Translations
//Assign:   Project 1
//Date:     10/20/19
//-----------------------------------------------------------------------------

#include "TestScanner.h"

//Change this to either run all tests or just the scanner test. [0, 1]
#define PRIMARY_TEST_ONLY 1

int main(int argc, char* argv[]) {

    TestScanner tester;

    if(PRIMARY_TEST_ONLY == 1) {
        tester.primaryScannerTest("");
    }
    else {
        tester.runTokenTests();
        tester.primaryScannerTest("");
    }

    return 0;
}