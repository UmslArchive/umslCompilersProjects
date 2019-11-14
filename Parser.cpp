//Author:   Colby Ackerman
//Class:    CS4280 Program Translations
//Assign:   Project 2
//Date:     11/15/19
//-----------------------------------------------------------------------------

#include "Parser.h"

//Constructor
Parser::Parser() :
    currentToken(Token(ERROR_tk, "PARSE_BEGIN", 0))
{}

//Init
void Parser::sendFileDataToScanner(std::string fileData) {
    scanner.loadFileData(fileData);
}

ParseTree Parser::parse() {
    return ParseTree();
}

void Parser::program() {

}

void Parser::block() {

}

void Parser::vars() {

}

void Parser::expr() {

}

void Parser::A() {

}

void Parser::N() {

}

void Parser::M() {

}

void Parser::R() {

}

void Parser::stats() {

}

void Parser::mStat() {

}

void Parser::stat() {

}

void Parser::in() {

}

void Parser::out() {

}

void Parser::IF() {

}

void Parser::loop() {

}

void Parser::assign() {

}

void Parser::RO() {

}
