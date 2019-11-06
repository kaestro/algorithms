#include <vector>
#include <algorithm>
#include <iostream>


std::vector<int> time_withdrawl;

void read();
int solution();

int main() {
    read();
    std::cout << solution() << std::endl;
}

void read() {
    int size;
    std::cin >> size;
    time_withdrawl.resize(size);
    for (int i = 0; i < size; ++i) {
        std::cin >> time_withdrawl[i];
    }
}

int solution() {
    int size = time_withdrawl.size();
    int answer = 0;
    sort(std::begin(time_withdrawl), std::end(time_withdrawl));
    for (int i = size; i > 0; --i) {
        answer += i * time_withdrawl[size - i];
    }
    return answer;
}