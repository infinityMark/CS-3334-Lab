#include <iostream>
//#include <array>
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
const int HIGHPRIORITY = 0;
const int LOWEPRIORITY = 1;

void output(int finishTime, bool remain) {
	cout << finishTime;
	if (remain) cout << " ";
}

void process(int testTime) {
	Queue highQueue;
	Queue highArrvialQueue;
	Queue loweQueue;
	Queue loweArrvialQueue;

	Queue manager;
	int* arr = new int[testTime]();
	int taskCounter = 0;

	int r, w, p;
	int currTime = 0;

	while (testTime--) {
		cin >> r;
		cin >> w;
		cin >> p;

		manager.enqueue(p);
		if (p == HIGHPRIORITY) {
			highQueue.enqueue(w);
			highArrvialQueue.enqueue(r);
			continue;
		}
		loweQueue.enqueue(w);
		loweArrvialQueue.enqueue(r);
	}

	while (!manager.isEmpty()) {
		if (!highQueue.isEmpty() && highArrvialQueue.top() <= currTime) {
			currTime += highQueue.dequeue();
			manager.dequeue();
			arr[taskCounter++] = currTime;
			continue;
		}
		else if (!loweQueue.isEmpty() && loweArrvialQueue.top() <= currTime) {
			currTime += loweQueue.dequeue();
			manager.dequeue();
			arr[taskCounter++] = currTime;
			continue;
		}
		currTime++;
	}
}

int main() {
	int testTime;

	while (true) {
		cin >> testTime;
		process(testTime);
		//break;
	}

	return 0;
}