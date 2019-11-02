#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map< string, vector< string > >  result;
    for (auto vs : clothes) {
        result[vs[1]].push_back(vs[0]);
    }
    for (auto vs : result) {
        answer *= (vs.second.size() + 1);
    }
    return answer - 1;
}