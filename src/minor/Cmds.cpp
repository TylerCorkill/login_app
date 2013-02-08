#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
//#include "include/User.h"
//#include "include/Error.h"

using namespace std;

//User::User(string newName, string newPass, int newType);

//extern string user;		// Username input string
//extern string pass;		// Password input string

//string chkUser;			// Username check string
//string chkPass;			// Password check string
//string chkType;			// User type check string
//string holdHash;		// Hash holder
//bool nameTaken;         // Holds true if username is taken

//string error(string error);

int add(int i1, int i2)
{
    return i1 + i2;
}

int sub(int i1, int i2)
{
    return i1 - i2;
}

int wipe_ulib()
{
	ofstream userLib;
	userLib.open("lib/ulib");
	userLib.close();
}

//unsigned int make_hash(string hashIn)
//{                                    //APHash, algorithim by Arash Partow
    //unsigned int hash = 0xAAAAAAAA;
    //for (int i = 0; i < hashIn.length(); i++)
    //{
        //hash ^= ((i & 1) == 0) ?
                //((hash << 7) ^ hashIn[i] * (hash >> 3)) :
                //(~((hash << 11) + (hashIn[i] ^ (hash >> 5))));
    //}                                //End APHash algorithim
    //stringstream hashSS;
    //hashSS << hash;
    //holdHash = hashSS.str();
//}

//int create_entry()                                   //Creates basic user
//{
    //ofstream userLib;
    //userLib.open("lib/ulib", fstream::app);
    //make_hash(user);
    //userLib << holdHash
            //<< ":";
    //make_hash(pass);
    //userLib << holdHash
            //<< "!";
    //make_hash(holdHash.substr(1, 3));//Basic password hash section
    //userLib << holdHash
            //<< "\n";
    //userLib.close();
//}

//int make(string userNew, int type)                  //Makes user specified type; 1, 2, or 3
//{
    //bool success = false;
    //fstream userLib;
    //userLib.open("lib/ulib");
    //string holdUser;
    //int colon;
    //int exPoint;
    //make_hash(userNew);
    //while (userLib >> holdUser)
    //{
    	//int inputLoc = userLib.tellg();
        //colon = holdUser.find(':');
        //exPoint = holdUser.find('!');
        //chkUser = holdUser.substr(0, colon);
        //chkPass = holdUser.substr(colon + 1, exPoint - (colon + 1));
        //chkType = holdUser.substr(exPoint + 1, holdUser.length() - (exPoint + 1));
        //if (holdHash == chkUser)
        //{
            //make_hash(chkPass.substr(type, 3));//Password hash section
            //userLib.seekp(inputLoc - (holdUser.length() - exPoint));
            //userLib << holdHash;
            //success = true;
        //}
    //}
    //userLib.close();
    //if (success)
    //{
        //if (type == 1)          // Basic success
        //{
            //cout << "\n> "
                 //<< type
                 //<< "'s user-type changed to basic"
                 //<< endl;
        //}
        //else if (type == 2)     // Power success
        //{
            //cout << "\n> "
                 //<< type
                 //<< "'s user-type changed to basic"
                 //<< endl;
        //}
        //else if (type == 3)     // Admin success
        //{
            //cout << "\n> "
                 //<< type
                 //<< "'s user-type changed to admin"
                 //<< endl;
        //}
        //else cerr << error("typeError");
    //}
    //else cerr << error("typeChange");
//}

//int check_login()
//{
    //nameTaken = false;
    //ifstream userLib;
    //userLib.open("lib/ulib"); 
    //string holdUser;
    //int colon;
    //int exPoint;
    //make_hash(user);
    //while (userLib >> holdUser)
    //{
        //colon = holdUser.find(':');
        //exPoint = holdUser.find('!');
        //chkUser = holdUser.substr(0, colon);
        //chkPass = holdUser.substr(colon + 1, exPoint - (colon + 1));
        //chkType = holdUser.substr(exPoint + 1, holdUser.length() - (exPoint + 1));
        //if (holdHash == chkUser)
        //{
            //nameTaken = true;
            //make_hash(pass);
            //if (holdHash == chkPass)
            //{
                //make_hash(chkPass.substr(1, 3));            //Basic password hash section
                //if (holdHash == chkType) return 1;
                //else
                //{
                    //make_hash(chkPass.substr(2, 3));        //Power password hash section
                    //if (holdHash == chkType) return 2;
                    //else
                    //{
                        //make_hash(chkPass.substr(3, 3));    //Admin password hash section
                        //if (holdHash == chkType) return 3;
                        //else return 0;
                    //}
                //}
            //}
            //else return 0;
        //}            
    //}
    //userLib.close();
//}

//int change_pass(string uName)
//{
    //int type;
    //bool success = false;
    //bool noUserEntry = true;
    //fstream userLib;
    //userLib.open("lib/ulib");
    //string holdUser;
    //int colon;
    //int exPoint;
    //make_hash(uName);
    //while (userLib >> holdUser)
    //{
        //int inputLoc = userLib.tellg();
        //colon = holdUser.find(':');
        //exPoint = holdUser.find('!');
        //chkUser = holdUser.substr(0, colon);
        //chkPass = holdUser.substr(colon + 1, exPoint - (colon + 1));
        //chkType = holdUser.substr(exPoint + 1, holdUser.length() - (exPoint + 1));
        //if (holdHash == chkUser)
        //{
            //noUserEntry = false;
            //cout << "\nCurrent Password: ";
            //cin >> pass;
            //make_hash(pass);
            //if (holdHash == chkPass)
            //{
                //make_hash(chkPass.substr(1, 3));            //Basic password hash section
                //if (holdHash == chkType) type = 1;
                //else
                //{
                    //make_hash(chkPass.substr(2, 3));        //Power password hash section
                    //if (holdHash == chkType) type = 2;
                    //else
                    //{
                        //make_hash(chkPass.substr(3, 3));    //Admin password hash section
                        //if (holdHash == chkType) type = 3;
                        //else cerr << error("typeError");
                    //}
                //}
                //if (type == (1 || 2 || 3))
                //{
                    //string nPass, nPassChk;
                    //cout << "New Password: ";
                    //cin >> nPass;
                    //cout << "Confirm Password: ";
                    //cin >> nPassChk;
                    //if (nPass == nPassChk)
                    //{
                        //cout << "\n> Changing "
                             //<< uName
                             //<< "'s password..."
                             //<< endl;
                        //make_hash(nPass);
                        //userLib.seekp(inputLoc - (holdUser.length() - colon));
                        //userLib << holdHash;
                        //make_hash(holdHash.substr(type, 3));//Password hash section
                        //userLib.seekp(inputLoc - (holdUser.length() - exPoint));
                        //userLib << holdHash;
                        //success = true;
                    //}
                    //else cerr << error("passMismatch");
                //}
            //}
            //else cerr << error("passMismatch");
        //}
    //}
    //if (noUserEntry) cerr << error("noUserEntry");
    //if (success)
    //{
        //cout << "\n> "
             //<< uName
             //<< "'s password successfully changed"
             //<< endl;
    //}
    //else
    //{
        //cout << "\n> Password change incomplete"
             //<< endl;
    //}
//}
