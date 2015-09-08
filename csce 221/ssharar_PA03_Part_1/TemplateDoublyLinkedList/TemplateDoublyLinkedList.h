#include <cstdlib>
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class DoublyLinkedList;	//class deceleration

// list node
template <typename T>
class DListNode {
private: T obj;
  DListNode<T> *prev, *next;
  friend class DoublyLinkedList<T>;
public:
  DListNode(T e = T(), DListNode<T> *p = NULL, DListNode<T> *n = NULL)
    : obj(e), prev(p), next(n) {}
  T getElem() const { return obj; }
  DListNode<T> * getNext() const { return next; }
  DListNode<T> * getPrev() const { return prev; }
};

// doubly linked list
template <typename T>
class DoublyLinkedList {
protected: DListNode<T> header, trailer;
public:
  DoublyLinkedList() : header(T()), trailer(T()) // constructor
  { header.next = &trailer; trailer.prev = &header; }
  DoublyLinkedList(const DoublyLinkedList<T>& dll); // copy constructor
  ~DoublyLinkedList(); // destructor
  DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& dll); // assignment operator
  // return the pointer to the first node
  DListNode<T> *getFirst() const { return header.next; } 
  // return the pointer to the trailer
  const DListNode<T> *getAfterLast() const { return &trailer; }
  // return if the list is empty
  bool isEmpty() const { return header.next == &trailer; }
  T first() const; // return the first object
  T last() const; // return the last object
  void insertFirst(T newobj); // insert to the first of the list
  T removeFirst(); // remove the first node
  void insertLast(T newobj); // insert to the last of the list
  T removeLast(); // remove the last node
};
// output operator
template <typename T>
ostream& operator<<(ostream& out, const DoublyLinkedList<T>& dll);





//.CPP FUNCTIONS HERE:



// extend range_error from <stdexcept>
template <typename T>
struct EmptyDLinkedListException : std::range_error {
  explicit EmptyDLinkedListException(char const* msg=NULL): range_error(msg) {}
};
// copy constructor
//BIG OH = O(n)
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& dll)
{
  // Initialize the list
  header.next = &trailer; trailer.prev = &header;
  
  // Copy from dll
  /* Complete this function */
	//declares temporary node and set it equal to the first element of old list
	DListNode<T> *temp_node;
	temp_node = dll.getFirst();

	//runs through list until trailer is reached
	//inserts elements of old list into new list
	//iterates counter
  while(temp_node != dll.getAfterLast()) 
  {  
	this->insertLast(temp_node->getElem());
	
	temp_node = temp_node->next;
  }
  }
 
// assignment operator
//BIG OH = O(n)
template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& dll)
{
 //Checks for self assignment
  if (this != &dll)
  {
	// Delete the whole list
  /* Complete this function */
	  while(!isEmpty()) 
	  {  
		this->removeFirst();
	  }
	
	DListNode<T> *temp_nodeC;
	temp_nodeC = dll.getFirst();
 
	 // Copy from dll
	  /* Complete this function */
	//runs through list until trailer is reached
	//inserts elements of old list into new list
	//iterates counter
	  while(temp_nodeC != dll.getAfterLast()) 
	  {  
		this->insertLast(temp_nodeC->getElem());
		
		temp_nodeC = temp_nodeC->next;
	  }
  }
  return *this;
}
// insert the object to the first of the linked list
template <typename T>
void DoublyLinkedList<T>::insertFirst(T newobj)
{ 
  DListNode<T> *newNode = new DListNode<T>(newobj, &header, header.next);
  header.next->prev = newNode;
  header.next = newNode;
}
// insert the object to the last of the linked list
template <typename T>
void DoublyLinkedList<T>::insertLast(T newobj)
{
  DListNode<T> *newNode = new DListNode<T>(newobj, trailer.prev,&trailer);
  trailer.prev->next = newNode;
  trailer.prev = newNode;
}
// remove the first object of the list
template <typename T>
T DoublyLinkedList<T>::removeFirst()
{ 
  if (isEmpty())
    throw EmptyDLinkedListException<T>("Empty Doubly Linked List");
  DListNode<T> *node = header.next;
  node->next->prev = &header;
  header.next = node->next;
  T obj = node->obj;
  delete node;
  return obj;
}
// remove the last object of the list
template <typename T>
T DoublyLinkedList<T>::removeLast()
{
  if (isEmpty())
    throw EmptyDLinkedListException<T>("Empty Doubly Linked List");
  DListNode<T> *node = trailer.prev;
  node->prev->next = &trailer;
  trailer.prev = node->prev;
  T obj = node->obj;
  delete node;
  return obj;
}
// destructor
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList<T>()
{
  DListNode<T> *prev_node, *node = header.next;
  while (node != &trailer) {
    prev_node = node;
    node = node->next;
    delete prev_node;
  }
  header.next = &trailer;
  trailer.prev = &header;
}
// return the first object
template <typename T>
T DoublyLinkedList<T>::first() const
{ 
  if (isEmpty())
    throw EmptyDLinkedListException<T>("Empty Doubly Linked List");
  return header.next->obj;
}
// return the last object
template <typename T>
T DoublyLinkedList<T>::last() const
{
  if (isEmpty())
    throw EmptyDLinkedListException<T>("Empty Doubly Linked List");
  return trailer.prev->obj;
}
// return the list length
template <typename T>
int DoublyLinkedListLength(DoublyLinkedList<T>& dll) {
  DListNode<T> *current = dll.getFirst();
  int count = 0;
  while(current != dll.getAfterLast()) {
    count++;
    current = current->getNext(); //iterate
  }
  return count;
}
// output operator
//BIG OH = O(n)
template <typename T>
ostream& operator<<(ostream& out, const DoublyLinkedList<T>& dll) {
  
  /* Complete this function */
  
  //Declare temporary node and assign to 1st elem
	DListNode<T> *temp_node;
	temp_node = dll.getFirst();
	//Run thru until end is reached
	//Print all elems
	//Iterate
	while(temp_node != dll.getAfterLast()) 
	  {  
		out << temp_node->getElem() << " ";
		
		temp_node = temp_node->getNext();
	  }
  return out;
}