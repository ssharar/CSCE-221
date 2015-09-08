#include "BinaryNode.h"
#include <iostream>
#include <queue>

using namespace std;

class BinaryTree {

	BinaryNode *root;
	void deleteTree(BinaryNode *root);
		
public:
	//Constructor and Destructor
	BinaryTree() {root = NULL;}
	BinaryTree(int el) {root = new BinaryNode(el);}
	~BinaryTree() {deleteTree(root); root = NULL;}
	
	//Functions
	BinaryNode *getRoot() {return root;}
	bool isEmp() {return root == NULL;}
	int size() {return (root == NULL) ? 0 : root->size(root);}
	int height() {return (root == NULL) ? 0 : root->height(root);}
	double avgSC(BinaryNode *t, int *cost);
	
	void copy(BinaryTree& rhs)	
	{
		if (this != &rhs)
		{
			deleteTree(root);
			if (rhs.root != NULL) root = rhs.root->copy();
		}
	}
	
	void merge(int rItem, BinaryTree& T1, BinaryTree& T2);
	
	
	BinaryNode* findMin(BinaryNode *t);
	BinaryNode* removeMin(BinaryNode *t);
	void insertNode(int x);
	BinaryNode* remove(int x, BinaryNode *t);
	/*void insert(int x) //throw(DuplicateItem)
	{ root = insert(x, root, 1); }
	void remove(int x) //throw(ItemNotFound)
	{ root = remove(x, root); }*/
	
};

ostream& operator<<(ostream& os, BinaryTree& Tree);

