#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    while (!progresses.empty()) {
        int size = progresses.size();
        for (auto i = 0; i < size; ++i) {
            progresses[i] += speeds[i];
        }

        if (progresses[0] >= 100){
            int maxIdx;
            for (maxIdx = 0; maxIdx < size; ++maxIdx) {
                if (progresses[maxIdx] < 100) break;
            }
            int popNumber = maxIdx;
            answer.push_back(popNumber);
            vector<int> nprogresses, nspeeds;
            int nsize = size - popNumber;
            if (nsize == 0){
                return answer;
            }
            if (nsize == 1) {
                answer.push_back(1);
                return answer;
            }

            nprogresses.resize(nsize);
            nspeeds.resize(nsize);
            for (int i = maxIdx, j = 0; i < size; ++i) {
                nprogresses[j] = progresses[i];
                nspeeds[j++] = speeds[j];
            }
            progresses = nprogresses;
            speeds = nspeeds;
        }
    }
    return answer;
}

int main() {
    vector<int> progresses = {93, 30, 55};
    vector<int> speeds = {1, 30, 5};
    solution(progresses, speeds);
    return 0;
}