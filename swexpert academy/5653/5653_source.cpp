#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

class cell {
 public:
    void reset() {
        healthPoint = lifetime = 0;
        occupy = false;
    }
    void set(int hp) {
        lifetime = 2 * hp;
        healthPoint = hp;
        occupy = true;
    }
    int healthPoint;
    int lifetime;
    bool occupy;
};

const int drow[4] = { -1, 0, 1, 0 };
const int dcol[4] = { 0, 1, 0, -1 };
const int Offset = 300;

typedef pair< int, int> ii;
typedef queue< ii > myQueue;

int N = 0, M = 0;
int K = 0;

cell Map[600][600];

void init() {
    for (int row = 0; row < 600; ++row) {
        for (int col = 0; col < 600; ++col) {
            Map[row][col].reset();
        }
    }
}

int main() {
    int T = 0, hp = 0;
    freopen("5653.txt", "r", stdin);
    cin >> T;
    for (int testcase = 1; testcase <= T; ++testcase) {
        init();
        cin >> N >> M >> K;

        queue< pair< int, int > > q[11];
        for (int row = Offset; row < N + Offset; ++row) {
            for (int col = Offset; col < M + Offset; ++col) {
                cin >> hp;

                if (hp == 0) continue;

                Map[row][col].set(hp);

                q[hp].push({row, col});
            }
        }

        while (K--) {
            for (int i = 10; i >= 1; i--) {
                int qSize = q[i].size();

                for (int j = 0; j < qSize; ++j) {
                    int row = q[i].front().first;
                    int col = q[i].front().second;

                    q[i].pop();

                    --Map[row][col].lifetime;

                    if (Map[row][col].healthPoint > Map[row][col].lifetime) {
                        for (int d = 0; d < 4; ++d) {
                            int nrow = row + drow[d];
                            int ncol = col + dcol[d];

                            if (!Map[nrow][ncol].occupy) {
                                Map[nrow][ncol].set(Map[row][col].healthPoint);

                                q[i].push({nrow, ncol});
                            }
                        }
                    }

                    if (Map[row][col].lifetime != 0) {
                        q[i].push({row, col});
                    }
                }
            }
        }

        int result = 0;

        for (int i = 1; i < 10; ++i) {
            result += q[i].size();
        }

        cout << "#" << testcase << " " << result << endl;
    }

    return 0;
}