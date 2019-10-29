#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int sum_of_sevendwarves(const vector<int>& dwarves);
void print_answer(vector<int> dwarves);

int main() {
    vector<int> dwarves(9, 0);
    for (auto i = 0; i < dwarves.size(); ++i)
        cin >> dwarves[i];
    
    sort(dwarves.begin(), dwarves.end());
    do {
        if (sum_of_sevendwarves(dwarves) == 100)
        {
            print_answer(dwarves);
            break;
        }
    } while (next_permutation(dwarves.begin(), dwarves.end()));

    return 0;
}

int sum_of_sevendwarves(const vector<int>& dwarves) {
    int result = 0;
    for (int i = 0; i < 7; ++i)
        result += dwarves[i];
    return result;
}
void print_answer(vector<int> dwarves) {
    sort(dwarves.begin(), dwarves.begin() + 7);

    for (int i = 0; i < 7; ++i)
        cout << dwarves[i] <<endl;
}