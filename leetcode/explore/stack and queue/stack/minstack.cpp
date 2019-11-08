#include <stack>
#include <iostream>

using ii = std::pair<int, int>;

class MinStack {
 private:
    std::stack<ii> mstack;
 public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if (mstack.empty()) {
            mstack.push({x, x});
        } else {
            int min_val = getMin();
            min_val = std::min(min_val, x);
            mstack.push({x, min_val});
        }
    }
    
    void pop() {
        if (!mstack.empty()) {
            mstack.pop();
        }
    }
    
    int top() {
        if (!mstack.empty()) {
            ii temp = mstack.top();
            return temp.first;
        }
    }
    
    int getMin() {
        if (!mstack.empty()) {
            ii temp = mstack.top();
            return temp.second;
        }
    }
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    std::cout << minStack.getMin() << std::endl;
    minStack.pop();
    std::cout << "{" << minStack.top() << "," << minStack.getMin() << std::endl;

    return 0;
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */