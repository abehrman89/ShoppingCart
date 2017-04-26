/*********************************************************************
 ** Program Filename: Items.hpp
 ** Author: Alexandra Behrman
 ** Date: 6/26/16
 ** Description: Items Class header file
 ** Input: none
 ** Output: Items functions
 *********************************************************************/

#ifndef Items_hpp
#define Items_hpp

#include <iostream>
#include <string>
using namespace std;

class Items
{
    
private:
    
    string name;
    string unit;
    int quantity;
    double price;
    
public:
    
    Items();
    Items(string, string, int, double);
    
    void setName(string);
    void setUnit(string);
    void setQuantity(int);
    void setPrice(double);
    
    string getName();
    string getUnit();
    int getQuantity();
    double getPrice();
    
};

#endif
