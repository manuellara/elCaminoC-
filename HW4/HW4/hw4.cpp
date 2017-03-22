/*
*
* HW4 - calculating final score to get letter grades
* Manuel Lara
*
*
* ALGORITHM 
*
* Differences from LAB 3 : input verification & letter grade assigned to final score.
* 
* STEP 1
* First, initialize name and letter grade as strings
* Second, initialize test scores (1-3) and quiz scores as integers
* Third, initialize test average, final score, and assignment score as floats
*
* Prompt user to input name
* Store user input in the name variable
* Prompt user to enter their 3 test score and store them as testScore1 , testScore2 , testScore3 
* Verify that input is legit 
* Prompt user to enter their assignment score as REAL number and store it in assScore
* Verify input is legit
* Prompt user to enter their quiz score as integer and store it as quizScore
* Verify input is legit
* 
* Step 2
* Get the test score average and set as testAverage
* Next, calculate the final average and set weight to each criteria
* 
* Step 3
* Assign letter grades to values
* Then print values for name, test scores (1-3), assignment score, quiz score, and final average score
* Lastly, print letter grade
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
	string name, letterGrade;
	int testScore1, testScore2, testScore3, quizScore;
	float testAvge, average, assScore;

	cout << endl << "Enter your full name: ";
	getline(cin, name);
	cout << endl << "Enter 3 INTEGER numbers for TEST scores separated by spaces: ";
	cin >> testScore1 >> testScore2 >> testScore3;
	/*// verification //*/
	if (!cin)
	{
		cout << ("Input is not INTEGER, please try again...");
		return 0;
	}
	/*// end verification //*/
	cout << endl << "Enter ASSIGNMENT score as REAL number: ";
	cin >> assScore;
	/*// verification //*/
	if (!cin)
	{
		cout << ("Input not a REAL, please try again...");
		return 0;
	}
	/*// end verification //*/
	cout << endl << "Enter an INTEGER number for QUIZ score: ";
	cin >> quizScore;
	/*// verification //*/
	if (!cin)
	{
		cout << ("Input not INTEGER, please try again...");
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