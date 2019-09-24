#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

const int MAX = 50;
const int drow = 0, dcol = 1;
const int direction[8][2] = {
    {-1, -1}, {-1, 0}, {-1, 1},
    {0, -1}, {0, 1},
    {1, -1}, {1, 0}, {1, 1}
};
const int directionSize = 8;

int width, height;
int map[MAX][MAX];
bool visited[MAX][MAX];

int solution();
void search(int row, int col);
void showMap();
void showVisited();

int main(){
    freopen("4963.txt", "r", stdin);
    while(1){
        cin >> width >> height;
        if(width == 0 && height == 0){
            return 0;
        }

        memset(visited, false, sizeof(visited));

        memset(map, 0, sizeof(map));

        for(int row = 0; row < height; ++row){
            for(int col = 0; col < width; ++col){
                cin >> map[row][col];
            }
        }
        cout << solution() << endl;
    }

    return 0;
}

int solution(){
    int ans = 0;
    for(int row = 0; row < height; ++row){
        for(int col = 0; col < width; ++col){
            if(!visited[row][col] && map[row][col] == 1){
                //showMap();
                //showVisited();
                search(row, col);
                ans++;
            }
        }
    }
    return ans;
}

void search(int row, int col){
    visited[row][col] = true;

    for(int d = 0; d < directionSize; ++d){
        int nr = row + direction[d][drow];
        int nc = col + direction[d][dcol];

        if(nr < 0 || nr >= height || nc < 0 || nc >= width) continue;

        if(!visited[nr][nc] && map[nr][nc] == 1)
            search(nr, nc);
    }
}

void showMap(){
    for (int row = 0; row < height; ++row){
        for(int col = 0; col < width; ++col){
            cout << map[row][col] << " ";
        }
        cout << endl;
    }
}

void showVisited(){
    for (int row = 0; row < height; ++row){
        for(int col = 0; col < width; ++col){
            if(visited[row][col] == true) cout << "T" << " ";
            else cout << "F" << " ";
        }
        cout << endl;
    }
}
