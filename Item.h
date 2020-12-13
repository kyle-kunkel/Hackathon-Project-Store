#pragma once
#include <iostream>
class Item{
 public:
  void addStock();//Increases stock by 1 only
  void subStock();//decreases stock by 1 only
  void updateItemDescription(std::string description);//update discription
  void setItemName(std::string name);//updates the item name
  int getStockAmount();//retruns stock left for this item
  std::string getItemName();//retrun name of item
  double getItemPrice();
  void updateItemStock(int newStockSize);

  //Constructor with parameter
  Item(std::string name, int stock, double price);
  //Default Constructor
  Item();

 private:
  std::string itemName;
  int stockAmount;
  double itemPrice;
  std::string itemDescription;
};