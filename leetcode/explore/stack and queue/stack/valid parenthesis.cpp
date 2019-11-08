#include <stack>
#include <string>
#include <unordered_set>
#include <map>
#include <iostream>
#include <vector>

class Solution {
 private:
    std::stack<char> par_stack;
    const std::unordered_set<char> left_par = {'{', '[', '('};
    std::map<char, char> partner = { {'}', '{'}, {']', '['}, {')', '('} };
 public:
    bool isValid(std::string s) {
        char top_stack;
        for (auto letter : s) {
            if (left_par.find(letter) != left_par.end()) {
                par_stack.push(letter);
            } else {
                if (par_stack.empty()) return false;
                top_stack = par_stack.top();
                if (top_stack != partner[letter]) return false;
                else par_stack.pop();
            }
        }

        return par_stack.empty();
    }
};

int main() {
    std::vector<std::string> inputs = {
        "()", "()[]{}", "(]", "([)]", "{[]}"
    };

    for (auto input : inputs) {
        Solution s;
        if (s.isValid(input)) std::cout << "true" << input <<  std::endl;
        else std::cout << "false for " << input << std:: endl;
    }

    return 0;
}