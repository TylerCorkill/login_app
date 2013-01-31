#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

extern int caller;      // Variable for switch(caller) in main()

string user;            // Username input string
string pass;            // Password input string
bool basic = false;     // Basic value
bool power = false;     // Power value
bool admin = false;     // Admin value

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
        if (user != "")
        {
            cout << "\nPassword: ";
            cin >> pass;
            if (check_login() == 1)//Basic user login
            {
                cout << '\n'
                     << "> Logged in "
                     << user
                     << endl;
                basic = true;
                return caller = 2;//Calls cmd_line()
            }
            else if (check_login() == 2)//Power user login
            {
                cout << "\n> Logged in power "
                     << user
                     << endl;
                power = true;
                return caller = 2;//Calls cmd_line()
            }
            else if (check_login() == 3)//Admin user login
            {
                cout << "\n> Logged in admin "
                     << user
                     << endl;
                admin = true;
                return caller = 2;//Calls cmd_line()
            }
            else
            {
                error("badLogin");
                return caller = 1;//Calls login()
            }
        }
        else
        {
            error("emptyUser");
            return caller = 1;//Calls login()
        }
    }             
}