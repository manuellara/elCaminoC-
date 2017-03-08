/*
*
* HW3 - calculating test score percentage 
* Manuel Lara
*
* program asks for name, test, assignment, and quiz score
* then it calculates the percentage of each aspect 
* finally, it prints the output 
*
*
*
*
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	///////////// PART 1 /////////////////////
	string name;
	int testScore1, testScore2, testScore3, assScore, quizScore; 
	float testAvge, average ;

	cout << endl << "Enter your full name: " ;
	getline(cin, name);
	cout << endl << "Enter 3 INTEGER numbers for TEST scores separated by spaces: " ;
	cin >> testScore1 >> testScore2 >> testScore3 ;
	cout << endl << "Enter ASSIGNMENT score as REAL number: ";
	cin >> assScore ;
	cout << endl << "Enter an INTEGER number for QUIZ score: " ;
	cin >> quizScore;
	cout << endl;

	

	///////////// PART 2 /////////////////////
	testAvge = (testScore1 + testScore2 + testScore3) / 3;
	average = (testAvge * .6) + (quizScore * .1) + (assScore * .3) ;
	cout << endl;


	///////////// PART 3 /////////////////////
	cout << "_____________________________________________________________________________________________" << endl ;
	cout << endl << setw(40) << "Name: " << setw(25) << name ;
	cout << endl << setw(40) << "Test Scores: " << setw(5) << testScore1 << setw(5) << "|" << setw(5) << testScore2 << setw(5) << "|" << setw(5) << testScore3 ;
	cout << endl << setw(40) << "Test Average: " << setw(25) << testAvge ;
	cout << endl << setw(40) << "Quiz Score: " << setw(25) << quizScore;
	cout << endl << setw(40) << "Assignment Score: " << setw(25) << assScore;
	cout << endl << setw(40) << "Final Score: " << setw(25) << fixed << setprecision(2) << average;
	cout << endl << "_____________________________________________________________________________________________" << endl;

	cout << endl;



	return 0;
}