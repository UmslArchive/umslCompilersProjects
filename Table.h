//Author:   Colby Ackerman
//Class:    CS4280 Program Translations
//Assign:   Project 1
//Date:     10/20/19
//-----------------------------------------------------------------------------

#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <map>

//Rows
enum State {
    START_st,
    MID_ID_st,
    MID_INT_st,
    MID_OP_st,
    GT_st,
    LT_st,
    ASSIGN_st,
    EQ_st,
    LT_EQ_st,
    GT_EQ_st,
    FIN_EOF_st,
    FIN_IDENT_st,
    FIN_INT_st,
    FIN_OP_st,
    ERROR_st,
    TOTAL_st
};

class Table {
private:
    //Column mapping
    static bool isInitialized;
    static std::map<char, int> sigma;

    State currentState;

public:
    //Constructor
    Table();

    State getNextState(char nextChar);
};

#endif