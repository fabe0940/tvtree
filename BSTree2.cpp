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

void BinarySearchTree::deleteNode(DATA_TYPE val) {
	deleteNode(rootPtr, val);
}


void BinarySearchTree::deleteNode(TreePtr& treePtr, DATA_TYPE val) {
	if(treePtr == NULL) {
		return;
	} else if(val == treePtr->data) {
		deleteNodeItem(treePtr);
	} else if(val < treePtr->data) {
		deleteNode(treePtr->leftPtr, val);
	} else {
		deleteNode(treePtr->rightPtr, val);
	}
}


void BinarySearchTree::deleteNodeItem(TreePtr& treePtr) {
	TreePtr delPtr;

	if(isLeaf(treePtr)) {
		delete treePtr;
		treePtr = NULL;
	} else if(treePtr->leftPtr == NULL) {
		delPtr = treePtr;
		treePtr = treePtr->rightPtr;
		delPtr->rightPtr = NULL;
		delete delPtr;
	} else if(treePtr->rightPtr == NULL) {
		delPtr = treePtr;
		treePtr = treePtr->leftPtr;
		delPtr->leftPtr = NULL;
		delete delPtr;
	} else {
		DATA_TYPE replacementItem;
		processLeftMost(treePtr->rightPtr, replacementItem);
		treePtr->data = replacementItem;
	}
}


void BinarySearchTree::processLeftMost(TreePtr& treePtr, DATA_TYPE& theItem) {
	if(treePtr->leftPtr != NULL)
		processLeftMost(treePtr->leftPtr, theItem);
	else {
		theItem = treePtr->data;
		TreePtr delPtr = treePtr;
		treePtr = treePtr->rightPtr;
		delPtr->rightPtr = NULL;
		delete delPtr;
	}
}

void BinarySearchTree::addNode(DATA_TYPE newData) {
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

			if(newData == treePtr->data) {
				return;
			} else if(newData < treePtr->data) {
				treePtr = treePtr->leftPtr;
			} else {
				treePtr = treePtr->rightPtr;
			}
		}

		if(newData < targetNodePtr->data) {
			targetNodePtr->leftPtr = newPtr;
		} else {
			targetNodePtr->rightPtr = newPtr;
		}
	}
}

BinarySearchTree::TreePtr BinarySearchTree::searchNodeInBST(TreePtr treePtr, DATA_TYPE key) {
	if(treePtr != NULL) {
		if(key == treePtr->data) {
			return treePtr;
		} else if(key < treePtr->data) {
			return searchNodeInBST(treePtr->leftPtr, key);
		} else {
			return searchNodeInBST(treePtr->rightPtr, key);
		}
	} else {
		return NULL;
	}
}

void BinarySearchTree::searchNode(DATA_TYPE searchKey) {
	TreePtr srchPtr = NULL;

	srchPtr = searchNodeInBST(rootPtr, searchKey);

	if(srchPtr != NULL) {
		cout << "\n Node: " << srchPtr->data << " was found in the BST" << endl;
	} else {
		cout << "\n Node: " << searchKey << " was not found" << endl;
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
		cout << treePtr->data << endl;
		printBST_InOrder(treePtr->rightPtr);
	}
}

void BinarySearchTree::printPreOrder() {
	printBST_PreOrder(rootPtr);
}


void BinarySearchTree::printBST_PreOrder(TreePtr treePtr) {
	if(treePtr != NULL) {
		cout << treePtr->data << endl;
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
		cout << treePtr->data << endl;
	}
}

void BinarySearchTree::printBackwardPostOrder() {
	printBST_BackwardPostOrder(rootPtr, 0);
}


void BinarySearchTree::printBST_BackwardPostOrder(TreePtr treePtr, int depth) {
	const int INDENT = 4;

	if(treePtr != NULL) {
		printBST_BackwardPostOrder(treePtr->rightPtr, depth+1);

		for(int i = 0 ; i < INDENT*depth ; i++) {
			cout << " ";
		}
		cout << treePtr->data << endl;

		printBST_BackwardPostOrder(treePtr->leftPtr, depth+1);
	}
}
