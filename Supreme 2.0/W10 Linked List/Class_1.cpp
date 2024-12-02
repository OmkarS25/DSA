#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;

	Node()
	{
		this->data = 0;
		this->next = NULL;
	}
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
	Node(int data, Node *next)
	{
		this->data = data;
		this->next = next;
	}
};

void print(Node *head)
{

	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}

int findLength(Node *&head)
{
	int len = 0;
	Node *temp = head;
	while (temp != NULL)
	{
		temp = temp->next;
		len++;
	}
	return len;
}

// I want to insert a node right at the head of Linked List
void insertAtHead(Node *&head, Node *&tail, int data)
{
	// check for Empty LL
	if (head == NULL)
	{
		// empty LL wala case
		// step1: creation of node
		Node *newNode = new Node(data);
		// step2: update head and tail
		head = newNode;
		tail = newNode;
	}
	else
	{
		// non-empty LL wala case
		// step1: creation of node
		Node *newNode = new Node(data);
		// step2: connect with head node
		newNode->next = head;
		// step3: update head
		head = newNode;
	}
}

// I want to insert a node right at the end of LINKED LIST
void insertAtTail(Node *&head, Node *&tail, int data)
{
	if (head == NULL)
	{
		// empty LL wala case
		// step1: creation of node
		Node *newNode = new Node(data);
		// step2: update head and tail
		head = newNode;
		tail = newNode;
	}
	else
	{
		// non-empty LL wala case
		// step1: creatae a node
		Node *newNode = new Node(data);
		// step2: connect woth tail ndoe
		tail->next = newNode;
		// step3: update tail;
		tail = newNode;
	}
}

void createTail(Node *&head, Node *&tail){
	if(!head) return;
	tail = head;
	while(tail->next != NULL){
		tail = tail->next;
	}
	// jab while loop khatam hoga to tail last node pe hoga
}

void insertAtPosition(int data, int position, Node *&head, Node *&tail)
{
	// assumption: position ki value [1 to len+1] tak hogi
	int len = findLength(head);

	if (position == 1)
	{
		insertAtHead(head, tail, data);
		return;
	}
	else if (position > len)
	{
		insertAtTail(head, tail, data);
		return;
	}
	else
	{
		// insert at the middle of linked list

		// step 1: create a new node
		Node *newNode = new Node(data);
		// step2: travese to the position-1 node
		Node *prev = NULL;
		Node *curr = head;
		while (position != 1)
		{
			position--;
			prev = curr;
			curr = curr->next;
		}

		// step3: connect the new node
		newNode->next = curr;

		// step4: connect the previous node
		prev->next = newNode;
	}
}

void insertInMiddle(int data, int pos, Node *head){
	for(int i=1; i<pos-1; i++){
		head = head->next;
	}
	head->next = new Node(data, head->next);
}

int main()
{
	// // Creation of node
	// Node *a;
	// Node *first = new Node(10);
	// Node *second = new Node(20);
	// Node *third = new Node(30);
	// Node *fourth = new Node(40);
	// Node *fifth = new Node(50);

	// // Linking of nodes
	// first->next = second;
	// second->next = third;
	// third->next = fourth;
	// fourth->next = fifth;

	Node *head = NULL;
	Node *tail = NULL;
	insertAtHead(head, tail, 20);
	insertAtHead(head, tail, 50);
	insertAtHead(head, tail, 60);
	insertAtHead(head, tail, 90);
	// insertAtTail(head, tail, 77);
	insertInMiddle(33, 2, head);

	print(head);
	cout << endl;

	return 0;
}
