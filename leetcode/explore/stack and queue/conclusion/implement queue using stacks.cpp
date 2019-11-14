#include <stack>

class MyQueue {
private:
    std::stack<int> left_stack, right_stack;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while (!left_stack.empty()) {
            auto top = left_stack.top(); left_stack.pop();
            right_stack.push(top);
        }
        left_stack.push(x);
        while (!right_stack.empty()) {
            auto top = right_stack.top(); right_stack.pop();
            left_stack.push(top);
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int top = left_stack.top();
        left_stack.pop();

        return top;
    }
    
    /** Get the front element. */
    int peek() {
        if (!left_stack.empty()) return left_stack.top();
        else return -1;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return left_stack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */