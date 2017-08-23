/*
CS 1 - Final Project 
Manuel Lara

int main()
	CALLS menu()

string fileInput()
	takes 1 parameter : fin passed as reference 
	ask user to input data file to read from
	check to see if file exists
	if not
		loop and ask the user reenter a different file
		if file exists
			exit loop
	return file name

void menuOptions()
		output of menu options 

string waitForChar()
	waits for input
	return the first char of input

void addNewCustomer()
	takes 1 parameter : temp is passed by reference 
	ask user for first name , last name , city , state , address , and balance  
	check to make sure balance input is valid
	store them as values for temp

string removeCustomer()
	ask user who they would like to remove
	return input 

string balanceWithdraw()
	ask user who they want to make a withdraw from 
	return input

float withdrawAmoutn()
	ask user how much they would like to withdraw
	return amount

string balanceDeposit()
	ask user for user you want to make a deposit in
	return input 

float depositAmount()
	ask user for amount to be deposited 
	return amount 

string outputFileName()
	ask user for output file name
	return output file name

string sortListPrompt()
	display sorting menu 
	ask user to select sorting option
	return first char of input 

string enterName()
	ask user for the name of whose record to display
	return input

void menu()
	CALL fileInput and pass fin 
	store result in target

	open target

	enter loop while not the end of file
		pick up title
		enter for loop to iterate 3 times
			pick up last name , first name , address , city , state , balance

	enter do-while loop while input is not x and array is not full
		CALL menuOptions()
		CALL waitForChar() and store the result in m

		if user selects a
			CALL addNewCustomer() and pass temp
			check if name in list
			if same name is detected
				ask user to input different name
			set temp to current element in customer array
			increment size
			clear screen

		if user selects r
			CALL removeCustomer() and store result in ntarget
			store current size of array to temp variable 

			iterate through array
				if name is found, 
					move all elements up 1
					decrease logical size of array by 1

				else if counter equals size at the end 
					record was not found

		if user selects p
			print header
			if size equals 0
				print error statement

			else 
				iterate through array 
					print elements in tabular format

		if user selects w
			CALL balanceWithdraw() and store result in target
			for the length of the logical size
				if target matches element last name
					CALL withdrawAmount() and store in wAmount
						if wAmount is larger than element balance, 
							enter loop and keep asking until condition is met
								break
						subtract wAmount from element balance
					else
						subtract wAmount from element balance
				else
					print error statement 

		if user selects d
			CALL balamceDeposite() and store variable in target
			iterate through list and find corresponding name
				if name found 
					CALL depositAmount() and store variable in dAmount
					add dMount to current balance
				else 
					print error message

		if user selects s
			CALL outputFileName() and store variable in target
			open file
			prints record to file
			close file

		if user selects t
		CALL sortListPrompt() and store in starget

		ask user whether they want to sort by name , city , or balance 
		bubble sort the selection

		if user selects v
		CALL enterName() and store value in ptarget
		iterate through customers 
		if ptarget matched a record
			print the record

	

*/


#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#define max 50

using namespace std;

struct account																		//structure definition
{
	string firstName, lastName, address, city, state;
	float balance;
};

string fileInput(ifstream &fin);
void menu();
void menuOptions();
string waitForChar();
void addNewCustomer(account &temp);
string removeCustomer();
string balanceWithdraw();
float withdrawAmount();
string balanceDeposit();
float depositAmount();
string outputFileName();
string sortListPrompt();
string enterName();

int main()
{
	menu();														//calls menu
}

