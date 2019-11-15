//Author:   Colby Ackerman
//Class:    CS4280 Program Translations
//Assign:   Project 2
//Date:     11/15/19
//-----------------------------------------------------------------------------

#include "ParseTree.h"

node::node(std::string label) :
    label(label), 
    children(std::vector<node*>()),
    data(std::vector<std::string>())
{
    //std::cout << label << children.size() << data.size() << std::endl;
}

void ParseTree::printNode(node* node) {
    std::cout << node->label;
    if(node->data.size() > 0)
        std::cout << "\tdata: ";

    for(int i = 0; i < node->data.size(); ++i) {
        std::cout << node->data[i] << ", ";
    }

    std::cout << std::endl;       
}

void ParseTree::printAll(node* root) {
    printNode(root);
    for(int i = 0; i < root->children.size(); ++i) {
        if(root->children[i] != NULL) {
            printAll(root->children[i]);
        }
    }
}