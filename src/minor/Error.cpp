#include <iostream>
#include <string>

using namespace std;

string error(string error)
{
	if 		(error == "userExists")   	return "\n------------------------------\nError: Username already exists\n------------------------------\n";
	else if (error == "passMismatch") 	return "\n----------------------------\nError: Passwords don't match\n----------------------------\n";
	else if (error == "badLogin") 	  	return "\n----------------------\nError: Incorrect login\n----------------------\n";
	else if (error == "emptyUser") 		return "\n-------------------------\nError: Must type username\n-------------------------\n";
	else if (error == "prgmUnknown") 	return "\n----------------------\nError: Unknown Program\n----------------------\n"; 	
	else if (error == "cmdUnknown") 	return "\n----------------------------------------------------------\nError: Unknown Command, type 'help' for a list of commands\n----------------------------------------------------------\n";
	else if (error == "typeUnknown") 	return "\n-----------------------\nError: Unknown usertype\n-----------------------\n";
	else if (error == "noUserEntry")	return "\n-------------------------\nError: User doesn't exist\n-------------------------\n";
	else if (error == "typeChange")		return "\n-----------------------------\nError: Type change incomplete\n-----------------------------\n";
	else if (error == "passChange")		return "\n---------------------------------\nError: Password change incomplete\n---------------------------------\n";
	else if (error == "typeError")		return "\n-------------------\nError: in user type\n-------------------\n";	
	else 								return "\n-----------------\nError: in error()\n-----------------\n";
}