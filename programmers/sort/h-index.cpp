#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const int& lhs, const int& rhs) {
    string left = to_string(lhs);
    string right = to_string(rhs);
    int l_length = left.length();
    int r_length = right.length();
    if (l_length == r_length) {
        return left > right;
	} else {
        auto min_length = min(l_length, r_length);
        if (left.substr(0, min_length) != right.substr(0, min_length)) {
            return left > right;
		} else {
            bool left_gt = l_length > r_length;
            if (left_gt) {
                return left[min_length] > left[0];
			} else {
                return right[min_length] > right[0];
            }
		}
	}
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), compare);
    answer.reserve(numbers.size() * 3);
    for (auto n : numbers) {
        answer += to_string(n);
	}
    return answer;
}