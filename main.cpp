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
	Show temp;
	BinarySearchTree t;

	/* Initialize */
	running = 1;

	/* Parse file */
	infile.open(FILENAME);

	if(infile.fail()) {
		cerr << "Unable to open file: " << FILENAME << endl;
		exit(1);
	}

	while(!infile.eof()) {
		Show temp;

		do {
			getline(infile, line);
		} while(line == "");
		temp.setTitle(line);

		getline(infile, line);
		temp.setGenre(line);

		getline(infile, line);
		temp.setAddress(line);

		getline(infile, line);
		while(line != "") {
			temp.addActor(line);
			getline(infile, line);
		}

		t.addNode(temp);
	}

	t.printInOrder();

	/* Interact with user */
	while(running) {
		running = 0;
	}

	/* Clean up */
	
	exit(0);
}
