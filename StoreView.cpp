#include <iostream>
#include <vector>
#include <iomanip>
#include "Item.h"
#include "StoreView.h"
#include "Account.h"
#include "dlist.h"

using namespace std;

vector<Item> storeHome::StoreHomePage(vector<Item> items){

  cout << left << setw(26) << "Item" << left;
  cout << left << setw(15) << "Price";
  cout  << "Availability" << endl;
  cout << "-----------------------------------------------------" << endl;
int total;
  char space = ' ';
  for(int i = 0; i < 5; i++){
    cout << i+1 << ". ";
    cout << left << setw(25) << items[i].getItemName();
    cout << left << setw(15) << fixed << setprecision(2) << items[i].getItemPrice();
    total = items[i].getStockAmount();
    if(total > 5){
      cout << "In Stock" << endl;
    }
    else if(total <= 0)
      cout << "Out of stock" << endl;
    else
      cout << "Low stock" << endl;

  }

  int input;
  cout << endl;
  cout << "Please select an option" << endl;
  cout << "1. View an Item" << endl;
  cout << "2. Return to home page" << endl;
  string input2;
while(cin >> input){
  switch(input){
    case 1:
      cout << "Select an item" << endl;
      cin.ignore();
      getline(cin, input2);
      items = showItem( input2, items);
      break;
    case 2:
      return items;
    default:
      cout << "Invalid item. Please try again" << endl;
  }
  cout << "1. View an Item" << endl;
  cout << "2. Return to home page" << endl;
}
  return items;
}

vector<Item> storeHome::showItem(string input, vector<Item> items){
  bool itemFound = false;
  for(int i = 0; i < items.size(); i++){
    if(items[i].getItemName() == input){
      cout << endl << "Displaying product information for: " << items[i].getItemName() << endl;
      cout << "Price: $" << items[i].getItemPrice() << endl;
      int itemQuant = items[i].getStockAmount();
      cout << "The total stock: " << itemQuant << endl << endl;

      cout << "Select an option" << endl;
      cout << "1. Add to cart" << endl;
      cout << "2. Return back to products page" << endl;
      int choice;
      cin >> choice;
      switch(choice){
        case 1:
          int finalTotal;
          finalTotal = addToCart(choice, itemQuant);
          finalTotal = items[i].getStockAmount() - finalTotal;
          items[i].updateItemStock(finalTotal);
        case 2:
          return items;
      }
  
      itemFound = true;
      return items;
    }
  }
  if(itemFound == false)
    cout << "Uh oh... looks like this item can't be found. Please try again" << endl;
  return items;
}

int storeHome::addToCart(int input, int totalItems){
  int quant;
  int remaining;
  cout << "Please enter the quantity of the product: ";
  cin.ignore();

  while(cin>>quant){
    if( totalItems == 0){
      cout << "Item is currently not available" << endl;
      quant = 0;
      return quant;
    }
    else if(quant > totalItems)
      cout << "Purchase is too large. Please enter a new quantity" << endl;
    else{
      cout << "Adding to the cart..." << endl;
      break;
    }  
}
return quant;
}

vector<Item> storeHome::cartView(Account* tempAccount, Account* signedInAccount, std::vector<Item> items, int startingStock, int totalCartPrice){
    Dlist <shoppingCart> cart;
    shoppingCart *tempCart = new shoppingCart;


cout << left << setw(20) << "Item";
      cout << left << setw(20) << "Quantity";
      cout << left << setw(20) << "Unit Price";
      cout << left << setw(20) << "Total cost" << endl;
      cout << "---------------------------------------------------------------------------" << endl;
      if(tempAccount == signedInAccount){
        for(int i = 0; i < items.size(); i++){
          if(items[i].getStockAmount() != startingStock){
            int cartTotal = startingStock - items[i].getStockAmount() ;
            tempCart->price = items[i].getItemPrice();
            tempCart->quant = cartTotal;
            tempCart->itemName = items[i].getItemName();
            cart.InsertFront(*tempCart);
            tempCart = new shoppingCart;
          }
        }
        if(cart.IsEmpty()){
          std::cout << "Whoops looks like your cart is empty" << std::endl;
          //break;
        }
        while(!cart.IsEmpty()){
        *tempCart = cart.RemoveFront();
        
        std::cout << left << setw(20) << tempCart->itemName; 
        std::cout << left << setw(20) << tempCart->quant; 
        std::cout << left << setw(20) << tempCart->price; 
        std::cout << left << setw(20) << tempCart->price * tempCart->quant << std::endl;

        totalCartPrice = (tempCart->price * tempCart->quant) + totalCartPrice;
        }
      }
      else{
        if(cart.IsEmpty()){
          std::cout << "Whoops looks like your cart is empty" << std::endl;
        }
        for(int i = 0; i < items.size(); i++)
            items[i].updateItemStock(10);
      
        
        tempAccount = signedInAccount;
      }
      cout << "---------------------------------------------------------------------------" << endl;
      cout << setw(60) << "Total Price: " << fixed << setprecision(2) << totalCartPrice << endl << endl << endl;
      totalCartPrice = 0;
      return items;
}