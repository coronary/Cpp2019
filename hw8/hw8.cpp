// hw8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::string;

const int NUM_GRADES = 10; 

void process(ifstream& in, ofstream& out) {
	string name;
	int num;
	double sum;
	double avg;
	while (!in.eof()) {
		avg = 0;
		num = 0;
		sum = 0;
		for (int i = 0; i < NUM_GRADES+2; i++) {
			if (i < 2) {
				in >> name;
				out << name << " ";
			}
			if (i > 1) {
				in >> num;
				sum += num;
				out << num << " ";
			}
		}
		avg = sum / NUM_GRADES;
		out << " Average is " << avg << endl;
	}
}

void prob8() {
	ifstream inStream("t.txt");
	ofstream outStream("r.txt", ios::app);
	if (inStream.fail() || outStream.fail()) {
		EXIT_FAILURE;
	}
	process(inStream, outStream);
	inStream.close();
	outStream.close();
}

void answer(ifstream& in) {
	string ans;
	getline(in, ans);
	cout << ans << endl;
}
void prob12() {
	string ans;
	ifstream inStream("ans.txt");
	int count = 0;
	while (true) {
		//Just to show loop and then break
		if (count > 11) break;
		cout << "Enter your question: ";
		cin >> ans;
		if (inStream.eof()) {
			inStream.close();
			inStream.open("ans.txt");
		}
		answer(inStream);
		count += 1;
	}
	inStream.close();

}
int main()
{
	prob8();
	prob12();

}

