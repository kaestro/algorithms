#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const int& lhs, const int& rhs) {
    string left = to_string(lhs);
    string right = to_string(rhs);
    return left + right > right + left;
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), compare);
    if (numbers[0] == 0) return to_string(0);
    answer.reserve(numbers.size() * 3);
    for (auto n : numbers) {
        answer += to_string(n);
	}
    return answer;
}

int main() {
    int a = 30, b = 3;
    compare(a, b);

    return 0;
}