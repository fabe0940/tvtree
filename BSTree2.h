/* BSTree2.h
 *
 * Interface for Binary Search Tree class WITH
 * deletion.
 */

#ifndef _BSTREE_H_
#define _BSTREE_H_

#include "Show.h"

class BinarySearchTree {
	private:
		typedef struct BSTreeNode {
			Show data;
			BSTreeNode *leftPtr;
			BSTreeNode *rightPtr;
		} *TreePtr;

		TreePtr rootPtr; // root of the BST

		void initBSTree() { rootPtr = NULL; }
		void deleteBST(TreePtr& treePtr);

		void printBST_InOrder(TreePtr treePtr);
		void printBST_TitleInOrder(TreePtr treePtr);

		bool isLeaf(TreePtr treePtr);

		void searchTitleInBST(TreePtr treePtr, Show searchKey);
		void searchActorInBST(TreePtr treePtr, string key);
		void searchDateInBST(TreePtr treePtr, int start, int end);

	public:
		BinarySearchTree() { initBSTree(); }
		~BinarySearchTree();

		void addNode(Show newData);
		void searchNodeTitle(string s);
		void searchNodeActor(string s);
		void searchNodeDate(int start, int end);
		void deleteNode(Show val);

		void print();
		void printTitle();

		bool isEmpty() { return (rootPtr == NULL); }
};

#endif
