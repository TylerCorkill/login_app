#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdlib.h>

#include "include/User.h"
//#include "include/Error.h"

using namespace std;

extern int caller;      // Variable for switch(caller) in main()

//User::User(string newName, string newPass, int newType);
//User::User();
//extern string user;     // Username input string
//extern string pass;     // Password input string
//extern bool basic;      // Basic value
//extern bool power;      // Power value
//extern bool admin;      // Admin value

extern User user;

//string error(string error);

int help();
int start(string prgm);
int stop(string sPrgm);
int add(int i1, int i2);
int wipe_ulib();
//int make(string userNew, int type);
//int change_pass(string uName);
int minecraft(string mUser, string mPass);

//void class_test();

int cmd_line()
{
    string cmd;
    cout << "\nEnter Command: ";
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
        //basic = false;
        //power = false;
        //admin = false;
        cout << "\n> "
             << user.name()
             << " logged out"
             << endl;
        return caller = 1;//Calls login()
    }
    else if (cmd == "quit")
    {
        cout << "\n> Exiting program...\n";
        return caller = 0;//Breaks
    }
    else if (user.type() == 1 || 2 || 3)                // Basic, Power, and Admin
    {
        if (cmd == "start")
        {
            string program;
            cin >> program;
            start(program);
            return caller = 2;//Calls cmd_line()
        }
        else if (cmd == "stop")
        {
            string program;
            cin >> program;
            stop(program);
            return caller = 2;//Calls cmd_line()
        }
        else if (cmd == "add")
        {
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
        else if (user.type() == 2 || 3)                 // Power and Admin
        {
            if (cmd == "sys")
            {
                string command;
                cin >> command;
                system(command.c_str());
                return caller = 2;//Calls cmd_line()
            }
            if (cmd == "basic")
            {
                string username;
                cin >> username;
                cout << "\n> Changing "
                     << username
                     << "'s user-type..."
                     << endl;
                user.hold();
                user.new_name(username);
                user.make(1);
                user.release();
                return caller = 2;//Calls cmd_line()
            }
            else if (cmd == "power")
            {
                string username;
                cin >> username;
                cout << "\n> Changing "
                     << username
                     << "'s user-type..."
                     << endl;
                user.hold();
                user.new_name(username);
                user.make(2);
                user.release();
                return caller = 2;//Calls cmd_line()
            }
            else if (user.type() == 3)                  // Admin only
            {
                if (cmd == "wipe-ulib")
                {
                    cout << "\n> Wipeing user library..."
                         << endl;
                    wipe_ulib();
                    cout << "\n> User library wiped\n"
                         << endl;
                    return caller = 1;//Calls login()
                }
                else if (cmd == "mod-pass")
                {
                    string username;
                    cin >> username;
                    user.hold();
                    user.new_name(username);
                    user.pass_change();
                    user.release();
                    return caller = 2;//Calls cmd_line()
                }
                //else if (cmd == "class-test") class_test();
                else if (cmd == "admin")
                {
                    string username;
                    cin >> username;
                    cout << "\n> Changing "
                         << username
                         << "'s user-type..."
                         << endl;
                    user.hold();
                    user.new_name(username);
                    user.make(3);
                    user.release();
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