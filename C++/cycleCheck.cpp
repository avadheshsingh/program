//Cyclefinding problem
#include<iostream>
using namespace std;
struct Node {
	struct Node* next;
	int key;
};
struct Node Heap[1000];
int heapIdx;

struct Node* getNode() {
	struct Node* temp = &Heap[heapIdx++];
	temp->next = NULL;
	return temp;
}


void push(struct Node* root, int key) {
	struct Node* temp = getNode();
	temp->key = key;
	temp->next = root->next;
	root->next = temp;
}


bool detectLoop(struct Node* root) {
	
	struct Node* slowptr = root;
	struct Node* fastptr = root;
	while (slowptr && fastptr && fastptr->next) {
		slowptr = slowptr->next;
		fastptr = fastptr->next->next;
		if (slowptr == fastptr)
			return true;
	}
	return false;
}

int main()
{
	/* Start with the empty list */
	heapIdx = 0;
	struct Node* head = getNode();

	push(head, 20);
	push(head, 4);
	push(head, 15);
	push(head, 10);

	/* Create a loop for testing */
	head->next->next->next->next->next = head;

	if (detectLoop(head))
		cout << "Loop found";
	else
		cout << "No Loop";
	getchar();
	return 0;
}