/*********************************************************************
 ** Program Filename: List.hpp
 ** Author: Alexandra Behrman
 ** Date: 6/26/16
 ** Description: List header file
 ** Input: none
 ** Output: List functions
 *********************************************************************/

#ifndef ShoppingCart_hpp
#define ShoppingCart_hpp

#include <iostream>
#include "Items.hpp"
#include <string>
using namespace std;

class List
{

private:
    
    Items* list;
    int capacity;
    int arrayEnd;
    
public:
    
    List();
    
    Items* createItem();
    
    void addItem(Items*);
    
    void removeItem(Items*);
    
    double subtotal();
    
    void displayList();
    
    Items* findItem(string);

};

#endif
