Login project
=========

## Description
This is a beginner project I've started as a suplement to learning C++, as well as practice git use.

### Program Features
* User login, requireing password verification
* Ability to create a new user without logging in
* External account library, so accounts aren't deleted upon quitting the program
* Usertypes, only basic, power, and admin for now
* Account info hashing for the account library
* Unique usertype hashing, avoiding a specific "admin" hash that the library could be searched for
* A limited command line, mostly used to check functionality of program additions. Current abilities are as follows:
  * User logout (obviously)
  * Start/Stop programs (only Minecraft at the moment)
  * Enter system commands (terminal/command prompt etc.) from inside the program
  * Admin-only commands, as follows:
  * Wipe the account library (deletes default admin too, so still a work in progress)
  * Make a user an admin (for which an admin is needed, and wiping would destroy ALL accounts)
  * Change user passwords
* And ofcourse a system for displaying errors

### Default Accounts
##### Username/Password

basic/pass

power/pass

admin/pass



## Compiling
You will need a C++ compiler; I use the gcc.  If you prefer another compiler thats perfectly ok,
it just has to compile the multiple source files into one *.exe.  And if you don't have gcc, 
but want it, download it [**here**](http://sourceforge.net/projects/mingw/).

### Using gcc
Since I use the gcc I'll provide an easy mode, just enter this command from the program directory:

      g++ src/main/Main.cpp src/major/CmdLine.cpp src/major/Login.cpp src/major/NewUser.cpp src/minor/Cmds.cpp src/minor/Help.cpp src/minor/Start.cpp src/minor/Stop.cpp -o main.exe

And run main.exe, which should be in the program's directory.
