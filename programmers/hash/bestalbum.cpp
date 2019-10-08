#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int>& lhs, const pair<int, int>& rhs) {
    if (lhs.first < rhs.second) return true;
    if (lhs.first == rhs.first && lhs.second > rhs.second) return true;
    return false;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> total_score;
    map<int, string> temp;
    map<string, vector< pair<int, int> > > group_by_genres;
    auto size = genres.size();
    for (auto i = 0; i < size; ++i) {
        auto gn = genres[i];
        auto pl = plays[i];
        total_score[gn] += pl;
        group_by_genres[gn].push_back({pl, i});
    }

    for (auto ts : total_score) {
        temp[ts.second] = ts.first;
    }

    for (auto it = group_by_genres.begin(); it != group_by_genres.end(); ++it) {
        sort(it->second.begin(), it->second.end(), compare);
    }

    for (auto it = temp.rbegin(); it != temp.rend(); ++it) {
        auto sit = group_by_genres[it->second].begin();
        auto bg = group_by_genres[it->second].begin();
        while (sit != group_by_genres[it->second].end() && sit - bg < 2) {
            answer.push_back(sit->second);
            sit++;
        }
    }

    return answer;
}