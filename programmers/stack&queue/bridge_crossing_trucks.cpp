#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> bridge;
    for (auto i = 0; i < bridge_length; ++i) {
        bridge.push(0);
    }
    int sum = 0;
    int truckLeft = truck_weights.size();
    int nextTruckIdx = 1;
    int noTrucks = truck_weights.size();
    int nextTruck = truck_weights[0];
    truck_weights.push_back(weight);
    while (truckLeft > 0) {
        answer++;
        int frt = bridge.front();
        bridge.pop();
        if (frt > 0) {
            sum -= frt;
            truckLeft--;
        }
        if (sum + nextTruck <= weight) {
            sum += nextTruck;
            bridge.push(nextTruck);
            nextTruck = truck_weights[nextTruckIdx++];
        } else {
            bridge.push(0);
        }

    }
    return answer;
}

int main() {
    int bridge_length = 2;
    int weight = 10;
    vector< int > truck_weights = { 7, 4, 5, 6 };
    cout << solution(bridge_length, weight, truck_weights) << endl;
    truck_weights = {10};
    weight = 100;
    bridge_length = 100;
    cout << solution(bridge_length, weight, truck_weights) << endl;
    bridge_length = 100;
    weight = 100;
    truck_weights = {10,10,10,10,10,10,10,10,10,10};
    cout << solution(bridge_length, weight, truck_weights) << endl;

    return 0;
}