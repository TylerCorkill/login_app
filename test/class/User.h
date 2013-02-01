#ifndef USER_H
#define USER_H

using namespace std;

class User					// User class test for program
{
private:
	string trueName;
	string truePass;
	int trueType;		// 1 basic, 2 power, 3 admin
public:
	User()
	{
		trueName = "*";
		truePass = "*";
		trueType = 0;
	}
	User(string newName = "*", string newPass = "*", int newType = 0)
	{
		trueName = newName;
		truePass = newPass;
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
	unsigned int name_hash()
	{                                    //APHash, algorithim by Arash Partow
	    unsigned int hash = 0xAAAAAAAA;
	    for (int i = 0; i < trueName.length(); i++)
	    {
	        hash ^= ((i & 1) == 0) ?
    	            ((hash << 7) ^ trueName[i] * (hash >> 3)) :
        	        (~((hash << 11) + (trueName[i] ^ (hash >> 5))));
    	}                                //End APHash algorithim
    	return hash;
	}
	unsigned int pass_hash()
	{                                    //APHash, algorithim by Arash Partow
	    unsigned int hash = 0xAAAAAAAA;
	    for (int i = 0; i < truePass.length(); i++)
	    {
	        hash ^= ((i & 1) == 0) ?
    	            ((hash << 7) ^ truePass[i] * (hash >> 3)) :
        	        (~((hash << 11) + (truePass[i] ^ (hash >> 5))));
    	}                                //End APHash algorithim
    	return hash;
	}
	unsigned int type_hash()
	{                                    //APHash, algorithim by Arash Partow
		stringstream hashOut;
		hashOut << pass_hash();
		string passHash = hashOut.str();

	    unsigned int hash = 0xAAAAAAAA;
	    for (int i = 0; i < passHash.substr(trueType, 3).length(); i++)
	    {
	        hash ^= ((i & 1) == 0) ?
    	            ((hash << 7) ^ passHash.substr(trueType, 3)[i] * (hash >> 3)) :
        	        (~((hash << 11) + (passHash.substr(trueType, 3)[i] ^ (hash >> 5))));
    	}                                //End APHash algorithim
    	return hash;
	}
};

#endif