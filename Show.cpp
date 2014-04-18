#include <iostream>
#include <string>
#include "Show.h"

using namespace std;

Show::Show(void) {
	int i;

	yearStart = 0;
	yearEnd = 0;
	title = "";
	genre = "";
	address = "";

	for(i = 0; i < _SHOW_ARRAY_LEN; i++) {
		actors[i] = "";
	}

	return;
}

Show::~Show(void) {
	return;
}

void Show::print(void) {
	int i;

	cout << title << " (" << yearStart << " - " << yearEnd << ")" << endl;
	cout << "  " << genre << endl;
	cout << "  " << address << endl;

	i = 0;
	while(actors[i] != "") {
		cout << "  " <<  actors[i++] << endl;
	}

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
	int i;

	i = 0;
	while(actors[i] != "") {
		i++;
	}

	actors[i] = a;

	return;
}

int Show::getYearStart(void) {
	return yearStart;
}

int Show::getYearEnd(void) {
	return yearEnd;
}

int Show::hasActor(string a) {
	int i;
	int result;

	i = 0;
	result = 0;

	for(i = 0; i < _SHOW_ARRAY_LEN; i++) {
		result = result ||  (a == actors[i]);
	}

	return result;
}

string Show::getTitle(void) {
	return title;
}
