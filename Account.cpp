#include "Account.h" 
#include <iostream>
#include <string>
//////////////////////////////////////////////////////////////////
//-Constructors-
//////////////////////////////////////////////////////////////////
Account::Account(std::string first, std::string last, std::string number){
  firstName = first;
  lastName = last;
  phoneNumber = number;
  isMember = true;
}

Account::Account(){
  firstName = "Guest";
  lastName = "";
  phoneNumber = "5555555555";
  isMember = false;
}
//////////////////////////////////////////////////////////////////
//-Getters-
//////////////////////////////////////////////////////////////////
std::string Account::getFirstName(){
  return firstName;
}
std::string Account::getLastName(){
  return lastName;
}
std::string Account::getPhoneNumber(){
  return phoneNumber;
}
//////////////////////////////////////////////////////////////////
//-Setters-
//////////////////////////////////////////////////////////////////
void Account::updatePhoneNumber(std::string number){
  phoneNumber = number;
}
//////////////////////////////////////////////////////////////////
//-Print Functions-
//////////////////////////////////////////////////////////////////
void Account::printUserInfo(){
  std::cout << "Member: " << firstName << " " << lastName << std::endl;
  std::cout << "Phone Number: " << phoneNumber << std::endl;
}
//////////////////////////////////////////////////////////////////
//-Cart-
//////////////////////////////////////////////////////////////////
void Account::addItemToCart(Item item){
  cart.InsertBack(item);
  item.subStock();
}
void Account::printCart(){
  //Dlist <Item> temp(cart);
  std::cout << "Shopping Cart: "<< std::endl;
  while(cart.IsEmpty()==false){
    std::cout <<"-"<< cart.RemoveBack().getItemName() << std::endl;
  }
}
