#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "include/User.h"
//#include "include/exUser.h"

using namespace std;

extern int caller;          // Variable for switch(caller) in main()
extern User user;

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
        cout << "\nEnter desired password: ";
        cin >> pass;
        cout << "\nConfirm desired password: ";
        cin >> chkPass;
        if (pass != chkPass)
        {
            cerr << error("passMismatch");
            return caller = 3;//Calls new_user()
        }
        else
        {
            user.new_pass(pass);
            if (user.type() == 3)
            {
                int type;
                cout << "\nEnter type: ";
                cin >> type;
                user.new_type(type);
            }
            else user.new_type(1);
            cout << "\n> Creating user "
                 << user.name()
                 << "..."
                 << endl;
            user.create_entry();
            cout << "\n> User "
                 << user.name()
                 << " created!"
                 << endl;
            return caller = 1;//Calls login()
        }
    }
    user.release();
}