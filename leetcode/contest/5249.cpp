#include <string>
#include <stack>

using namespace std;

class Solution {
    stack<char> prior;
public:
    string minRemoveToMakeValid(string s) {
        string temp;
        for (auto letter : s) {
            if (letter != ')')
            {
                prior.push(letter);
            } else
            {
                temp = get_substring();
            }
            
        }
    }

    string get_substring();
};