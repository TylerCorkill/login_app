#ifndef USER_H
#define USER_H

#include "Error.h"

using namespace std;



class User					// User class test for program
{
private:
	string trueName;
	string truePass;
	int trueType;		// 1 basic, 2 power, 3 admin

	string holdName;
	string holdPass;
	int holdType;

	bool nameTaken;
public:
//	User()
//	{
//		trueName = "*";
//		truePass = "*";
//		trueType = 0;
//	}
//	User(string newName = "*", string newPass = "*", int newType = 1)
//	{
//		trueName = newName;
//		truePass = newPass;
//		trueType = newType;
//	}


	string new_name(string newName)
	{
		trueName = newName;
	}
	string new_pass(string newPass)
	{
		truePass = newPass;
	}
	int new_type(int newType)
	{
		trueType = newType;
	}


	string name()
	{
		return trueName;
	}
	string pass()
	{
		return truePass;
	}
	int type()
	{
		return trueType;
	}
	bool name_taken()
	{
		return nameTaken;
	}


	int hold()
	{
		holdName = trueName;
		holdPass = truePass;
		holdType = trueType;
	}
	int release()
	{
		trueName = holdName;
		truePass = holdPass;
		trueType = holdType;
	}


	string hash(int value)
	{                                    //APHash, algorithim by Arash Partow
		string point;
		if (value == 1) point = trueName;
		else if (value == 2) point = truePass;
		else if (value == 3)
		{
			stringstream SS;
			SS << hash(2);
			point = SS.str().substr(trueType, 3);
		}

	    unsigned int hash = 0xAAAAAAAA;
	    for (int i = 0; i < point.length(); i++)
	    {
	        hash ^= ((i & 1) == 0) ?
    	            ((hash << 7) ^ point[i] * (hash >> 3)) :
        	        (~((hash << 11) + (point[i] ^ (hash >> 5))));
    	}                                //End APHash algorithim

    	stringstream SS;
    	SS << hash;
    	return SS.str();
	}


	int create_entry()                                   //Creates basic user
	{
    	fstream userLib;
    	userLib.open("lib/ulib", fstream::app);
    	//make_hash(user);
    	userLib << hash(1)		// name
	            << ":";
    	//make_hash(pass);
    	userLib << hash(2)		// pass
        	    << "!";
    	//make_hash(holdHash.substr(1, 3));//Basic password hash section
    	userLib << hash(3)		// type
        	    << "\n";
    	userLib.close();
	}


	int check()
	{
    	nameTaken = false; 
    	int colon, exPoint;
    	string holdUser, 
    		   chkUser, chkPass, chkType;
    	ifstream userLib;
    	userLib.open("lib/ulib");
    	//make_hash(user);
    	while (userLib >> holdUser)
    	{
	        colon = holdUser.find(':');
        	exPoint = holdUser.find('!');
        	chkUser = holdUser.substr(0, colon);
        	chkPass = holdUser.substr(colon + 1, exPoint - (colon + 1));
	        chkType = holdUser.substr(exPoint + 1, holdUser.length() - (exPoint + 1));
    	    if (hash(1) == chkUser)
        	{
	            nameTaken = true;
            	//make_hash(pass);
            	if (hash(2) == chkPass)
            	{	
	                //make_hash(chkPass.substr(1, 3));            //Basic password hash section
	                trueType = 1;
                	if (hash(3) == chkType) return 1;
                	else
                	{
	                    //make_hash(chkPass.substr(2, 3));        //Power password hash section
	                    trueType = 2;
                    	if (hash(3) == chkType) return 2;
                    	else
                    	{
	                        //make_hash(chkPass.substr(3, 3));    //Admin password hash section
	                        trueType = 3;
                        	if (hash(3) == chkType) return 3;
                        	else return 0;
                    	}
                	}
            	}
            	else return 0;
        	}            
    	}
    	userLib.close();
	}


	int make(int newType)                  //Makes user specified type; 1, 2, or 3
	{
    	bool success = false;
    	string holdUser,
    		   chkUser, chkPass, chkType;
    	int colon, exPoint;

    	fstream userLib;
    	userLib.open("lib/ulib");

    	while (userLib >> holdUser)
    	{
	    	int inputLoc = userLib.tellg();
        	colon = holdUser.find(':');
        	exPoint = holdUser.find('!');
        	chkUser = holdUser.substr(0, colon);
        	chkPass = holdUser.substr(colon + 1, exPoint - (colon + 1));
        	chkType = holdUser.substr(exPoint + 1, holdUser.length() - (exPoint + 1));
        	if (hash(1) == chkUser)
        	{
        		truePass = chkPass;
        		trueType = newType;

            	userLib.seekp(inputLoc - (holdUser.length() - exPoint));
            	userLib << hash(3);
            	success = true;
        	}
    	}
    	userLib.close();
	    if (success)
    	{
    	    if (trueType == 1)          // Basic success
	        {
            	cout << "\n> "
                 	 << trueName
                 	 << "'s user-type changed to basic"
                 	 << endl;
        	}
        	else if (trueType == 2)     // Power success
        	{
	            cout << "\n> "
                 	 << trueName
                 	 << "'s user-type changed to basic"
                 	 << endl;
        	}
        	else if (trueType == 3)     // Admin success
        	{
	            cout << "\n> "
    	             << trueName
        	         << "'s user-type changed to admin"
            	     << endl;
        	}
        	else cerr << error("typeError");
    	}
    	else cerr << error("typeChange");
	}


