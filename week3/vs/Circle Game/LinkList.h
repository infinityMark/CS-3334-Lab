#pragma once
#include "ListNode.h"
#include <string>
using namespace std;

class CircleLinkList {
public:
    CircleLinkList();
    CircleLinkList(string n);
    void insertIndex(int i, int d);
    void insert(int i);
    void remove(int d);
    void print(int i);
    ListNode* pointerIteration(int aim);
private:
    ListNode* first;
    ListNode* head;
    ListNode* rear;
    string name;
};