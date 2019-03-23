// hw9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "salariedemployee.h"
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;



namespace SavitchEmployees {
	class Administrator : public SalariedEmployee {
	public:
		Administrator();
		Administrator(string name, string title, string super, string area);
		void setSupervisor(string name);
		void setArea(string area);
		void setTitle(string title);
		string readIn() const;
		void print() const;
		void printCheck() const;
	private:
		string title;
		string area;
		string super;
	};

}

using SavitchEmployees::Administrator;
Administrator::Administrator() {
	Employee();
	title = "No Title Yet";
	area = "No Area Yet";
	super = "No Super Yet";
	salary = 0;
}

Administrator::Administrator(string nVal, string tVal, string sVal, string aVal) : title(tVal), super(sVal), area(aVal) {
	setName(nVal);
}

void Administrator::setSupervisor(string name) {
	super = name;
}

void Administrator::setArea(string aVal) {
	area = aVal;
}

void Administrator::setTitle(string tVal) {
	title = tVal;
}

string Administrator::readIn() const {
	string data;
	cout << "Input some data: ";
	cin >> data;
	return data;
}

void Administrator::print() const {
	cout << "Name: " << Employee::getName() << endl;
	cout << "Title: " << title << endl;
	cout << "Area of Expertise: " << area << endl;
	cout << "Supervisor: " << super << endl;
	cout << "SSN: " << getSsn() << endl;
	cout << "Salary: " << getSalary() << endl << endl;
}
void Administrator::printCheck() const {
	//Only works if the member variables of Employee are marked //protected instead of private.
	cout << "\n__________________________________________\n";
	cout << "Pay to the order of " << getName() << endl;
	cout << "The sum of " << salary << " Dollars\n";
	cout << "____________________________________________\n";
	cout << "Check Stub: NOT NEGOTIABLE\n";
	cout << "Employee Number: " << getSsn() << endl;
	cout << "Title: " << title << endl;
	cout << "Area of Expertise: " << area << endl;
	cout << "Supervisor: " << super << endl;
	cout << "Administrator. \nAnnual Salary: $" << salary;
	cout << "\n__________________________________________\n";
}

int main()
{
	using SavitchEmployees::Administrator;
	Administrator andy = Administrator();
	andy.print();
	andy.setSsn("12345");
	andy.setSupervisor("Tony");
	andy.setName("Andy");
	andy.setArea("Production");
	andy.setTitle("Admin");
	andy.setSalary(100);
	andy.print();
	andy.printCheck();
}
