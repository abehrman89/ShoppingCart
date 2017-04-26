/*********************************************************************
 ** Program Filename: cartMain.cpp
 ** Author: Alexandra Behrman
 ** Date: 6/29/16
 ** Description: main function
 ** Input: user choice
 ** Output: item array
 *********************************************************************/

#include <iostream>
#include "List.hpp"
#include <string>
using namespace std;

int main()
{

    List l1;
    
    int choice;
    
        cout << "What would you like to do?\n";
        cout << "To add an item to your shopping list, type 1.\n";
        cout << "To remove an item from your shopping list, type 2.\n";
        cout << "To display your shopping list, type 3.\n";
        cout << "To quit, type 0.\n";
    
        cin >> choice;

    while (choice != 0)
    {
        if(choice == 1)
        {
            Items *newItem = l1.createItem();
            
            l1.addItem(newItem);
        }
        else if (choice == 2)
        {
            string name;
            
            cout << "Please enter the name of the item you want to remove from your shopping list:\n";
            cin >> name;
            
            Items *foundItem = l1.findItem(name);
            
            if (foundItem != NULL)
            {
                l1.removeItem(foundItem);
            }
            else
            {
            cout << "Item not found.\n";
            }
        }
        else if (choice == 3)
        {
            l1.displayList();
        }
        else if (choice != 0)
        {
            cout << "The valid choices are 1, 2, or 3.\n";
        }
        
        cout << "What would you like to do?\n";
        cout << "To add an item to your shopping list, type 1.\n";
        cout << "To remove an item from your shopping list, type 2.\n";
        cout << "To display your shopping list, type 3.\n";
        cout << "To quit, type 0.\n";
        
        cin >> choice;
    }
    
    return 0;
}