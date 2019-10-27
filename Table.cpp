//Author:   Colby Ackerman
//Class:    CS4280 Program Translations
//Assign:   Project 1
//Date:     10/20/19
//-----------------------------------------------------------------------------

#include "Table.h"

//Static init
bool Table::isInitialized = false;
std::map<char, int> Table::sigma;
std::vector< std::vector<int> > Table::fsaTable;

//Constructor
Table::Table() {    
    //Start values at 1 because when using the [] operator with a std::map,
    //0 is returned if the key is not found.
    int value = 1;

    //Initialize sigma
    if(!isInitialized) {

        sigma = std::map<char, int>();
        
        //As the scanner reads in the file character by character, the character
        //will be categorized into one of these 7 categories. Ended up needing
        //to do this because otherwise the state transition table would've been
        //huge.
        
        //Special Operators
        sigma.insert(std::pair<char, int>('=', value++));
        sigma.insert(std::pair<char, int>('<', value++));
        sigma.insert(std::pair<char, int>('>', value++));

        //alpha
        sigma.insert(std::pair<char, int>('A', value++));

        //Other operators
        sigma.insert(std::pair<char, int>('O', value++));      

        //digits
        sigma.insert(std::pair<char, int>('D', value++));

        //Whitespace
        sigma.insert(std::pair<char, int>('W', value++));

        //EOF
        sigma.insert(std::pair<char, int>('E', value++));

        //Build the table
        buildFsaTable();

        isInitialized = true;
    }
}

