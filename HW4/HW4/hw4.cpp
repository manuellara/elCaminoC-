/*
*
* HW4 - calculating letter grades
* Manuel Lara
*
* 
* 
* 
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
	/*//////////// PART 1 ////////////////////*/
	string name;
	int testScore1, testScore2, testScore3, quizScore;
	float testAvge, average, assScore;
	string letterGrade;

	cout << endl << "Enter your full name: ";
	getline(cin, name);
	cout << endl << "Enter 3 INTEGER numbers for TEST scores separated by spaces: ";
	cin >> testScore1 >> testScore2 >> testScore3;
	/*// verification //*/
	if (!cin)
	{
		cout << ("Numbers are not INTEGERS, please try again...");
		return 0;
	}
	/*// end verification //*/
	cout << endl << "Enter ASSIGNMENT score as REAL number: ";
	cin >> assScore;
	/*// verification //*/
	if (!cin)
	{
		cout << ("Number is not a REAL, please try again...");
		return 0;
	}
	/*// end verification //*/
	cout << endl << "Enter an INTEGER number for QUIZ score: ";
	cin >> quizScore;
	/*// verification //*/
	if (!cin)
	{
		cout << ("Number is not INTEGER, please try again...");
		return 0;
	}
	/*// end verification //*/
	cout << endl;



	/*//////////// PART 2 ////////////////////*/
	testAvge = (testScore1 + testScore2 + testScore3) / 3;
	average = (testAvge * .6) + (quizScore * .1) + (assScore * .3);
	cout << endl;


	/*//////////// PART 3 ////////////////////*/
	/*// calculating grade //*/
	if (average >= 90)
	{
		letterGrade = "A";
	}
	else if (average >= 80)
	{
		letterGrade = "B";
	}
	else if (average >= 70)
	{
		letterGrade = "C";
	}
	else if (average >= 60)
	{
		letterGrade = "D";
	}
	else if (average > 50)
	{
		letterGrade = "F";
	}
	/*// end calculation //*/
	
	cout << "_____________________________________________________________________________________________" << endl;
	cout << endl << setw(40) << "Name: " << setw(25) << name;
	cout << endl << setw(40) << "Test Scores: " << setw(5) << testScore1 << setw(5) << "|" << setw(5) << testScore2 << setw(5) << "|" << setw(5) << testScore3;
	cout << endl << setw(40) << "Test Average: " << setw(25) << testAvge;
	cout << endl << setw(40) << "Quiz Score: " << setw(25) << quizScore;
	cout << endl << setw(40) << "Assignment Score: " << setw(25) << assScore;
	cout << endl << setw(40) << "Final Score: " << setw(25) << fixed << setprecision(2) << average;
	cout << endl << setw(40) << "Letter Grade: " << setw(25) << letterGrade;

	cout << endl << "_____________________________________________________________________________________________" << endl;

	cout << endl;



	return 0;
}