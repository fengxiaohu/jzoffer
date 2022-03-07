class CQueue {
public:
    CQueue() {
    stack<int,int> stack1;
    stack<int,int> stack2;
    }
    int size;
    void appendTail(int value) {
    if(stack1.szie()==0) 
    {
        stack2.push(value)
    }
    stack2.push(stack1.top())
    stack1.pop();
    stack1.push(value);

    }
    
    int deleteHead() {
    
    }
private:
    
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
