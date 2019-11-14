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
    ParseTree root;
    root = program();

    return root;
}

ParseTree Parser::program() {
    currentToken = scanner.getNextToken();
    vars();
    block();

    if(currentToken.getID() == EOF_tk) {
        std::cout << "FINISHED" << std::endl;
        currentToken.printToken();
        return ParseTree();
    }
    else {
        error();
    }

    return ParseTree();
}

void Parser::block() {
    if(currentToken.getID() == KWD_START_tk){
        currentToken = scanner.getNextToken();
        vars();
        stats();
        if(currentToken.getID() == KWD_STOP_tk) {
            currentToken = scanner.getNextToken();
            return;
        }
        else {
            error();
        }
    }
    else {
        error();
    }
}

void Parser::vars() {
    if(currentToken.getID() == KWD_VAR_tk) {
        currentToken = scanner.getNextToken();
        if(currentToken.getID() == IDENTIFIER_tk) {
            currentToken = scanner.getNextToken();
            if(currentToken.getID() == OPERATOR_tk && currentToken.getInstance().compare(":") == 0) {
                currentToken = scanner.getNextToken();
                if(currentToken.getID() == INTEGER_tk) {
                    currentToken = scanner.getNextToken();
                    vars();
                    return;
                }
                else {
                    error();
                }
            }
            else {
                error();
            }
        }
        else {
            error();
        }
    }
    else {
        return;
    }
}

void Parser::expr() {
    A();
    Z();
}
void Parser::Z() {
    if(currentToken.getID() == OPERATOR_tk && currentToken.getInstance().compare("+") == 0) {
        currentToken = scanner.getNextToken();
        expr();
        return;
    }
}

void Parser::A() {
    N();
    Y();
}

void Parser::Y() {
    if(currentToken.getID() == OPERATOR_tk && currentToken.getInstance().compare("-") == 0) {
        currentToken = scanner.getNextToken();
        A();
    }
    return;
}

void Parser::N() {
    M();
    X();
}

void Parser::X() {
    if(currentToken.getID() == OPERATOR_tk && currentToken.getInstance().compare("/") == 0) {
        currentToken = scanner.getNextToken();
        N();
        return;
    }
    else if(currentToken.getID() == OPERATOR_tk && currentToken.getInstance().compare("*") == 0) {
        currentToken = scanner.getNextToken();
        N();
        return;
    }
}

void Parser::M() {
    if(currentToken.getID() == OPERATOR_tk && currentToken.getInstance().compare("-") == 0) {
        currentToken = scanner.getNextToken();
        M();
        return;
    }
    else {
        R();
        return;
    }
}

void Parser::R() {
    if(currentToken.getID() == OPERATOR_tk && currentToken.getInstance().compare("[") == 0) {
        currentToken = scanner.getNextToken();
        expr();
        if(currentToken.getID() == OPERATOR_tk && currentToken.getInstance().compare("]") == 0) {
            currentToken = scanner.getNextToken();
            return;
        }
        else {
            error();
        }
            
    }
    else if(currentToken.getID() == IDENTIFIER_tk) {
        currentToken = scanner.getNextToken();
        return;
    }
    else if(currentToken.getID() == INTEGER_tk) {
        currentToken = scanner.getNextToken();
        return;
    }
    else {
        error();
    }
}

void Parser::stats() {
    stat();
    if(currentToken.getID() == OPERATOR_tk && currentToken.getInstance().compare(";") == 0) {
        currentToken = scanner.getNextToken();
        mStat();
        return;
    }
    else {
        error();
    }
}

void Parser::mStat() {

}

void Parser::stat() {
    if(currentToken.getID() == KWD_IN_tk) {
        currentToken = scanner.getNextToken();
        in();
        return;
    }
    else if(currentToken.getID() == KWD_OUT_tk) {
        currentToken = scanner.getNextToken();
        out();
        return;
    }
    else if(currentToken.getID() == KWD_START_tk) {
        currentToken = scanner.getNextToken();
        block();
        return;
    }
    else if(currentToken.getID() == KWD_COND_tk) {
        currentToken = scanner.getNextToken();
        IF();
        return;
    }
    else if(currentToken.getID() == KWD_ITERATE_tk) {
        currentToken = scanner.getNextToken();
        loop();
        return;
    }
    else if(currentToken.getID() == IDENTIFIER_tk) {
        currentToken = scanner.getNextToken();
        assign();
        return;
    }
    else {
        error();
    }
}

void Parser::in() {

}

void Parser::out() {
    expr();
    return;
}

void Parser::IF() {

}

void Parser::loop() {

}

void Parser::assign() {

}

void Parser::RO() {

}

void Parser::W() {

}

void Parser::T() {

}

void Parser::error() {
    std::cerr << "PARSE ERROR" << std::endl;
    currentToken.printToken();
    exit(1);
}