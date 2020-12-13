#include "Item.h"
#include "dlist.h"
#include <iostream>
#include <vector>

using namespace std;

class Sorting{
  public:
  int binarySearchString(string arr[], string x, int n);
  void displayProductInfo(vector<Item> item, string data);
  void productSearch(string itemSearch[], vector<Item> item);
};