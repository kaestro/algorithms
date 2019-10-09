#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    vector<int> sorted_priorities = priorities;
    sort(sorted_priorities.begin(), sorted_priorities.end(), greater<int>());
    auto size = priorities.size();
    
    bool printed = false;
    auto it = sorted_priorities.begin();
    while (!printed) {
        for (int i = 0; i < size; ++i) {
            if (*it == priorities[i]) {
                if (i == location) {
                    printed = true;
                    break;
				} else {
                    it++;
                    answer++;
				}
			}
		}
	}
    
    return answer;
}