//////////////////////////////
// HW 2
// Manuel Lara
/////////////////////////////


#include <iostream>
#include <string>
#include <iomanip>

using namespace std; 

int main()
{

	const int bread = 63;
	const int cheese = 106;
	const int mayo = 49; 
	const int pickle = 25;

	string name;
	int slicesOfBread;
	int slicesOfCheese;
	int amountOfMayo;
	int slicesOfPickle;



	cout << setw(50) ;
	cout << "Welcome to my calorie counter!" << endl ;
	cout << endl;

	cout << left << setw(50);
	cout << "Enter your name: ";
	getline(cin, name);
	cout << endl;

	cout << "Hello " << name << ", please enter the number of ingredents used in your sandwich " << endl ;
	cout << endl;

	cout << left << setw(50);
	cout << "Enter slices of bread: ";
	cin >> slicesOfBread;
	cout << left << setw(50);
	cout << "Enter slices of cheese: ";
	cin >> slicesOfCheese;
	cout << left << setw(50);
	cout << "Enter amount of mayo: ";
	cin >> amountOfMayo;
	cout << left << setw(50);
	cout << "Enter slices of pickle: ";
	cin >> slicesOfPickle;
	cout << endl;

	cout << right << setw(25);
	cout << "bread calories: ";
	cout << right << setw(25);
	cout << bread * slicesOfBread << endl;
	cout << right << setw(25);
	cout << "cheese calories: ";
	cout << right << setw(25);
	cout << cheese * slicesOfCheese << endl;
	cout << right << setw(25);
	cout << "mayo calories: ";
	cout << right << setw(25);
	cout << mayo * amountOfMayo << endl;
	cout << right << setw(25);
	cout << "pickle calories: ";
	cout << right << setw(25);
	cout << pickle * slicesOfPickle << endl;
	cout << endl;
	cout << right << setw(25);
	cout << "total calories: ";
	cout << right << setw(25);
	cout << (bread * slicesOfBread) + (cheese * slicesOfCheese) + (mayo * amountOfMayo) + (pickle * slicesOfPickle) << endl ;
	cout << endl;

	int totalCalories = (bread * slicesOfBread) + (cheese * slicesOfCheese) + (mayo * amountOfMayo) + (pickle * slicesOfPickle);


	cout << "There were " << totalCalories  << " calories in my lunch today." << endl;
	cout << "What's for lunch today? Funny!!!!" << endl;
	cout << endl;



	return 0;

}