#include <cstring>
#include <iostream>
using namespace std;
#define TITLE_LEN 81

//********************************************************************
//  Book.cpp
//
//  Represents a single book.
//*******************************************************************

class Book {

public:
	int compareTo(Book* compareBook);
	Book(const char *newTitle) {
		strcpy_s(title, TITLE_LEN, newTitle);
	}

	char *getBook() {
		return title;
	}

private:
	char title[TITLE_LEN];

};


