#include <string>
#include <vector>
#include <iostream>

using namespace std;

// return shortest substr is correct parenthesis string or not.
// return length of shortest left balanced substr
bool shortest_substr_type_and_length(const string& input, int& left_substr_length);
// flip left substring following given direction.
void run_correction(string& input);

string solution(string p) {
    if (p.length() == 0) return "";

    string answer = "";
    int left_substr_length;
    bool isCorrectSubstr;

    isCorrectSubstr = shortest_substr_type_and_length(p, left_substr_length);
    string left_substr = p.substr(0, left_substr_length);
    string right_substr = solution(p.substr(left_substr_length));
    if (isCorrectSubstr) {
        answer = left_substr + right_substr;
    } else {
        run_correction(left_substr);
        answer = "(" + right_substr + ")" + left_substr.substr(1, left_substr_length - 2);
    }

    return answer;
}

bool shortest_substr_type_and_length(const string& input, int& left_substr_length) {
    size_t no_left_par = 0, no_right_par = 0;
    size_t input_length = input.length();
    char left_par;
    if (input[0] == '(') left_par = '(';
    else left_par = ')';

    for (size_t i = 0; i < input_length; ++i)
    {
        if (input[i] == left_par) no_left_par++;
        else no_left_par--;

        if (no_left_par == 0) {
            left_substr_length = i + 1;
            break;
        }
    }

    return left_par == '(';
}

void run_correction(string& input) {
    int input_length = input.length();
    for (size_t i = 1; i < input_length - 1; ++i)
    {
        if (input[i] == '(') input[i] = ')';
        else input[i] = '(';
    }
}

int main() {
    vector< string > input = {
        "(()())()", ")(", "()))((()"
    };

    for (auto& s : input) {
        cout << solution(s) << endl;
    }
}