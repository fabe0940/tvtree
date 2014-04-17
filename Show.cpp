#include <iostream>
#include <string>
#include "Show.h"
#include "StringList.h"

using namespace std;

Show::Show(void) {
	yearStart = 0;
	yearEnd = 0;
	title = "";
	genre = "";
	address = "";

	return;
}

Show::~Show(void) {
	return;
}

void Show::print(void) {
	cout << title << " (" << yearStart << " - " << yearEnd << ")" << endl;
	cout << genre << endl;
	cout << address << endl;
	actors.print();

	return;
}

void Show::setStartYear(int y) {
	if(y > 0) {
		yearStart = y;
	}

	return;
}

void Show::setEndYear(int y) {
	if(y > 0) {
		yearEnd = y;
	}

	return;
}

void Show::setTitle(string t) {
	title = t;

	return;
}

void Show::setGenre(string g) {
	genre = g;

	return;
}

void Show::setAddress(string a) {
	address = a;

	return;
}

void Show::addActor(string a) {
	actors.add(a);

	return;
}