	int pass_change()
	{
	    int colon, exPoint;
    	bool success = false;
    	bool noUserEntry = true;
    	fstream userLib;
    	userLib.open("lib/ulib");
    	string holdUser,
    		   chkUser, chkPass, chkType;
    	while (userLib >> holdUser)
    	{
	        int inputLoc = userLib.tellg();
        	colon = holdUser.find(':');
        	exPoint = holdUser.find('!');
        	chkUser = holdUser.substr(0, colon);
        	chkPass = holdUser.substr(colon + 1, exPoint - (colon + 1));
        	chkType = holdUser.substr(exPoint + 1, holdUser.length() - (exPoint + 1));
        	if (hash(1) == chkUser)
        	{
	            noUserEntry = false;
            	cout << "\nCurrent Password: ";
            	cin >> truePass;
            	if (hash(2) == chkPass)
            	{
            		int type;
	                trueType = 1;            //Basic password hash section
                	if (hash(3) == chkType) type = 1;
                	else
                	{
	                    trueType = 2;        //Power password hash section
                    	if (hash(3) == chkType) type = 2;
                    	else
                    	{
                        	trueType = 3;    //Admin password hash section
                        	if (hash(3) == chkType) type = 3;
                        	else cerr << error("typeError");
                    	}
                	}
                	if (type == (1 || 2 || 3))
                	{
	                    string nPass, nPassChk;
                    	cout << "New Password: ";
                    	cin >> nPass;
                    	cout << "Confirm Password: ";
                    	cin >> nPassChk;
                    	if (nPass == nPassChk)
                    	{
	                        cout << "\n> Changing "
                             	 << trueName
                             	 << "'s password..."
                             	 << endl;
                        	new_pass(nPass);
                        	userLib.seekp(inputLoc - (holdUser.length() - colon));
                        	userLib << hash(2);
                        	userLib.seekp(inputLoc - (holdUser.length() - exPoint));
                        	userLib << hash(3);
                        	success = true;
                    	}
                    	else cerr << error("passMismatch");
                	}
            	}
            	else cerr << error("passMismatch");
        	}
    	}
    	if (noUserEntry) cerr << error("noUserEntry");
    	if (success)
    	{
	        cout << "\n> "
             	 << trueName
              	 << "'s password successfully changed"
             	 << endl;
    	}
    	else
    	{
	        cout << "\n> Password change incomplete"
             	 << endl;
    	}
	}


//	unsigned int name_hash()
//	{                                    //APHash, algorithim by Arash Partow
//	    unsigned int hash = 0xAAAAAAAA;
//	    for (int i = 0; i < trueName.length(); i++)
//	    {
//	        hash ^= ((i & 1) == 0) ?
//    	            ((hash << 7) ^ trueName[i] * (hash >> 3)) :
//        	        (~((hash << 11) + (trueName[i] ^ (hash >> 5))));
//    	}                                //End APHash algorithim
//    	return hash;
//	}
//	unsigned int pass_hash()
//	{                                    //APHash, algorithim by Arash Partow
//	    unsigned int hash = 0xAAAAAAAA;
//	    for (int i = 0; i < truePass.length(); i++)
//	    {
//	        hash ^= ((i & 1) == 0) ?
//    	            ((hash << 7) ^ truePass[i] * (hash >> 3)) :
//        	        (~((hash << 11) + (truePass[i] ^ (hash >> 5))));
//    	}                                //End APHash algorithim
//    	return hash;
//	}
//	unsigned int type_hash()
//	{                                    //APHash, algorithim by Arash Partow
//		stringstream hashOut;
//		hashOut << pass_hash();
//		string passHash = hashOut.str();
//
//	    unsigned int hash = 0xAAAAAAAA;
//	    for (int i = 0; i < passHash.substr(trueType, 3).length(); i++)
//	    {
//	        hash ^= ((i & 1) == 0) ?
//    	            ((hash << 7) ^ passHash.substr(trueType, 3)[i] * (hash >> 3)) :
//        	        (~((hash << 11) + (passHash.substr(trueType, 3)[i] ^ (hash >> 5))));
//    	}                                //End APHash algorithim
//    	return hash;
//	}


};

#endif