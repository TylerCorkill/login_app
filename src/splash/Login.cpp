#include <iostream>
#include <string>

using namespace std;

extern int caller;      // Variable for switch(caller) in main()

string user;            // Username input string
string pass;            // Password input string
bool basic;             // Basic value
bool power;             // Power value
bool admin;             // Admin value

string error(string error);

int check_login();

int login()
{
    cout << "\n> Type 'new' to create new user, or enter username."
         << endl
         << "\nUsername: ";
    cin >> user;
    if (user == "new")
    {
        return caller = 3;//Calls new_user()
    }
    //else if (user == "break") return caller = 0;
    else
    {
        cout << "\nPassword: ";
        cin >> pass;
        if (check_login() == 1)                 //Basic user login
        {
            cout << "\n> Logged in "
                 << user
                 << endl;
            basic = true;
            return caller = 2;//Calls cmd_line()
        }
        else if (check_login() == 2)            //Power user login
        {
            cout << "\n> Logged in power "
                 << user
                 << endl;
            power = true;
            return caller = 2;//Calls cmd_line()
        }
        else if (check_login() == 3)            //Admin user login
        {
            cout << "\n> Logged in admin "
                 << user
                 << endl;
            admin = true;
            return caller = 2;//Calls cmd_line()
        }
        else
        {
            cerr << error("badLogin");
            return caller = 1;//Calls login()
        }
    }
}