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
            std::cout << "exit BLOCK" << std::endl;
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
                    std::cout << "exit VARS" << std::endl;
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
        std::cout << "exit VARS" << std::endl;
        return;
    }
}

void Parser::expr() {
    std::cout << "entered EXPR" << std::endl;
    A();
    Z();
    std::cout << "exit EXPR" << std::endl;
}
void Parser::Z() {
    std::cout << "entered Z" << std::endl;
    if(currentToken.getID() == OPERATOR_tk && currentToken.getInstance().compare("+") == 0) {
        currentToken = scanner.getNextToken();
        expr();
        std::cout << "exit Z" << std::endl;
        return;
    }
}

void Parser::A() {
    std::cout << "entered A" << std::endl;
    N();
    Y();
    std::cout << "exit A" << std::endl;
}

void Parser::Y() {
    std::cout << "entered Y" << std::endl;
    if(currentToken.getID() == OPERATOR_tk && currentToken.getInstance().compare("-") == 0) {
        currentToken = scanner.getNextToken();
        A();
    }
    std::cout << "exit Y" << std::endl;
    return;
}

void Parser::N() {
    std::cout << "entered N" << std::endl;
    M();
    X();
    std::cout << "exit N" << std::endl;
}

void Parser::X() {
    std::cout << "entered X" << std::endl;
    if(currentToken.getID() == OPERATOR_tk && currentToken.getInstance().compare("/") == 0) {
        currentToken = scanner.getNextToken();
        N();
        std::cout << "exit X" << std::endl;
        return;
    }
    else if(currentToken.getID() == OPERATOR_tk && currentToken.getInstance().compare("*") == 0) {
        currentToken = scanner.getNextToken();
        N();
        std::cout << "exit X" << std::endl;
        return;
    }
}

void Parser::M() {
    std::cout << "entered M" << std::endl;
    if(currentToken.getID() == OPERATOR_tk && currentToken.getInstance().compare("-") == 0) {
        currentToken = scanner.getNextToken();
        M();
        std::cout << "exit M" << std::endl;
        return;
    }
    else {
        R();
        std::cout << "exit M" << std::endl;
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
            std::cout << "exit R" << std::endl;
            return;
        }
        else {
            error();
        }
            
    }
    else if(currentToken.getID() == IDENTIFIER_tk) {
        currentToken = scanner.getNextToken();
        std::cout << "exit R" << std::endl;
        return;
    }
    else if(currentToken.getID() == INTEGER_tk) {
        currentToken = scanner.getNextToken();
        std::cout << "exit R" << std::endl;
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
        std::cout << "exit STATS" << std::endl;
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
        std::cout << "exit MSTAT" << std::endl;
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
    if(currentToken.getID() == OPERATOR_tk && currentToken.getInstance().compare(";") == 0) {
        currentToken = scanner.getNextToken();
        std::cout << "exit STAT" << std::endl;
        return;
    }
}

void Parser::in() {
    std::cout << "entered IN" << std::endl;
    if(currentToken.getID() == KWD_IN_tk) {
        currentToken = scanner.getNextToken();
        if(currentToken.getID() == IDENTIFIER_tk) {
            currentToken = scanner.getNextToken();
            std::cout << "exit IN" << std::endl;
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
        std::cout << "exit OUT" << std::endl;
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
                        std::cout << "exit IF" << std::endl;
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
    std::cout << "exit IF" << std::endl;
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
                        std::cout << "exit LOOP" << std::endl;
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
    std::cout << "exit LOOP" << std::endl;
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
                std::cout << "exit ASSIGN" << std::endl;
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
    std::cout << "exit ASSIGN" << std::endl;
    return;
}

void Parser::RO() {
    std::cout << "entered RO" << std::endl;
    if(currentToken.getID() == OPERATOR_tk && currentToken.getInstance().compare("<") == 0) {
        currentToken = scanner.getNextToken();
        W();
        std::cout << "exit RO" << std::endl;
        return;
    }
    else if(currentToken.getID() == OPERATOR_tk && currentToken.getInstance().compare(">") == 0) {
        currentToken = scanner.getNextToken();
        T();
        std::cout << "exit RO" << std::endl;
        return;
    }
    else if(currentToken.getID() == OPERATOR_tk && currentToken.getInstance().compare("=") == 0) {
        currentToken = scanner.getNextToken();
        std::cout << "exit RO" << std::endl;
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
        std::cout << "exit W" << std::endl;
        return;
    }
    else if(currentToken.getID() == OPERATOR_tk && currentToken.getInstance().compare(">") == 0) {
        currentToken = scanner.getNextToken();
        std::cout << "exit W" << std::endl;
        return;
    }

    std::cout << "exit W" << std::endl;
    return;
}

void Parser::T() {
    std::cout << "entered T" << std::endl;
    if(currentToken.getID() == OPERATOR_tk && currentToken.getInstance().compare(">") == 0) {
        currentToken = scanner.getNextToken();
        std::cout << "exit T" << std::endl;
        return;
    }

    std::cout << "exit T" << std::endl;
    return;
}

void Parser::error() {
    std::cerr << "PARSE ERROR" << std::endl;
    currentToken.printToken();
    exit(1);
}
