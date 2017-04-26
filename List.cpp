/*********************************************************************
 ** Program Filename: List.cpp
 ** Author: Alexandra Behrman
 ** Date: 6/26/16
 ** Description: List Class function definitions
 ** Input: user entry
 ** Output: Item array
 *********************************************************************/

#include <iostream>
#include "List.hpp"
#include <string>
using namespace std;

List::List()
{
    capacity = 4;
    arrayEnd = 0;
    
    list = new Items[capacity];
}

/*********************************************************************
 ** Function: createItem()
 ** Description: creates a new Item that will then be added to the array
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: pointer to new Item must exist
 *********************************************************************/
Items* List::createItem()
{
    string name;
    string unit;
    int quantity;
    double price;
    
    //get new Item details from user
    cout << "Please enter the name of the item you would like to add to your shopping list:\n";
    cin >> name;
    
    cout << "Please enter the unit of sale for your item (ie. can, pound, ounce, bag):\n";
    cin >> unit;
    
    cout << "Please enter the quantity you will be buying as a whole number (ie. 1, 2, 3):\n";

    while(!(cin >> quantity))
    {
        cout << "Please enter whole numbers only.\n";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    
    cout << "Please enter the price per " << unit << " of your item (use the form 0.00):\n";
   
    while(!(cin >> price))
    {
        cout << "Please enter a number in the form 0.00.\n";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    
    double totalPrice = 0;
    
    totalPrice = quantity * price;
    
    //display item and details added to shopping list
    cout << "\n";
    
    cout << "You have added an item to your shopping list:\n";
    
    cout << "\n";
    
    cout << quantity << " " << unit << "(s) of " << name << "(s) at $" << price
         << " per " << unit << " for a subtotal of $" << totalPrice << endl;
    
    cout << "\n";
    
    //create Item pointer to new Item object
    Items *newItem = new Items();
    
    newItem->setName(name);
    newItem->setUnit(unit);
    newItem->setQuantity(quantity);
    newItem->setPrice(price);
    
    return newItem;
}

/*********************************************************************
 ** Function: addItem(Items *theItem
 ** Description: adds the new Item to the array
 ** Parameters: Item pointer to the new item
 ** Pre-Conditions: pointer must exist from createItem()
 ** Post-Conditions: arrayEnd must have incremented (if Item added); Item must be in array
 *********************************************************************/
void List::addItem(Items *theItem)
{
    //if the end of the array is not equal to the capacity of the array
    if (arrayEnd != capacity)
    {
        list[arrayEnd] = *theItem;
        arrayEnd++;
    }
    
    else
    {
        capacity = capacity * 2;
        
        //create new temp array, copy list to temp, delete list, assign temp to list
        Items *temp = new Items[capacity];
        
        for (int i = 0; i < arrayEnd; i++)
        {
            temp[i] = list[i];
        }
        
        delete [] list;
        
        list = temp;
        
        //the new Item is added to the array at the point arrayEnd
        list[arrayEnd] = *theItem;
        arrayEnd++;
    }
}

/*********************************************************************
 ** Function: removeItem(Items *theItem
 ** Description: removes an Item from the array
 ** Parameters: Item pointer to the item to be removed
 ** Pre-Conditions: Item must exist, Item pointer must exist
 ** Post-Conditions: arrayEnd must decrement; remaining array Items must shift over vacant spot
 *********************************************************************/
void List::removeItem(Items *theItem)
{
    
    //loop through array until name is found, the shift all array elements back
    for (int i = 0; i < arrayEnd; i++)
    {
        if (list[i].getName() == theItem->getName())
        {
            for (int j = i; j < arrayEnd; j++)
            {
                list[j] = list[j + 1];
            }
            arrayEnd--;
        }
    }
}

/*********************************************************************
 ** Function: double subtotal()
 ** Description: calculates the subtotal
 ** Parameters: none
 ** Pre-Conditions: Item must exist
 ** Post-Conditions: none
 *********************************************************************/
double List::subtotal()
{
    int i;
    
    return list[i].getQuantity() * list[i].getPrice();
}

/*********************************************************************
 ** Function: displayList()
 ** Description: displays the list array
 ** Parameters: none
 ** Pre-Conditions: array must exist
 ** Post-Conditions: none
 *********************************************************************/
void List:: displayList()
{
    for (int i = 0; i < arrayEnd; i++)
    {
        cout << list[i].getName() << " - " << list[i].getQuantity() << " " << list[i].getUnit()
             << "(s) $" << list[i].getPrice() << "/" << list[i].getUnit() << ": $"
             << list[i].getQuantity() * list[i].getPrice() << endl;
    }
    
    double total = 0;
    
    for (int i = 0; i < arrayEnd; i++)
    {
        total += list[i].getQuantity() * list[i].getPrice();
    }
    
    cout << "The total cost for this shopping trip is: $" << total << endl;
    
    cout << "\n";
}

/*********************************************************************
 ** Function: findItem(string name)
 ** Description: finds Item in array
 ** Parameters: string name
 ** Pre-Conditions: none
 ** Post-Conditions: either return the found Item or return NULL
 *********************************************************************/
Items* List::findItem(string name)
{
    for (int count = 0; count < arrayEnd; count++)
    {
        if (list[count].getName() == name)
        {
            return &list[count];
        }
    }
    
    return NULL;
}