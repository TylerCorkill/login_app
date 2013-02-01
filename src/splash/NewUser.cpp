#include <iostream>
#include <string>

using namespace std;

extern string user;         // Username input string
extern string pass;         // Password input string
extern string chkPass;      // Password check string
extern int caller;          // Variable for switch(caller) in main()
extern bool nameTaken;      // Holds true if username is taken

string error(string error);

int check_login();
int create_user();

int new_user()
{
    cout << "\n\n> Type 'cancel' to return to login\n"
         << endl
         << "Enter desired username: ";
    cin >> user;
    check_login();
    if (user == "cancel")
    {
        cout << '\n'
             << "> Canceling...\n"
             << endl;
        return caller = 1;//Calls login()
    }
    else if (nameTaken)
    {
        cerr << error("userExists");
        return caller = 3;//Calls new_user()
    }
    else
    {
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
                 << user
                 << "..."
                 << endl;
            create_user();
            cout << "\n> User "
                 << user
                 << " created!"
                 << endl;
            return caller = 1;//Calls login()
        }
    }
}