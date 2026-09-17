#include <iostream>
#include "LinkList.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int initNum;
    cin >> initNum;
    int temp;

    cin >> temp;

    CircleLinkList list;
    while (initNum--) {
        cin >> temp;
        list.insert(temp);
    }

    int totalRunTime;
    cin >> totalRunTime;
    
    int command;
    for (int i = 0; i < totalRunTime; i++)
    {
        cin >> command;
        switch (command) {
        case 1:
                cin >> temp;
                cin >> command;
                list.insertIndex(temp, command);
            case 2:
                cin >> temp;
                list.remove(temp);
            case 3:
                cin >> temp;
                list.print(temp);
        }
    }
    return 0;
}