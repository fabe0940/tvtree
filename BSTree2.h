/* BSTree2.h
 *
 * Interface for Binary Search Tree class WITH
 * deletion.
 */

#ifndef _BSTREE_H_
#define _BSTREE_H_

typedef int DATA_TYPE;

class BinarySearchTree {
	private:
		typedef struct BSTreeNode {
			DATA_TYPE data;
			BSTreeNode *leftPtr;
			BSTreeNode *rightPtr;
		} *TreePtr;

		TreePtr rootPtr; // root of the BST

		void initBSTree() { rootPtr = NULL; }
		void deleteBST(TreePtr& treePtr);

		void deleteNode(TreePtr& treePtr, DATA_TYPE theItem);
		void deleteNodeItem(TreePtr& treePtr);
		void processLeftMost(TreePtr& treePtr, DATA_TYPE& theItem);

		void printBST_InOrder(TreePtr treePtr);
		void printBST_PreOrder(TreePtr treePtr);
		void printBST_PostOrder(TreePtr treePtr);

		void printBST_BackwardPostOrder(TreePtr treePtr, int depth);

		bool isLeaf(TreePtr treePtr);

		TreePtr searchNodeInBST(TreePtr treePtr, DATA_TYPE searchKey);

	public:
		BinarySearchTree() { initBSTree(); }
		~BinarySearchTree();

		void addNode(DATA_TYPE newData);
		void searchNode(DATA_TYPE searchKey);
		void deleteNode(DATA_TYPE val);

		void printTree();

		void printInOrder();
		void printPreOrder();
		void printPostOrder();

		void printBackwardPostOrder();

		bool isEmpty() { return (rootPtr == NULL); }
};

#endif
