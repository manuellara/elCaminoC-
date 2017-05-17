/*
ALGORITHM 
CS-1 Assignment 3 
Manuel Lara

//////////////////////   MAIN    /////////////////////////
declare variables for fin, fout, fileName, outputFile, name, ID, salary, flatTax, tax, net, avgCount, avgNet, highestNet, lowestNet, highestName, lowestName
CALL checkFile

///////////////////////function 1 : checkFile
takes 16 variables : fin, fout, fileName, outputFile, name, ID, salary, flatTax, tax, net, avgCount, avgNet, highestNet, lowestNet, highestName, lowestName
prompt user to enter file path 
store user input in fileName
open fileName
if the file fails to open, prompt the user and exit the program
if the program opens successfully, prompt the user for output file name and store it in outputFile
open outputFile

CALL header and pass fout
CALL NameSalID and pass fin, fout, name, ID, salary, flatTax, tax, net, avgCount, avgNet, highestNet, lowestNet, highestName, lowestName

close fileName
close outputFile


///////////////////////////function 2 : header 
takes fout as a parameter 
print table headers with the appropriate format 


////////////////////////function 3 : NameIDSal 
takes fin, fout, name, ID, salary, flatTax, tax, net, avgCount, avgNet, highestNet, lowestNet, highestName, lowestName as parameters 
while not end of file
get the first line and store it as name
get the second line , split values between ID and salary
clear buffer

if the ID length does not equal 4 , print invalid statement
if salary is less than or equal to 0 , print invalid statement
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

if ID length is 4 and salary is greater than 0
print statement table

if ID length is 4 and salary is greater than 0
add to counter , add to total net

CALL minMax and pass net, name, highestNet, lowestNet, highestName, lowestName
CALL printNclose and pass fout, avgNet, avgCount, highestNet, lowestNet, highestName, lowestName


//////////////////////////function 4 : minMax
takes net, name, highestNet, lowestNet, highestName, lowestName as parameters 
if net is greater than highestNet
set highestNet to net
set highestName to name

if lowestNet is lowestNet , set lowestNet to net
else if net is less than lowest
lowestNet is net
lowestName is name

/////////////////////////function 5 : printNclose 
takes fout, avgNet, avgCount, highestNet, lowestNet, highestName, lowestName as parameters 
print average net by dividing totalNet by the local counter
next print highestNet statement
next print lowestNet statement

*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

void checkFile(ifstream &fin, ofstream &fout, string &fileName, string &outputFile, string &name, string &ID, float &salary, float &flatTax, float &tax, float &net, int &avgCount, float &avgNet, float &highestNet, float &lowestNet, string &highestName, string &lowestName);
void header(ofstream &fout);
void NameIDSal(ifstream &fin, ofstream &fout, string &name, string &ID, float &salary, float &flatTax, float &tax, float &net, int &avgCount, float &avgNet, float &highestNet, float &lowestNet, string &highestName, string &lowestName);
void minMax(float &net, string &name, float &highestNet, float &lowestNet, string &highestName, string &lowestName);
void printNclose(ofstream &fout, float &avgNet, int &avgCount, float &highestNet, float &lowestNet, string &highestName, string &lowestName);

int main()
{
	string fileName;
	string outputFile;
	string name;
	string ID;
	float salary;
	float flatTax;
	float tax;
	float net;
	float highestNet = -1;
	float lowestNet = -1;
	string highestName;
	string lowestName;
	int avgCount = 0;
	float avgNet = 0;

	ifstream fin;
	ofstream fout;

	checkFile(fin, fout, fileName, outputFile, name, ID, salary, flatTax, tax, net, avgCount, avgNet, highestNet, lowestNet, highestName, lowestName);

}

void checkFile(ifstream &fin, ofstream &fout, string &fileName, string &outputFile, string &name, string &ID, float &salary, float &flatTax, float &tax, float &net, int &avgCount, float &avgNet, float &highestNet, float &lowestNet, string &highestName, string &lowestName)
{

	cout << "Enter file path : ";
	getline(cin, fileName);

	///////////opens data file
	fin.open(fileName.c_str() );

	if (fin.fail())
	{
		cout << "Bad file name...";
		exit(0);
	}
	else
	{
		cout << "Enter output file name followed by '.txt' : ";
		getline(cin, outputFile);
		////////////opens output file
		fout.open(outputFile);

		///////////prints header
		header(fout);

		///////////gets name , id , salary and processes it
		NameIDSal(fin, fout, name, ID, salary, flatTax, tax, net, avgCount, avgNet, highestNet, lowestNet, highestName, lowestName);

	}

	/////////////////file in/out close
	fin.close();
	fout.close();
}

void header(ofstream &fout)
{
	fout << left << fixed << setprecision(2);
	fout << setw(20) << "Name" << setw(20) << "ID" << setw(20) << "Gross Income" << setw(20) << "Taxes" << setw(20) << "Net Income" << endl;
	fout << "===================================================================================================" << endl;
}

void NameIDSal(ifstream &fin, ofstream &fout, string &name, string &ID, float &salary, float &flatTax, float &tax, float &net, int &avgCount, float &avgNet, float &highestNet, float &lowestNet, string &highestName, string &lowestName)
{
	while (!fin.eof())
	{
		//////////DATA
		getline(fin, name);
		fin >> ID >> salary;
		fin.ignore(128, '\n');

		///////////////bad/invalid data check
		if (name == "" || ID == "" || salary == 0)
		{
			cout << "Bad data in file" << endl;
			exit(0);
		}

		////////ID Check 
		if (ID.length() != 4)
		{
			fout << setw(20) << name << setw(20) << ID << setw(20) << salary << setw(20) << "****INVALID ID" << endl;
		}
		////////salary check 
		if (salary <= 0)
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
		else if (salary > 3500 && salary <= 8000)
		{
			flatTax = 0;
			tax = (salary - 3500) * 6 / 100;
			net = salary - (flatTax + tax);
		}
		else if (salary > 8000 && salary <= 20000)
		{
			flatTax = 270;
			tax = (4500 * (6 / 100)) + ((salary - 8000) * (11 / 100));
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
			tax = (4500 * (6 / 100)) + (12000 * (11 / 100)) + (14000 * (17 / 100)) + (20000 * (24 / 100)) + ((salary - 54000) * (32 / 100));
			net = salary - (flatTax + tax);
		}

		/////////table print statement
		if (ID.length() == 4 && salary > 0)
		{
			fout << setw(20) << name << setw(20) << ID << setw(20) << salary << setw(20) << tax + flatTax << setw(20) << net << endl;
		}
		/////////finds average net
		if (ID.length() == 4 && salary > 0)
		{
			avgCount += 1;
			avgNet += net;
		}

		/////////finds min max
		minMax(net, name, highestNet, lowestNet, highestName, lowestName);
	}

	/////////////print statement 
	printNclose(fout, avgNet, avgCount, highestNet, lowestNet, highestName, lowestName);
}

void minMax(float &net, string &name, float &highestNet, float &lowestNet, string &highestName, string &lowestName)
{
	////////finds max net
	if (net > highestNet)
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
}

void printNclose(ofstream &fout, float &avgNet, int &avgCount, float &highestNet, float &lowestNet, string &highestName, string &lowestName)
{
	fout << "\n\n\n" << setw(40) << "Average Net" << setw(20) << avgNet / avgCount << endl;
	fout << setw(40) << "Highest Net Income" << setw(20) << highestName << setw(20) << highestNet << endl;
	fout << setw(40) << "Lowest Net Income" << setw(20) << lowestName << setw(20) << lowestNet << endl;

}