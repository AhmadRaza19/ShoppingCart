#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

#include "ShoppingCart.h"
#include "ItemToPurchase.h"

//Default Constructor
ShoppingCart::ShoppingCart(){
   customerName = "none";
   currentDate = "January 1, 2016";
   }
   
//Parametrized Constructor
ShoppingCart::ShoppingCart(string customerName, string currentDate){
   this-> customerName = customerName;
   this-> currentDate = currentDate;
   }
   
//Get functions
string ShoppingCart::GetCustomerName(){
   return customerName;
   }   
   
string ShoppingCart::GetDate(){
   return currentDate;
   }


//Adds object to vector
void ShoppingCart::AddItem(ItemToPurchase& item1){
   
   cartItems.push_back(item1);
   
   }
//Uses a loop to iterate each spot in vector, deletes spot that shares value as userItem
void ShoppingCart::RemoveItem(string userItem){
   unsigned long int i = 0;
   for (i = 0; i < cartItems.size(); i++){
      if(this->cartItems.at(i).GetName() == userItem){
         this->cartItems.erase(cartItems.begin() + i);
         return;
         }
      }
      //Outputs if item isnt found
      cout << "Item not found in cart. Nothing removed." << endl;
   }

//Uses a loop to find place in vector that equals place in item2, changes quantity of that place
void ShoppingCart::ModifyItem(ItemToPurchase item2){
   unsigned long int i = 0;
   for (i = 0; i < cartItems.size(); i++){
      if (this->cartItems.at(i).GetName() == item2.GetName()){
         this->cartItems.at(i).SetQuantity(item2.GetQuantity());
         return;
         }
      }
   //Outpurs if item isnt found
   cout << "Item not found in cart. Nothing modified." << endl;
   }
   
//Gets total number in cart
int ShoppingCart::GetNumItemsInCart(){
   int numItems = 0;
   unsigned long int i;
   for (i = 0; i < cartItems.size(); i++){
       numItems = numItems + cartItems.at(i).GetQuantity();
       }
   return numItems;    
   }   

//Gets total value of items in cart
int ShoppingCart::GetCostOfCart(){
   unsigned long int i;
   int cost = 0;
   for (i = 0; i < cartItems.size(); i++){
      cost = cost + (cartItems.at(i).GetPrice() * cartItems.at(i).GetQuantity());
   }
   return cost;
   }   

//Prints total 
void ShoppingCart::PrintTotal(){
    long unsigned int i;

    cout << "Number of Items: " << GetNumItemsInCart();
    
    if (cartItems.size() != 0){
       cout << endl;
       }
    cout << endl;    
    for (i = 0; i < cartItems.size(); i++){
       cout << cartItems.at(i).GetName() << " " << cartItems.at(i).GetQuantity() << " @ $" << cartItems.at(i).GetPrice() << " = $" << (cartItems.at(i).GetPrice() * cartItems.at(i).GetQuantity()) << endl;
       }
    if (cartItems.size() == 0){
       cout << endl << "SHOPPING CART IS EMPTY" << endl;
       }
       
    cout << endl << "Total: $" << GetCostOfCart() << endl; 
    }
//Prints descriptions
void ShoppingCart::PrintDescriptions(){
   cout << endl <<"Item Descriptions" << endl;
   unsigned long int i;
   for (i = 0; i < cartItems.size(); i++){
      cout << cartItems.at(i).GetName() << ": " << cartItems.at(i).GetDescription() << endl;
      }
   }

