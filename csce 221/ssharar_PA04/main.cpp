// main.cpp
//Tests all functionality of the My_vec class.

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
//#include "BinaryNode.h"
#include "BinaryTree.h"

using namespace std;

int main(){
try{
	PrintTreeNode pt;
	
	string filename;
		
	cout << "Enter filename: ";
	cin >> filename;
	
	ifstream f1(filename.c_str(), ifstream::in);
		
	cout << "Input data: \n";
	int lineVal;
	f1 >> lineVal;
	//cout << lineVal << endl;
	
	BinaryTree bt(lineVal);
	
	while(f1.good())
	{
		f1 >> lineVal;
		if (f1.good())
		{
		//	cout << lineVal << endl;
			bt.insertNode(lineVal);
		}
	}
	cout << endl;
	
	int* search_cost = new int(0);
	if(bt.size() < 16)
		cout << "Binary tree: \n" << bt;
	else
	{
		ofstream of("output1.txt");
		of << bt;
		cout << "Tree was larger than 2^4, was outputted into file 'output.txt' " << endl;
	}
	cout << "Number of nodes: " << bt.size() << endl;
	cout << "Average search cost: " << bt.avgSC(bt.getRoot(), search_cost) << endl;
	
	/*cout << "\nPreorder: ";
	bt.getRoot()->preOrderT(pt);
	cout << endl << "Inorder: ";
	bt.getRoot()->inOrderT(pt);
	cout << endl << "Posorder: ";
	bt.getRoot()->postOrderT(pt);
	cout << endl<<endl;
	
	cout << "What element to remove? " ;
	cin >> lineVal;
	bt.remove(lineVal, bt.getRoot());
	
	*search_cost = 0;
	if(bt.size() < 16)
		cout << "New binary tree: \n" << bt;
	else
	{
		ofstream of("output2.txt");
		of << bt;
		cout << "Tree was larger than 2^4, was outputted into file 'output2.txt' " << endl;
	}
	cout << "Number of nodes: " << bt.size() << endl;
	cout << "Average search cost: " << bt.avgSC(bt.getRoot(), search_cost) << endl;
	
	delete search_cost;
	

	cout << "\nPreorder: ";
	bt.getRoot()->preOrderT(pt);
	cout << endl << "Inorder: ";
	bt.getRoot()->inOrderT(pt);
	cout << endl << "Posorder: ";
	bt.getRoot()->postOrderT(pt);
	cout << endl<<endl;
	*/
}

catch(exception &error){
	cerr << "Error: " << error.what() << endl;
}
}