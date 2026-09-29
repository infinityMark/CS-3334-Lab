#include <iostream>
using namespace std;

// ListNode
class ListNode{
public:
	ListNode(int);
	ListNode(int d, ListNode* n);

	int getData();
	void setNext(ListNode* n);
	ListNode* getNext();
private:
	int data;
	ListNode* next;
};

ListNode:: ListNode(int d) : data(d), next(nullptr) {};
ListNode:: ListNode(int d, ListNode* n) : data(d), next(n) {};
int ListNode:: getData() { return data; };
void ListNode::setNext(ListNode* n) { next = n; };
ListNode* ListNode::getNext() { return next; };

// Queue
class Queue {
public:
	Queue();

	bool isEmpty();
	void enqueue(int);
	int dequeue();
	int top();
private:
	ListNode* head;
	ListNode* rear;
};

Queue::Queue() { head = nullptr; rear = nullptr; };
bool Queue::isEmpty() { return head == nullptr; };
void Queue::enqueue(int d) {
	ListNode* newNode = new ListNode(d);
	if (isEmpty()) {
		head = newNode;
		rear = head;
		return; 
	} // else;

	rear->setNext(newNode);
	rear = newNode;
}
int Queue::dequeue() {
	if (isEmpty()) return -1;
	// else
	int result = head -> getData();

	// single
	if (head == rear) {
		head = nullptr;
		rear = nullptr;
		return result;
	}

	ListNode* deleteNode = head;
	head = head->getNext();

	delete deleteNode;
	return result;
}

int Queue::top() {
	if (isEmpty()) return -1;
	// else
	return head->getData();
}
// main

void process(){
    
}

int main(){
    int testingCase;
    while(testingCase--){
        process();
    }
    return 0;
}