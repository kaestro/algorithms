#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int weightSum = 0;
    int frontTruckIdx = 0;
    int curTruckIdx = 0;
    auto noTrucks = truck_weights.size();
    int timePassed = 0;

    queue <int> truckInsertedTime;
    while (frontTruckIdx != noTrucks) {
        if (timePassed - truckInsertedTime.front() == bridge_length) {
            truckInsertedTime.pop();
            weightSum -= truck_weights[frontTruckIdx++];
        }

        if (curTruckIdx < noTrucks && weightSum + truck_weights[curTruckIdx] <= weight) {
            weightSum += truck_weights[curTruckIdx++];
            truckInsertedTime.push(timePassed);
        }

        timePassed++;
    }
    answer = timePassed;
    return answer;
}