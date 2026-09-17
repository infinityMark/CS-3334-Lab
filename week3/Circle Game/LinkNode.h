#ifdef LISTNODE_H
#define LISTNODE_H

class ListNode{
public:
    ListNode(int);
    ListNode(int, ListNode*);
    ListNode* getNext() {return next;};
    int getData() {return data;};
    void setNext(ListNode* n) {next = n;};
private:
    int data;
    ListNode* next;
};

#endif