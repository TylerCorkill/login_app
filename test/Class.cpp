#include <iostream>
#include <string>
#include <sstream>

using namespace std;




class Calc1					// Example 1, member functions defined inside class
{
private:
	int mValue;
public:
	Calc1()
	{
		mValue = 0;
	}
	void add(int nValue)
	{
		mValue += nValue;
	}
	void sub(int nValue)
	{
		mValue -= nValue;
	}
	void mult(int nValue)
	{
		mValue *= nValue;
	}
	int get_value()
	{
		return mValue;
	}
};




class Calc2					// Example 2, member functions defined outside class
{
private:
	int mValue;
public:
	Calc2()
	{
		mValue = 0;
	}
	void add(int nValue);
	void sub(int nValue);
	void mult(int nValue);
	int get_value()
	{
		return mValue;
	}
};

void Calc2::add(int nValue)
{
	mValue += nValue;
}

void Calc2::sub(int nValue)
{
	mValue -= nValue;
}

void Calc2::mult(int nValue)
{
	mValue *= nValue;
}




class Fraction
{
private:
	int mNumerator;
	int mDenominator;
public:
	Fraction()										// Default constructor
	{
		mNumerator = 0;
		mDenominator = 1;
	}
	Fraction(int nNumerator, int nDenominator = 1)	// Constructor with parameters
	{
		//assert(nDenominator != 0);
		mNumerator = nNumerator;
		mDenominator = nDenominator;
	}
	int numerator()
	{
		return mNumerator;
	}
	int denominator()
	{
		return mDenominator;
	}
	double result()
	{
		return static_cast <double> (mNumerator) / mDenominator;
	}
};




class User					// User class test for program
{
private:
	string trueName;
	string truePass;
	int trueType;		// 1 basic, 2 power, 3 admin
public:
	User()
	{
		trueName = "*";
		truePass = "*";
		trueType = 0;
	}
	User(string newName = "*", string newPass = "*", int newType = 0)
	{
		trueName = newName;
		truePass = newPass;
		trueType = newType;
	}
	string name()
	{
		return trueName;
	}
	string pass()
	{
		return truePass;
	}
	int type()
	{
		return trueType;
	}
	unsigned int name_hash()
	{                                    //APHash, algorithim by Arash Partow
	    unsigned int hash = 0xAAAAAAAA;
	    for (int i = 0; i < trueName.length(); i++)
	    {
	        hash ^= ((i & 1) == 0) ?
    	            ((hash << 7) ^ trueName[i] * (hash >> 3)) :
        	        (~((hash << 11) + (trueName[i] ^ (hash >> 5))));
    	}                                //End APHash algorithim
    	return hash;
	}
	unsigned int pass_hash()
	{                                    //APHash, algorithim by Arash Partow
	    unsigned int hash = 0xAAAAAAAA;
	    for (int i = 0; i < truePass.length(); i++)
	    {
	        hash ^= ((i & 1) == 0) ?
    	            ((hash << 7) ^ truePass[i] * (hash >> 3)) :
        	        (~((hash << 11) + (truePass[i] ^ (hash >> 5))));
    	}                                //End APHash algorithim
    	return hash;
	}
	unsigned int type_hash()
	{                                    //APHash, algorithim by Arash Partow
		stringstream hashOut;
		hashOut << pass_hash();
		string passHash = hashOut.str();

	    unsigned int hash = 0xAAAAAAAA;
	    for (int i = 0; i < passHash.substr(trueType, 3).length(); i++)
	    {
	        hash ^= ((i & 1) == 0) ?
    	            ((hash << 7) ^ passHash.substr(trueType, 3)[i] * (hash >> 3)) :
        	        (~((hash << 11) + (passHash.substr(trueType, 3)[i] ^ (hash >> 5))));
    	}                                //End APHash algorithim
    	return hash;
	}
};

void class_test()
{
	string testName, testPass;
	int testType = 3;
	cout << "\n> Enter name: ";
	cin >> testName;
	cout << "\n> Enter pass: ";
	cin >> testPass;
	cout << "\n> Testing class User..."
		 << endl;
	User test(testName, testPass, testType);
	cout << "\n> Username: "
		 << test.name()
		 << endl
		 << "\n> Password: "
		 << test.pass()
		 << endl
		 << "\n> Usertype: "
		 << test.type()
		 << endl
		 << "\n> User hash: "
		 << test.name_hash()
		 << ":"
		 << test.pass_hash()
		 << "!"
		 << test.type_hash()
		 << endl;
}