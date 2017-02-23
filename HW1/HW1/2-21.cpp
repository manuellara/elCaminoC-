//-------------
//2-21 HW1
//Manuel Lara
//--------------

#include <iostream>

using namespace std;

int main()
{
	cout << "Manuel Lara" << endl;

	double regularWage,				//holds regular wage
		basePayRate = 18.25,		//base pay rate
		regularHours = 40.0,		//hours worked less overtime
		overTimeWages,				//holds overtime wages
		overTimePayRate = 27.78,	//over time pay rate
		overTimeHours = 10,			//over time hours worked
		totalWages;					//holds total wages

	//calculate regular wages 
	regularWage = basePayRate * regularHours;

	//calculate overtime wages 
	overTimeWages = overTimeHours * overTimePayRate;

	//calculate total wages 
	totalWages = regularWage + overTimeWages;

	//display wages 
	cout << "Wages for this week are $" << totalWages << endl;

	return 0;
}