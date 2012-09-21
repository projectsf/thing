#include <iostream>


struct Node {
	int value;
	Node* next;
};

Node* head = NULL;

/**
 * Inserts a node into a linked list
 */
void listInsert(int value)
{
	Node* temp = new Node;
	temp->value = value;
	temp->next = NULL;
	
	if(head == NULL) {
	  head = temp;
	}
	  
	else {
	  Node *curr = head;
	  Node *prev = head;
	  while(curr) {
	  	prev = curr;
	    curr = curr->next;
	  }
	  prev->next = temp;
	}
	  
}

/**
 * Remove duplicates efficiently from sorted list
 * 
 * Keep track of current and next nodes 
 */
void removeDuplicates()
{
	Node* prev = head;
	Node* curr = head;
	int prevValue;
	while(curr) {
		prevValue = prev->value;
		curr = prev->next;
		if(curr->value == prevValue) {
			prev->next = curr->next;
			delete curr;
			curr = prev;
	  }
	  else {
	  	prev = curr;
	    curr = curr->next;
	  }
	}
}



int main()
{
	
	listInsert(1); 
	listInsert(1);
	listInsert(1);
	listInsert(3);
  listInsert(3);
	listInsert(3);
	listInsert(3);
	listInsert(3);
	listInsert(9);
						
	std::cout << "Inserted elements into list" << std::endl;


  Node* curr = head;
  while(curr) {
  	std::cout << " " << curr->value;
  	curr = curr->next;
  }
  
  removeDuplicates();
  std::cout << std::endl << "Removed duplicate elements in first list" << std::endl;

  curr = head;
  while(curr) {
  	std::cout << " " << curr->value;
  	curr = curr->next;
  }
  
}
