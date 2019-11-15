//Author:   Colby Ackerman
//Class:    CS4280 Program Translations
//Assign:   Project 2
//Date:     11/15/19
//-----------------------------------------------------------------------------

#ifndef PARSE_TREE_H
#define PARSE_TREE_H

#include <string>
#include <vector>

struct node {
    node* left;
    node* right;
    std::vector<std::string> data;
};

class ParseTree {
    node root;
};

#endif