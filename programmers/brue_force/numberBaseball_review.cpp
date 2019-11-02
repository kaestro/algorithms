#include <string>
#include <vector>

using namespace std;

int solution(vector< vector< int > > baseball) {
    int answer = 0;
    auto size = baseball.size();
    string num1 = "", num2 = "";
    bool isAns;
    int no_strikes, no_ball;
    for (int candidate = 123; candidate <= 987; ++candidate) {
        num1 = to_string(candidate);
        if (num1[1] == '0' || num1[2] == '0') continue;
        if (num1[0] == num1[1] || num1[0] == num1[2] || num1[1] == num1[2]) continue;

        isAns = true;
        for (auto bn = 0; bn < size; ++bn) {
            no_strikes = no_ball = 0;
            num2 = to_string(baseball[bn][0]);
            for (int lidx = 0; lidx < 3; ++lidx) {
                for (int ridx = 0; ridx < 3; ++ridx) {
                    if (lidx == ridx && num1[lidx] == num2[ridx]) {
                        no_strikes++;
                        continue;
                    }
                    if (lidx != ridx && num1[lidx] == num2[ridx])  {
                        no_ball++;
                        continue;
                    }
                }
            }

            if (no_strikes != baseball[bn][1] || no_ball != baseball[bn][2]) {
                isAns = false;
                break;
            }
        }

        if (isAns)
            answer++;
    }
    return answer;
}