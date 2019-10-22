#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    queue<int> finishedDays;

    auto size = progresses.size();
    for (auto i = 0; i < size; ++i) {
        int finished_day = (100 - progresses[i] + speeds[i] - 1) / speeds[i]; // round up operation
        finishedDays.push(finished_day);
    }

    while (!finishedDays.empty()) {
        int numFlush = 1;
        int firstFinishedDay = finishedDays.front();
        finishedDays.pop();

        while (firstFinishedDay >= finishedDays.front() && !finishedDays.empty()) {
            finishedDays.pop();
            numFlush++;
        }
        answer.push_back(numFlush);
    }
    return answer;
}
