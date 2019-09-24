#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

const vector<vector<int>> direction = {
    {1, 0}, {0, 1}, {-1, 0}, {0, -1}
};

vector<vector<int>> map;

int width, height, depth;
int ans;

void read();
void init();
void printMap();
void solution();
void dfs(int depth);
void erase(int row, int col);
void clean();

int main(int argc, char** argv)
{
	int test_case;
	int T;

    //freopen("5656.txt", "r", stdin);

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{

        init();
        read();
        solution();
        //printMap();

        cout << "#" << test_case << " " << ans << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

void init(){
    map.clear();
    width = 0, height = 0, depth = 0;
    ans = 0;
}

void solution(){
    dfs(depth);
}

void dfs(int depth){
    int size = 0;
    for (auto v:map) {
        size += v.size();
    }
    if (size < ans)
        ans = size;

    if (depth == 0) return;

    for (int col = 0; col < width; ++col){
        if (!map[col].empty()){
            vector<vector<int>> temp = vector<vector<int>>(map);
            erase(map[col].size() - 1, col);
            clean();
            dfs(depth - 1);
            map = temp;
        }
    }
}

inline bool checkBoundary(int row, int col){
    return col >= 0 && col < width && row >= 0 && row < map[col].size();
}

void erase(int row, int col){
    int value = map[col][row];
    map[col][row] = 0;
    for (int i = 0; i < value; ++i){
        for (int d = 0; d < direction.size(); ++d){
            int nrow = row + i * direction[d][0];
            int ncol = col + i * direction[d][1];

            if(checkBoundary(nrow, ncol)){
                erase(nrow, ncol);
            }
        }
    }
}

void clean(){
    //printMap();
    for (auto& v:map){
        vector<int>::iterator it = v.begin();
        while (it != v.end()){
            if (*it == 0) {
                it = v.erase(it);
            } else {
                ++it;
            }
        }
        //printMap();
    }
}


void read(){
    cin >> depth >> width >> height;

    map = vector<vector<int>>(width);
    ans = width * height;

    int temp;
    for (int row = 0; row < height; ++row){
        for (int col = 0; col < width; ++col) {
            cin >> temp;
            if(temp != 0) map[col].insert(map[col].begin(), temp);
        }
    }
}

void printMap(){
    for (int i = 0; i < map.size(); ++i){
        for (auto number:map[i]){
            cout << number << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printMap2(){
    auto start = map[0].rbegin();
    vector<int>::reverse_iterator it[width];
    for (int i = 0; i < width; ++i){
        it[i] = map[i].rbegin();
    }

    while(1) {
        for (int i = 0; i < width; ++i){
            if (it[i] != map[i].rend()){
                cout << endl;
            }
        }
    }
}
