// hw2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

const double FRACTION (9.0 / 5.0);

void prob7() {
	int toReport;
	int userScore = 0, totalScore = 0, holder = 0;

	cout << "How many exercises to input? ";
	cin >> toReport;

	for (int i = 0; i < toReport; i++) {
		cout << endl << "Score for exercise " << i + 1 << ": ";
		cin >> holder;
		userScore += holder;
		cout << "Total point possible for exercise " << i + 1 << ": ";
		cin >> holder;
		totalScore += holder;
	}
	cout << "Your total is " << userScore << " out of " << totalScore
		<< ", or " << ((double)userScore / (double)totalScore) * 100 << "%";
}

void prob8() {
	int cel = 101;
	int far;
	do {
		cel -= 1;
		far = (FRACTION * cel) + 32;
	} while (cel != far);
	cout << "Celsius: " << cel
		<< " Fahrenheit: " << far;
}

int main()
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	//prob7();
	prob8();
}

//----------------------------------------------------------------------------------------
//Output of problem 7: 
//How many exercises to input ? 3
//
//Score for exercise 1 : 10
//Total point possible for exercise 1 : 10
//
//Score for exercise 2 : 7
//Total point possible for exercise 2 : 12
//
//Score for exercise 3 : 5
//Total point possible for exercise 3 : 8

//Output of problem 8:
//Celsius: -40 Fahrenheit : -40