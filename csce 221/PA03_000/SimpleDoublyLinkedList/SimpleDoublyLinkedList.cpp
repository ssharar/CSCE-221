#include <iostream>
using namespace std;

// list node
struct Node {
  int data; // each node holds an integer data
  Node* previous; // pointer to the previous node
  Node* next; // pointer to the next node
  Node(int d=0, Node* prv=NULL, Node* nxt=NULL) : data(d), previous(prv), next(nxt) {}
  Node* get_previous() const { return previous; }
  Node* get_next() const { return next; }
  Node* insert_before(int d); // insert the int before this node
                                // return a pointer to the inserted node
  Node* insert_after(int d); // insert the int after this node
                               // return a pointer to the inserted node
  void delete_before(); // delete the node before this node
  void delete_after(); // delete the node after this node
};

// insert the int before this node
// return a pointer to the inserted node
//BIG OH = O(1)
Node* Node::insert_before(int d) {
  
  /* Complete this function */
  //Create new node 
  Node* u = new Node(d);

  //Set the new node's next pointer to current node
  //Set new node's previous pointer to node before current node
  //Set node before current node's next pointer to new node
  u->next = this;
  u->previous = this->previous;
  this->previous->next = this->previous = u;
  
}
// insert the int after this node
// return a pointer to the inserted node
//BIG OH = O(1)
Node* Node::insert_after(int d) {
  
  /* Complete this function */
   //Create new node 
   Node* u = new Node(d);

  //Set the new node's previous pointer to current node
  //Set new node's next pointer to node after current node
  //Set node after current node's previous pointer to new node
  u->previous = this;
  u->next = this->next;
  this->next->previous = this->next = u;
  
}
// delete the node before this node
//BIG OH = O(1)
void Node::delete_before()
{
  
  /* Complete this function */
  //Check if there is a previous node
  if(this->previous == NULL)
  {
  }
  else
  {
	//If there is,
	//Make new node of node before previous and previous node
	//Set before previous's node's next to current node
	//Set current node's previous to before previous's node
	//Delete previous node
	Node* before_prev = new Node();
	before_prev = this->previous->previous;
	Node* prev = new Node();
	prev = this->previous;
	
	before_prev->next = this;
	this->previous = before_prev;
	
	delete prev;
  }
  
}
// delete the node after this node
//BIG OH = O(1)
void Node::delete_after()
{
  
  /* Complete this function */
  //Check if there is a next node
  if(this->next == NULL)
  {
  }
  else
  {
	//If there is,
	//Make new node of node after nest and next node
	//Set after next's node's previous to current node
	//Set current node's next to after next's node
	//Delete next node
	Node* after_next = new Node();
	after_next = this->next->next;
	Node* next = new Node();
	next = this->next;
	
	after_next->previous = this;
	this->next = after_next;
	
	delete next;
  }
  
}

// Display the doubly linked list
void display_list(Node* header, Node* trailer) {
  Node* p=header->get_next();
  //Node* p=header; // uncomment this if want to display the header
  while (p!=trailer) {
    cout << p->data << ", ";
    p=p->get_next();
  }
  //cout << p->data << ", "; // uncomment this if want to display the trailer
  cout << endl;
}

// Test program
int main() {
  // Construct a linked list with header & trailer
  cout << "Create a new list" << endl;
  Node *header = new Node(-1);
  Node *trailer = new Node(-2);
  trailer->previous = header;
  header->next = trailer;
  cout << "list: ";
  display_list(header,trailer);
  cout << endl;
  
  // Insert 10 nodes at back with value 10,20,30,..,100
  cout << "Insert 10 nodes at back with value 10,20,30,..,100" << endl;
  for (int i=10;i<=100;i+=10) {
    trailer->insert_before(i);
  }
  cout << "list: ";
  display_list(header,trailer);
  cout << endl;

 // Insert 10 nodes at front with value 100,90,80,..,10
  cout << "Insert 10 nodes at front with value 100,90,80,..,10" << endl;
  for (int i=10;i<=100;i+=10) {
    header->insert_after(i);
  }
  cout << "list: ";
  display_list(header,trailer);
  cout << endl;
 
  // Delete the last 10 nodes
  cout << "Delete the last 10 nodes" << endl;
  for (int i=0;i<10;i++) {
    trailer->delete_before();
  }
  cout << "list: ";
  display_list(header,trailer);
  cout << endl;

  // Delete the first 10 nodes
  cout << "Delete the first 10 nodes" << endl;
  for (int i=0;i<10;i++) {
    header->delete_after();
  }
  cout << "list: ";
  display_list(header,trailer);
 
  return 0;
  
}