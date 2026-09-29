void reverseFirstK(int k, queue<int>& Queue){
    if (k<0) return;
    if (Queue.isEmpty()) return;

    stack<int> stack;
    int test;
    
    while (k--) {
        stack.push(Queue.dequeue());
        if (k==0) test = stack.top();
    }

    while (!stack.isEmpty()) {
        Queue.enque(stack.top());
        stack.pop();
    }

    while(Queue.top()!=test){
        Queue.enque(Queue.dequeue());
    }
}