#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef pair< int, int > ii;

bool compare(const ii& lhs, const ii& rhs) {
    if (lhs.first > rhs.first) return true;
    if (lhs.first == rhs.first && lhs.second < rhs.second) return true;
    return false;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector< pair< int, int > > scores = {{0, 1}, {0, 2}, {0, 3}};
    vector< vector< int > > selections = {
        {1, 2, 3, 4, 5}, {2, 1, 2, 3, 2, 4, 2, 5}, {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
    };
    auto size = answers.size();
    for (auto i = 0; i < size; ++i) {
        for (auto j = 0; j < 3; ++j) {
            if (selections[j][i % selections[j].size()] ==  answers[i])
                scores[j].first++;
		}
	}
    
    sort(scores.begin(), scores.end(), compare);
    auto max = scores[0].first;
    auto it = scores.begin();
    while (it != scores.end()) {
        if (it->first == max) {
            answer.push_back(it->second);
            it++;
		} else{
            break;
        }
	}
    
    
    return answer;
}