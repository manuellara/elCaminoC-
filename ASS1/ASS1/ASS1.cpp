/*  
CS 1 - Manuel Lara
Ammortization Table 

Algorithm 

*/

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	string name;
	string choice;
	float loanAmount;
	float interest;
	float yearsToPay;

	cout << "Enter your name: " ;
	getline(cin, name); 
	cout << "Would you like to create an Ammortization table? Enter 'y' for Yes or 'n' for No: " ;
	cin >> choice;
	if (!cin)
	{
		cout << "You did not follow the instructions...try again" << endl;
		cin.clear();
		cin.ignore(128, '\n');
		cin >> choice;
	}
	else if (choice == "y")
	{
		cout << "Enter loan amount: " ;
		cin >> loanAmount;
		if (!cin)
		{
			cout << "You did not enter a valid loan amount...try again" << endl;
			cin.clear();
			cin.ignore(128, '\n');
			cin >> loanAmount;
		}
		else
		{
			cout << "Enter interest rate: " ;
			cin >> interest;
			if (!cin)
			{
				cout << "You did not enter a valid interest rate...try again" << endl;
				cin.clear();
				cin.ignore(128, '\n');
				cin >> interest;
			}
			else
			{
				interest = interest / 100;
				cout << "Enter amount of years you would like to pay off loan: " ;
				cin >> yearsToPay;
				if (!cin)
				{
					cout << "You did not enter a valid year...try again" << endl;
					cin.clear();
					cin.ignore(128, '\n');
					cin >> yearsToPay;
				}
				else
				{
					float P = loanAmount;
					float n = yearsToPay * 12;
					float r = interest / n;
					float base = pow((1 + r), n);
					float A = (P * ((r * base) / (base - 1)));

					/*Name Statement*/
					cout << "\n\n\nYour name is: " << name << endl;
					/*Loan Info*/
					cout << "Loan amount: " << loanAmount << endl;
					cout << "Interest rate: " << interest << endl;
					cout << "Years to pay loan: " << yearsToPay << endl;
					cout << "# of Monthly Payments: " << n << endl;
					/*Ammortization Table*/
					cout << "\n\n\nPayment #" << " " << "Payment Amount" << " " << "Interest" << " " << "Principal" << " " << "Ending Balance" << endl;
					float ending = P;
					for (int counter = 0; counter < n + 1; counter++)
					{
						float mp = A;
						float inter = ending * r ;
						float principal = mp - inter ;

						cout << fixed << setprecision(2);
						cout << counter << setw(15) << mp << setw(15) << inter << setw(15) << principal << setw(15) << ending << endl;
						ending = ending - principal;

					}
				}
			}
		}
	}
	else if (choice == "n") 
	{
		cout << "...goodbye." << endl;
		exit(0);
	}




}