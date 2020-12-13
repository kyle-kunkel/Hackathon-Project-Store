#include <iostream>
#include <iomanip>
#include <vector>
#include "Account.h" 
#include "Item.h"
#include "StoreView.h"
#include "Sorting.h"
#include "Hash.h"

//Sign in or create account
Account* signInOrCreate(Hash* hash, Account* account){
  int selection;
  std::cout<<"1. Sign-In\n2. Create Account\n3. Back\n";
  std::cin>>selection;
  switch(selection){
    case 1:{
      std::string username;
      std::cout << "Please enter your username: ";
      std::cin >> username;
      account=hash->signIn(username);
      break;
    }
    case 2:
      account = hash->createAccount();
      break;
    case 3:
      break;
    default:
      std::cout << "Invalid Input" << std::endl;
  }
  return account;
}
//Provides options for the website
void displayWebsiteMenu(){
  std::cout << "Select an option..." << std::endl;
  std::cout << "1. View the store" << std::endl;
  std::cout << "2. Search the store" << std::endl;
  std::cout << "3. Check your cart" << std::endl;
  std::cout << "4. Sign-In/Create Account" << std::endl;
  std::cout << "5. Exit website" << std::endl;
}

int main() {
  //Hash where users and stored and retrieved
  Hash userHash;
  Account* signedInAccount = userHash.signIn();
  Account* tempAccount = signedInAccount;
  Sorting binary;
  int selection;
  storeHome home;
  int startingStock = 10;

  std::vector <Item> items;
  items.push_back(Item("candy cane", 10, 1.00));
  items.push_back(Item("ugly christmas sweater", 10, 25.00));
  items.push_back(Item("gingerbread house", 10, 15.00));
  items.push_back(Item("santa hat", 10, 5.00));
  items.push_back(Item("christmas tree", 10, 75.00));

  //Could be used for sign in page
  Account myAccount("Francisco", "Martell", "210-555-5555");

  string itemSearch[5];
  string itemName;


  //Decide on a sorting method for itemSearch
  //Using this temporarily but will eventually be itemSearch(array) or items(vector) **Vector would be better**
  string arr[] = { "candy cane", "christmas tree", "gingerbread house", "santa hat", "ugly christmas sweater"};

  double totalCartPrice = 0;
  string result;
  cout << "Welcome back " << signedInAccount->getFirstName() << endl;
  displayWebsiteMenu();

while(std::cin>>selection){
  switch (selection){
    case 1:
      items = home.StoreHomePage(items);
      break;
    case 2:
      binary.productSearch(arr,items);
      break;
    case 3:
      items = home.cartView(tempAccount, signedInAccount, items, startingStock,  totalCartPrice);
      cout << endl << "Remaining: " << endl;
      break;
    case 4:
        std::cout << "User creates or logs into user account" << std::endl;
        signedInAccount = signInOrCreate(&userHash, signedInAccount);
        cout << "Logged in as " << signedInAccount->getFirstName() << endl;
        break;
    case 5:
        std::cout << "Thank you for visiting!" << std::endl;
        return 0;
    default:
      std::cout << "Invalid input" << std::endl;
  }
    displayWebsiteMenu();
}
  return 0;
}
