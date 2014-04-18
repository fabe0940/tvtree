/* BSTree2.cpp
 *
 * Binary Search Tree Implementation with Deletion.
 */

#include <iostream>
#include <string>
#include "BSTree2.h"

using namespace std;

BinarySearchTree::~BinarySearchTree() {
	deleteBST(rootPtr);
}

bool BinarySearchTree::isLeaf(TreePtr treePtr) {
		return ((treePtr->leftPtr == NULL) && (treePtr->rightPtr == NULL));
}

void BinarySearchTree::deleteBST(TreePtr& treePtr) {
	if(treePtr != NULL) {
		deleteBST(treePtr->leftPtr);
		deleteBST(treePtr->rightPtr);

		delete treePtr;
		treePtr = NULL;
	}
}

void BinarySearchTree::addNode(Show newData) {
	TreePtr newPtr;

	newPtr = new BSTreeNode;
	newPtr->data = newData;
	newPtr->leftPtr = NULL;
	newPtr->rightPtr = NULL;

	if(rootPtr == NULL) {
		rootPtr = newPtr;
	} else {
		TreePtr treePtr = rootPtr;
		TreePtr targetNodePtr;

		while(treePtr != NULL) {
			targetNodePtr = treePtr;

			if(newData.getTitle() == treePtr->data.getTitle()) {
				return;
			} else if(newData.getTitle() < treePtr->data.getTitle()) {
				treePtr = treePtr->leftPtr;
			} else {
				treePtr = treePtr->rightPtr;
			}
		}

		if(newData.getTitle() < targetNodePtr->data.getTitle()) {
			targetNodePtr->leftPtr = newPtr;
		} else {
			targetNodePtr->rightPtr = newPtr;
		}
	}
}

void BinarySearchTree::searchTitleInBST(TreePtr treePtr, Show key) {
	if(treePtr != NULL) {
		if(key.getTitle() == treePtr->data.getTitle()) {
			treePtr->data.print();
		} else if(key.getTitle() < treePtr->data.getTitle()) {
			searchTitleInBST(treePtr->leftPtr, key);
		} else {
			searchTitleInBST(treePtr->rightPtr, key);
		}
	}
}

void BinarySearchTree::searchActorInBST(TreePtr treePtr, string key) {
	if(treePtr != NULL) {
		searchActorInBST(treePtr->leftPtr, key);
		if(treePtr->data.hasActor(key)) {
			treePtr->data.print();
		}
		searchActorInBST(treePtr->rightPtr, key);
	}
}

void BinarySearchTree::searchDateInBST(TreePtr treePtr, int start, int end) {
	int srcStart;
	int srcEnd;

	if(treePtr != NULL) {
		searchDateInBST(treePtr->leftPtr, start, end);
		srcStart = treePtr->data.getYearStart();
		srcEnd = treePtr->data.getYearEnd();
		if(srcStart >= start && srcEnd <= end) {
			treePtr->data.print();
		}
		searchDateInBST(treePtr->rightPtr, start, end);
	}
}

void BinarySearchTree::searchNodeTitle(string s) {
	Show searchKey;
	searchKey.setTitle(s);
	searchTitleInBST(rootPtr, searchKey);
}

void BinarySearchTree::searchNodeActor(string s) {
	searchActorInBST(rootPtr, s);
}

void BinarySearchTree::searchNodeDate(int start, int end) {
	searchDateInBST(rootPtr, start, end);
}

void BinarySearchTree::print() {
	printBST_InOrder(rootPtr);
}

void BinarySearchTree::printBST_InOrder(TreePtr treePtr) {
	if(treePtr != NULL) {
		printBST_InOrder(treePtr->leftPtr);
		treePtr->data.print();
		printBST_InOrder(treePtr->rightPtr);
	}
}

void BinarySearchTree::printTitle() {
	printBST_TitleInOrder(rootPtr);
}

void BinarySearchTree::printBST_TitleInOrder(TreePtr treePtr) {
	if(treePtr != NULL) {
		printBST_TitleInOrder(treePtr->leftPtr);
		cout << treePtr->data.getTitle() << endl;
		printBST_TitleInOrder(treePtr->rightPtr);
	}
}