void menu()
{
	string title , m , target , ntarget , starget, ptarget;
	account temp , customer[max], tempSortString;
	int size = 0;
	int tSize , tempSortInt , tempSize;
	float wAmount , dAmount;
	ifstream fin;
	ofstream fout;

	target = fileInput(fin);												//gets filename and verifies it, stores result in target

	fin.open(target);														//opens file

	while (!fin.eof())														//populates bank
	{
		getline(fin, title);										//picks up first line
		fin.clear();
		fin.ignore(128, '\n');

		for (size ; size < 3 ; size++ )
		{
			getline(fin, temp.lastName, ',');
			fin >> temp.firstName;
			fin.clear();
			fin.ignore(128, '\n');
			getline(fin, temp.address);
			getline(fin, temp.city);
			getline(fin, temp.state);
			fin >> temp.balance;
			fin.clear();
			fin.ignore(128, '\n');

			customer[size] = temp;
		}

		fin.close();															//close input file
	}

	do
	{
		cout << "\n\nWelcome to First Bank of ECC!";

		cout << "\n\nChoose an option...";

		menuOptions();

		m = waitForChar();													//CALLS waitForChar() and stores result in 'm'

		if (m == "a" || m == "A")
		{
			addNewCustomer(temp);											//CALLS addNewCustomer and passes temp

			for (int i = 0 ; i < size ; i++)								//iterates through array
			{
				if (temp.lastName == customer[i].lastName )					//compares last name
				{
					while (true)											//if last names are the same, enter loop
					{
						cout << "\n\nSame name detected ; pick a different name. : ";			//error message

						getline(cin , temp.lastName);								//call addNewCustomer and pass temp

						if (temp.lastName != customer[i].lastName)			//if new temp last name not equal to current 
						{
							break;
							
						}

					}
				}
			}

			customer[size] = temp;											//set customer index to temp
			size++;															//increase size
			system("cls");													//clear screen
		}
		else if (m == "r" || m == "R")
		{
			ntarget = removeCustomer();										//CALL removeCustomer() and set name to target 

			tSize = size;													//saves size before

			for (int i = 0 ; i < size ; i++)								//iterate through customer
			{
				if (ntarget == customer[i].lastName)						//if name is found
				{
					for (int j = i ; j < size ; ++j)
					{
						customer[j] = customer[j + 1];						//replace current value with the next value until the end of size
					}
					size--;													//decreases size
					cout << "\n\nCongrats, you removed a record!";
					break;
				}
			}

			if (tSize == size)
			{
				cout << "\n\nRecord does not exist.....";
			}

			cin.get();
			system("cls");
		}
		else if (m == "p" || m == "P")
		{
			if (size == 0)
			{
				cout << left << fixed << setprecision(2);
				cout << setw(20) << "\n\nFirst Bank of ECC Report\n" << endl;
				cout << setw(20) << "Name" << setw(20) << "Address" << setw(20) << "City" << setw(20) << "State" << setw(20) << "Balance" << endl;
				cout << "---------------------------------------------------------------------------------------------------\n" << endl;
				cout << setw(20) << "No entries...." << endl;
			}
			else 
			{
				cout << left << fixed << setprecision(2);
				cout << setw(20) << "\n\nFirst Bank of ECC Report\n" << endl;
				cout << setw(20) << "Name" << setw(20) << "Address" << setw(20) << "City" << setw(20) << "State" << setw(20) <<"Balance" << endl;
				cout << "---------------------------------------------------------------------------------------------------\n" << endl;

				for (int i = 0; i < size; i++)
				{
					cout << setw(20) << customer[i].lastName + ", " + customer[i].firstName << setw(20) << customer[i].address << setw(20) << customer[i].city << setw(20) << customer[i].state << setw(1) << "$" << setw(20) << customer[i].balance << endl;
				}
			}

			cin.get();

			system("cls");
		}
		else if (m == "w" || m == "W")
		{
			target = balanceWithdraw();

			for (int i = 0; i < size; i++)									//iterate through customer
			{
				if (target == customer[i].lastName)							//if name is found
				{
					wAmount = withdrawAmount();

					if (wAmount > customer[i].balance)
					{
						while (true)
						{
							cout << "\n\nInvalid amount; please enter an amount below " << customer[i].balance << ".......";
							wAmount = withdrawAmount();
							
							if (wAmount < customer[i].balance)
							{
								break;
							}
						}
						customer[i].balance -= wAmount;

						cout << "\n\nCongrats, you made a withdraw!";
					}
					else
					{
						customer[i].balance -= wAmount;

						cout << "\n\nCongrats, you made a withdraw!";
					}
				}
				else if (i == size-1)
				{
					cout << "\n\nRecord does not exist....." << endl;
				}
			}
					
			cin.get();
			system("cls");
		}
		else if (m == "d" || m == "D")
		{
			target = balanceDeposit();
			for (int i = 0; i < size; i++)									//iterate through customer
			{
				if (target == customer[i].lastName)							//if name is found
				{
					dAmount = depositAmount();								//gets amount to deposit 

					customer[i].balance += dAmount;							//adds amount to current balance

					cout << "\n\nCongrats, you made a deposit!" << endl;

				}
				else
				{
					cout << "\n\nRecord does not exist....." << endl;		//error message 
				}
			}

			cin.get();
			
			system("cls");

		}
		else if (m == "s" || m == "S")
		{
			target = outputFileName();

			fout.open(target);

			if (size == 0)
			{
				fout << left << fixed << setprecision(2);
				fout << setw(20) << "\n\nFirst Bank of ECC Report\n" << endl;
				fout << setw(20) << "Name" << setw(20) << "Address" << setw(20) << "City" << setw(20) << "State" << setw(20) << "Balance" << endl;
				fout << "---------------------------------------------------------------------------------------------------\n" << endl;
				fout << setw(20) << "No entries...." << endl;
			}
			else
			{
				fout << left << fixed << setprecision(2);
				fout << setw(20) << "\n\nFirst Bank of ECC Report\n" << endl;
				fout << setw(20) << "Name" << setw(20) << "Address" << setw(20) << "City" << setw(20) << "State" << setw(20) << "Balance" << endl;
				fout << "---------------------------------------------------------------------------------------------------\n" << endl;

				for (int i = 0; i < size; i++)
				{
					fout << setw(20) << customer[i].lastName + ", " + customer[i].firstName << setw(20) << customer[i].address << setw(20) << customer[i].city << setw(20) << customer[i].state << setw(20) << customer[i].balance << endl;
				}
			}

			fout.close();

			cout << "\n\nCongrats! Current bank info has been saved to " << target << " !" << endl;

			cin.get();

			system("cls");

		}
		else if (m == "t" || m == "T")
		{
			starget = sortListPrompt();

			tempSize = size;

			if (starget == "n" || starget == "N")
			{
				cout << "\n\nYou selected sort by LAST NAME";

				for ( int counter = size-1 ; counter > 0 ; counter--)				//will iterate until end of array-1
				{
					for (int i = 0 ; i < size-1 ; i++)								//will iterate length of array 
					{
						if (customer[i].lastName > customer[i+1].lastName)				//compares 2 strings
						{
							tempSortString = customer[i + 1];							//stores i+1 in temp
							customer[i + 1] = customer[i];								//sets i+1 to i
							customer[i] = tempSortString;								//sets temp to i
						}
					}
					size--;															//decrements size by 1 to not compare already sorted element 
				}

				size = tempSize;
				cout << "\n\nCongrats, sort by LAST name successful!";
				cin.get();
				system("cls");

			}
			else if(starget == "c" || starget == "C")
			{
				cout << "\n\nYou selected sort by LAST NAME";

				for (int counter = size - 1; counter > 0; counter--)				//will iterate until end of array-1
				{
					for (int i = 0; i < size - 1; i++)								//will iterate length of array 
					{
						if (customer[i].city > customer[i + 1].city)				//compares 2 strings
						{
							tempSortString = customer[i + 1];							//stores i+1 in temp
							customer[i + 1] = customer[i];								//sets i+1 to i
							customer[i] = tempSortString;								//sets temp to i
						}
					}
					size--;															//decrements size by 1 to not compare already sorted element 
				}

				size = tempSize;
				cout << "\n\nCongrats, sort by CITY successful!";
				cin.get();
				system("cls");
			}
			else if(starget == "b" || starget == "B")
			{
				cout << "\n\nYou selected sort by LAST NAME";

				for (int counter = size - 1; counter > 0; counter--)				//will iterate until end of array-1
				{
					for (int i = 0; i < size - 1; i++)								//will iterate length of array 
					{
						if (customer[i].balance > customer[i + 1].balance)				//compares 2 strings
						{
							tempSortString = customer[i + 1];							//stores i+1 in temp
							customer[i + 1] = customer[i];								//sets i+1 to i
							customer[i] = tempSortString;								//sets temp to i
						}
					}
					size--;															//decrements size by 1 to not compare already sorted element 
				}

				size = tempSize;
				cout << "\n\nCongrats, sort by BALANCE successful!";
				cin.get();
				system("cls");
			}
			else
			{
				cout << "\n\nInvalid selection.....";
				cin.get();
				system("cls");
			}

		}
		else if (m == "v" || m == "V")
		{
			ptarget = enterName();

			for (int i = 0 ; i < size ; i++)
			{
				if (ptarget == customer[i].lastName)
				{
					cout << left << fixed << setprecision(2);
					cout << setw(20) << "\n\nFirst Bank of ECC Report\n" << endl;
					cout << setw(20) << "Name" << setw(20) << "Address" << setw(20) << "City" << setw(20) << "State" << setw(20) << "Balance" << endl;
					cout << "---------------------------------------------------------------------------------------------------\n" << endl;

					cout << setw(20) << customer[i].lastName + ", " + customer[i].firstName << setw(20) << customer[i].address << setw(20) << customer[i].city << setw(20) << customer[i].state << setw(1) << "$" << setw(20) << customer[i].balance << endl;

					cout << "\n\nCongrats, record was printed!";
				}
				else if( i == size && target != customer[i].lastName )
				{
					cout << "\n\nRecord does not exist...";
				}
			}
			cin.get();
			system("cls");
		}
		else if (m == "x" || m == "X")
		{
			cout << "\n\nGoodbye....\n\n";
			exit(0);
		}
		else
		{
			cout << "\n\nInvalid option";
		}
	} while (m != "x" || m != "X" || size <= max-1 );
	
	cout << "\n\nGoodbye....\n\n";
	exit(0);
}

