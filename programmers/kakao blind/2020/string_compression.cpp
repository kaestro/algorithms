#include <vector>
#include <string>
#include <iostream>

using namespace std;

int solution(string input) {
    int str_length, min_length;
    min_length = str_length = input.length();

    for (auto unit_length = 1; unit_length <= str_length / 2; ++unit_length)
    {
        size_t str_idx = 0;
        int compressed_length = str_length;
        while (str_idx < str_length)
        {
            string cur_string = input.substr(str_idx, unit_length);
            size_t next_idx = str_idx + unit_length;
            int repeated_cnt = 0;
            while (next_idx < str_length && cur_string == input.substr(next_idx, unit_length))
            {
                next_idx += unit_length;
                repeated_cnt += 1;
            }

            if (repeated_cnt != 0)
            {
                compressed_length += 1;
                compressed_length -= unit_length * repeated_cnt;
                str_idx = next_idx;
            } else {
                str_idx += 1;
            }
        }
        min_length = min(compressed_length, min_length);
    }

    return min_length;
}

int main() {
    vector<string> input = {
        "aabbaccc", "ababcdcdababcdcd", "abcabcdede",
        "abcabcabcabcdededededede", "xababcdcdababcdcd"
    };
    for (auto& s : input) {
        cout << solution(s) << endl;
    }
    return 0;
}