#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include "BSTree2.h"
#include "StringList.h"

using namespace std;

#define FILENAME "tvDB.txt"

int main(void) {
	int running;
	ifstream infile;
	string line;
	StringList test;

	/* Initialize */
	running = 1;

	/* Parse file */
	infile.open(FILENAME);

	if(infile.fail()) {
		cerr << "Unable to open file: " << FILENAME << endl;
		exit(1);
	}

	getline(infile, line);
	while(!infile.eof()) {
		test.add(line);
		getline(infile, line);

		while(line == "\n") {
			getline(infile, line);
		}
	}

	test.print();

	/* Interact with user */
	while(running) {
		running = 0;
	}

	/* Clean up */
	
	exit(0);
}
