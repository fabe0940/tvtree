#include <cstdlib>
#include <iostream>
#include <string>
#include "StringList.h"

using namespace std;

StringList::StringList(void) {
	head = NULL;
	length = 0;

	return;
}

StringList::~StringList(void) {
	StringListNodePtr temp;

	while(head != NULL) {
		temp = head;
		head = head->next;

		delete temp;
	}

	return;
}

void StringList::print(void) {
	StringListNodePtr temp;

	cout << "StringList (" << length << ")" << endl;

	temp = head;
	while(temp != NULL) {
		cout << "  " << temp->str << endl;
		temp = temp->next;
	}

	return;
}

void StringList::add(string s) {
	StringListNodePtr temp;

	temp = new StringListNode;
	temp->str = s;

	temp->next = head;
	head = temp;

	length++;

	return;
}
