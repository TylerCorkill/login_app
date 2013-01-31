#include <iostream>
#include <string>

using namespace std;

string error(string error)
{
	//string userExists = 	
	if 		(error == "userExists")   	return "\n------------------------------\nError: Username already exists\n------------------------------\n";
	//string passMismatch = 	
	else if (error == "passMismatch") 	return "\n----------------------------\nError: Passwords don't match\n----------------------------\n";
	//string badLogin = 		
	else if (error == "badLogin") 	  	return "\n----------------------\nError: Incorrect login\n----------------------\n";
	//string emptyUser = 		
	else if (error == "emptyUser") 		return "\n-------------------------\nError: Must type username\n-------------------------\n";
	//string prgmUnknown = 	
	else if (error == "prgmUnknown") 	return "\n----------------------\nError: Unknown Program\n----------------------\n";
	//string cmdUnknown = 	
	else if (error == "cmdUnknown") 	return "\n----------------------------------------------------------\nError: Unknown Command, type 'help' for a list of commands\n----------------------------------------------------------\n";
	//string typeUnknown = 	
	else if (error == "typeUnknown") 	return "\n-----------------------\nError: Unknown usertype\n-----------------------\n";

	//string errorErr = 		
	else 								return "\n-----------------\nError: in error()\n-----------------\n";

	//if 		(error == "userExists") 	cerr << userExists << endl;
	//else if (error == "passMismatch") 	cerr << passMismatch << endl;
	//else if (error == "badLogin") 		cerr << badLogin << endl;
	//else if (error == "emptyUser") 		cerr << emptyUser << endl;
	//else if (error == "prgmUnknown")	cerr << prgmUnknown << endl;
	//else if (error == "cmdUnknown") 	cerr << cmdUnknown << endl;
	//else if (error == "typeUnknown")	cerr << typeUnknown << endl;
	//else 								cerr << errorErr << endl;
}