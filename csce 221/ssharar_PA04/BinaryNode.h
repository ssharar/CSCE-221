#include <cstddef>
#include <iostream>
using namespace std;

class TreeOperation{
public:
	virtual void proccessNode(int ele, int search_cost) = 0;
};
class PrintTreeNode : public TreeOperation
{
public:
	void proccessNode(int element, int search_cost)
	{
		cout << element << " [" << search_cost << "] \t";	//add SC
	}	
};

class BinaryNode {
	friend class BinaryTree;
	int elem;
	int SC;
	
public:
	BinaryNode *left, *right;
	
	//constructor
	
	BinaryNode (int el=0, int sc =1, BinaryNode *lt = NULL, BinaryNode *rt=NULL): elem(el), SC(sc), left(lt), right(rt) {}
	
	//functions
	BinaryNode *getLeft() {return left;}
	BinaryNode *getRight() {return right;}
	int getElem() {return elem;}
	int size(BinaryNode *t);
	int height(BinaryNode *t);
	int getSC() {return SC;}
	BinaryNode *copy();
	
	void preOrderT(TreeOperation& op);
	void inOrderT(TreeOperation& op);
	void postOrderT(TreeOperation& op);
};

