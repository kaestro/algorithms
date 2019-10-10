#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

bool checkNumber(int i, string numbers);

int solution(string numbers) {
    int answer = 0;
    sort(numbers.begin(), numbers.end(), greater<char>());
    vector<bool> isPrime(stoi(numbers) + 1, true);
    for (int i = 2; i <= stoi(numbers); ++i) {
        if (isPrime[i] && inputBelongToCombination(i, numbers)) {
            answer++;
        }
        if (isPrime[i]) {
            for (int j = i; j <=stoi(numbers); j += i) {
                isPrime[j] = false;
            }
        }
    }
    return answer;
}

bool checkNumber(int input, string numbers) {
    bool numberHasDigit;
    vector<bool> visited(numbers.length());
    while (input != 0) {
        numberHasDigit = false;
        int temp = input % 10;
        for (int j = 0; j <= numbers.length(); ++j) {
            if (temp == numbers[j] - '0' && !visited[j]) {
                visited[j] = true;
                numberHasDigit = true;
                break;
            }
        }
        if (!numberHasDigit) return false;
        input /= 10;
    }
}