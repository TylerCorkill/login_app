#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdlib.h>

#include "include/User.h"
//#include "include/exUser.h"

using namespace std;

extern int caller;      // Variable for switch(caller) in main()
extern User user;

int help(int type);
int add(int i1, int i2);
int wipe_ulib();
int start(string prgm);
int stop(string sPrgm);
int minecraft(string mUser, string mPass);

int cmd_line()
{
    string cmd;
    cout << "\nEnter Command: ";
    cin >> cmd;

    
    if (cmd == "quit")
    {
        cout << "\n> Exiting program...\n";
        return caller = 0;//Breaks
    }
    else if (cmd == "logout")
    {
        cout << "\n> Logging out..."
             << endl;
        cout << "\n> "
             << user.name()
             << " logged out"
             << endl;
        user.reset();
        return caller = 1;//Calls login()
    }
    //else if (cmd == "test")
    //{
        //user.hold();
        //cout << user.name() << endl;
        //string name2, pass2;
        //cout << "Test name: ";
        //cin >> name2;
        //cout << "Test pass: ";
        //cin >> pass2;
        //user.new_name(name2);
        //user.new_pass(pass2);
        //user.new_type(1);
        //cout << user.name() << user.pass() << user.type() << endl;
        //user.release();
    //}
    else if (user.type() == 1 || 2 || 3)                // Basic, Power, and Admin
    {
        if (cmd == "help")
        {
            help(user.type());
            return caller = 2;//Calls cmd_line()
        }
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
            while (!(cin >> x1))
            {
                num_check();
                return caller = 2;//Calls cmd_line()
            }
            while (!(cin >> x2))
            {
                num_check();
                return caller = 2;//Calls cmd_line()
            }
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
