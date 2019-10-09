#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

#define tr(it, container) for (auto it = container.begin(); \
                                it != container.end(); ++it)

using namespace std;

typedef pair< int, int > ii;

class Compare {
 public:
    bool operator()(const ii& lhs, const ii& rhs) {
        if (lhs.second > rhs.second) return true;
        return false;
    }
};

bool jobs_compare(const vector<int>& lhs, const vector<int>& rhs){
    if (lhs[0] < rhs[0]) return true;
    if (lhs[0] == rhs[0] && lhs[1] < rhs[1]) return true;
    return false;
}

typedef priority_queue< ii, vector<ii>, Compare > myQueue;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    auto size = jobs.size();
    myQueue input;
    sort(jobs.begin(), jobs.end(), jobs_compare);

    int time_now = 0;
    int no_finished = 0;
    int no_next = 0;
    while (no_finished < size) {
        while (no_next < size && jobs[no_next][0] <= time_now){
            input.push({jobs[no_next][0], jobs[no_next][1]});
            no_next++;
        }
        ii temp;
        if (!input.empty()) {
            temp = input.top();
            input.pop();
        } else {
            temp = {jobs[no_next][0], jobs[no_next][1]};
            no_next++;
        }
        int time_max = time_now > temp.first ? time_now : temp.first;
        time_now = time_max + temp.second;
        answer += (time_now - temp.first);
        no_finished++;
    }

    answer /= size;
    return answer;
}

int main() {
    vector< vector< int > > jobs = {
        {0, 3}, {1, 9}, {2, 6}
    };
    cout << solution(jobs) << endl;
}