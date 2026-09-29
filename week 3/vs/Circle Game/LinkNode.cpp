#include "ListNode.h"

ListNode::ListNode(int d) : data(d), next(nullptr) {}

ListNode::ListNode(int d, ListNode* n) : data(d), next(n) {}

ListNode* ListNode::get_Next() { return next; }

void ListNode::setNext(ListNode* n) { next = n; }

int ListNode::getData() { return data; }