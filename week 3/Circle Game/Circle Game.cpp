#include <iostream>
#include <LinkNode.h>
#include <LinkList.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int initNum;
    cin >> initNum;
    int temp;

    cin >> temp;
    
    ListNode* firstNode = new ListNode(temp);
	initNum--;
    while (initNum--){
        cin >> temp;
    }
	return 0;
}