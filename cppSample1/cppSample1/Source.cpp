//-----------------
//Test1.cpp
//Manuel Lara
//-----------------


#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "Manuel Lara" << endl;

	string Name;
	int Year;

	cout << "Please enter you name and press enter: ";
	getline (cin, Name);

	cout << "Please enter your birth year using 4 digits: ";
	cin >> Year;

	cout << "\n\n\aHello, " << Name << "! Welcome to CS 1. \n\n\a" << endl;

	cout << "At age of  " << 2017 - Year << ", you will have a fun semester.";

	cout << "\n\nHave a good day. \n\n";

	return 0;
}