void Table::buildFsaTable() {
    //Allocate space
    for(int i = 0; i < TOTAL_st; ++i) {
        fsaTable.push_back(std::vector<int>(sigma.size()));
    }

    //Add state transitions:

    //Start    
    fsaTable[START_st][sigma['='] - 1] = ASSIGN_st;
    fsaTable[START_st][sigma['<'] - 1] = LT_st;
    fsaTable[START_st][sigma['>'] - 1] = GT_st;
    fsaTable[START_st][sigma['A'] - 1] = MID_ID_st;
    fsaTable[START_st][sigma['O'] - 1] = MID_OP_st;
    fsaTable[START_st][sigma['D'] - 1] = MID_INT_st;
    fsaTable[START_st][sigma['W'] - 1] = START_st;
    fsaTable[START_st][sigma['E'] - 1] = FIN_EOF_st;

    //Mid identifier
    fsaTable[MID_ID_st][sigma['='] - 1] = FIN_IDENT_st;
    fsaTable[MID_ID_st][sigma['<'] - 1] = FIN_IDENT_st;
    fsaTable[MID_ID_st][sigma['>'] - 1] = FIN_IDENT_st;
    fsaTable[MID_ID_st][sigma['A'] - 1] = MID_ID_st;
    fsaTable[MID_ID_st][sigma['O'] - 1] = FIN_IDENT_st;
    fsaTable[MID_ID_st][sigma['D'] - 1] = MID_ID_st;
    fsaTable[MID_ID_st][sigma['W'] - 1] = FIN_IDENT_st;
    fsaTable[MID_ID_st][sigma['E'] - 1] = FIN_IDENT_st;

    //Mid integer
    fsaTable[MID_INT_st][sigma['='] - 1] = FIN_INT_st;
    fsaTable[MID_INT_st][sigma['<'] - 1] = FIN_INT_st;
    fsaTable[MID_INT_st][sigma['>'] - 1] = FIN_INT_st;
    fsaTable[MID_INT_st][sigma['A'] - 1] = FIN_INT_st;
    fsaTable[MID_INT_st][sigma['O'] - 1] = FIN_INT_st;
    fsaTable[MID_INT_st][sigma['D'] - 1] = MID_INT_st;
    fsaTable[MID_INT_st][sigma['W'] - 1] = FIN_INT_st;
    fsaTable[MID_INT_st][sigma['E'] - 1] = FIN_INT_st;
    
    //Mid operator
    fsaTable[MID_OP_st][sigma['='] - 1] = FIN_OP_st;
    fsaTable[MID_OP_st][sigma['<'] - 1] = FIN_OP_st;
    fsaTable[MID_OP_st][sigma['>'] - 1] = FIN_OP_st;
    fsaTable[MID_OP_st][sigma['A'] - 1] = FIN_OP_st;
    fsaTable[MID_OP_st][sigma['O'] - 1] = FIN_OP_st;
    fsaTable[MID_OP_st][sigma['D'] - 1] = FIN_OP_st;
    fsaTable[MID_OP_st][sigma['W'] - 1] = FIN_OP_st;
    fsaTable[MID_OP_st][sigma['E'] - 1] = FIN_OP_st;

    //Greater than operator
    fsaTable[GT_st][sigma['='] - 1] = GT_EQ_st;
    fsaTable[GT_st][sigma['<'] - 1] = FIN_OP_st;
    fsaTable[GT_st][sigma['>'] - 1] = FIN_OP_st;
    fsaTable[GT_st][sigma['A'] - 1] = FIN_OP_st;
    fsaTable[GT_st][sigma['O'] - 1] = FIN_OP_st;
    fsaTable[GT_st][sigma['D'] - 1] = FIN_OP_st;
    fsaTable[GT_st][sigma['W'] - 1] = FIN_OP_st;
    fsaTable[GT_st][sigma['E'] - 1] = FIN_OP_st;

    //Less than operator
    fsaTable[LT_st][sigma['='] - 1] = LT_EQ_st;
    fsaTable[LT_st][sigma['<'] - 1] = FIN_OP_st;
    fsaTable[LT_st][sigma['>'] - 1] = FIN_OP_st;
    fsaTable[LT_st][sigma['A'] - 1] = FIN_OP_st;
    fsaTable[LT_st][sigma['O'] - 1] = FIN_OP_st;
    fsaTable[LT_st][sigma['D'] - 1] = FIN_OP_st;
    fsaTable[LT_st][sigma['W'] - 1] = FIN_OP_st;
    fsaTable[LT_st][sigma['E'] - 1] = FIN_OP_st;


    //Assignment operator
    fsaTable[ASSIGN_st][sigma['='] - 1] = EQ_st;
    fsaTable[ASSIGN_st][sigma['<'] - 1] = FIN_OP_st;
    fsaTable[ASSIGN_st][sigma['>'] - 1] = FIN_OP_st;
    fsaTable[ASSIGN_st][sigma['A'] - 1] = FIN_OP_st;
    fsaTable[ASSIGN_st][sigma['O'] - 1] = FIN_OP_st;
    fsaTable[ASSIGN_st][sigma['D'] - 1] = FIN_OP_st;
    fsaTable[ASSIGN_st][sigma['W'] - 1] = FIN_OP_st;
    fsaTable[ASSIGN_st][sigma['E'] - 1] = FIN_OP_st;

    //Equality comparison operator
    fsaTable[EQ_st][sigma['='] - 1] = FIN_OP_st;
    fsaTable[EQ_st][sigma['<'] - 1] = FIN_OP_st;
    fsaTable[EQ_st][sigma['>'] - 1] = FIN_OP_st;
    fsaTable[EQ_st][sigma['A'] - 1] = FIN_OP_st;
    fsaTable[EQ_st][sigma['O'] - 1] = FIN_OP_st;
    fsaTable[EQ_st][sigma['D'] - 1] = FIN_OP_st;
    fsaTable[EQ_st][sigma['W'] - 1] = FIN_OP_st;
    fsaTable[EQ_st][sigma['E'] - 1] = FIN_OP_st;

    //Less than equal comparison operator
    fsaTable[LT_EQ_st][sigma['='] - 1] = FIN_OP_st;
    fsaTable[LT_EQ_st][sigma['<'] - 1] = FIN_OP_st;
    fsaTable[LT_EQ_st][sigma['>'] - 1] = FIN_OP_st;
    fsaTable[LT_EQ_st][sigma['A'] - 1] = FIN_OP_st;
    fsaTable[LT_EQ_st][sigma['O'] - 1] = FIN_OP_st;
    fsaTable[LT_EQ_st][sigma['D'] - 1] = FIN_OP_st;
    fsaTable[LT_EQ_st][sigma['W'] - 1] = FIN_OP_st;
    fsaTable[LT_EQ_st][sigma['E'] - 1] = FIN_OP_st;

    //Greater than equal comparison operator
    fsaTable[GT_EQ_st][sigma['='] - 1] = FIN_OP_st;
    fsaTable[GT_EQ_st][sigma['<'] - 1] = FIN_OP_st;
    fsaTable[GT_EQ_st][sigma['>'] - 1] = FIN_OP_st;
    fsaTable[GT_EQ_st][sigma['A'] - 1] = FIN_OP_st;
    fsaTable[GT_EQ_st][sigma['O'] - 1] = FIN_OP_st;
    fsaTable[GT_EQ_st][sigma['D'] - 1] = FIN_OP_st;
    fsaTable[GT_EQ_st][sigma['W'] - 1] = FIN_OP_st;
    fsaTable[GT_EQ_st][sigma['E'] - 1] = FIN_OP_st;

    for(int i = 0; i < fsaTable.size(); ++i ) {
        for(int j = 0; j < fsaTable[0].size(); ++j) {
            std::cout << fsaTable[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

