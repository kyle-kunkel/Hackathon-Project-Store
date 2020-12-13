#pragma once
#include "string"
#include "dlist.h"
#include <iostream>
#include "Item.h"
class Account{
 
 public:

  std::string getFirstName();
  //Effects: Retruns the first name of the account holder(string)

  std::string getLastName();
  //Effects: Retruns the account holder's last name (string)

  std::string getPhoneNumber();
  //Effects: Retrun the Account Holder's phone number (string)

  void updatePhoneNumber(std::string number);
  //Effects: Updates Account Holder's phone number
  //Accepts: String of numbers
  //Returns: Updated Number String

  void printUserInfo();
  //Effects: Prints the Users' Information

  void addItemToCart(Item item);
  //Effects: Adds Items to cart - may change

  void printCart();
  //Effects: Prints cart - May change

  //Default Constructor
  Account();
  //Effect: Builds the account object and sets info equal to 
  //defualt, which is guest
  
  Account(std::string first, std::string last, std::string number);
  //Effects: Builds the acount object with the accepted parameters
  //Accepts: strings of firstName, LastName, phoneNumber

 private:
  //Data variables 
  std::string firstName;
  std::string lastName;
  std::string phoneNumber;

  //Identifies whether a member or not- no current use
  bool isMember;
  
  //old cart 
  Dlist <Item> cart;

};
