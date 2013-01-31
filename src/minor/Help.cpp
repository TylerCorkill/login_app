#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

extern bool admin;

int help()
{
	if (admin)
	{
		cout << "\n================================================="
			 << "\n|     Commands      |        Desctiption        |"
			 << "\n| - - - - - - - - - | - - - - - - - - - - - - - |"
			 << "\n|                   |                           |"
			 << "\n|  help             |  Displays this box        |"
			 << "\n|                   |                           |"
			 << "\n|  logout           |  Logs out current user    |"
			 << "\n|                   |                           |"
			 << "\n|  quit             |  Exits this program       |"
			 << "\n|                   |                           |"
			 << "\n|  start PROGRAM    |  Starts external PROGRAM  |"
			 << "\n|                   |                           |"
			 << "\n|  stop PROGRAM     |  Quits external PROGRAM   |"
			 << "\n|                   |                           |"
			 << "\n|  sys COMMAND      |  Enters system COMMAND    |"
			 << "\n|                   |                           |"
			 << "\n|  wipe-ulib        |  Wipes the user library   |"
			 << "\n|                   |                           |"
			 << "\n|  admin USER       |  Makes USER an admin      |"
			 << "\n|                   |                           |"
			 << "\n| - - - - - - - - - | - - - - - - - - - - - - - |"
			 << "\n================================================="
			 << endl;
	}
	else
	{
		cout << "\n================================================="
			 << "\n|     Commands      |        Desctiption        |"
			 << "\n| - - - - - - - - - | - - - - - - - - - - - - - |"
			 << "\n|                   |                           |"
			 << "\n|  help             | displays this information |"
			 << "\n|                   |                           |"
			 << "\n|  logout           | logs out current user     |"
			 << "\n|                   |                           |"
			 << "\n|  quit             | exits this program        |"
			 << "\n|                   |                           |"
			 << "\n|  start PROGRAM    | starts external PROGRAM   |"
			 << "\n|                   |                           |"
			 << "\n|  stop PROGRAM     | quits external PROGRAM    |"
			 << "\n|                   |                           |"
			 << "\n| - - - - - - - - - | - - - - - - - - - - - - - |"
			 << "\n================================================="
			 << endl;
	}
}