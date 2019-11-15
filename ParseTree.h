//Author:   Colby Ackerman
//Class:    CS4280 Program Translations
//Assign:   Project 2
//Date:     11/15/19
//-----------------------------------------------------------------------------

#ifndef PARSE_TREE_H
#define PARSE_TREE_H

#include <iostream>
#include <string>
#include <vector>

struct node {
    std::string label;
    std::vector<node*> children;
    std::vector<std::string> data;

    int indent;

    //Constructor
    node(std::string label);
};

class ParseTree {
public:
    node* root;

    void printAll(node* root);
    void printNode(node* node);
};

#endif