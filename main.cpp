#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include "BSTree2.h"
#include "Show.h"

using namespace std;

#define FILENAME "tvDB.txt"

int main(void) {
	int running;
	ifstream infile;
	string line;
	Show* test;

	/* Initialize */
	running = 1;

	/* Parse file */
	infile.open(FILENAME);

	if(infile.fail()) {
		cerr << "Unable to open file: " << FILENAME << endl;
		exit(1);
	}

	while(!infile.eof()) {
		test = new Show();

		getline(infile, line);
		test->setTitle(line);

		getline(infile, line);
		test->setGenre(line);

		getline(infile, line);
		test->setAddress(line);

		getline(infile, line);
		while(line != "") {
			test->addActor(line);
			getline(infile, line);
		}

		test->print();
		cout << "--" << endl;

		delete test;
	}

	/* Interact with user */
	while(running) {
		running = 0;
	}

	/* Clean up */
	
	exit(0);
}
