#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int> > baseball) {
    int answer = 0;
    auto size = baseball.size();
    string num1 = "";
    string num2 = "";
    bool isAns;
    int no_strike, no_ball;
    for (int candidate = 123; candidate <= 987; ++candidate) {
        num1 = to_string(candidate);
        if (num1[1] == '0' || num1[2] == '0') continue;
        if (num1[0] == num1[1] || num1[0] == num1[2] || num1[1] == num1[2]) continue;

        isAns = true;
        for (int i = 0; i < size; ++i) {
            no_strike = 0;
            no_ball = 0;
            num2 = to_string(baseball[i][0]);
            for (int a = 0; a < 3; ++a) {
                for (int b = 0; b < 3; ++b) {
                    if (a == b && num1[a] == num2[b]) {
                        no_strike++;
                        continue;
                    }
                    if (a != b && num1[a] == num2[b]) {
                        no_ball++;
                        continue;
                    }
                }
            }
            if (no_strike != baseball[i][1] || no_ball != baseball[i][2]) {
                isAns = false;
                break;
            }
        }

        if (isAns) 
            answer++;
    }
    return answer;
}

int main() {
    vector<vector<int > > baseball = {
        {123, 1, 1}, {356, 1, 0}, {327, 2, 0}, {489, 0, 1}
    };
    solution(baseball);
}