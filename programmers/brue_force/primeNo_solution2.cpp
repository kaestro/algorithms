#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int solution(string numbers) {
    int answer = 0;

    string temp;
    temp = numbers;
    sort(temp.begin(), temp.end(), greater<char>());
    int maximum = stoi(temp);
    vector<bool> isPrime(maximum + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i < maximum; ++i) {
        if (isPrime[i]) {
            for (int j = 2 * i; j <= maximum; j += i) {
                isPrime[j] = false;
            }
        }
    }

    set<int> candidates;
    sort(numbers.begin(), numbers.end());
    int len = numbers.length();
    while (numbers[0] == '0') next_permutation(numbers.begin(), numbers.end());
    do {
        for (int i = 1; i <= len; ++i) {
            int temp = stoi(numbers.substr(0, i));
            if (isPrime[temp])
                candidates.insert(temp);
        }
    } while (next_permutation(numbers.begin(), numbers.end()));

    answer = candidates.size();

    return answer;
}

int main() {
    solution("17");
    solution("011");
}