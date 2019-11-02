#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef pair< int, int > ii;
typedef priority_queue< ii > myQueue;

class Compare {
 public:
    bool operator()(const ii& lhs, const ii& rhs) const {
        if (lhs.first > rhs.first) return true;
        if (lhs.first == rhs.first && lhs.second < rhs.second) return true;
        return false;
    }
};

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int size = dates.size();
    myQueue left;
    priority_queue<int> nextSupply;
    for (auto i = 0; i < size; ++i) {
        left.push({dates[i], supplies[i]});
    }
    while (stock < k) {
        while (!left.empty() && left.top().first <= stock) {
            nextSupply.push(left.top().second);
            left.pop();
        }
        stock += nextSupply.top();
        nextSupply.pop();
        answer++;
    }
    return answer;
}