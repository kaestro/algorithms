#include <stdio.h>

const int N = 100;
const int K = 1000;
const int UP = 1, DOWN = 2, LEFT = 3, RIGHT = 4;
const int xy[5][2] = {
    {0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};

class node {
 public:
    int cnt, dir, maxcnt;

    node(int cnt, int dir, int maxcnt):
        cnt(cnt), dir(dir), maxcnt(maxcnt)
        {};
    
};


int n, m, k;
node map[N + 1][N + 1];
node next_map[N + 1][N + 1];

void move() {
    for (auto i = 0; i < n; ++i) {
        for (auto j = 0; j < m; ++j) {
            if (map[i][j].cnt > 0) {
                int dir = map[i][j].dir;
                int nextx = i + xy[dir][0];
                int nexty = j + xy[dir][1];

                if (nextx == 0 || nextx == n - 1 || nexty == 0 || nexty == n - 1) {
                    next_map[nextx][nexty].cnt = map[i][j].cnt / 2;

                    if (dir == UP)
                        next_map[nextx][nexty].dir = DOWN;
                    else if (dir == DOWN)
                        next_map[nextx][nexty].dir = UP;
                    else if (dir == LEFT)
                        next_map[nextx][nexty].dir = RIGHT;
                    else if (dir == RIGHT)
                        next_map[nextx][nexty].dir = LEFT;
                } else {
                    if(next_map[nextx][nexty].maxcnt > 0) {
                        next_map[nextx][nexty].cnt += map[i][j].cnt;

                        if (next_map[nextx][nexty].maxcnt < map[i][j].cnt) {
                            next_map[nextx][nexty].maxcnt = map[i][j].cnt;
                            next_map[nextx][nexty].dir = map[i][j].dir;
                        }
                    } else {
                        next_map[nextx][nexty].cnt = map[i][j].cnt;
                        next_map[nextx][nexty].dir = map[i][j].dir;
                        next_map[nextx][nexty].maxcnt = map[i][j].cnt;
                    }
                }
            }
        }
    }

    for (auto i = 0; i < n; ++i) {
        for (auto j = 0; j < m; ++j) {
            map[i][j] = next_map[i][j], next_map[i][j] = node(0, 0, 0);
        }
    }
}

int get_answer() {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sum += map[i][j].cnt;
        }
    }
}

