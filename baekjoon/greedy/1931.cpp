#include <algorithm>
#include <vector>
#include <iostream>

using ii = std::pair<int, int>;

std::vector<ii> meetings; 

void read();
int solution();
bool compare(const ii left, const ii right);

int main() {
    read();
    std::cout << solution()  << std::endl;
}

void read() {
    int size;
    std::cin >> size;
    meetings.resize(size);
    for (int i = 0; i < size; ++i) {
        std::cin >> meetings[i].first >> meetings[i].second;
    }
}

int solution() {
    std::sort(meetings.begin(), meetings.end(), compare);
    int end_time = -1;
    int num_meetings = 0;
    for (auto cit = meetings.cbegin(); cit != meetings.cend(); ++cit)
    {
        if (cit->first >= end_time) {
            end_time = cit->second;
            ++num_meetings;
        }
    }
    return num_meetings;
}

bool compare(const ii left, const ii right) {
    if (left.second < right.second) return true;
    if (left.second == right.second && left.first < right.first) return true;
    return false;
}