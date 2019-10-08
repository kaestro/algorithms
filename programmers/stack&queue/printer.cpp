#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> qpriorities, qindexes;

    for (auto& pr : priorities) {
        qpriorities.push(pr);
    }
    auto size = priorities.size();

    for (int i = 0; i < size; ++i) {
        qindexes.push(i);
    }
    sort(priorities.begin(), priorities.end(), greater<int>());
    while (!qpriorities.empty()) {
        int nextPriority = qpriorities.front();
        int nextIndex = qindexes.front();
        if (nextPriority == priorities.front()) {
            answer++;
            qpriorities.pop();
            priorities.erase(priorities.begin());
            if (nextIndex == location) {
                break;
            }
            qindexes.pop();
        } else {
            qpriorities.push(nextPriority);
            qindexes.push(nextIndex);
            qindexes.pop();
            qpriorities.pop();
        }
    }
    return answer;
}

int main() {
    vector < int > priorities = {2, 1, 3, 2};
    int location = 2;
    cout << solution(priorities, location) << endl;
    priorities = {1, 1, 9, 1, 1, 1};
    location = 0;
    cout << solution(priorities, location) << endl;
}