#include <vector>
#include <stack>
#include <iostream>

class Solution {
 private:
    // stores only indexes of increasing temperature indexes.
    // if 32, 30, 48, 42, 46, 56 is given it will have
    // 0, 2, 5
    std::stack<int> i_incre_temps;
    // temperature per dates. used to make input into object variable
    std::vector<int> temp_dates;
    // the answer. the dates gap between first warmer date.
    std::vector<int> gap_warmer_dates;
 public:
    std::vector<int> dailyTemperatures(std::vector<int>& T) {
        int cnt_days = T.size();
        temp_dates = std::vector<int>(T);
        gap_warmer_dates.resize(cnt_days);
        for (int i = cnt_days - 1; i >= 0; --i) {
            find_warmerdate(i);
        }
        return gap_warmer_dates;
    }

    void find_warmerdate(int cur_date) {
        int coldest_temp, coldest_idx;
        int cur_temp = temp_dates[cur_date];
        // remove all indexes inside the stack until it has
        // no indexes of temperature with equal or less inside
        // then the next push will make cur_temp to be the top.
        // that is, cur_temp becomes the coldest inside stack
        while (!i_incre_temps.empty()) {
            coldest_idx = i_incre_temps.top();
            coldest_temp = temp_dates[coldest_idx];
            if (cur_temp >= coldest_temp) i_incre_temps.pop();
            else break;
        }
        if (i_incre_temps.empty()) gap_warmer_dates[cur_date] = 0;
        else gap_warmer_dates[cur_date] = i_incre_temps.top() - cur_date;
        i_incre_temps.push(cur_date);
    }
};    

int main() {
    std::vector<int> temp_dates = {73, 74, 75, 71, 69, 72, 76, 73};
    Solution s;

    auto ans = s.dailyTemperatures(temp_dates);
    for (auto dates : ans) {
        std::cout << dates << " ";
    }

    return 0;
}