string fileInput(ifstream &fin)
{
	string target;

	cout << "\n\nEnter input file path: ";

	//target = "Final_Sp17.txt";									//uncomment to automate 

	getline(cin, target);

	fin.open(target);

	if ( fin.fail() )
	{
		while (true)
		{
			cout << "\n\nFilename does not exist, please try again : ";

			getline(cin, target);

			fin.open(target);

			if (!fin.fail())
			{
				break;
			}
		}
	}

	cout << "\n\nCongrats, you added records!";

	cin.get();
	system("cls");

	return target;
}

void menuOptions()
{
	cout << "\n\nA.) Add customer";
	cout << "\n\nR.) Remove customer";
	cout << "\n\nP.) Print all customers to the monitor";
	cout << "\n\nW.) Make a withdraw";
	cout << "\n\nD.) Make a deposit";
	cout << "\n\nS.) Save current Bank info to file";
	cout << "\n\nT.) Sort list";
	cout << "\n\nV.) Print customer details to monitor";
	cout << "\n\nX.) Exit" << endl << endl;
}

string waitForChar()
{
	string m;
	
	cin >> m;															//grabs input 
	cin.ignore(128, '\n');

	m = m.at(0);														//returns first char

	cout << "\n\nYou chose ' " << m << " '" << endl;

	return m;
}

