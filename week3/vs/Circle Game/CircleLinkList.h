#pragma once
#include "ListNode.h"
#include <string>
#include <iostream>
using namespace std;

class CircleLinkList {
public:
    CircleLinkList();
    CircleLinkList(string n);
    void insertIndex(int i, int d);
    void insert(int i);
    void remove(int d);
    void print(int i);
    void pointerIteration(int aim);
    
    void increaselengths();
    void decreaselengths();
private:
    ListNode* first;
    ListNode* head;
    ListNode* rear;
    string name;
    int lengths;
};