#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> ropes;

void read();
int solution();

int main() {
    read();
    std::cout << solution() << std::endl;
    return 0;
}

void read() {
    int size;
    std::cin >> size;
    ropes.resize(size);

    for (int i = 0; i < size; ++i) {
        std::cin >> ropes[i];
    }

    sort(ropes.begin(), ropes.end());
}

int solution() {
    int max_wsum = -1;
    int ropes_size = ropes.size();

    for (auto i = 0; i < ropes_size; ++i) {
        max_wsum = std::max(max_wsum, ropes[i] * (ropes_size - i));
    }

    return max_wsum;
}