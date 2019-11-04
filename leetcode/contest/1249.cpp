#include <stack>
#include <string>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
private:
    stack<int> lp_idxs;
    priority_queue<int, vector<int>, greater<int>> reject_idxs;
public:
    string minRemoveToMakeValid(string input) {
        for (auto i = 0; i < input.length(); ++i)
        {
            if (input[i] == '(') {
                lp_idxs.push(i);
            } else if (input[i] == ')') {
                if (lp_idxs.empty()) {
                    reject_idxs.push(i);
                } else {
                    lp_idxs.pop();
                }
            }
        }

        while (!lp_idxs.empty())
        {
            reject_idxs.push(lp_idxs.top());
            lp_idxs.pop();
        }

        string answer = "";

        for (auto i = 0; i < input.length(); ++i)
        {
            if (!reject_idxs.empty() && i == reject_idxs.top()) {
                reject_idxs.pop();
            } else {
                answer += input[i];
            }
        }

        return answer;
    }
};

int main() {
    Solution s;
    vector<string> inputs = {
        "lee(t(c)o)de)",  "a)b(c)d",  "))(("
    };

    for (auto input : inputs)
        cout << s.minRemoveToMakeValid(input) << endl;
    
    return 0;
}