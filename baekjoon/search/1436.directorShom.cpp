#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int find_nth_doomsday(int N) {
    int count = N;
    int curNumber = 666;
    while (count > 0)
    {
        if (to_string(curNumber).find("666") != string::npos)
            count--;
        curNumber++;
    }
    return curNumber - 1;
}

int main() {
    int N;
    cin >> N;
    cout << find_nth_doomsday(N) << endl;

    return 0;
}