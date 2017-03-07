/*
*
* HW3 - calculating test score percentage 
* Manuel Lara
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
	float testScore1, testScore2, testScore3, assScore, quizScore; //testScoreWeighed, progAssWeighed, quizWeighed;
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

	// testScoreWeighed = ( (testScore1/100) + (testScore2/100) + (testScore3/100) ) * .60 ;
	// progAssWeighed = (assScore/100) * .30 ;
	// quizWeighed = (quizScore/100) * .10 ;
	// cout << testScoreWeighed << endl << quizWeighed << endl << progAssWeighed <<endl ;

	///////////// PART 2 /////////////////////
	testAvge = (testScore1 + testScore2 + testScore3) / 3;
	average = (testAvge * .6) + (quizScore * .1) + (assScore * .3) ;
	cout << endl;


	///////////// PART 3 /////////////////////
	cout << endl << setw(20) << "Name: " << setw(20) << name ;
	cout << endl << setw(20) << "Test Scores: " << setw(20) << testScore1 << setw(5) << testScore2 << setw(5) <<testScore3 ;
	cout << endl << setw(20) << "Test Average: " << setw(20) << testAvge ;


	return 0;
}