#ifndef STOREVIEW_H
#define STOREVIEW_H

#include <vector>
#include "Item.h"
#include "dlist.h"
#include "Account.h"
struct shoppingCart {
  double price;
  int quant;
  std::string itemName;
};

class storeHome{
  
  public:
   std::vector<Item> StoreHomePage(std::vector<Item> items);
   std::vector<Item> showItem(std::string input, std::vector<Item> items);
   int addToCart(int input, int totalItems);
   std::vector<Item> cartView(Account* tempAccount, Account* signedInAccount, std::vector<Item> items, int startingStock, int totalCartPrice);
};

#endif