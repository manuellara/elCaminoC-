/*
Manuel Lara
CS 1 - Assignment 2

Algorithm

first, declare all the variables you will need. name , ID , salary, net , counter, etc..
next, declare file handlers for in/out

INPUT :
ask the user for a file or path. store the response in fileName
next, ask the user to enter the desired output name. store the response in outputFile

use appropriate file handlers to open each file

PROCESS :
while not end of file
	get the first line and store it as name
	get the second line , split values between ID and salary
	clear buffer

	if the counter is 0 , print out the table header
	if the ID length does not equal 4 , print invalid statement 
	if salary is less than or equal to 0 , print invalid statemnt 
	if salary is greater than or equal to 3500
		flatTax is 0 , tax is 0 and net is unaffected
	if salary is greater than 3500 but less than or equal to 8000
		flatTax is 0 , tax is 6% and net is calculated
	if salary is greater than 8000 but less than or equal to 20000
		flatTax is 270 , tax is 11% , net is calculated
	if salary is greater than 20000 but less than or equal to 34000
		flatTax is 1590 , tax is 17% , net is calculated 
	if salary is greater than 34000 but less than or equal to 54000
		flatTax is 3970 , tax is 24% , net is calculated
	if salary is greater than 54000 
		flat tax is 8770 , tax is 32% , net is calculated

OUTPUT :
	if ID length is 4 and salary is greater than 0 
		print statement table 

	if ID length is 4 and salary is greater than 0  
		add to counter , add to total net

	if net is greater than highestNet 
		set highestNet to net
		set highestName to name

	if lowestNet is lowestNet , set lowestNet to net
	else if net is less than lowest 
		lowestNet is net
		lowestName is name 

	increment counter

next print avgerage net by dividing totalNet by the local counter
next print highestNet statement
next print lowestNet statment 

last , close both in/out file handlers

*/


#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
	string fileName;
	string outputFile;
	string name;
	string ID;
	float salary;
	int count = 0;
	float flatTax;
	float tax;
	float net;
	float highestNet = -1;
	float lowestNet = -1;
	string highestName;
	string lowestName;
	int avgCount = 0;
	float avgNet = 0;

	///////////////file handlers 
	ifstream fin;
	ofstream fout;

	////////////////file input
	cout << "Enter file path : ";
	getline(cin , fileName);

	//////////////file output
	cout << "Enter output file name: ";
	getline(cin , outputFile);

	////////////////////file in/out open
	fin.open(fileName );
	fout.open(outputFile );

	while ( !fin.eof() )
	{
		//////////DATA
		getline(fin, name);
		fin >> ID >> salary;
		fin.ignore(128, '\n');

		/////////table header 
		if (count == 0)
		{
			fout << left << fixed << setprecision(2);
			fout << setw(20) << "Name" << setw(20) << "ID" << setw(20)  << "Gross Income" << setw(20) << "Taxes" << setw(20) << "Net Income" << endl ;
			fout << "===================================================================================================" << endl;
		}
		////////ID Check 
		if ( ID.length() != 4 )
		{
			fout << setw(20) << name << setw(20) << ID << setw(20) << salary << setw(20) << "****INVALID ID" << endl;
		}
		////////salary check 
		if ( salary <= 0 )
		{
			fout << setw(20) << name << setw(20) << ID << setw(20) << salary << setw(20) << "****INVALID SALARY" << endl;
		}
		/////////calculating tax
		if (salary <= 3500)
		{
			flatTax = 0;
			tax = 0;
			net = salary - (flatTax + tax);
		}
		else if (salary > 3500 && salary <= 8000 )
		{
			flatTax = 0;
			tax = (salary - 3500) * 6/100;
			net = salary - (flatTax + tax);
		}
		else if (salary > 8000 && salary <= 20000)
		{
			flatTax = 270;
			tax = (4500 * (6/100)) + ( (salary - 8000) * (11/100) ) ;
			net = salary - (flatTax + tax);
		}
		else if (salary > 20000 && salary <= 34000)
		{
			flatTax = 1590;
			tax = (4500 * (6 / 100)) + (12000 * (11 / 100)) + ((salary - 20000) * (17 / 100));
			net = salary - (flatTax + tax);
		}
		else if (salary > 34000 && salary <= 54000)
		{
			flatTax = 3970;
			tax = (4500 * (6 / 100)) + (12000 * (11 / 100)) + (14000 * (17 / 100)) + ((salary - 34000) * (24 / 100));
			net = salary - (flatTax + tax);
		}
		else if (salary > 54000)
		{
			flatTax = 8770;
			tax = (4500 * (6 / 100)) + (12000 * (11 / 100)) + (14000 * (17 / 100))+ (20000 * (24/100)) + ((salary - 54000) * (32 / 100));
			net = salary - (flatTax + tax);
		}

		/////////table print statement
		if (ID.length() == 4 && salary > 0)
		{
			fout << setw(20) << name << setw(20) << ID << setw(20) << salary << setw(20) << tax + flatTax << setw(20) << net << endl ;
		}

		/////////finds average net
		if (ID.length() == 4 && salary > 0)
		{
			avgCount +=1 ;
			avgNet += net; 
		}

		////////finds max net
		if ( net > highestNet)
		{
			highestNet = net;
			highestName = name;
		}

		////////finds min net
		if (lowestNet == lowestNet)
		{
			lowestNet = net;
			lowestName = name;
		}
		else if (net < lowestNet)
		{
			lowestNet = net;
			lowestName = name;
		}

		count++;
	}

	fout << "\n\n\n" << setw(40) << "Average Net" << setw(20) << avgNet / avgCount << endl;
	fout << setw(40) << "Highest Net Income" << setw(20) << highestName << setw(20) << highestNet << endl;
	fout << setw(40) << "Lowest Net Income" << setw(20) << lowestName << setw(20) << lowestNet << endl;

	/////////////////file in/out close
	fin.close();
	fout.close();
}