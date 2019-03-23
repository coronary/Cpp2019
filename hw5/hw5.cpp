// hw5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;


class HotDogStand {
public:
	HotDogStand(int idVal, int dogsSoldVal) : id(idVal), dogsSold(dogsSoldVal) {
		numCarts += 1;
		totalDogs += dogsSold;
	}
	HotDogStand(int idVal) {
		id = idVal;
		dogsSold = 0;
		numCarts += 1;
	}
	HotDogStand() {
		id = numCarts++;
		dogsSold = 0;
		numCarts += 1;
	}
	void justSold();
	int getSold();
	static int getTotalDogs();
private:
	static int totalDogs;
	static int numCarts;
	int id;
	int dogsSold;
};

int HotDogStand::totalDogs = 0;
int HotDogStand::numCarts = 0;

void HotDogStand::justSold() {
	dogsSold += 1;
	totalDogs += 1;
}
int HotDogStand::getSold() {
	return dogsSold;
}
int HotDogStand::getTotalDogs() {
	return totalDogs;
}
void buyDog(HotDogStand& stand, int num) {
	for (int i = 0; i < num; i++) {
		stand.justSold();
	}
}
void test41() {
	cout << "Initiating first test\n";
	HotDogStand stand(0, 0);
	cout << "Dogs sold at this location: " << stand.getSold() << ". Expected 0"
		<< endl << "Total dogs sold: " << HotDogStand::getTotalDogs() << ". Expected 0"
		<< endl << "Buying 12 hotdogs...\n";
	buyDog(stand, 12);
	cout << "Reported dogs: " << stand.getSold() << ". Expected 12"
		<< endl << "Total dogs sold: " << HotDogStand::getTotalDogs() << ". Expected 12\n" << endl;
}

void test42() {
	cout << "Initiating second test\n";
	HotDogStand stand(1, 70);
	cout << "Dogs sold at this location: " << stand.getSold() << ". Expected 70"
		<< endl << "Total dogs sold: " << HotDogStand::getTotalDogs() << ". Expected 82"
		<< endl << "Buying 120 hotdogs...\n";
	buyDog(stand, 120);
	cout << "Reported dogs: " << stand.getSold() << ". Expected 190"
		<< endl << "Total dogs sold: " << HotDogStand::getTotalDogs() << ". Expected 202\n" << endl;
}

void test43() {
	cout << "Initiating third test\n";
	HotDogStand stand(2, 700);
	cout << "Dogs sold at this location: " << stand.getSold() << ". Expected 700"
		<< endl << "Total dogs sold: " << HotDogStand::getTotalDogs() << ". Expected 902"
		<< endl << "Buying 1 hotdog...\n";
	buyDog(stand, 1);
	cout << "Reported dogs: " << stand.getSold() << ". Expected 701"
		<< endl << "Total dogs sold: " << HotDogStand::getTotalDogs() << ". Expected 903\n" << endl;
}
void prob4() {
	test41();
	test42();
	test43();
}
//Problem 8 -----------------------------------------------------
const double KEL_FROM_CEL = 273.15;
const double CEL_FROM_FAR = (5.0 / 9);
class Temperature {
public: 
	double getKel();
	double getFar();
	double getCel();
	void setKel(double temp);
	void setFar(double temp);
	void setCel(double temp);
	bool operator ==(Temperature& compareTemp);
	friend ostream& operator <<(ostream& outputStream, Temperature& compareTemp);
	friend istream& operator >>(istream& inputStream, Temperature& inputTemp);
private:
	double temp;
};

ostream& operator <<(ostream& outPutStream, Temperature& printTemp) {
	cout << printTemp.getFar() << endl;
	return outPutStream;
}
istream& operator >>(istream& inputStream, Temperature& inputTemp) {
	double farTemp;
	cin >> farTemp;
	inputTemp.setFar(farTemp);
	return inputStream;
}

bool Temperature::operator == (Temperature& compareTemp) {
	return (temp == compareTemp.getKel());
}
void Temperature::setKel(double temp) {
	Temperature::temp = temp;
}

void Temperature::setCel(double temp) {
	Temperature::temp = temp + KEL_FROM_CEL;
}

void Temperature::setFar(double tempVal) {
	temp = ((CEL_FROM_FAR * (tempVal - 32)) + KEL_FROM_CEL);
}

double Temperature::getCel() {
	return temp - KEL_FROM_CEL;
}

double Temperature::getFar() {
	return (getCel() / CEL_FROM_FAR) + 32;
}

double Temperature::getKel() {
	return temp;
}

void test8(double cel, double far) {
	Temperature test;
	cout << endl << "Setting temperature to " << cel << " degrees celsius\n";
	test.setCel(cel);
	cout << "Testing << operator. The fahrenheit value should be " << test.getFar()
		 << " Value: " << test 
		<<"Input a Fahrenheit value (will compare to " << far << "): ";
	cin >> test;
	cout << "If this prints out your number then the << operator and the >> operator are working correctly.\nValue: " << test;
	cout << "Testing equality against a temperature of " << far << " degrees fahrenheit\n";
	Temperature test1;
	test1.setFar(far);
	if (test == test1) {
		cout << "The temperatures were equal\n";
	}
	else {
		cout << "The temperatures were different\n";
	}
}

void prob8() {
	test8(0, 50);
	test8(100, 10);
	test8(300, 26);
}

int main()
{
	prob4();
	prob8();
}

