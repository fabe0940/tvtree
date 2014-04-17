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
		int index;
		string line;
		string str;
		Show temp;

		do {
			getline(infile, line);
		} while(line == "");

		index = line.find("(");
		str = line.substr(0, index - 1);
		temp.setTitle(str);
		str = line.substr(index + 1, index + 5);
		temp.setStartYear(atoi(str.c_str()));
		str = line.substr(index + 6, index + 10);
		temp.setEndYear(atoi(str.c_str()));

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

	infile.close();

	/* Interact with user */
	while(running) {
		running = 0;
	}

	/* Clean up */
	
	exit(0);
}
