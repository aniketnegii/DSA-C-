/*
	Author:Rashmi Singh
    Date:23/10/21
	
 	Given a Linked List, find the nth node from the end of a linked list.
 	Output:
	Original List is: 12 31 28 45 60 
	Output:28
	
*/


#include <iostream>
using namespace std;

/* creating a node structure in C/C++ */
struct Node {
   int data;
   struct Node *next;
};

/* defining head as null as there is no node in the list initially. */
struct Node* head = NULL;

void push(int data) {
	Node *temp;
	temp = head;

	/* creating a node and assigning data to it and make its next as null */
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data = data;
   	new_node->next = NULL;

   	/* check if it's empty make new_node as head */
	if(head == NULL) {
   		head = new_node;
	}
	/* otherwise move upto the last and then connect last node with the new_node */
	else { 
		while(temp->next != NULL) {
			temp = temp->next;
		}
   		temp->next = new_node;
	}
}

/* Function to find the nth Node from the end. */
void nthNodeFromEnd(int nthNode) {
	Node *prev, *curr;
	prev = head;
	curr = head;

	if(head == NULL) {
		cout << "The list doesn't exist." << endl;
		return;
	}

	/* curr pointer is being moved ahead n times. */
	for(int i = 0; i < nthNode; i++) {
		if(curr != NULL) {
			curr = curr->next;	
		}
		else {
			cout << "Enough nodes are not present in the linked list." << endl;
			return;
		}
	}

	// Now the difference between prev and curr pointer is n

	/* now we'll move prev and curr pointer both until curr becomes null and finally prev will be at n from last */
	while(curr != NULL) {
		curr = curr->next;
		prev = prev->next;
	}

	/* finally printing data of nth node from last */
	cout << prev->data << endl;

}

/* for printing the linked list */
void printList() {

   	struct Node* ptr;
   	ptr = head;
   	
   	while (ptr != NULL) {
      	cout<< ptr->data <<" ";  
      	ptr = ptr->next;
   	}
   	cout<<endl;
}

int main() {

	push(12);
	push(31);
	push(28);
	push(45);
	push(60);
	cout<<"Original List is: ";
	printList();
	nthNodeFromEnd(3);

	return 0;

}