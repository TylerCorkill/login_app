#include <iostream>
#include <string>
#include <sstream>
#include "User.h"

using namespace std;

//User::User();
User::User(string newName, string newPass, int newType);
//string User::name();
//string User::pass();
//int User::type();
//unsigned int User::name_hash();
//unsigned int User::pass_hash();
//unsigned int User::type_hash();


void class_test()
{
	string testName, testPass;
	int testType = 3;
	cout << "\nEnter name: ";
	cin >> testName;
	cout << "\nEnter pass: ";
	cin >> testPass;
	cout << "\n> Testing class User..."
		 << endl;
	User test(testName, testPass, testType);
	cout << "\n> Username: "
		 << test.name()
		 << endl
		 << "\n> Password: "
		 << test.pass()
		 << endl
		 << "\n> Usertype: "
		 << test.type()
		 << endl
		 << "\n> User hash: "
		 << test.name_hash()
		 << ":"
		 << test.pass_hash()
		 << "!"
		 << test.type_hash()
		 << endl;
}