//Author:   Colby Ackerman
//Class:    CS4280 Program Translations
//Assign:   Project 1
//Date:     10/20/19
//-----------------------------------------------------------------------------

#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <map>
#include <vector>

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

    TOTAL_st, //placed here since there rest are final states
     
    FIN_EOF_st,
    FIN_IDENT_st,
    FIN_INT_st,
    FIN_OP_st,
    ERROR_st
};

class Table {
private:
    //Column mapping
    static bool isInitialized;
    static std::map<char, int> sigma;

    //2D table (vector of vectors)
    static std::vector<std::vector<int>> fsaTable;

    void buildFsaTable();

public:
    //Constructor
    Table();

    State getNextState(State currentState, char nextChar);
};

#endif