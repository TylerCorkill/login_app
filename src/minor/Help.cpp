#include <iostream>
#include <string>

using namespace std;

extern bool basic;
extern bool power;
extern bool admin;

string error(string error);

int help()
{
	if (basic)
	{
		cout << "\n  ================================================="
			 << "\n  |     Commands      |        Desctiption        |"
			 << "\n  | - - - - - - - - - | - - - - - - - - - - - - - |"
			 << "\n  |                   |                           |"
			 << "\n  |  help             | displays this information |"
			 << "\n  |                   |                           |"
			 << "\n  |  logout           | logs out current user     |"
			 << "\n  |                   |                           |"
			 << "\n  |  quit             | exits this program        |"
			 << "\n  |                   |                           |"
			 << "\n  |  start PROGRAM    | starts external PROGRAM   |"
			 << "\n  |                   |                           |"
			 << "\n  |  stop PROGRAM     | quits external PROGRAM    |"
			 << "\n  |                   |                           |"
			 << "\n  | - - - - - - - - - | - - - - - - - - - - - - - |"
			 << "\n  ================================================="
			 << endl;
	}
	else if (power)
	{
		cout << "\n  ================================================="
			 << "\n  |     Commands      |        Desctiption        |"
			 << "\n  | - - - - - - - - - | - - - - - - - - - - - - - |"
			 << "\n  |                   |                           |"
			 << "\n  |  help             |  Displays this box        |"
			 << "\n  |                   |                           |"
			 << "\n  |  logout           |  Logs out current user    |"
			 << "\n  |                   |                           |"
			 << "\n  |  quit             |  Exits this program       |"
			 << "\n  |                   |                           |"
			 << "\n  |  start PROGRAM    |  Starts external PROGRAM  |"
			 << "\n  |                   |                           |"
			 << "\n  |  stop PROGRAM     |  Quits external PROGRAM   |"
			 << "\n  |                   |                           |"
			 << "\n  |  sys COMMAND      |  Enters system COMMAND    |"
			 << "\n  |                   |                           |"
			 << "\n  |  basic USER       |  Makes USER an admin      |"
			 << "\n  |                   |                           |"
			 << "\n  |  power USER       |  Makes USER a power type  |"
			 << "\n  |                   |                           |"
			 << "\n  | - - - - - - - - - | - - - - - - - - - - - - - |"
			 << "\n  ================================================="
			 << endl;
	}
	else if (admin)
	{
		cout << "\n  ============================================================="
			 << "\n  |     Commands      |              Desctiption              |"
			 << "\n  | - - - - - - - - - | - - - - - - - - - - - - - - - - - - - |"
			 << "\n  |                   |                                       |"
			 << "\n  |  help             |  Displays this box                    |"
			 << "\n  |                   |                                       |"
			 << "\n  |  logout           |  Logs out current user                |"
			 << "\n  |                   |                                       |"
			 << "\n  |  quit             |  Exits this program                   |"
			 << "\n  |                   |                                       |"
			 << "\n  |  start PROGRAM    |  Starts external predefined PROGRAM   |"
			 << "\n  |                   |                                       |"
			 << "\n  |  stop PROGRAM     |  Quits external predefined PROGRAM    |"
			 << "\n  |                   |                                       |"
			 << "\n  |  sys COMMAND      |  Enters system COMMAND                |"
			 << "\n  |                   |                                       |"
			 << "\n  |  wipe-ulib        |  Wipes the user library               |"
			 << "\n  |                   |                                       |"
			 << "\n  |  mod-pass USER    |  Opens change USER password dialog    |"
			 << "\n  |                   |                                       |"
			 << "\n  |  basic USER       |  Makes USER a basic type              |"
			 << "\n  |                   |                                       |"
			 << "\n  |  power USER       |  Makes USER a power type              |"
			 << "\n  |                   |                                       |"
			 << "\n  |  admin USER       |  Makes USER an admin                  |"
			 << "\n  |                   |                                       |"
			 << "\n  | - - - - - - - - - | - - - - - - - - - - - - - - - - - - - |"
			 << "\n  ============================================================="
			 << endl;
	}
	else
	{
		cerr << error("typeUnknown");
	}
}