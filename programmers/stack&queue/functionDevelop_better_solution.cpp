#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    queue<int> finishedDays;

    auto size = progresses.size();
    for (auto i = 0; i < size; ++i) {
        int remnant = (100 - progresses[i]) % speeds[i];
        int quotient = (100 - progresses[i]) / speeds[i];
        if (remnant == 0)
            finishedDays.push(quotient);
        else
            finishedDays.push(quotient + 1);
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
}