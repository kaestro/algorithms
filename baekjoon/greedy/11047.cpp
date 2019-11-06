#include <iostream>
#include <vector>

std::vector<int> coins;

int goal_money;

void read();
int solution();

int main() {
    read();
    std::cout << solution() << std::endl;
}

void read() {
    int size;
    std::cin >> size >> goal_money;
    coins.resize(size);
    for (int i = 0; i < size; ++i) {
        std::cin >> coins[i];
    }
}

int solution() {
    int num_coins = 0;
    for (auto rit = coins.crbegin(); rit != coins.crend(); ++rit)
    {
        // instead of using while loop, this is much more efficient
        num_coins += (goal_money)/(*rit);
        goal_money %= (*rit);
    }
    return num_coins;
}