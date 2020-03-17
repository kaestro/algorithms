// learn how to use getchar()

#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("8888.txt", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int num_parts, num_probs;
        int jihak;
        cin >> num_parts >> num_probs >> jihak;
        jihak--;
        vector<vector<bool>> part_solved = vector<vector<bool>>(num_parts);
        vector<int> score_probs = vector<int>(num_probs, num_parts);

        for (int i = 0; i < num_parts; ++i) {
            part_solved[i] = vector<bool>(num_probs, false);
            for (int j = 0; j < num_probs; ++j) {
                int solved;
                while (1) {
                    solved = getchar() - '0';
                    if (solved == 0 || solved == 1) break;
                }
                part_solved[i][j] = solved;
                score_probs[j] -= solved;
            }
        }

        vector<int> total_scores = vector<int>(num_parts, 0);
        vector<int> num_solved = vector<int>(num_parts, 0);
        for (int i = 0; i < num_parts; ++i) {
            int sum = 0;
            for (int j = 0; j < num_probs; ++j) {
                sum += part_solved[i][j] * score_probs[j];
                num_solved[i] += part_solved[i][j];
            }
            total_scores[i] = sum;
        }

        int rank = 1;
        for (int i = 0; i < num_parts; ++i) {
            if (i == jihak) continue;
            if (total_scores[i] > total_scores[jihak]) rank++;
            else if (total_scores[i] == total_scores[jihak]) {
                if (num_solved[i] > num_solved[jihak]) rank++;
                if (num_solved[i] == num_solved[jihak] && i < jihak) rank++;
            }
        }

        // 등수를 마지막 라인에
        cout << "#" << test_case << " " << total_scores[jihak] << " " << rank <<  endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}