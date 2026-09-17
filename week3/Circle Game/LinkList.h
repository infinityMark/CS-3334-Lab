// List.h
#ifndef LIST_H
#define LIST_H
#include "ListNode.h"
#include <string>
#include <iostream>
using namespace std;

class LinkList {
public:
    LinkList();
    LinkList(string n);
private:
    ListNode* head;
    string name;
};

#endif