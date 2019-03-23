// hw7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <map>
#include <string>;
using namespace std;
const int MAX_LEN = 80;


void results(map<char, int> finalMap) {
	map<char, int>::const_iterator iter;
	iter = finalMap.begin();
	cout << iter->second + 1 << " words\n";
	iter++;
	for (iter; iter != finalMap.end(); iter++) {
		cout << iter->second << " " << iter->first << endl;
	}
}
void prob2()
{
	map<char, int> letterMap;
	int numWords = 0;
	char sentence[MAX_LEN];
	cout << "Please input a sentence: ";
	cin.getline(sentence, MAX_LEN);
	for (int i = 0; sentence[i] != NULL; i++) {
		if (ispunct(sentence[i])) {
			continue;
		}
		if (isupper(sentence[i])) {
			sentence[i] = tolower(sentence[i]);
		}
		letterMap[sentence[i]]++;
	}
	results(letterMap);
}

class Student {
public:
	Student(string childName) :name(childName) {
		cout << "New Student created with name " << childName << endl;
	}
	Student(string childName, string classes) :name(childName) {
		cout << "New Student created with name " << childName << endl;
		setListWithList(classes);
	}
	~Student() {
		delete [] classList;
		cout << "Deleting student " << endl;
	}
	int getNumClasses(){
		return numClasses;
	}
	void setNumClasses(int num){
		numClasses = num;
	}
	string getName(){
		return name;
	}
	string setName(string newName){
		name = newName;
	}
	string* getClassList() {
		return classList;
	}
	void setListWithList(string list) {
		classList = new string[numClasses];
		for (int i = 0; i < numClasses; i++) {
			classList[i] = list[i];
		}
	}
	void setClassList() {
		int num;
		cout << "Input number of classes: ";
		cin >> num;
		classList = new string[num];
		for (int i = 0; i < num; i++) {
			cout << "Input a class name: ";
			cin >> classList[i];
			numClasses += 1;
		}
	}
	void printClasses() {
		if (numClasses == 0) {
			cout << "No classes on file for " << name << endl;
		}
		for (int i = 0; i < numClasses; i ++) {
			cout << classList[i] << endl;
		}
	}
	void reset() {
		numClasses = 0;
		for (int i = 0; i < numClasses; i++) {
			classList[i] = "";
		}
	}
	//Student& operator =(const Student& copyStudent) {
		//cout << "We in here\n";
		//setName(copyStudent->getName());
		//setNumClasses(copyStudent.getNumClasses());
		//setListWithList(copyStudent.classList);
		//setName("brian");
		//cout << "We out here\n";
		//return *this;
	//}
private:
	string name;
	int numClasses;
	string* classList;
};
void prob4() {
	Student chad = Student("chad");
	chad.setClassList();
	chad.printClasses();
	Student& brian = chad;
	brian.getName();
	brian.printClasses();
}

int main() {
	prob2();
	prob4();
}

