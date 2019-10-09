#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> completeDays;
    auto size = progresses.size();
    for (auto i = 0; i < size; ++i) {
        int daysCompleted = 0;
        while (progresses[i] < 100) {
            progresses[i] += speeds[i];
            daysCompleted++;
        }
        completeDays.push(daysCompleted);
    }

    int numsFinished = 1;
    int dayFinished = completeDays.front();
    completeDays.pop();
    while (!completeDays.empty()) {
        int frt = completeDays.front();
        if (completeDays.front() <= dayFinished) {
            numsFinished++;
            completeDays.pop();
        } else {
            answer.push_back(numsFinished);
            numsFinished = 1;
            dayFinished = completeDays.front();
            completeDays.pop();
        }
    }
    answer.push_back(numsFinished);
    return answer;
}