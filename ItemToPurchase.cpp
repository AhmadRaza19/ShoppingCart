#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

//Default Constructor
ItemToPurchase::ItemToPurchase(){
   itemName = "none";
   itemDescription = "none";
   itemPrice = 0;
   itemQuantity = 0;
   }
   
//Parametrized Constructor   
ItemToPurchase::ItemToPurchase(string itemName, string itemDescription, int itemPrice, int itemQuantity){
   this->itemName = itemName;
   this->itemDescription = itemDescription;
   this->itemPrice = itemPrice;
   this->itemQuantity = itemQuantity;
   }


//Set Functions
void ItemToPurchase::SetName(string itemName) {
   this->itemName = itemName;
   }
   
   
void ItemToPurchase::SetDescription(string itemDescription) {
   this->itemDescription = itemDescription;
   }
   

void ItemToPurchase::SetPrice(int itemPrice) {
   this->itemPrice = itemPrice;
   }


void ItemToPurchase::SetQuantity(int itemQuantity) {
   this->itemQuantity = itemQuantity;
   }
   
//Get or Return Functions
string ItemToPurchase::GetName() {
   return itemName;
   }
   
   
string ItemToPurchase::GetDescription() {
   return itemDescription;
   }
   

int ItemToPurchase::GetPrice() {
   return itemPrice;
   }


int ItemToPurchase::GetQuantity() {
   return itemQuantity;
   }
   

//Print Functions
void ItemToPurchase::PrintItemCost() {
   cout << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << itemQuantity * itemPrice << endl;
   }    
   

void ItemToPurchase::PrintItemDescription() {
   cout << itemName << ": " << itemDescription << endl;
   }   

