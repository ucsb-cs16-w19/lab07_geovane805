#include <cassert>
#include "linkedList.h"
#include "linkedListFuncs.h"



void addIntToEndOfList(LinkedList *list, int value) 
{
  assert(list!=NULL); // if list is NULL, we can do nothing.

  // (1) Allocate a new node.  p will point to it.
  Node *p = new Node;
  // (2) Set p's data field to the value passed in
  p->data = value; 
  // (3) Set p's next field to NULL
  p->next = NULL;

  if (list->head == NULL) 
  {
    // (4) Make both head and tail of this list point to p
    list->head = p;
    list->tail = p;
  } 

  else
  {
    // Add p at the end of the list.   
    // (5) The current node at the tail? Make it point to p instead of NULL
    list->tail->next = p;
    // (6) Make the tail of the list be p now.
    list->tail = p;
  }

}

void addIntToStartOfList(LinkedList *list, int value) {
  assert(list!=NULL); // if list is NULL, we can do nothing.

  Node *p = new Node; // allocate a new node, p points to it
  p->data = value;   //  set p's data field to the value passed in
  p->next = NULL;   //   set p's next field to NULL

  if (list->head == NULL) 
  {
	//head and tail of the list point to p
  	list->head = p;
	list->tail = p;
  }
  
  else
  {
	p->next = list->head;
	list->head = p;
  }
}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return a pointer to node with the largest value.
// You may assume list has at least one element  
// If more than one element has largest value, 
//  break tie by returning a pointer to the one the occurs
//  earlier in the list, i.e. closer to the head

Node * pointerToMax(LinkedList *list) {

  // Code may assume that these assertions are true;
  //  so does not need to do error checking for these conditions.
  assert(list!=NULL);
  assert(list->head != NULL);

  Node *max;
  max = list->head;
  for (Node *n = list->head; n != NULL; n = n->next)
  {
	  if (n->data > max->data)
		max = n;
  }
  return max;
}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return a pointer to node with the smallest value.  
// You may assume list has at least one element
// If more than one element has smallest value, 
//  break tie by returning a pointer to the one the occurs
//  earlier in the list, i.e. closer to the head


Node * pointerToMin(LinkedList *list) {

  // Code may assume that these assertions are true;
  //  so does not need to do error checking for these conditions.

  assert(list!=NULL);
  assert(list->head != NULL);
  
  Node *min;
  min = list->head;
  for (Node *n = list->head; n != NULL; n = n->next)
  {
	  if (n->data < min->data)
		min = n;
  }
  return min;
}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return the largest value in the list.
// This value may be unique, or may occur more than once
// You may assume list has at least one element

int largestValue(LinkedList *list) {

  // Code may assume that these assertions are true;
  //  so does not need to do error checking for these conditions.

  assert(list!=NULL);
  assert(list->head != NULL);

  int largestVal = list->head->data;
  for (Node *n = list->head; n != NULL; n = n->next)
  {
  	if (n->data > largestVal)
	{
		largestVal = n->data;
	}
  }
  return largestVal;

}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return the smallest value in the list.
// This value may be unique, or may occur more than once
// You may assume list has at least one element

int smallestValue(LinkedList *list) {
  // Code may assume that these assertions are true;
  //  so does not need to do error checking for these conditions.

  assert(list!=NULL);
  assert(list->head != NULL);

  int smallestVal = list->tail->data;
  for (Node *n = list->head; n != NULL; n = n->next)
  {
	  if (n->data < smallestVal)
	  {
		  smallestVal = n->data;
	  }
  }
  return smallestVal;
}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return the sum of all values in the list.
// You may assume that list is not NULL
// However, the list may be empty (i.e. list->head may be NULL)
//  in which case your code should return 0.

int sum(LinkedList * list) {
  // Code may assume that these assertions are true;
  //  so does not need to do error checking for these conditions.

  assert(list!=NULL);

  int sum = 0;
  if (list->head == NULL)
  {
	  return 0;
  }
  
  else
  {
	  for (Node *n = list->head; n != NULL; n = n->next)
	  {
		  sum = sum + n->data;
	  }
  }
  return sum;
}

