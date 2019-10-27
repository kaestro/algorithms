#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

inline int num_patrolling(vector<int>::const_iterator cit, vector<int>::const_iterator cbegin) {
    return int(cit - cbegin) + 1;
}

// wp stands for weakpoints
// weak_points stores dist of wps at wall from 0
int solution(int wall_length, vector<int> weak_points, vector<int> patrol_dists) {
    if (weak_points.size() == 1)
        return 1;

    vector<int> dist_btw_wp;
    for (int i = 1; i < weak_points.size(); ++i)
        dist_btw_wp.push_back(weak_points[i] - weak_points[i - 1]);
    dist_btw_wp.push_back(weak_points[0] + wall_length - weak_points.back());

    sort(patrol_dists.begin(), patrol_dists.end());
    auto num_wp = weak_points.size();

    int ans = 0x3f3f3f3f;
    do {
        for (int first_wp_idx = 0; first_wp_idx < num_wp; ++first_wp_idx) {
            int end_wp_idx = (first_wp_idx + num_wp - 1) % num_wp;
            bool wp_patrolled[20]{};

            auto it_patrol_dists = patrol_dists.cbegin();
            int patrolled_dist = 0;

            for (int cur_wp_idx = first_wp_idx; cur_wp_idx != end_wp_idx; (++cur_wp_idx) %= num_wp)
            {
                if (it_patrol_dists == patrol_dists.cend()) break; // can't patrol all

                wp_patrolled[cur_wp_idx] = true;
                patrolled_dist += dist_btw_wp[cur_wp_idx];
                if (patrolled_dist > *it_patrol_dists)
                {
                    ++it_patrol_dists;
                    patrolled_dist = 0;
                }
            }

            if (it_patrol_dists != patrol_dists.cend())
                ans = min(ans, num_patrolling(it_patrol_dists, patrol_dists.cbegin()));
        }
    } while (next_permutation(patrol_dists.begin(), patrol_dists.end()));

    return ans == 0x3f3f3f3f ? -1 : ans;
}


int main() {
    vector<int> wall_lengths = {12, 12};
    vector<vector <int> > weaks = {
        {1, 5, 6, 10},
        {1, 3, 4, 9, 10}
    };
    vector<vector<int> > dists = {
        {1, 2, 3, 4},
        {3, 5, 7}
    };
    for (int i = 0; i < wall_lengths.size(); ++i)
        cout << solution(wall_lengths[i], weaks[i], dists[i]) << endl;
}