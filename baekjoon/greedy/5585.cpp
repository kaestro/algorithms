#include <vector>
#include <iostream>

const int coins[6] = {500, 100, 50, 10, 5, 1};
const int paid = 1000;

int payment;

int solution();

int main() {
    std::cin >> payment;
    std::cout << solution() << std::endl;
    return 0;
}

int solution() {
    int change_left = paid - payment;
    int num_coins = 0;
    for (int i = 0; i < 6; ++i) {
        num_coins += (change_left / coins[i]);
        change_left %= coins[i];
    }
    return num_coins;
}