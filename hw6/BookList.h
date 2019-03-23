//********************************************************************
//  BookList.h
//
//  Represents a collection of books.
//*******************************************************************
#define LIST_LEN 1024
#include "Book.h"

class BookNode {
public:
	//--------------------------------------------------------------
	//  Sets up the node
	//--------------------------------------------------------------
	BookNode() { };
	BookNode(Book *theBook) {
		book = theBook;
		next = NULL;
	};
	char *getTitle();
	friend class BookList;

private:
	Book *book;
	BookNode *next;
};

class BookList {

	//----------------------------------------------------------------
	//  Sets up an initially empty list of books.
	//----------------------------------------------------------------
public:
	void add(Book *);
	void insert(Book *);
	void delet(Book *);
	char* getBookList(char *, size_t);

	BookList() {
		head = NULL;
	};

private:
	int size;
	BookNode *head;

};


