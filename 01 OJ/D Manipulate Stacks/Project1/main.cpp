#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Node part;
class ListNode {
public:
	ListNode(int d);
	ListNode(int d, ListNode* n);
	ListNode* get_Next();
	void setNext(ListNode* n);
	int getData();
private:
	int data;
	ListNode* next;
};

ListNode::ListNode(int d) : data(d), next(nullptr) {}

ListNode::ListNode(int d, ListNode* n) : data(d), next(n) {}

ListNode* ListNode::get_Next() { return next; }

void ListNode::setNext(ListNode* n) { next = n; }

int ListNode::getData() { return data; }

// Stack part
class Stack {
public:
	Stack();
	void push(int ele);
	void pop();
	int top();
	bool isEmpty();
private:
	ListNode* head;
};

Stack::Stack() { head = nullptr; };

bool Stack::isEmpty() { return head == nullptr; }

void Stack::push(int ele) {
	if (isEmpty()) {
		ListNode* newNode = new ListNode(ele);
		head = newNode;
		return;
	}
	// else
	ListNode* newNode = new ListNode(ele, head);
	head = newNode;
}

void Stack::pop() {
	if (isEmpty()) return;

	ListNode* removeNode = head;

	// single element
	if (!head->get_Next()) {
		delete removeNode;
		head = nullptr; // empty the stack
		return;
	}

	// more than 1
	head = head->get_Next();
	delete removeNode;
}

int Stack::top() { return head->getData(); };

// Manipulate Stacks
string process(vector<int> source, vector<int> arr) {
	// pass the stack by pass by value
	vector<int> simulateArr;
	Stack S;
	Stack A;
	for (int i = 0; i < (int)source.size(); i++) {
		A.push(source[i]);
	}

	// 1 2 3 4 5
	// 1 5 4 2 3
	// 3 2 1 4 5
	int j = 0;
	while (j < (int)arr.size()) {
		if (!S.isEmpty() && S.top() == arr[j]) {
			simulateArr.push_back(S.top());
			S.pop();
			j++;
		}
		else if (!A.isEmpty()) {
			S.push(A.top());
			A.pop();
		}
		else {
			return "Impossible";
		}
	}
	return "Aye";
}

void writeVector(vector<int>& arr, int element) {
	while (element--) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
}

int main() {
	int testCases;
	int numOfA;
	int operateTime;
	int lengthOfVector;

	vector<int> simulateStackA;

	cin >> testCases;	//1

	while (testCases != 0) {
		cin >> numOfA;	//5
		lengthOfVector = numOfA;

		// initialize stcak
		writeVector(simulateStackA, lengthOfVector);

		cin >> operateTime;	// 3 total run time of permutation
		while (operateTime--) {
			vector<int> permutation;
			
			writeVector(permutation, lengthOfVector);

			cout << process(simulateStackA, permutation) << endl;

			permutation.clear();
		}
		testCases--;
	}

	return 0;
}