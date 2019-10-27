//Author:   Colby Ackerman
//Class:    CS4280 Program Translations
//Assign:   Project 1
//Date:     10/20/19
//-----------------------------------------------------------------------------

#include "Table.h"

//Static init
bool Table::isInitialized = false;
std::map<char, int> Table::sigma;

//Constructor
Table::Table() {
    
    //Starting state
    currentState = START_st;
    
    //Start values at 1 because when using the [] operator with a std::map,
    //0 is returned if the key is not found.
    int value = 1;

    //Initialize sigma
    if(!isInitialized) {

        sigma = std::map<char, int>();
        
        //Operators
        sigma.insert(std::pair<char, int>('=', value++));
        sigma.insert(std::pair<char, int>('<', value++));
        sigma.insert(std::pair<char, int>('>', value++));
        sigma.insert(std::pair<char, int>(':', value++));
        sigma.insert(std::pair<char, int>('+', value++));
        sigma.insert(std::pair<char, int>('-', value++));
        sigma.insert(std::pair<char, int>('*', value++));
        sigma.insert(std::pair<char, int>('/', value++));
        sigma.insert(std::pair<char, int>('%', value++));
        sigma.insert(std::pair<char, int>('.', value++));
        sigma.insert(std::pair<char, int>('(', value++));
        sigma.insert(std::pair<char, int>(')', value++));
        sigma.insert(std::pair<char, int>(',', value++));
        sigma.insert(std::pair<char, int>('{', value++));
        sigma.insert(std::pair<char, int>('}', value++));
        sigma.insert(std::pair<char, int>(';', value++));
        sigma.insert(std::pair<char, int>('[', value++));
        sigma.insert(std::pair<char, int>(']', value++));      

        //Whitespace
        sigma.insert(std::pair<char, int>(' ', value++));
        sigma.insert(std::pair<char, int>('\t', value++));
        sigma.insert(std::pair<char, int>('\n', value++));

        //alpha
        for(int i = 0; i < 26; ++i) {
            sigma.insert(std::pair<char, int>((char)(i + 97), value++));
        }

        //digits
        for(int i = 0; i <  10; ++i) {
            sigma.insert(std::pair<char, int>((char)(i + 48), value++));
        }

        isInitialized = true;
    }
}