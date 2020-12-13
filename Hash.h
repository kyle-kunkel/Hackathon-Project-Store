#pragma once
#include <iostream>
#include "string"
#include "Account.h"
#include <fstream>

//-Implemetation of Hash Class for Users---------------------------
class Hash {
public:

	Account* signIn(std::string username);
  //Effect: Signs in to a Account based on username if exist
  //Accepts: Username
  //Returns: Account address
  
	Account* signIn();
  //Effects: Used to sign into a guest account by returning 
  //a account reference
  //Return: GuestAccount Reference/ address

	Account* createAccount();
  //Effects: Creates a accounte Based on user inputed Information
  //Returns: Nothing (VOID)
  //Important: Places the account on the hash and links it if 
  //necesary


	Hash();
  //Effects: Initializes hashTable 
  //Effecst: Initailizes guessAccount

	~Hash();
  //Destructor

private:

  struct memberNode {
		std::string username;
		Account* account;
		memberNode* next;
	};
  //What-is-it: Structure for the memberNode
  //Declares: String username- used for login
  //Declares: Account pointer- used for acces to the account    
  //          associated with the username
  //Declares: memberNode pointer- Points the the next memberNode//             Incase of colision

	static const int tableSize = 100;
  //Effects: Sets a static constant size for the hash table

	bool usernameTaken(std::string username);
  //Effects: Retruns true of the username is already used
  //Accepts: String username
  //Returns: bool

	int hashKey(std::string key);
  //Effects: Calculates the index of the hashed username/key
  //Returns: int index

	void createAccount(std::string firstName, std::string lastName, std::string number, std::string username);
  //Effects: Used to create Accounts bease on text file

	void removeEverything();
  //What-is-it: Helper Function for destructor

	memberNode* hashTable[tableSize];
  //What-is-it: Creates a array of member Fuctions AKA hash table

	Account* guestAccount;
  //What-is-it: A pointer to the guest account created in the //Constructor

};//End of class Decloration

//////////////////////////////////////////////////////////////////
//-Constructors and destructors-
//////////////////////////////////////////////////////////////////

Hash::Hash() {
	for (int i = 0; i < tableSize; i++) {
		hashTable[i] = NULL;
	}
	guestAccount = new Account();

	std::ifstream myfile("user.txt");

	std::string firstName, lastName, phoneNumber, username;
	while (myfile >> firstName >> lastName >> phoneNumber >> username) {
		createAccount(firstName,lastName,phoneNumber,username);
	}
}

inline Hash::~Hash()
{
	removeEverything();
}
//////////////////////////////////////////////////////////////////
//- Sign in - CreateAccount - - Methods
//////////////////////////////////////////////////////////////////
inline Account* Hash::signIn(std::string username)
{
	if (!usernameTaken(username)) {
		std::cout << "Username Not Found" << std::endl;
		return guestAccount;
	}
	else {
		int index = hashKey(username);
		bool found = false;
		memberNode* temp = hashTable[index];
		while (found == false && temp != NULL) {
			if (temp->username == username) {
				found = true;
			}
			else {
				temp = temp->next;
			}
		}//Exit While Loop
		return temp->account;
	}
}

inline Account* Hash::signIn()
{
	return guestAccount;
}


Account* Hash::createAccount()
{

	std::string firstName, lastName, number, username;

	std::cout << "Enter first Name: " << std::endl;
	std::cin >> firstName;
	std::cout << "Enter last Name: " << std::endl;
	std::cin >> lastName;
	std::cout << "Enter Phone Number: " << std::endl;
	std::cin >> number;
	std::cout << "Create Username: " << std::endl;
	std::cin >> username;
	if (usernameTaken(username)) {
		while (usernameTaken(username)) {
			std::cout << "Sorry Username already take :( \nCreate Username: " << std::endl;
			std::cin >> username;
		}
	}
	int keyIndex = hashKey(username);
	memberNode* current = new memberNode;
	if (hashTable[keyIndex] == NULL) {
		hashTable[keyIndex] = current;
	}
	else {////I'm leaving off at the tracing of this    
		memberNode* temp = hashTable[keyIndex];
		bool exitLoop = true;
		while (exitLoop) {
			if (temp->next == NULL) {
				temp->next = current;
				exitLoop = false;
			}
			temp = temp->next;
		}
	}


	current->account = new Account(firstName, lastName, number);
	current->next = NULL;
	current->username = username;
  return current->account;
}
//Creates a account
void Hash::createAccount(std::string firstName, std::string lastName, std::string number, std::string username)
{

	
	if (usernameTaken(username)) {
		while (usernameTaken(username)) {
			std::cout << "Sorry Username already take :( \nCreate Username: " << std::endl;
			std::cin >> username;
		}
	}
	int keyIndex = hashKey(username);
	memberNode* current = new memberNode;
	if (hashTable[keyIndex] == NULL) {
		hashTable[keyIndex] = current;
	}
	else {////I'm leaving off at the tracing of this    
		memberNode* temp = hashTable[keyIndex];
		bool exitLoop = true;
		while (exitLoop) {
			if (temp->next == NULL) {
				temp->next = current;
				exitLoop = false;
			}
			temp = temp->next;
		}
	}


	current->account = new Account(firstName, lastName, number);
	current->next = NULL;
	current->username = username;
}
//////////////////////////////////////////////////////////////////
//-Destructor Helper Method-
//////////////////////////////////////////////////////////////////
inline void Hash::removeEverything()
{
	
	for (int i = 0; i < tableSize; i++) {
		
		if (hashTable[i] != NULL) {
			memberNode* tempNode = hashTable[i];
			while (tempNode != NULL) {
				delete( tempNode->account);
				memberNode* next = tempNode->next;
				delete( tempNode);
				tempNode = next;
			}

		}
	}
}
//////////////////////////////////////////////////////////////////
//-Hashing Methods-
//////////////////////////////////////////////////////////////////
bool Hash::usernameTaken(std::string username)
{
	int index = hashKey(username);
	bool found = false;
	if (hashTable[index] == NULL) {
		return found;
	}
	else {

		memberNode* temp = hashTable[index];
		while (found == false && temp != NULL) {
			if (temp->username == username) {
				found = true;
			}
			else {
				temp = temp->next;
			}

		}
	}
	return found;
}


inline int Hash::hashKey(std::string key) {
	int index = 0;
	for (int i = 0; i < key.length(); i++) {
		index = index + (int)key[i];
	}
	return index % 100;
}
