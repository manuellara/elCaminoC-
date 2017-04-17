/*  
CS 1 - Manuel Lara
Ammortization Table 

Algorithm 

STEP 1 : INPUT
import all the libraries you will need, in this case we used iostream, sring, cmath, and iomanip
next, initialize variables for name, choice, loan amount, interest, and years to pay

next prompt the user to enter thir name and store it in the name variable
validate the input

next, promp the user to enter whether they would like to create an ammortization table(y or n) and store answer in the choice variable
evaluate the input
if it is neither 'y' or 'n', it will prompt you to reenter a value 
if 'n', program will exit
if 'y' program will proceed

next, prompt the user to enter a loan amount and store it in the loam amount variable
evaluate input
if loan amount is not a number, prompt the user  to reenter a number

next, prompt the user to enter an interest rate and store it in the interest rate variable
evaluate input 
if interest rate is not a n umber, prompt the user to reenter a valid interest rate
once a valid number is read, divide the number by 100 to get the decimal and store it in the interest rate variable

next, prompt the user to enter amount of years they would like to pay off the loan and store it in years to pay variable 
evaluate input
if years to pay is not a number, prompt the user to enter a valid number

STEP 2 : PROCESS 
set user input to accomidate ammortization formula variables
P = loan amount 
n = years to pay * 12
r = interest / n
base = (1+r)^n
A = P * ( base*r / base-1 )

next, include print statements to show all user input

STEP 3 : OUTPUT
include a standalone print staement the catagory labels (payment no, payment amount, interest, principal, ending balance)
next we will create a loop to print the output, but first we must initialize a local variable and set it to the ending balance OUTSIDE of the loop

create a loop and set the counter to stop at our previously defined n variable + 1 
to make things more readable
set A to mp
set inter to ending * r
set principal to mp - inter

next, have your print statement 

lastly, set the reset variable to ending to ending - principal 
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
					cout << left;
					cout << "\n\n\n" << setw(15) <<"Payment #" << setw(20) << "Payment Amount" << setw(15) << "Interest" << setw(15) << "Principal" << setw(15) << "Ending Balance" << endl;
					float ending = P;
					for (int counter = 0; counter < n + 1; counter++)
					{
						float mp = A;
						float inter = ending * r ;
						float principal = mp - inter ;

						cout << fixed << setprecision(2);
						cout << setw(15) << counter << setw(20) << mp << setw(15) << inter << setw(15) << principal << setw(15) << ending << endl;
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