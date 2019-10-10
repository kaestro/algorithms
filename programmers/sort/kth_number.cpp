#include <string>
#include <vector>
#include <algorithm>

#define tr(it, container) for (auto it = container.begin(); \
                                it != container.end(); ++it)

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    tr (it, commands) {
        auto sit = array.begin();
        auto temp = vector< int >(sit + (*it)[0] - 1, sit + (*it)[1]);
        sort(temp.begin(), temp.end());
        answer.push_back(temp[(*it)[2] - 1]);
    }
    
    return answer;
}

int main() {
    vector< int > array = {1, 5, 2, 6, 3, 7, 4};
    vector< vector <int> > commands = { {2, 5, 3}, {4, 4, 1}, {1, 7, 3} };

    solution(array, commands);

    return 0;
}