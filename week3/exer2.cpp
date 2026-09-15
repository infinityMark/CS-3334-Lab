void reverse(i, j){
    if (!first || i<0 || j<0) {return;}

    ListNode* ptr = first;
    ListNode* iPtr = nullptr;
    ListNode* jPtr = nullptr;
    ListNode* tempPtr1 = nullptr;
    ListNode* tempPtr2 = nullptr;
    int counter = -1;

    while (ptr){
        if (counter==i){
            iPtr = ptr;
        } else if (counter + 1 == j){
            tempPtr2 = ptr;
            tempPtr1 = ptr->getNext()->getNext();
            ptr.setNext(iPtr);
            iptr.setNext(jPtr);
        }
        ptr = ptr->getNext();
        counter+;
    }
    
    ListNode* ptr = first;
    for (int c = -1; c<i; c++){
        if (c+1==i){
            tempPtr1 = ptr->getNext()->getNext();
            ptr->setNext(jPtr);
            jptr->setNext(tempPtr1);
        }
    }
}