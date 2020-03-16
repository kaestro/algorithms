#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int T, N;
const int correct = 0x3ffffff;
int map[26];
int words[15];
int answer;

void initMap() {
    for (int i = 0; i < 26; ++i) {
        map[i] = 0x01 << i;
    }
}

void solution(int begin, int curWord) {
    if (curWord == correct) {
        ++answer;
    }

    for (int i = begin; i < N; ++i) {
        solution(i + 1, curWord | words[i]);
    }
}

int main() {
    initMap();
    freopen("9480.txt", "r", stdin);
    scanf("%d", &T);
    for (int testcase = 1; testcase <= T; ++testcase) {
        scanf("%d", &N);
        string str;
        for (int i = 0; i < N ; ++i) {
            cin >> str;
            int n = 0;
            for (int j = 0; j < str.length(); ++j) {
                n |= map[str[j] - 'a'];
                if (n == correct) break;
            }
            words[i] = n;
        }
        answer = 0;
        solution(0, 0);
        printf("#%d %d\n", testcase, answer);
    }
    return 0;
}