#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "include/User.h"

using namespace std;

extern int caller;      // Variable for switch(caller) in main()

User user;

int login()
{
    cout << "\n> Type 'new' to create new user, or enter username."
         << endl
         << "\nUsername: ";
    string name;
    cin >> name;
    user.new_name(name);
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
        user.new_pass(pass);
        if (user.check() == 1)                 //Basic user login
        {
            cout << "\n> Logged in "
                 << user.name()
                 << endl;
            user.new_type(1);
            //cout << user.type();
            return caller = 2;//Calls cmd_line()
        }
        else if (user.check() == 2)            //Power user login
        {
            cout << "\n> Logged in power "
                 << user.name()
                 << endl;
            user.new_type(2);
            cout << user.type();
            return caller = 2;//Calls cmd_line()
        }
        else if (user.check() == 3)            //Admin user login
        {
            cout << "\n> Logged in admin "
                 << user.name()
                 << endl;
            user.new_type(3);
            cout << user.type();
            return caller = 2;//Calls cmd_line()
        }
        else
        {
            user.reset();
            cerr << error("badLogin");
            return caller = 1;//Calls login()
        }
    }
}