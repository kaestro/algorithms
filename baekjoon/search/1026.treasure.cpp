#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

int input_size;
vector<int> va, vb;

void initialize();
int min_sum();

int main() {
    initialize();
    cout << min_sum() << endl;

    return 0;
}

void initialize() {
    cin >> input_size;
    va.resize(input_size);
    vb.resize(input_size);
    for (int i = 0; i < input_size; ++i)
        cin >> va[i];
    for (int i = 0; i < input_size; ++i)
        cin >> vb[i];
}

int min_sum() {
    int result = 0;
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end(), greater<int>());
    for (int i = 0; i < input_size; ++i)
        result += va[i] * vb[i];

    return result;
}