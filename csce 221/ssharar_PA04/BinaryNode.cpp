#include "BinaryNode.h"
using namespace std;

int BinaryNode::size(BinaryNode *t)
{
	if (t == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + size(t->left) + size(t->right);
	}
}

int BinaryNode::height(BinaryNode *t)
{
	if (t == NULL)
	{
		return -1;
	}
	else
	{
		int heightLeft = height(t->left);
		int heightRight = height(t->right);
		return (heightLeft > heightRight) ? 1+heightLeft : 1+heightRight; 
	}
}

BinaryNode *BinaryNode::copy()
{
	BinaryNode *root = new BinaryNode(elem);
	if (left != NULL)
	{
		root->left = left->copy();
	}
	if (right != NULL)
	{
		root->right = right->copy();
	}
	
	return root;
}

void BinaryNode::preOrderT(TreeOperation& op)
{
	op.proccessNode(elem, this->getSC());
	if (left != NULL) left->preOrderT(op);
	if (right != NULL) right->preOrderT(op);
}

void BinaryNode::inOrderT(TreeOperation& op)
{
	if (left != NULL) left->inOrderT(op);
	op.proccessNode(elem, this->getSC());
	if (right != NULL) right->inOrderT(op);
}

void BinaryNode::postOrderT(TreeOperation& op)
{
	if (left != NULL) left->postOrderT(op);
	if (right != NULL) right->postOrderT(op);
	op.proccessNode(elem, this->getSC());
}