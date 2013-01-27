#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int caller = 1;				// Variable for switch(caller) in main()

int login();
int cmd_line(int argc, char *argv[]);
int new_user();

char hold()
{
    char hold;
    cin >> hold;
    return hold;
}

int main(int argc, char *argv[])
{
    switch (caller)
    {
        case 1:               //Calls login()
            caller = 1;
            login();
            main(argc, argv);
            break;
        case 2:               //Calls cmd_line()
            caller = 1;
            cmd_line(argc, argv);
            main(argc, argv);
            break;
        case 3:               //Calls new_user()
            caller = 1;
            new_user();
            main(argc, argv);
            break;
        default:              //Breaks
            return 0;
            break;
    }
    if (hold() == 'r') main(argc, argv);
    return 0;
}