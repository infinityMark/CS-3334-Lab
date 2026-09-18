#include <iostream>
#include <string>
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

// main
void reverseString(string& str) {
	int left = 0, right = str.length() - 1;
	while (left < right) {
		swap(str[left], str[right]);
		left++;
		right--;
	}
}

string process(string str) {
	int length = str.length();
	if (length == 1) return str;
	// else

	Stack stack; // store the each char of str as ASCII decimal valeu
	stack.push(int(str[0]));

	for (int i = 1; i < length; i++) {
		if (str[i] <= stack.top()) {
			stack.push(str[i]);
			continue;
		}
		// else
		while(!stack.isEmpty() && str[i] > stack.top())
			stack.pop();
		stack.push(str[i]);
	}

	string reversedStr = "";
	while (!stack.isEmpty()) {
		reversedStr += stack.top();
		stack.pop();
	}

	reverseString(reversedStr);
	return reversedStr;
}

int main() {
	string parameter;
	int testCase;
	cin >> testCase;

	while (testCase != 0) {
		cin >> parameter;
		cout << process(parameter) << endl;
		testCase--;
	}
	return 0;
}