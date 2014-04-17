/* BSTree2.cpp
 *
 * Binary Search Tree Implementation with Deletion.
 */


#include <iostream>
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

BinarySearchTree::TreePtr BinarySearchTree::searchNodeInBST(TreePtr treePtr, Show key) {
	if(treePtr != NULL) {
		if(key.getTitle() == treePtr->data.getTitle()) {
			return treePtr;
		} else if(key.getTitle() < treePtr->data.getTitle()) {
			return searchNodeInBST(treePtr->leftPtr, key);
		} else {
			return searchNodeInBST(treePtr->rightPtr, key);
		}
	} else {
		return NULL;
	}
}

void BinarySearchTree::searchNode(Show searchKey) {
	TreePtr srchPtr = NULL;

	srchPtr = searchNodeInBST(rootPtr, searchKey);

	if(srchPtr != NULL) {
		cout << "\n Node: " << srchPtr->data.getTitle() << " was found in the BST" << endl;
	} else {
		cout << "\n Node: " << searchKey.getTitle() << " was not found" << endl;
	}
}

void BinarySearchTree::printTree() {
	printBST_InOrder(rootPtr);
}

void BinarySearchTree::printInOrder() {
	printBST_InOrder(rootPtr);
}

void BinarySearchTree::printBST_InOrder(TreePtr treePtr) {
	if(treePtr != NULL) {
		printBST_InOrder(treePtr->leftPtr);
		treePtr->data.print();
		printBST_InOrder(treePtr->rightPtr);
	}
}

void BinarySearchTree::printPreOrder() {
	printBST_PreOrder(rootPtr);
}


void BinarySearchTree::printBST_PreOrder(TreePtr treePtr) {
	if(treePtr != NULL) {
		treePtr->data.print();
		printBST_PreOrder(treePtr->leftPtr);
		printBST_PreOrder(treePtr->rightPtr);
	}
}

void BinarySearchTree::printPostOrder() {
	printBST_PostOrder(rootPtr);
}


void BinarySearchTree::printBST_PostOrder(TreePtr treePtr) {
	if(treePtr != NULL) {
		printBST_PostOrder(treePtr->leftPtr);
		printBST_PostOrder(treePtr->rightPtr);
		treePtr->data.print();
	}
}
