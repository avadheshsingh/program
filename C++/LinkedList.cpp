//linked List

#include<iostream>
using namespace std;

struct Node {
	struct Node* next;
	int value;
};
static struct Node Heap[1000];
static int heapIdx;
struct Node* root;

struct Node* getNode(int Key) {
	struct Node* temp = &Heap[heapIdx++];
	temp->next = NULL;
	temp->value = Key;
	return temp;
}

void insertFront(struct Node* root, int key) {
	struct Node* temp = root;
	struct Node* newNode = getNode(key);
	if (root->next == NULL)
		root->next = newNode;
	else {
		newNode->next = root->next;
		root->next = newNode;
	}

}

void deleteFront(struct Node* root) {
	struct Node* temp = root;
	if (temp->next == NULL)
		return;
	else {
		temp->next = temp->next->next;
	
	}

}

void insertBack(struct Node* root, int key) {
	struct Node* temp = root;
	struct Node* newNode = getNode(key);
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = newNode;

}

void deleteBack(struct Node* root) {
	struct Node* temp = root;
	if (temp->next == NULL)
		return;

	while (temp->next->next != NULL)
		temp = temp->next;
	temp->next = NULL;
}

void print(struct Node* root) {
	struct Node* temp = root->next;
	while (temp!= NULL) {
		cout << temp->value << " ";
		temp = temp->next;
	}
}
void init() {
	heapIdx = 0;
	root = getNode(0);
}

int main() {
	//struct Node* root;
	init();

	int i, k;
	cin >> i;
	while (i) {
		switch (i) {
		case 1:
			cout << "inserting node at front:- ";
			cin >> k;
			insertFront(root, k);
			break;
		case 2:
			cout << "inserting node at back:- ";
			cin >> k;
			insertBack(root, k);
			break;
		case 3:
			cout << "deleting at front..!! ";
			deleteFront(root);
			break;
		case 4:
			cout << "deleting at back..!! ";
			deleteBack(root);
			break;
		case 5:
			cout << "print:- ";
			print(root);
			break;
		default:
			cout << "check";
		}
		cout << "enter your choice:-";
		cin >> i;
	}
	return 0;
}

