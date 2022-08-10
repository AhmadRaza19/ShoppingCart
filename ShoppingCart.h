#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "ItemToPurchase.h"

class ShoppingCart{
   public:
      //2 constructors
      ShoppingCart();
      ShoppingCart(string customerName, string currentDate);
      
      //Remaining functions
      string GetCustomerName();
      string GetDate();
      void AddItem(ItemToPurchase& item1);
      void RemoveItem(string);
      void ModifyItem(ItemToPurchase item2);
      int GetNumItemsInCart();
      int GetCostOfCart();
      
      void PrintTotal();
      void PrintDescriptions();
      
   private:
   string customerName;
   string currentDate;
   vector <ItemToPurchase> cartItems;
   
   
   
};
#endif
