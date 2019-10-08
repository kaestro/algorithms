#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    auto size = phone_book.size();
    for (auto i = 0; i < size; ++i) {
        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size()))
            return true;
    }
    return answer;
}