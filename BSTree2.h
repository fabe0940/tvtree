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

		void deleteNode(TreePtr& treePtr, Show theItem);
		void deleteNodeItem(TreePtr& treePtr);
		void processLeftMost(TreePtr& treePtr, Show& theItem);

		void printBST_InOrder(TreePtr treePtr);
		void printBST_PreOrder(TreePtr treePtr);
		void printBST_PostOrder(TreePtr treePtr);

		void printBST_BackwardPostOrder(TreePtr treePtr, int depth);

		bool isLeaf(TreePtr treePtr);

		TreePtr searchNodeInBST(TreePtr treePtr, Show searchKey);

	public:
		BinarySearchTree() { initBSTree(); }
		~BinarySearchTree();

		void addNode(Show newData);
		void searchNode(Show searchKey);
		void deleteNode(Show val);

		void printTree();

		void printInOrder();
		void printPreOrder();
		void printPostOrder();

		void printBackwardPostOrder();

		bool isEmpty() { return (rootPtr == NULL); }
};

#endif
