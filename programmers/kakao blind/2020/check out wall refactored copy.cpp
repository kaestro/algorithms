#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

inline int num_patrolling(vector<int>::const_iterator cit, vector<int>::const_iterator cbegin) {
    return int(cit - cbegin) + 1;
}

vector<int>& create_dist_btw_wp(vector<int>& weak_points, int wall_length) {
    vector<int>* result = new vector<int>;
    for (int i = 1; i < weak_points.size(); ++i)
        result->push_back(weak_points[i] - weak_points[i - 1]);
    result->push_back(weak_points[0] + wall_length - weak_points.back());
    return *result;
}

int calculate_patrollers(vector<int>& patrol_dists, vector<int>& dist_btw_wp);

// wp stands for weakpoints
// weak_points stores dist of wps at wall from 0
int solution(int wall_length, vector<int> weak_points, vector<int> patrol_dists) {
    if (weak_points.size() == 1)
        return 1;

    vector<int> dist_btw_wp = create_dist_btw_wp(weak_points, wall_length);

    sort(patrol_dists.begin(), patrol_dists.end());
    auto num_wp = weak_points.size();

    int ans = 0x3f3f3f3f;
    // TODO//
    // seems next_permutation is enough and 2 for loops inside
    // do_while loop seems overkill.
    // Needs to be checked
    do {
        int num_patrollers = calculate_patrollers(patrol_dists, dist_btw_wp);
        if (num_patrollers != -1)
            ans = min(ans, num_patrollers);
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

int calculate_patrollers(vector<int>& patrol_dists, vector<int>& dist_btw_wp) {
    int num_wp = dist_btw_wp.size();
    int num_patrollers = 0x3f3f3f3f;
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
            
    }
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