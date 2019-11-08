#include <vector>
#include <string>
#include <stack>
#include <unordered_set>

class Solution {
 private:
    std::stack<int> integers;
    std::unordered_set<std::string> ops = {
        "+", "-", "*", "/"
    };
 public:
    int evalRPN(std::vector<std::string>& tokens) {
        for (auto token : tokens) {
            if (isOp(token)) {
                // TODO
                // get 2 value, calculate, store
                calculate(token);
            } else {
                integers.push(std::stoi(token));
            }
        }
    }
    inline bool isOp(std::string& token) {
        return ops.find(token) != ops.end();
    }

    void calculate(std::string& token) {
        int rhs = integers.top(); integers.pop();
        int lhs = integers.top(); integers.pop();
        if (token == "+") integers.push(lhs + rhs);
        else if (token == "-") integers.push(lhs - rhs);
        else if (token == "*") integers.push(lhs * rhs);
        else if (token == "/") integers.push(lhs / rhs);
    }
};

int main() {

    return 0;
}