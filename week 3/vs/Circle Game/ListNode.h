#pragma once

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