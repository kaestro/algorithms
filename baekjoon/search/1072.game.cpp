#include <iostream>

using namespace std;

int main() {
    long long game_total, game_won;
    cin >> game_total >> game_won;

    long long winrate_original = (100*game_won)/game_total;
    if (winrate_original >= 99)
    {
        cout << -1 << endl;
    } else
    {
        long long low = 0;
        long long high = game_total;
        long long mid;
        while (low < high)
        {
            mid = (low + high)/2;
            long long winrate_new = 100*(game_won + mid) / (game_total + mid);
            if (winrate_new == winrate_original)
            {
                low = mid + 1;
            } else
            {
                high = mid;
            }
        }
        cout << low << endl;
    }

    return 0;
}