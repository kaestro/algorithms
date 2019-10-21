#include <string>
#include <vector>
#include <iostream>

using namespace std;

// compress input with given unit length.
// early termination when compressed string becomes longer than min_length and return min_length
// min_length is the length of currently shortest compressed string
int compressed_string_length_by_unit(const string& input, int unit_length, int min_length);

int solution(string input) {
    int input_length = input.length();
    int min_length = input_length;
    for (auto unit_length = 1; unit_length <= input_length / 2; ++unit_length) {
        int cur_length = compressed_string_length_by_unit(input, unit_length, min_length);
        min_length = min(cur_length, min_length);
    }

    return min_length;
}

int compressed_string_length_by_unit(const string& input, int unit_length, int min_length)
{
    int cur_length = unit_length; // current length of compressed string
    int input_length = input.length();
    int num_unit_repeated = 1;

    string cur_substr = input.substr(0, unit_length);
    for (auto str_index = unit_length; cur_length < min_length && str_index < input_length; str_index += unit_length)
    {
        if (str_index + unit_length > input_length) 
        {
            cur_length += (input_length - str_index);
            break;
        }

        string next_substr = input.substr(str_index, unit_length);
        if (cur_substr != next_substr) 
        {
            cur_length += unit_length;
            cur_substr = next_substr;
            num_unit_repeated = 1;
        } else {
            num_unit_repeated += 1;
            switch (num_unit_repeated)
            {
                case 2: cur_length++; break;
                case 10: cur_length++; break;
                case 100: cur_length++; break;
            }
        }
    }
    return cur_length;
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