#include <string>
#include <iostream>

using namespace std;

const int no_chars = 256;

class Solution {
private:
    int hash_str[no_chars] = {0}, hash_pat[no_chars] = {0};

    void set_hash_pat(string t) {
        for (auto c : t) {
            ++hash_pat[c];
        }
    }
public:
    string minWindow(string str, string pat) {
        int len_pat = pat.length();
        int len_str = str.length();
        if (len_pat == 0) return pat;

        set_hash_pat(pat);

        int cnt_matches = 0;
        int start_idx = 0, min_length = len_str + 1;
        int ans_start_idx = 0;
        for (int i = 0; i < len_str; ++i) {
            int char_idx = str[i];
            ++hash_str[char_idx];

            if (hash_pat[char_idx] != 0 && hash_str[char_idx] <= hash_pat[char_idx]) {
                ++cnt_matches;
            }

            if (cnt_matches == len_pat) {
                while (1) {
                    int first_char_idx = str[start_idx];
                    if (hash_pat[first_char_idx] == 0) {
                        ++start_idx;
                    } else {
                        int cur_length = i - start_idx + 1;
                        if (cur_length < min_length) {
                            ans_start_idx = start_idx;
                            min_length = cur_length;
                        }
                        ++start_idx; --hash_str[first_char_idx];

                        if (hash_str[first_char_idx] + 1 == hash_pat[first_char_idx]) {
                            --cnt_matches;
                            break;
                        }
                    }
                }
            }
        }
        if (min_length == len_str+1) return pat;
        else return str.substr(ans_start_idx, min_length);
    }
};

int main() {
    string str = "ADOBECODEBANC", pat = "ABC";
    Solution s;
    str = "a", pat = "aa";
    cout << s.minWindow(str, pat) << endl;
    
    return 0;
}