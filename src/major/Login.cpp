#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "include/User.h"
//#include "include/Error.h"

using namespace std;

extern int caller;      // Variable for switch(caller) in main()

//User::User(string newName, string newPass, int newType);
//User::User();
//string user;            // Username input string
//string pass;            // Password input string
//bool basic;             // Basic value
//bool power;             // Power value
//bool admin;             // Admin value

User user;

//int check_login();
//string error(string error);

int login()
{
    cout << "\n> Type 'new' to create new user, or enter username."
         << endl
         << "\nUsername: ";
    string name;
    cin >> name;
    if (name == "new")
    {
        return caller = 3;//Calls new_user()
    }
    //else if (user == "break") return caller = 0;
    else
    {
        cout << "\nPassword: ";
        string pass;
        cin >> pass;
        //cout << "\ntest: ";
        //string test;
        //cin >> test;
        if (name != "")
        {
            user.new_name(name);
        }
        cout << "1";
        if (pass != "")
        {
            user.new_pass(pass);
        }
        cout << "2";
        if (pass == user.pass())
        {
            user.new_type(3);
        }
        cout << "3";
        if (user.type() == 1)                 //Basic user login
        {
            cout << "\n> Logged in "
                 << user.name()
                 << endl;
            //basic = true;
            return caller = 2;//Calls cmd_line()
        }
        else if (user.type() == 2)            //Power user login
        {
            cout << "\n> Logged in power "
                 << user.name()
                 << endl;
            //power = true;
            return caller = 2;//Calls cmd_line()
        }
        else if (user.type() == 3)            //Admin user login
        {
            cout << "\n> Logged in admin "
                 << user.name()
                 << endl;
            //admin = true;
            return caller = 2;//Calls cmd_line()
        }
        else
        {
            cerr << error("badLogin");
            return caller = 1;//Calls login()
        }
    }
}