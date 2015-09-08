#pragma once

#include "TemplateDoublyLinkedList.h"
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

// Disjoint Set
template <typename T>
class DisjointSet {
private:
	vector<DListNode<T>*> nodeLocator;
public:
	~DisjointSet();
	DisjointSet(int n);
	
	vector<DListNode<T>*> getNodeLocator() const {return nodeLocator;}
	DListNode<T>* MakeSet(int key, T node);
	DListNode<T>* Union(DListNode<T> nodeI, DListNode<T> nodeJ);
	DListNode<T>* FindSet(DListNode<T>& node) {return node.getRepresentative();}
	DListNode<T>* FindSet(int nodeKey);
};



template <typename T>
DisjointSet<T>::DisjointSet(int n)
{
	nodeLocator.resize(n);
}

template <typename T>
DisjointSet<T>::~DisjointSet()
{
	for (int i = 0; i<nodeLocator.size(); i++)
	{
		delete[] nodeLocator[i];
	}
	//nodeLocator.clear();
}

template <typename T>
DListNode<T>* DisjointSet<T>::MakeSet(int key, T node)
{
	DListNode<T>* Node1st = new DListNode<T>(key, node, NULL, NULL);
	Node1st->setRepresentative(Node1st);
	Node1st->setTrailer(Node1st);
	
	if (nodeLocator.size() > key)
	{
		nodeLocator[key] = Node1st;
	}
	else
	{
		nodeLocator.resize(2*key);
		nodeLocator[key] = Node1st;
	}
}

template <typename T>
DListNode<T>* DisjointSet<T>::Union(DListNode<T> nodeI, DListNode<T> nodeJ)
{
	if (nodeI.getListSize() > nodeJ.getListSize())
	{
		
		nodeI.getTrailer()->setNext(nodeJ.getRepresentative());
		nodeJ.setPrevious(nodeI.getTrailer());
		
		DListNode<T>* temp1 = nodeJ.getNext();
		for (int i=0; i < nodeJ.getListSize()-1; i++)
		{
			temp1->setRepresentative(nodeI.getRepresentative());
			temp1 = temp1->getNext();
		}
		
		nodeJ.setRepresentative(nodeI.getRepresentative());
		
		DListNode<T>* temp2 = &nodeI;
		nodeI.setTrailer(temp1);
		nodeI.getRepresentative()->setListSize(nodeI.getListSize()+nodeJ.getListSize());
		
		return nodeI.getRepresentative();
	}
	else
	{
		nodeJ.getTrailer()->setNext(nodeI.getRepresentative());
		nodeI.setPrevious(nodeJ.getTrailer());
		
		DListNode<T>* temp1 = nodeI.getNext();
		for (int i=0; i < nodeI.getListSize()-1; i++)
		{
			temp1->setRepresentative(nodeJ.getRepresentative());
			temp1 = temp1->getNext();
		}
		
		nodeI.setRepresentative(nodeJ.getRepresentative());
		
		DListNode<T>* temp2 = &nodeJ;
		nodeJ.setTrailer(temp1);
		nodeJ.getRepresentative()->setListSize(nodeI.getListSize()+nodeJ.getListSize());
		
		return nodeJ.getRepresentative();
	}
}

template <typename T>
DListNode<T>* DisjointSet<T>::FindSet(int nodeKey)
{
	if (nodeKey == 0)
	{
		
	}
	
	if (nodeLocator[nodeKey] != NULL)
	{
		return nodeLocator[nodeKey]->getRepresentative();
	}
}



template <typename T>
ostream& operator<<(ostream& out, const DisjointSet<T>& ds) {
	
	vector<DListNode<T>*> NL = ds.getNodeLocator();
	int set_counter =0;
	
	for (int i=0; i<NL.size(); i++)
	{
		
		if(NL[i] != NULL && NL[i] == NL[i]->getRepresentative())
		{
			
			out << "Set " << set_counter++ << ": { ";
			DListNode<T>* temp = NL[i]->getRepresentative();
			while (temp != NULL)
			{
				
				out << temp->getElem() << ", ";
				temp = temp->getNext();
			}
		out << "} \t";
		}
	}
	
	return out;
}