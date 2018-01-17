class MinStack {
private:
    stack<int> buffer;
    stack<int> minBuffer;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        if (buffer.empty() || x <= minBuffer.top()){ 
            minBuffer.push(x);
        }
        buffer.push(x);
    }
    
    void pop() {
        int val = buffer.top();
        buffer.pop();
        if (val == minBuffer.top()) minBuffer.pop();
    }
    
    int top() {
        return buffer.top();
    }
    
    int getMin() {
        return minBuffer.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
