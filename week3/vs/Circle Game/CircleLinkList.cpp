#include "LinkList.h"
#include <iostream>
using namespace std;

CircleLinkList::CircleLinkList() : first(nullptr), name("") {}
CircleLinkList::CircleLinkList(string n) : first(nullptr), name(n) {}
ListNode::ListNode(int value) : data(value), next(nullptr) {}
ListNode::ListNode(int value, ListNode* n) : data(value), next(n) {}

void CircleLinkList::insert(int n) {
	ListNode* newNode = new ListNode(n);

	if (first) {
		first = new ListNode(n);
		head = first;
		rear = first;
		rear->setNext(head);
		return;
	};

	// else case
	// no need update head
	ListNode* ptr = head;
	while (ptr->get_Next()) {
		ptr = ptr->get_Next();
	}
	ptr->setNext(newNode);
	rear = newNode;
	rear->setNext(head);
}

void CircleLinkList::insertIndex(int n, int d) {
	if (first == nullptr && d != 0) return;

	if (d == 0) {
		insert(n);
		return;
	}

	// assume 1
	ListNode* ptr = pointerIteration(n);

	// Not enough length
	//if (counter != d) { return; };

	ListNode* newNode = new ListNode(n);
	ListNode* prevNext = ptr->get_Next();
	ptr->setNext(newNode);
	newNode->setNext(prevNext);
	first = newNode;

	if (ptr == rear) {
		newNode = rear;
	}
}

void CircleLinkList::remove(int d) {
	if (d < 1) return;

	// remove head
	ListNode* ptr = pointerIteration(d);
}

void CircleLinkList::print(int i) {
	if (i < 1) { return; }

	ListNode* ptr = pointerIteration(i);
	first = ptr;

	cout << ptr->getData() << endl;
}

ListNode* CircleLinkList::pointerIteration(int aim) {
	ListNode* ptr = first;
	int counter = 1;

	while (counter != aim) {
		ptr = ptr->get_Next();
		counter++;
	}

	return ptr;
}