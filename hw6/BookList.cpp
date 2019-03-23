//********************************************************************
//  BookList.h
//
//  Represents a collection of books.
//*******************************************************************
#include "pch.h"
#include "BookList.h"
#include <iostream>
using namespace std;
//----------------------------------------------------------------
//  Creates a new Book object and adds it to the end of
//  the linked list.
//----------------------------------------------------------------
void BookList::add(Book *newBook) {

	BookNode *node = new BookNode(newBook);
	BookNode *current;

	if (head == NULL)
		head = node;
	else {
		current = head;
		while (current->next != NULL)
			current = current->next;
		current->next = node;
	}
}

//----------------------------------------------------------------
//  Returns this list of books as a string.
//----------------------------------------------------------------
char *BookList::getBookList(char *list, size_t list_len) {

	list[0] = '\0';
	BookNode *current = head;

	while (current != NULL) {
		strcat_s(list, list_len, current->book->getBook());
		strcat_s(list, list_len, "\n");
		current = current->next;
	}

	return list;
}

//---------------------------------------------------------------------------------------start
int Book::compareTo(Book* compareBook){
	return strcmp(title, compareBook->getBook());
}

char* BookNode::getTitle() {
	return book->getBook();
}

int compare(Book* book, Book* book1) {
	return book->compareTo(book1);
}

void BookList::insert(Book *newBook) {
	BookNode *newNode = new BookNode(newBook);
	if (head == NULL) {
		head = newNode;
	}//covers if the newNode is less than the head
	else if (head->book->compareTo(newBook) > 0) {
		newNode->next = head;
		head = newNode;
	}
	else {
		BookNode *current = head;
		BookNode *last = current;
		BookNode *swap;
		int comp;
		do {
			comp = compare(newBook, current->book);
			if (comp < 0) {
				//This means the current title is greater than the newBook
				last->next = newNode;
				newNode->next = current;
				break;
			}
			//This is to catch if the node should go at the end
			else if (current->next == NULL) {
				current->next = newNode;
				break;
			}
			swap = current->next;
			last = current;
			current = swap;
		} while (true);
	}

}

void BookList::delet(Book *bookToDelete) {
	BookNode *current = head;
	BookNode *last = NULL;
	BookNode *swap;
	//while (bookToDelete->compareTo(current->book) != 0 || current->next == NULL) {
	while(true) {
		//covers if head needs to be deleted
		if (bookToDelete->compareTo(head->book) == 0) {
			head = head->next;
			break;
		}
		else if (current->next == NULL){
			last->next = NULL;
			break;
		}
		else if (bookToDelete->compareTo(current->book) == 0) {
			last->next = current->next;
			break;
		}
		swap = current->next;
		last = current;
		current = swap;
	}
}
