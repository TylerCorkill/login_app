#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

string error(string error);

int stop(string sPrgm)
{
	if (sPrgm == "minecraft")
	{
		cout << "\n> Stopping minecraft...\n"
			 << endl;
		system("taskkill /IM javaw.exe /FI \"WINDOWTITLE eq Minecraft\"");
	}
	else cerr << error("prgmUnknown");
}