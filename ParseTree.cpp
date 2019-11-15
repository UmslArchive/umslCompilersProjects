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
    std::cout << label << children.size() << data.size() << std::endl;
}