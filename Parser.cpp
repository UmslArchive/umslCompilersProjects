//Author:   Colby Ackerman
//Class:    CS4280 Program Translations
//Assign:   Project 2
//Date:     11/15/19
//-----------------------------------------------------------------------------

#include "Parser.h"

Parser::Parser() :
    currentToken(Token(ERROR_tk, "PARSE_BEGIN", 0))
{}

void Parser::sendFileDataToScanner(std::string fileData) {
    scanner.loadFileData(fileData);
}