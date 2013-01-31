#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

extern string user;     // Username input string
extern string pass;     // Password input string
extern int caller;      // Variable for switch(caller) in main()
extern bool basic;      // Basic value
extern bool power;      // Power value
extern bool admin;      // Admin value

string error(string error);

int help();
int start(string prgm);
int stop(string sPrgm);
int add(int i1, int i2);
int wipe_ulib();
int make(string userNew, int type);
int minecraft(string mUser, string mPass);

//string cmd;

int cmd_line()
{
    string cmd;
    cout << "\nEnter Command: ";
    //getline (cin, cmd);
    cin >> cmd;
    if (cmd == "help")
    {
        help();
        return caller = 2;//Calls cmd_line()
    }
    else if (cmd == "logout")
    {
        cout << "\n> Logging out..."
             << endl;
        basic = false;
        power = false;
        admin = false;
        cout << "\n> "
             << user
             << " logged out"
             << endl;
        return caller = 1;//Calls login()
    }
    else if (basic || power || admin)
    {
        if (cmd == "start")                     // Starts program
        {
            string program;
            cin >> program;
            start(program);
            return caller = 2;//Calls cmd_line()
        }
        else if (cmd == "stop")                 // Stops program
        {
            string program;
            cin >> program;
            stop(program);
            return caller = 2;//Calls cmd_line()
        }
        else if (cmd == "add")
        {
            //cout << true;
            int x1, x2;
            cin >> x1 >> x2;
            cout << "\n> "
                 << x1
                 << " + "
                 << x2
                 << " = "
                 << add(x1, x2)
                 << endl;
            return caller = 2;//Calls cmd_line()
        }
        else if (cmd == "quit")
        {
            cout << "\n> Exiting program...\n";
            return caller = 0;//Breaks loop
        }
        else if (power || admin)
        {
            if (cmd == "sys")
            {
                string command;
                cin >> command;
                system(command.c_str());
                return caller = 2;//Calls cmd_line()
            }
            else if (cmd == "basic")
            {
                string userType;
                cin >> userType;
                //cout << user;
                cout << "\n> Changing "
                     << userType
                     << "'s user-type..."
                     << endl;
                make(userType, 1);// 1 coresponds to basic
                cout << "\n> "
                     << userType
                     << "'s user-type changed to basic"
                     << endl;
                return caller = 2;//Calls cmd_line()
            }
            else if (cmd == "power")
            {
                string userType;
                cin >> userType;
                //cout << user;
                cout << "\n> Changing "
                     << userType
                     << "'s user-type..."
                     << endl;
                make(userType, 2);// 2 coresponds to power
                cout << "\n> "
                     << userType
                     << "'s user-type changed to basic"
                     << endl;
                return caller = 2;//Calls cmd_line()
            }
            else if (admin)
            {
                if (cmd == "wipe-ulib")
                {
                    cout << "\n> Wipeing user library..."
                         << endl;
                    wipe_ulib();
                    admin = false;
                    cout << "\n> User library wiped\n"
                         << endl;
                    return caller = 1;//Calls login()
                }
                else if (cmd == "admin")
                {
                    string userType;
                    cin >> userType;
                    //cout << user;
                    cout << "\n> Changing "
                         << userType
                         << "'s user-type..."
                         << endl;
                    make(userType, 3);// 3 coresponds to admin
                    cout << "\n> "
                         << userType
                         << "'s user-type changed to admin"
                         << endl;
                    return caller = 2;//Calls cmd_line()
                }
                else
                {
                    cerr << error("cmdUnknown");
                    return caller = 2;//Calls cmd_line()
                }
            }
            else
            {
                cerr << error("cmdUnknown");
                return caller = 2;//Calls cmd_line()
            }
        }
        else
        {
            cerr << error("cmdUnknown");
            return caller = 2;//Calls cmd_line()
        }
    }
    else
    {
        cerr << error("cmdUnknown");
        return caller = 2;//Calls cmd_line()
    }
}