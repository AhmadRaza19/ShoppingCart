#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
using namespace std;

class ItemToPurchase{
   public:
      //2 constructors
      ItemToPurchase();
      ItemToPurchase(string itemName, string itemDescription, int itemPrice, int itemQuantity);
      
      //Remaining functions
      void SetName(string);
      void SetDescription(string);
      void SetPrice(int);
      void SetQuantity(int);
      string GetName();
      string GetDescription();
      int GetPrice();
      int GetQuantity();
      
      void PrintItemCost();
      void PrintItemDescription();
      
   private:
   string itemName;
   string itemDescription;
   int itemPrice;
   int itemQuantity;

};
#endif
