#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> answer;
    for (auto it = participant.begin(); it != participant.end(); ++it) {
        auto temp = answer.find(*it);
        if (temp != answer.end()) {
            temp->second++;
        } else {
            answer[*it] = 1;
        }
    }
    for (auto it = completion.begin(); it != completion.end(); ++it) {
        auto temp = answer.find(*it);
        if (temp->second == 1) answer.erase(temp);
        else temp->second--;
    }
    return answer.begin()->first;
}