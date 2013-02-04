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


	void new_name(string newName)
	{
		trueName = newName;
	}
	void new_pass(string newPass)
	{
		truePass = newPass;
	}
	void new_type(int newType)
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


    void reset()
    {
        //cout << "\n1-true: " << trueName << truePass << trueType << "\n1-hold: " << holdName << holdPass << holdType << endl;
        trueName = "";
        truePass = "";
        trueType = 0;
        holdName = "";
        holdPass = "";
        holdType = 0;
        //cout << "2-true: " << trueName << truePass << trueType << "\n2-hold: " << holdName << holdPass << holdType << endl;
    }


	void hold()
	{
        //cout << "\n1h-true: " << trueName << truePass << trueType << "\n1h-hold: " << holdName << holdPass << holdType << endl;
		holdName = trueName;
		holdPass = truePass;
		holdType = trueType;
        //cout << "2h-true: " << trueName << truePass << trueType << "\n2h-hold: " << holdName << holdPass << holdType << endl;
	}
	void release()
	{
        //cout << "1r-true: " << trueName << truePass << trueType << "\n1r-hold: " << holdName << holdPass << holdType << endl;
		trueName = holdName;
		truePass = holdPass;
		trueType = holdType;
        //cout << "2r-true: " << trueName << truePass << trueType << "\n2r-hold: " << holdName << holdPass << holdType << endl;
	}


	string hash(int value)
	{                                    //APHash, algorithim by Arash Partow
		string point;
		if (value == 1) point = trueName;
		else if (value == 2) point = truePass;
		else if (value == 3) point = hash(2).substr(trueType, 3);
        else if (value == 4) point = hash(1).substr(0, 3);
        else if (value == 5) point = hash(1).substr(3, 3);
        else if (value == 6) point = hash(1).substr(6, 3);

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
    	ofstream userLib;
    	userLib.open("lib/ulib", fstream::app);
    	userLib << hash(1)		// name
	            << ":"
    	        << hash(2)		// pass
        	    << "!"
                << hash(3)		// type
        	    //<< "\n"
                //<< hash(4)
                //<< ":"
                //<< hash(5)
                //<< "!"
                //<< hash(6)
                << "\n";
    	userLib.close();
	}


	int check()
	{
        hold();
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
                	if (hash(3) == chkType)
                    {
                        release();
                        userLib.close();
                        return 1;
                    }
                	else
                	{
	                    //make_hash(chkPass.substr(2, 3));        //Power password hash section
	                    trueType = 2;
                    	if (hash(3) == chkType)
                        {
                            release();
                            userLib.close();
                            return 2;
                        }
                    	else
                    	{
	                        //make_hash(chkPass.substr(3, 3));    //Admin password hash section
	                        trueType = 3;
                        	if (hash(3) == chkType)
                            {
                                release();
                                userLib.close();
                                return 3;
                            }
                        	else
                            {
                                release();
                                userLib.close();
                                return 0;
                            }
                    	}
                	}
            	}
            	else
                {
                    release();
                    userLib.close();
                    return 0;
                }
        	}            
    	}
        release();
    	userLib.close();
        return 0;
	}


	int make(int newType)                  //Makes user specified type; 1, 2, or 3
	{
        //hold();
    	bool success = false;
    	string holdUser, chkLine,
    		   chkUser, chkPass, chkType, chkPassIn;
    	int colon, exPoint, inputLoc;
        int line = 0;
        char holdChar;
    	fstream userLib;
    	userLib.open("lib/ulib");

        while(true)
        {
            if (userLib.peek() == -1) break;
            holdChar = userLib.get();
            if (holdChar == '\n') ++line;
        }
        //cout << line << endl;
        userLib.seekg(0, ios::beg);
    	while (userLib >> holdUser)
    	{
            --line;
	    	inputLoc = userLib.tellg();
        	colon = holdUser.find(':');
        	exPoint = holdUser.find('!');
        	chkUser = holdUser.substr(0, colon);
        	chkPass = holdUser.substr(colon + 1, exPoint - (colon + 1));
        	chkType = holdUser.substr(exPoint + 1, holdUser.length() - (exPoint + 1));
            //cout << line << endl << inputLoc << " " << colon << " " << exPoint << " " << holdUser.length() << endl;
        	if (hash(1) == chkUser)
        	{
                cin >> chkPassIn;
                truePass = chkPassIn;
                if (hash(2) == chkPass)
                {
                    trueType = newType;
                    userLib.seekp(inputLoc - (holdUser.length() - exPoint + line));
                    userLib << hash(3);
                    //cout << "check" << endl;
                    success = true;
                    break;
                }
                else
                {
                    cerr << error("passMismatch");
                    break;
                }
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
                 	 << "'s user-type changed to power"
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
        //release();
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
};

#endif