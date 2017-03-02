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

	int totalCalories;
	int filler;

	cout << setw(50);
	cout << "Welcome to my calorie counter!" << endl ;

	cout << left << setw(50);
	cout << "Enter your name: ";
	getline(cin, name);

	cout << left;
	cout << "Hello " << name << ", please enter the number of ingredents used in your sandwich " << endl;

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


	totalCalories = bread + cheese + mayo + pickle ;
	// filler = 642 - totalCalories; 

	cout << "There were " << totalCalories  /* + filler */ << " calories in my lunch today." << endl;
	cout << "What's for lunch today?" << endl;



	return 0;

}