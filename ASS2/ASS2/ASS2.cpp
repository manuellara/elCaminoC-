#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("incomes.txt") ;
	
	string name;
	string ID;
	float salary;
	int count = 0;
	float flatTax;
	float tax;
	float net;


	while ( !fin.eof() )
	{
		//////////DATA
		getline(fin, name);
		fin >> ID >> salary;
		fin.ignore(128, '\n');

		/////////table header 
		if (count == 0)
		{
			cout << left;
			cout << setw(20) << "Name" << setw(20) << "ID" << setw(20)  << "Gross Income" << setw(20) << "Taxes" << setw(20) << "Net Income" << endl << endl;
		}
		////////ID Check 
		if ( ID.length() != 4 )
		{
			cout << setw(20) << name << setw(20) << ID << setw(20) << salary << setw(20) << "****INVALID ID" << endl;
		}
		////////salary check 
		if ( salary <= 0 )
		{
			cout << setw(20) << name << setw(20) << ID << setw(20) << salary << setw(20) << "****INVALID SALARY" << endl;
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

		/////////print statement
		if (ID.length() == 4 && salary > 0)
		{
			cout << setw(20) << name << setw(20) << ID << setw(20) << salary << setw(20) << tax + flatTax << setw(20) << net << endl ;
		}


		count++;
	}

	fin.close();
}