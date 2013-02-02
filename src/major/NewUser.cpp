#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "include/User.h"
//#include "include/Error.h"

using namespace std;

extern int caller;          // Variable for switch(caller) in main()

//User::User(string newName, string newPass, int newType);
//User::User();
//extern User user();

//extern string user;         // Username input string
//extern string pass;         // Password input string
//extern string chkPass;      // Password check string
//extern bool nameTaken;      // Holds true if username is taken

//string error(string error);

extern User user;

//int check_login();
//int create_user();

int new_user()
{
    user.hold();
    cout << "\n> Type 'cancel' to return to login"
         << endl
         << "\nEnter desired username: ";
    string name;
    cin >> name;
    user.new_name(name);
    user.check();
    if (name == "cancel")
    {
        cout << "\n> Canceling...\n"
             << endl;
        return caller = 1;//Calls login()
    }
    else if (user.name_taken())
    {
        cerr << error("userExists");
        return caller = 3;//Calls new_user()
    }
    else
    {
        string pass, chkPass;
        cout << endl
             << "Enter desired password: ";
        cin >> pass;
        cout << endl
             << "Confirm desired password: ";
        cin >> chkPass;
        if (pass != chkPass)
        {
            cerr << error("passMismatch");
            return caller = 3;//Calls new_user()
        }
        else
        {
            cout << "\n> Creating user "
                 << user.name()
                 << "..."
                 << endl;
            user.new_pass(pass);
            user.create_entry();
            //create_user();
            cout << "\n> User "
                 << user.name()
                 << " created!"
                 << endl;
            return caller = 1;//Calls login()
        }
    }
    user.release();
}