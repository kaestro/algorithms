#include <queue>

class MyStack {
private:
    std::queue<int> left_queue, right_queue;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        while (!left_queue.empty()) {
            auto top = left_queue.front(); left_queue.pop();
            right_queue.push(top);
        }
        left_queue.push(x);
        while (!right_queue.empty()) {
            auto top = right_queue.front(); right_queue.pop();
            left_queue.push(top);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int top = left_queue.front();
        left_queue.pop();
        return top;
    }
    
    /** Get the top element. */
    int top() {
        return left_queue.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return left_queue.empty();
    }
};