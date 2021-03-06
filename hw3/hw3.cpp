// hw3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;


const int PLAYER_NUM = 10;

void viewPlayers(string players[], int scores[], int& lastPlayer) {
	for (int i = 0; i < lastPlayer; i++) {
		cout << players[i] << ": " << scores[i] << endl;
	}
	if (lastPlayer == 0) {
		cout << "No players recorded\n";
	}
}

void addPlayer(string players[], int scores[], int& lastPlayer) {
	string tempName;
	int tempScore;
	cout << "Enter the new player and their score separated by a space: ";
	cin >> tempName
		>> tempScore;
	players[lastPlayer] = tempName;
	scores[lastPlayer] = tempScore;
	lastPlayer += 1;
}
void findPlayer(string players[], int scores[], int& lastPlayer) {
	string tempName;
	int flag = 0;
	cout << "Enter the name of the player you want to find: ";
	cin >> tempName;
	for (int i = 0; i < lastPlayer; i++) {
		if (players[i] == tempName) {
			cout << players[i] << ": " << scores[i] << endl;
			flag = 1;
		}
	}
	if (flag == 0) {
		cout << "This player is not in our records\n";
	}
}

void removePlayer(string players[], int scores[], int& lastPlayer) {
	int afterRemoval = 0;
	string tempName;
	cout << "Enter the name of the player to be removed: ";
	cin >> tempName;
	for (int i = 0; i < lastPlayer; i++) {
		if (afterRemoval != 0) {
			players[i - 1] = players[i];
			players[i] = "Empty slot";
			scores[i - 1] = scores[i];
			scores[i] = 0;
		}
		if (players[i] == tempName) {
			cout << "Player " << tempName << " found. Removing player...\n";
			afterRemoval = 1;
		}
	}
	if (afterRemoval != 0) {
		cout << "Removed player " << tempName << endl;
		lastPlayer -= 1;
	}
	else if (afterRemoval == 0) {
		cout << "Player " << tempName << " not found\n";
	}
}
int menu() {
	int selection = 5;
	while (true) {
		cout << "TEAM MANAGER 3000\n"
			<< "(0) Add new player\n"
			<< "(1) Print all players\n"
			<< "(2) Find a player\n"
			<< "(3) Remove a player\n"
			<< "(4) quit\n"
			<< "Please enter an option: ";
		cin >> selection;
		if (selection < 0 || selection > 4) {
			cout << selection << " is not a valid option. Please choose one of the listed options.\n";
		}
		else {
			break;
		}
	}
	return selection;
}
void prob19() {
	string players[PLAYER_NUM];
	int scores[PLAYER_NUM];
	int lastPlayer = 0;
	int menuOption = 0;
	while (menuOption != 4) {
		menuOption = menu();
		switch (menuOption) {
			case 0:
				cout << "Selected Add a new player\n";
				if (lastPlayer < PLAYER_NUM) {
					addPlayer(players, scores, lastPlayer);
				}
				else {
					cout << "You have reached the maximum number of players\n";
				}
				break;
			case 1:
				cout << "Selected view all players\n";
				viewPlayers(players, scores, lastPlayer);
				break;
			case 2:
				cout << "Selected find a player\n";
				findPlayer(players, scores, lastPlayer);
				break;
			case 3:
				cout << "Selected remove a player\n";
				if (lastPlayer != 0) {
					removePlayer(players, scores, lastPlayer);
				}
				else {
					cout << "You have no players on your roster\n";
				}
				break;
			case 4:
				cout << "Selected quit\n";
				break;
		}
		cout << endl;
	}
	cout << "Thank you for using Team Manager 3000\n";
}
class Money {
	public:
		double getDollars();
		double getCents();
		double getAmount();
		void setDollars(double amount);
		void setCents(double amount);
	private:
		double dollars;
		double cents;
		
};
double Money::getDollars() {
	return dollars;
}
double Money::getCents() {
	return cents;
}
double Money::getAmount() {
	return (dollars + cents);
}
void Money::setDollars(double amount) {
	dollars = amount;
}
void Money::setCents(double amount) {
	cents = amount / 100;
}

int test1() {
	int flag = 0;
	double temp;
	Money account;

	account.setDollars(20);
	temp = account.getDollars();
	cout << "Expected $20. Got $" << temp << endl;
	if (temp != 20) flag = 1;
	
	account.setCents(55);
	temp = account.getCents();
	cout << "Expected 55 cents. Got " << temp * 100 << " cents\n";
	if (temp != 0.55) flag = 1;

	temp = account.getAmount();
	cout << "Expected $20.55. Got $" << temp << endl;
	if (temp != 20.55) flag = 1;
	return flag;

}
int test2() {
	int flag = 0;
	double temp;
	Money account;
	account.setDollars(2);
	temp = account.getDollars();
	cout << "Expected $2. Got $" << temp << endl;
	if (temp != 2) flag = 1;

	account.setCents(5);
	temp = account.getCents();
	cout << "Expected 5 cents. Got " << temp * 100<< " cents\n";
	if (temp != 0.05) flag = 1;

	temp = account.getAmount();
	cout << "Expected $2.05. Got $" << temp << endl;
	if (temp != 2.05) flag = 1;
	return flag;

}
void prob8() {
	cout << "Executing test 1\n";
	if (test1() != 0) {
		cout << "test 1 failed\n";
	}
	else {
		cout << "test 1 succeeded\n";
	}
	cout << "Executing test 2\n";
	if (test2() != 0) {
		cout << "test 2 failed\n";
	}
	else {
		cout << "test 2 succeeded\n";
	}
	

}
int main()
{
	//prob19();
	prob8();
}

