#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<int> sorted_priorities;
    queue<int> printer;
    int size = priorities.size();

    for (auto i = 0; i < size; ++i) {
        printer.push(i);
    }
    sorted_priorities = priorities;
    sort(sorted_priorities.begin(), sorted_priorities.end(), greater<int>());
    while (!printer.empty()) {
        int nextIdx = printer.front();
        printer.pop();
        if (priorities[nextIdx] == sorted_priorities[0]) {
            answer++;
            sorted_priorities.erase(sorted_priorities.begin());
            if (nextIdx == location) break;
        } else {
            printer.push(nextIdx);
        }
    }
    return answer;
}