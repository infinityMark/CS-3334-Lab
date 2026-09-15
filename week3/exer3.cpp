int searchPoint(Node*first1, Node *first2)
{
    if (!first) {return;}

    ListNode* searchPtr = first1;
    ListNode* ptr2= first2;

    while (searchPtr && ptr2){
        if (searchPoint->getData()==ptr2->getData()){
            return searchPoint.getData();
        }
        searchPtr = searchPtr->getNext();
        ptr2 = ptr2->getNext();
    } 
    return -1;
}

Node *intersectPoint(Node*first1, Node *first2)
{
    if (!first) {return first1;};

    ListNode* ptr1 = first1;
    ListNode* ptr2 = first2;

    int target = searchPoint(Node*first1, Node *first2);
    if (target==-1) {return first1;};

    while (ptr1){
        if(ptr1->getData()==target){
            break;
        }
        ptr1 = ptr1->getNext();
    }

    while (ptr2){
        if(ptr2->getData()==target){
            break;
        }
        ptr2 = ptr2->getNext();
    }

    ptr1->setNext(ptr2->getNext());
}