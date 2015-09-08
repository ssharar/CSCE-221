#include "DoublyLinkedList.h"
#include <stdexcept>
// extend range_error from <stdexcept>
struct EmptyDLinkedListException : std::range_error {
  explicit EmptyDLinkedListException(char const* msg=NULL): range_error(msg) {}
};
// copy constructor
//BIG OH = O(n)
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& dll)
{
  // Initialize the list
  header.next = &trailer; trailer.prev = &header;
  
  // Copy from dll
  /* Complete this function */
	//declares temporary node and set it equal to the first element of old list
	DListNode *temp_node;
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
DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& dll)
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
	
	DListNode *temp_nodeC;
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
void DoublyLinkedList::insertFirst(int newobj)
{ 
  DListNode *newNode = new DListNode(newobj, &header, header.next);
  header.next->prev = newNode;
  header.next = newNode;
}
// insert the object to the last of the linked list
void DoublyLinkedList::insertLast(int newobj)
{
  DListNode *newNode = new DListNode(newobj, trailer.prev,&trailer);
  trailer.prev->next = newNode;
  trailer.prev = newNode;
}
// remove the first object of the list
int DoublyLinkedList::removeFirst()
{ 
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  DListNode *node = header.next;
  node->next->prev = &header;
  header.next = node->next;
  int obj = node->obj;
  delete node;
  return obj;
}
// remove the last object of the list
int DoublyLinkedList::removeLast()
{
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  DListNode *node = trailer.prev;
  node->prev->next = &trailer;
  trailer.prev = node->prev;
  int obj = node->obj;
  delete node;
  return obj;
}
// destructor
DoublyLinkedList::~DoublyLinkedList()
{
  DListNode *prev_node, *node = header.next;
  while (node != &trailer) {
    prev_node = node;
    node = node->next;
    delete prev_node;
  }
  header.next = &trailer;
  trailer.prev = &header;
}
// return the first object
int DoublyLinkedList::first() const
{ 
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  return header.next->obj;
}
// return the last object
int DoublyLinkedList::last() const
{
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  return trailer.prev->obj;
}
// return the list length
int DoublyLinkedListLength(DoublyLinkedList& dll) {
  DListNode *current = dll.getFirst();
  int count = 0;
  while(current != dll.getAfterLast()) {
    count++;
    current = current->getNext(); //iterate
  }
  return count;
}
// output operator
//BIG OH = O(n)
ostream& operator<<(ostream& out, const DoublyLinkedList& dll) {
  
  /* Complete this function */
  
  //Declare temporary node and assign to 1st elem
	DListNode *temp_node;
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
