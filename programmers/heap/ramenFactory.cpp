#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    priority_queue<int> pq;
    auto size = dates.size();
    int lastDate = 0;
    while (stock <= k) {
        answer++;
        while (lastDate < size && dates[lastDate] <= stock) {
            pq.push(supplies[lastDate++]);
        }
        stock += pq.top();
        pq.pop();
    }

    return answer;
}

int main() {
    int stock = 4;
    vector<int> dates = {4, 10, 15};
    vector<int> supplies = {20, 5, 10};
    int k = 30;
    cout << solution(stock, dates, supplies, k) << endl;
}