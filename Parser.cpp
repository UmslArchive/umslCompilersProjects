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
    std::cout << "entered PROGRAM" << std::endl;
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
    std::cout << "entered BLOCK" << std::endl;
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
}

void Parser::vars() {
    std::cout << "entered VARS" << std::endl;
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
    std::cout << "entered EXPR" << std::endl;
    A();
    Z();
}
void Parser::Z() {
    std::cout << "entered Z" << std::endl;
    if(currentToken.getID() == OPERATOR_tk && currentToken.getInstance().compare("+") == 0) {
        currentToken = scanner.getNextToken();
        expr();
        return;
    }
}

void Parser::A() {
    std::cout << "entered A" << std::endl;
    N();
    Y();
}

void Parser::Y() {
    std::cout << "entered Y" << std::endl;
    if(currentToken.getID() == OPERATOR_tk && currentToken.getInstance().compare("-") == 0) {
        currentToken = scanner.getNextToken();
        A();
    }
    return;
}

void Parser::N() {
    std::cout << "entered N" << std::endl;
    M();
    X();
}

void Parser::X() {
    std::cout << "entered X" << std::endl;
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
    std::cout << "entered M" << std::endl;
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
    std::cout << "entered R" << std::endl;
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
    std::cout << "entered STATS" << std::endl;
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
    std::cout << "entered MSTAT" << std::endl;
    stat();
    if(currentToken.getID() == OPERATOR_tk && currentToken.getInstance().compare(";")) {
        currentToken = scanner.getNextToken();
        mStat();
        return;
    }
}

void Parser::stat() {
    std::cout << "entered STAT" << std::endl;
    in();
    out();
    block();
    IF();
    loop();
    assign();
}

void Parser::in() {
    std::cout << "entered IN" << std::endl;
    if(currentToken.getID() == KWD_IN_tk) {
        currentToken = scanner.getNextToken();
        if(currentToken.getID() == IDENTIFIER_tk) {
            currentToken = scanner.getNextToken();
            return;
        }
        else {
            error();
        }
    }
    return;
}

void Parser::out() {
    std::cout << "entered OUT" << std::endl;
    if(currentToken.getID() == KWD_OUT_tk) {
        currentToken = scanner.getNextToken();
        expr();
        return;
    }
}

void Parser::IF() {
    std::cout << "entered IF" << std::endl;
    if(currentToken.getID() == KWD_COND_tk) {
        currentToken = scanner.getNextToken();
        if(currentToken.getID() == OPERATOR_tk && currentToken.getInstance().compare("(") == 0) {
            currentToken = scanner.getNextToken();
            if(currentToken.getID() == OPERATOR_tk && currentToken.getInstance().compare("(") == 0) {
                currentToken = scanner.getNextToken();
                expr();
                RO();
                expr();
                if(currentToken.getID() == OPERATOR_tk && currentToken.getInstance().compare(")") == 0) {
                    currentToken = scanner.getNextToken();
                    if(currentToken.getID() == OPERATOR_tk && currentToken.getInstance().compare(")") == 0) {
                        currentToken = scanner.getNextToken();
                        stat();
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
            error();
        }
    }
    return;
}

void Parser::loop() {
    std::cout << "entered LOOP" << std::endl;
   if(currentToken.getID() == KWD_ITERATE_tk) {
        currentToken = scanner.getNextToken();
        if(currentToken.getID() == OPERATOR_tk && currentToken.getInstance().compare("(") == 0) {
            currentToken = scanner.getNextToken();
            if(currentToken.getID() == OPERATOR_tk && currentToken.getInstance().compare("(") == 0) {
                currentToken = scanner.getNextToken();
                expr();
                RO();
                expr();
                if(currentToken.getID() == OPERATOR_tk && currentToken.getInstance().compare(")") == 0) {
                    currentToken = scanner.getNextToken();
                    if(currentToken.getID() == OPERATOR_tk && currentToken.getInstance().compare(")") == 0) {
                        currentToken = scanner.getNextToken();
                        stat();
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
            error();
        }
    }
    return;
}

void Parser::assign() {
    std::cout << "entered ASSIGN" << std::endl;
    if(currentToken.getID() == IDENTIFIER_tk) {
        currentToken = scanner.getNextToken();
        if(currentToken.getID() == OPERATOR_tk && currentToken.getInstance().compare("<") == 0) {
            currentToken = scanner.getNextToken();
            if(currentToken.getID() == OPERATOR_tk && currentToken.getInstance().compare("<") == 0) {
                currentToken = scanner.getNextToken();
                expr();
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
    return;
}

void Parser::RO() {
    std::cout << "entered RO" << std::endl;
    if(currentToken.getID() == OPERATOR_tk && currentToken.getInstance().compare("<") == 0) {
        currentToken = scanner.getNextToken();
        W();
        return;
    }
    else if(currentToken.getID() == OPERATOR_tk && currentToken.getInstance().compare(">") == 0) {
        currentToken = scanner.getNextToken();
        T();
        return;
    }
    else if(currentToken.getID() == OPERATOR_tk && currentToken.getInstance().compare("=") == 0) {
        currentToken = scanner.getNextToken();
        return;
    }
    else {
        error();
    }
}

void Parser::W() {
    std::cout << "entered W" << std::endl;
    if(currentToken.getID() == OPERATOR_tk && currentToken.getInstance().compare("<") == 0) {
        currentToken = scanner.getNextToken();
        return;
    }
    else if(currentToken.getID() == OPERATOR_tk && currentToken.getInstance().compare(">") == 0) {
        currentToken = scanner.getNextToken();
        return;
    }
    
    return;
}

void Parser::T() {
    std::cout << "entered T" << std::endl;
    if(currentToken.getID() == OPERATOR_tk && currentToken.getInstance().compare(">") == 0) {
        currentToken = scanner.getNextToken();
        return;
    }

    return;
}

void Parser::error() {
    std::cerr << "PARSE ERROR" << std::endl;
    currentToken.printToken();
    exit(1);
}
