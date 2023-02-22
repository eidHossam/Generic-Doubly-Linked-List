# Generic Doubly Linked List!.

-This project is an implementation of a generic linked list that can be used with different data types ( Int, Float, Char).

-This linked list can be traversed in both ways, from the head to the tail or from the tail to the head. 
 
 # Main Features
	 1 - newList(void)
Creates a new list which contains the head, tail and the size of the list.
	
	2 - append(List_t *root, void *val)
Adds a new item to the end of the list.

	3 - push(List_t *root, void *val)
Adds a new item to the beginning of the list 

	4 - pop(List_t *root)
Removes the last item in the list

	5 - search(List_t *root, void *val, bool  compare(Node_t *node, void *val))
Checks if a value exist in the list.

	6 - printList(List_t *root, void (*f_ptr)(Node_t *node))
Prints the contents of the list.

  # How to use
  
  You just need to include the header file LL.h then make a new instance of the user defined data type List_t and start adding the items to the list.
