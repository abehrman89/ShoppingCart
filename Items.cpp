/*********************************************************************
 ** Program Filename: Items.cpp
 ** Author: Alexandra Behrman
 ** Date: 6/26/16
 ** Description: Items Class function definitions
 ** Input: user entry
 ** Output: Item name, unit, quantity, price
 *********************************************************************/

#include <iostream>
#include "Items.hpp"
#include <string>
using namespace std;

Items::Items()
{
    setName("");
    setUnit("");
    setQuantity(0);
    setPrice(0.00);
}

Items::Items(string theName, string theUnit, int theQuantity, double thePrice)
{
    setName(theName);
    setUnit(theUnit);
    setQuantity(theQuantity);
    setPrice(thePrice);
}

void Items::setName(string theName)
{
    name = theName;
}

string Items::getName()
{
    return name;
}

void Items::setUnit(string theUnit)
{
    unit = theUnit;
}

string Items::getUnit()
{
    return unit;
}

void Items::setQuantity(int theQuantity)
{
    quantity = theQuantity;
}

int Items::getQuantity()
{
    return quantity;
}

void Items::setPrice(double thePrice)
{
    price = thePrice;
}

double Items::getPrice()
{
    return price;
}