void addNewCustomer(account &temp)
{
	cout << "\n\nEnter FIRST name : ";
	getline(cin, temp.firstName);
	cout << "\n\nEnter LAST name : ";
	getline(cin, temp.lastName);
	cout << "\n\nEnter ADDRESS : ";
	getline(cin, temp.address);
	cout << "\n\nEnter CITY : ";
	getline(cin, temp.city);
	cout << "\n\nEnter STATE : ";
	getline(cin, temp.state);
	cout << "\n\nEnter the BALANCE : ";
	cin >> temp.balance;

	while (!cin)
	{
		cin.clear();									//clears error
		cin.ignore(128, '\n');							//removes the \n

		cout << "\n\nInvalid Balance, try again : ";
		cin >> temp.balance;
		cin.ignore(128, '\n');							//removes the \n

		if (cin)
		{
			break;
		}
	}



	cout << "\n\nCongrats, you've added a customer!" << endl;
	cin.get();
}

string removeCustomer()
{
	string target;

	cout << "\n\nEnter the LAST name of the customer to remove: ";
	cin >> target;
	cin.ignore(128, '\n');

	return target;
}

string balanceWithdraw()
{
	string target;

	cout << "\n\nEnter the LAST name of the customer that would like to make a withdraw: ";
	cin >> target;
	cin.ignore(128, '\n');

	return target;
}

float withdrawAmount()
{
	float withdrawAmount;

	cout << "\n\nHow much would you like to withdraw: ";
	cin >> withdrawAmount;
	cin.ignore(128, '\n');

	while (!cin)
	{
		cin.clear();									//clears error
		cin.ignore(128, '\n');							//removes the \n

		cout << "\n\nInvalid withdraw amount; try again : ";
		cin >> withdrawAmount;
		cin.ignore(128, '\n');							//removes the \n

		if (cin)
		{
			break;
		}

	return withdrawAmount;
	}
}

string balanceDeposit()
{
	string target;

	cout << "\n\nEnter the LAST name of the customer that would like to make a deposit: ";
	cin >> target;
	cin.ignore(128, '\n');

	return target;
}

float depositAmount()
{
	float depositAmount;

	cout << "\n\nHow much would you like to deposit: ";
	cin >> depositAmount;
	cin.ignore(128, '\n');

	while (!cin)
	{
		cin.clear();									//clears error
		cin.ignore(128, '\n');							//removes the \n

		cout << "\n\nInvalid deposit amount; try again : ";
		cin >> depositAmount;
		cin.ignore(128, '\n');							//removes the \n

		if (cin)
		{
			break;
		}
	}

	return depositAmount;
}

string outputFileName()
{
	string target;

	cout << "\n\nEnter output file name with .TXT at the end: ";
	
	cin >> target;
	cin.ignore(128, '\n');

	return target;
}

string sortListPrompt()
{
	string target;

	cout << "\n\nHow would you like to sort the list?";

	cout << "\n\nN.) Name\n\nC.) City\n\nB.) Balance\n\n";

	cin >> target;
	cin.ignore(128, '\n');

	target = target.at(0);

	return target;
}

string enterName()
{
	string target;

	cout << "\n\nEnter LAST name of record you would like to see: ";

	cin >> target;
	cin.ignore(128, '\n');

	return target;
}