#include "Sorting.h"
#include <iostream>

int Sorting:: binarySearchString(string itemSearch[], string itemSearched, int elements) {
  int first = 0;
  int last = elements - 1;
  while (first <= last) {
    int middle = (first + last) / 2;
    if (itemSearched == (itemSearch[middle])){
      return middle;
    }
    if (itemSearched > (itemSearch[middle]))
      first = middle + 1;
    else
      last = middle - 1;
  }
  return 0;
}

//Displays product information from the search page
void Sorting::displayProductInfo(vector<Item> item, string data) {

 for(int i = 0; i < item.size(); i++){
   if(item[i].getItemName() == data){
     cout << endl << endl; 
     cout << item[i].getItemName() << endl;
     cout << "Price: $" << item[i].getItemPrice() << endl;
     if(item[i].getStockAmount() < 5){
       cout << "Low stock" << endl;
     }
     else
      cout << "Available" << endl;
   }
 }
}

//Beginning search function used for getting user data for search
void Sorting::productSearch(string itemSearch[], vector<Item> item){
  cout << "Search for a product: ";
  cin.ignore();
  string input;
  getline(cin, input);

  int n = 5;
  int result = binarySearchString(itemSearch, input, n);
  if(result == -1){
    cout << "Error with search, please try again" << endl;
  }
  else{
    string foundItem = itemSearch[result];
    displayProductInfo(item, foundItem);
  }
}