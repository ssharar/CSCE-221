#include "BinaryTree.h"

//using namepsace std;

double BinaryTree::avgSC(BinaryNode *t, int *cost)
{
	*cost = *cost + t->getSC();
	
	if(t->left != NULL)
	{
		avgSC(t->left, cost);
	}
	if(t->right != NULL)
	{
		avgSC(t->right, cost);
	}
	return (double)(*cost) / (double)(size());
}

BinaryNode *BinaryTree::findMin(BinaryNode *t)
{
	if (t == NULL) ;
	while (t->left != NULL) t = t->left;
	return t;
}

BinaryNode *BinaryTree::removeMin(BinaryNode *t)
{
	if (t == NULL) ;
	if (t->left != NULL)
		t->left = removeMin(t->left);
	else
	{
		BinaryNode *node = t;
		t = t->right;
		delete node;
	}
	return t;
}

void inRecr(BinaryNode *t, int x, int comp)
{
	++comp;
	if(x < t->getElem())
	{
		if(t->left == NULL)
		{
			t->left = new BinaryNode(x, comp);
		}
		else
			inRecr(t->left, x, comp);
	}
	else
	{
		if(t->right == NULL)
		{
			t->right = new BinaryNode(x, comp);
		}
		else
			inRecr(t->right, x, comp);
	}
}

void BinaryTree::insertNode(int x)
{
	BinaryNode *temp = root;
	if (root == NULL)
		root = new BinaryNode(x);
	else
		inRecr(root, x, 1);
}

BinaryNode *BinaryTree::remove(int x, BinaryNode *t)
{
	if (t == NULL) ;
	
	if (x < t->elem)
		t->left = remove(x, t->left);
	else if (x > t->elem)
		t->right = remove(x, t->right);
	else if (t->left != NULL && t->right != NULL)
	{
		t->elem = findMin(t->right)->elem;
		t->right = removeMin(t->right);
	}
	else
	{
		BinaryNode *node = t;
		t = (t->left != NULL) ? t->left : t->right;
		delete node;
	}
	
	return t;
}

void BinaryTree::merge(int rItem, BinaryTree& T1, BinaryTree& T2)
{
	if (T1.root == T2.root && T1.root != NULL)
	{
		cerr << "Left tree is equal to the right tree and so merge was not completed." << endl;
		return;
	}
	
	if (this != &T1 && this != &T2) deleteTree(root);
	root = new BinaryNode(rItem, 1, T1.root, T2.root);
	
	if (this != &T1) T1.root = NULL;
	if (this != &T2) T2.root = NULL;
}

void BinaryTree::deleteTree(BinaryNode *root)
{
	if (root == NULL) return;
	if (root->left !=NULL) deleteTree(root->left);
	if (root->right != NULL) deleteTree(root->right);
	delete root;
}






ostream& operator<<(ostream& ost, BinaryTree& Tree) 
{
	if(Tree.isEmp()) return ost;
	
	queue<BinaryNode*> nQ;

	int currentLevel = 1;
	int nextLevel = 0;  
	int currentHeight = -1; 
	
	nQ.push(Tree.getRoot());
	
	while (!nQ.empty()) 
	{
		BinaryNode *node = nQ.front();
	
		nQ.pop();
		--currentLevel;
		if(node != NULL) 
		{
			ost << node->getElem() << '[' << node->getSC() << "] ";  
			nQ.push(node->getLeft());
			nQ.push(node->getRight());
			nextLevel += 2;  
		}
		else if(currentHeight != Tree.height())
			ost << "X ";
		
		if(currentLevel == 0) 
		{
			ost << endl;
			currentLevel = nextLevel;
			nextLevel = 0; 
			++currentHeight;
		}
	}
	return ost;  
}
/*ostream& operator<<(ostream OS, BinaryTree& BT)
{
	if(BT.isEmp()) return OS;
	
	queue<BinaryNode*> NQ;
	int currLev = 1;
	int nextLev = 0;
	int curH = -1;
	
	NQ.push(BT.getRoot());
	while (!NQ.empty())
	{
		BinaryNode *t = NQ.front();
		NQ.pop();
		--currLev;
		
		if (t != NULL)
		{
			OS << t->getElem() << '[' << t->getSC() << "] \t";
			NQ.push(t->getLeft());
			NQ.push(t->getRight());
			nextLev = nextLev +2;
		}
		else if (curH != BT.height())
		{
			OS << "X";
		}
		
		if(currLev == 0)
		{
			OS << endl;
			currLev = nextLev;
			nextLev = 0;
			++curH;
		}
	}
	
	return OS;
}*/