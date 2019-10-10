#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    auto it = prices.begin();
    while (it != prices.end()) {
        auto sit = it;
        int temp = 0;
        while (sit != prices.end()) {
            if (*sit < *it) {
                break;
            } else {
                sit++;
			}
		}
        answer.push_back(sit - it);
        it++;
	}
    return answer;
}