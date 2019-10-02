#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 50;
int width, height;

int map[MAX][MAX];
bool visited[MAX][MAX];

typedef struct{
    int dcol, drow;
}dir;

dir direction[8] = {{1,0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

void roamIsland(int row, int col)
{
    if(map[row][col] == 0 || visited[row][col]) return;

    visited[row][col] = true;

    for(int i = 0;i < 8; ++i){
        int newRow = row + direction[i].drow;
        int newCol = col + direction[i].dcol;

        if(newCol >= 0 && newCol < width && newRow >= 0 && newRow < height)
            roamIsland(newRow, newCol);
    }
}

int main(){

    while(1)
    {
        cin >> width >> height;
        if (width == 0 && height == 0)
            break;

        memset(visited, false, sizeof(visited));

        for(int row = 0; row < height; ++row)
            for(int col = 0; col < width; ++col)
                cin >> map[row][col];

        int answer = 0;

        for(int row = 0; row < height; ++row){
            for(int col = 0; col < width; ++col){
                if(!visited[row][col] && map[row][col] == 1){
                    roamIsland(row, col);
                    answer++;
                }
            }
        }

        cout << answer << endl;
    }

    return 0;
}