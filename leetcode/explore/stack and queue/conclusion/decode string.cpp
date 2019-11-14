#include <string>
#include <stack>
#include <algorithm>

class Solution {
 private:
    std::stack<char> stored;
 public:
    std::string decodeString(std::string s) {
        for (auto letter : s) {
            if (letter == ']') {
                std::string str = "";
                while (!stored.empty()) {
                    auto top = stored.top(); stored.pop();
                    if (top != '[') {
                        str += top;
                    } else {
                        std::reverse(str.begin(), str.end());
                        break;
                    }
                }

                std::string str_cnt = "";
                int cnt = 0;
                while (!stored.empty()) {
                    auto top = stored.top(); stored.pop();
                    if (top >= '0' && top <= '9') {
                        str_cnt += top;
                    } else {
                        stored.push(top);
                        break;
                    }
                }
                std::reverse(str_cnt.begin(), str_cnt.end());
                cnt = stoi(str_cnt);

                std::string created = "";
                for (int i = 0; i < cnt; ++i) {
                    created += str;
                }

                for (auto cletter : created) {
                    stored.push(cletter);
                }
            } else {
                stored.push(letter);
            }
        }

        std::string ans = "";
        while (!stored.empty()) {
            ans += stored.top(); stored.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution s;
    std::string input = "3[a2[c]]";
    auto ans = s.decodeString(input);
    return 0;
}