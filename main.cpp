#include <cstdlib>
#include <ctime>
#include <iostream>
#include "BSTree2.h"

using namespace std;

int main(void) {
	const int MAX = 20;
	int i;
	int j;
	int val;
	BinarySearchTree* tree;

	srand(time(NULL));

	for(i = 0; i < MAX; i++) {
		cout << "Test " << (i + 1) << " of " << MAX << endl;

		tree = new BinarySearchTree();

		for(j = 0; j < i; j++) {
			val = rand() % 100;
			cout << "[" << (i + 1) << "] Inserting " << val << endl;
			tree->addNode(val);
		}

		tree->printBackwardPostOrder();

		delete tree;
	}

	exit(0);
}
