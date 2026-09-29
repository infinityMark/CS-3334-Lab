void insert(i, d){
    int counter = 0;
    ListNode* ptr = first;

    while (prt && counter !=i){
        prt = ptr->getNext();
    }
    ListNode* newNode = new ListNode(d, ptr->getNext());
    ptr.setNext(newNode);
}