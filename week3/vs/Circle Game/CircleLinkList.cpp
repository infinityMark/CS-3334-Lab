#include "CircleLinkList.h"
//#include <iostream>
//using namespace std;

CircleLinkList::CircleLinkList() : first(nullptr), name("") {
	lengths = 0;
}
CircleLinkList::CircleLinkList(string n) : first(nullptr), name(n) {}

void CircleLinkList::insert(int n) {
	ListNode* newNode = new ListNode(n);

	if (!first) {
		first = new ListNode(n);
		head = first;
		rear = first;
		rear->setNext(head);
		increaselengths();
		return;
	};

	// else case
	// no need update 
	rear->setNext(newNode);
	rear = newNode;
	rear->setNext(head);
	increaselengths();
}

void CircleLinkList::insertIndex(int n, int d) {
	if (first == nullptr && d != 1) return;

	/*if (d == 1) {
		insert(n);
		return;
	}*/

	// assume 1
	pointerIteration(n);
	ListNode* ptr = first;

	ListNode* newNode = new ListNode(n);
	ListNode* prevNext = ptr->get_Next();
	ptr->setNext(newNode); 
	newNode->setNext(prevNext);
	first = newNode;

	if (ptr == rear) {
		newNode = rear;
		newNode->setNext(head);
	}
	increaselengths();
}

void CircleLinkList::remove(int i) {
	if (i < 1) return;

	// remove current node
	if (i == 1) {
		ListNode* curNode = first;
		while (curNode->get_Next() != first)
			curNode = curNode->get_Next();
		first = curNode;
	}

	pointerIteration(i - 1); // stop before the node going to be delete
	ListNode* removeNode = first -> get_Next();
	first->setNext(removeNode->get_Next());
	
	// special case handle
	if (removeNode == head) {
		head = first->get_Next();
		rear->setNext(head);
	} else if (removeNode == rear) {
		rear = first;
		rear->setNext(head);
	}
	first = first->get_Next();
	delete removeNode;
	decreaselengths();
}

void CircleLinkList::print(int i) {
	if (i < 1) { return; }

	pointerIteration(i);

	cout << first->getData() << endl;
}

void CircleLinkList::pointerIteration(int aim) {
	if (aim == 0) { return; };

	int loop = (aim > this->lengths) ? aim % this->lengths : aim;
	int counter = 1;

	while (counter != loop) {
		first = first->get_Next();
		counter++;
	}
}

void CircleLinkList::increaselengths() {
	this->lengths++;
}

void CircleLinkList::decreaselengths() {
	this->lengths--;
}