//This is the header file salariedemployee.h.
//This is the interface for the class SalariedEmployee.
#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H 
#include <string> 
#include "employee.h"
using std::string;
namespace SavitchEmployees
{
 class SalariedEmployee : public Employee
 {
	 public:
		 //SalariedEmployee();
		 //SalariedEmployee(const string& theName, const string& theSsn, double theWeeklySalary);
		 double getSalary() const;
		 void setSalary(double newSalary);
		 //void printCheck();
	 protected:
		 double salary;//weekly 
	};

 double SalariedEmployee::getSalary() const {
	 return salary;
 }
 void SalariedEmployee::setSalary(double newSalary)  {
	 salary = newSalary;
 }
}//SavitchEmployees 
#endif //SALARIEDEMPLOYEE_H
