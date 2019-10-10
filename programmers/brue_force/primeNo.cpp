#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>

#define tr(it, container) for (auto it = container.begin(); \
                                        it != container.end(); ++it)

using namespace std;

typedef vector<int> vi;

vector<bool> primeNumbers(int max) {
    vi result;
    vector<bool> result_bool(max + 1, true);
    result_bool[0] = false;
    result_bool[1] = false;
    for (int i = 2; i <= max; ++i) {
        bool isPrime = true;
        tr (it, result) {
            if (i % (*it) == 0) {
                isPrime = false;
                result_bool[*it] = false;
                break;
            }
        }
        if (isPrime) 
            result.push_back(i);
    }
    return result_bool;
}

void workCurInt(string& numbers, vector<bool>& used, int curInt, unordered_set<int>& result){
    result.insert(curInt);
    for (int i = 0; i < numbers.length(); ++i) {
        if (!used[i]) {
            used[i] = true;
            workCurInt(numbers, used, curInt * 10 + numbers[i] - '0', result);
            used[i] = false;
        }
    }
}

unordered_set< int > generate_combinations(string numbers) {
    vector<bool> used(numbers.length(), false);
    unordered_set<int> result;
    int i = 0;
    while (numbers[i] == '0') {
        i++;
    }
    for (; i < numbers.length(); ++i) {
        used[i] = true;
        workCurInt(numbers, used, numbers[i] - '0', result);
        used[i] = false;
    }
    return result;
}

int solution(string numbers) {
    int answer = 0;
    
    sort(numbers.begin(), numbers.end(), greater<char>());
    vector<bool> isPrime = primeNumbers(stoi(numbers));
    sort(numbers.begin(), numbers.end());
    unordered_set<int> candidates = generate_combinations(numbers);
    tr (it, candidates) {
        if (isPrime[*it])
            answer++;
    }
    
    return answer;
}

int main() {
    cout << solution("17") << endl;
    cout << solution("011") << endl;
    return 0;
}