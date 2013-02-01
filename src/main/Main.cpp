//#include <iostream>
//#include <vector>
//#include <fstream>
//#include <string>
//#include <sstream>
//#include <stdlib.h>

using namespace std;

int caller = 1;				// Variable for switch(caller) in main()

int login();
int cmd_line();
int new_user();

int main()
{
    switch (caller)
    {
        case 1:               //Calls login()
            login();
            main();
            break;
        case 2:               //Calls cmd_line()
            cmd_line();
            main();
            break;
        case 3:               //Calls new_user()
            new_user();
            main();
            break;
        default:              //Breaks
            return 0;
            break;
    }
    return 0;
}