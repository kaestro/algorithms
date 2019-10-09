#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector< int >, greater<int>> pq;
    for (auto value : scoville) {
        pq.push(value);
    }
    while (pq.size() > 1 && pq.top() < K) {
        answer++;
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        pq.push(first + 2 * second);
    }
    if (pq.size() == 1) {
        if (pq.top() < K)
            answer = -1;
    }
    return answer;
}