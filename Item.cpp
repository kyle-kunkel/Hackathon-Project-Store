#include "iostream"
#include "Item.h"

Item::Item(std::string name, int stock, double price){
  itemName = name;
  stockAmount = stock;
  itemPrice = price;
  itemDescription = "No description available :(";
}
//Default Constructor
Item::Item(){
  itemName = "Unnamed";
  stockAmount = 0;
  itemDescription = "No Description available";
}

//Implementaion of getters and setters
void Item::addStock(){
  if(stockAmount<100)
  {
    stockAmount--;
  }
}

void Item::subStock(){
  if(stockAmount>=0)
  {
    stockAmount++;
  }
}
void Item::updateItemDescription(std::string description){
  itemDescription = description;
}
void Item::setItemName(std::string name){
  itemName = name;
}
int Item::getStockAmount(){
  return stockAmount;
}

std::string Item::getItemName(){
  return itemName;
}

double Item:: getItemPrice(){
  return itemPrice;
}
void Item::updateItemStock(int newStockSize){
  stockAmount = newStockSize;
}