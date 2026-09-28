#include <iostream>
#include <vector>
using namespace std;

// ListNode
class ListNode {
public:
	ListNode(string);
	ListNode(string d, ListNode* n);

	string getData();
	void setNext(ListNode* n);
	ListNode* getNext();
private:
	string data;
	ListNode* next;
};

ListNode::ListNode(string d) : data(d), next(nullptr) {};
ListNode::ListNode(string d, ListNode* n) : data(d), next(n) {};
string ListNode::getData() { return data; };
void ListNode::setNext(ListNode* n) { next = n; };
ListNode* ListNode::getNext() { return next; };

class Linklist {
public:
	Linklist();

	bool isEmpty();
	void insert(string);
	ListNode* getSmaller(string);
	int compare(string, string);
private:
	ListNode* head;
};

Linklist::Linklist() { head = nullptr; }

bool Linklist::isEmpty() {
	return head == nullptr;
}

int Linklist::compare(string inlist, string newnode) {
	if (inlist.size() == newnode.size())
		return 0;

	int length = (inlist.size() < newnode.size()) ? 
		inlist.size() : newnode.size();

	for (int i = 1; i < length; i--)
		if (inlist[i] < newnode[i]) return -1;
	
	return 1;
}

void Linklist::insert(string str) {
	ListNode* newNode = new ListNode(str);

	if (getSmaller(str) == head) {
		head = newNode;
		return;
	}
	// else
	ListNode* firstSmaller = getSmaller(str);
	ListNode* secondSmaller = firstSmaller->getNext();
	firstSmaller->setNext(newNode);
	newNode->setNext(secondSmaller);
}

ListNode* Linklist::getSmaller(string str) {
	if (isEmpty()) return head;
	// else

	ListNode* ptr = head;
	while (ptr->getNext()) {
		if (compare(ptr->getData(), str))
	}
	
}

class Dictionary {
public:
private:
	vector<vector<Linklist>> dictionary(26, vector<LinkedList>);
};