#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case) {
        int numbers[10];
        int temp;
        for (int i = 0; i < 10; ++i) {
            cin >> temp;
            int trans = 0;
            while (temp > 0) {
                trans += temp % 10;
                temp /= 10;
            }
            numbers[i] = trans;
        }
        // remember the use of max_element, min_element function
        printf("#%d %d %d\n", *max_element(numbers, numbers+10), *min_element(numbers, numbers+10));
    }
    return 0;
}