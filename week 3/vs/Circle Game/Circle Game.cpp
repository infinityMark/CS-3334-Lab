//#include <iostream>
#include "CircleLinkList.h"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int initNum; // can use again
    cin >> initNum;

    int temp;    // can use again

    CircleLinkList list;
    while (initNum--) {
        cin >> temp;
        list.insert(temp);
    }

    int totalRunTime;
    cin >> totalRunTime;
    
    //int initNum;
    for (int i = 0; i < totalRunTime; i++)
    {
        cin >> initNum;
        if (initNum == 1) {
            cin >> temp;
            cin >> initNum;
            list.insertIndex(temp, initNum);
        } else if (initNum == 2) {
            cin >> temp;
            list.remove(temp);
        } else if (initNum == 3) {
            cin >> temp;
            list.print(temp);
        }
    }
    return 0;
}