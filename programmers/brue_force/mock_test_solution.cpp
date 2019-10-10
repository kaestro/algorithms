#include <string>
#include <vector>
#include <algorithm>

#define tr(it, container) for (auto it = container.begin();\
                            it != container.end(); ++it)

using namespace std;

typedef vector< int > vi;

vector< int > solution(vector< int > answers) {
    vector< int > answer;
    vi scores = {0, 0, 0};
    vector< vi > choices = {
        {1,2,3,4,5}, {2,1,2,3,2,4,2,5}, {3,3,1,1,2,2,4,4,5,5}
    };
    vi sizes;
    sizes.reserve(choices.size());
    tr (it, choices) {
        sizes.push_back(it->size());
    }

    auto ans_size = answers.size();
    for (auto i = 0; i < ans_size; ++i) {
        for (auto j = 0; j < choices.size(); ++j) {
            if (answers[i] == choices[j][i % sizes[j]])
                scores[j]++;
        }
    }
    auto max_score = max(scores.begin(), scores.end());
    for (auto i = 0; i < scores.size(); ++i) {
        if (*max_score == scores[i]) {
            answer.push_back(i);
        }
    }
    return answer;
}

int main() {
    vi answers = { 1, 2, 3, 4, 5 };
    solution(answers);
}