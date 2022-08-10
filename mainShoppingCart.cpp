#include <iostream>
#include <string>
#include <iomanip>
#include <istream>
using namespace std;

#include "ShoppingCart.h"
#include "ItemToPurchase.h"




void ExecuteMenu(char option, ShoppingCart& theCart) {
   ItemToPurchase item1;
   string itemName;
   string itemDesc;
   int itemPrice;
   int itemQuant;
   
   
    // Calls respective functions for each option
   if (option == 'a'){      
   cout << "ADD ITEM TO CART" << endl;
   
   cout << "Enter the item name:" << endl;
   cin.ignore(); //Ignores previous input
   getline(cin, itemName);
   
   cout << "Enter the item description:" << endl;
   getline(cin, itemDesc);
   
   cout << "Enter the item price:" << endl;
   cin >> itemPrice;
   
   cout << "Enter the item quantity:" << endl;
   cin >> itemQuant;
   
   item1.SetName(itemName);
   item1.SetDescription(itemDesc);
   item1.SetPrice(itemPrice);
   item1.SetQuantity(itemQuant);
   theCart.AddItem(item1); //Calls Add Item for item1 Object
   }else if (option == 'd'){
      cout << "REMOVE ITEM FROM CART" << endl;
      cout << "Enter name of item to remove:" << endl;
      cin.ignore(); //Ignores old inputs
      string userName;
      getline(cin,userName);
      theCart.RemoveItem(userName); //Calls Remove Item for user input variable
   }else if (option == 'c'){
      ItemToPurchase item2; //Creates a new object
      string userItemChoice;
      int newQuant;
      cout << "CHANGE ITEM QUANTITY" << endl;
      cout << "Enter the item name:" << endl;
      cin.ignore(); //Ignores old inputs
      getline(cin, userItemChoice);
      cout << "Enter the new quantity:" << endl;
      cin >> newQuant;
      item2.SetName(userItemChoice);
      item2.SetQuantity(newQuant);
      theCart.ModifyItem(item2); // Uses new object to replace old quantity with new quantity
   }else if (option == 'i'){
      cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
      cout << theCart.GetCustomerName() << "'s Shopping Cart - " << theCart.GetDate() << endl;
      theCart.PrintDescriptions(); //Prints Descriptions
   }else if (option == 'o'){
      cout << "OUTPUT SHOPPING CART" << endl;
      cout << theCart.GetCustomerName() << "'s Shopping Cart - " << theCart.GetDate() << endl;
      theCart.PrintTotal(); //Prints Totals
   }
   
}

//Prints Menu
void PrintMenu() {
   
   cout << "MENU" << endl;
   cout << "a - Add item to cart" << endl;
   cout << "d - Remove item from cart" << endl;
   cout << "c - Change item quantity" << endl;
   cout << "i - Output items' descriptions" << endl;
   cout << "o - Output shopping cart" << endl;
   cout << "q - Quit" << endl;

   
   }

int main() {
   string userName;
   string userDate;
   
   cout << "Enter customer's name:" << endl;
   getline(cin, userName);
   cout << "Enter today's date:" << endl << endl;
   getline(cin, userDate);

   cout << "Customer name: " << userName << endl;
   cout << "Today's date: " << userDate << endl << endl;
   
   //Sends name and date to constructor and creates theCart object
   ShoppingCart theCart(userName, userDate);
   
   PrintMenu();
   
   char userInput;
   cout << endl;
   cout << "Choose an option:" << endl;
   cin >> userInput;
   //While Loop to keep asking for input until quit is called
   while (userInput != 'q'){
      if (userInput == 'a' || userInput == 'd' || userInput == 'c' || userInput == 'i' || userInput == 'o'){
         ExecuteMenu(userInput, theCart);
         cout << endl;
         PrintMenu(); //Prints Menu
         cout << endl << "Choose an option:" << endl;
         cin >> userInput;
         }else{
            cout << "Choose an option:" << endl;
            cin >> userInput;
            }
      }
   

   
   
   
   return 0;
}
