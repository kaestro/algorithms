#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

const int drow = 0, dcol = 1;

int mapSize;
vector<vector<int>> map;
vector<vector<int>> direction = {
    {1, 1}, {1, -1}, {-1, -1}
};

int answer;

void reset();
void read();
void solution();
void findSquare(int row, int col);
void showMap();
int countDesserts(vector<bool> dessertsEaten);

int main()
{
	int T;
    freopen("2105.txt", "r", stdin);
    cin >> T;

	for (int testcase = 1; testcase <= T; testcase++)
	{
        reset();
        cin >> mapSize;
        read();
        showMap();
        solution();

        cout << "#" << testcase << " " << answer << endl;
	}
	
	return 0;
}

void read() {
    map = vector<vector<int>>(mapSize);
    int temp;
    for (auto i = 0; i < mapSize; ++i) {
        for (auto j = 0; j < mapSize; ++j) {
            cin >> temp;
            map[i].push_back(temp);
        }
    }
}

void reset() {
    map.clear();
    answer = -1;
    mapSize = 0;
}

void solution() {
    for (auto row = 0; row < mapSize - 1; ++row) {
        for (auto col = 1; col < mapSize - 1; ++ col) {
            findSquare(row, col);
        }
    }
}

inline bool inBoundary(const vector<int>& node){
    return node[drow] >= 0 && node[drow] < mapSize && node[dcol] >= 0 && node[dcol] < mapSize;
}

inline bool checkDessert(vector<bool>& dessertEaten, vector<int> node){
    int dessertNo = map[node[drow]][node[dcol]];
    if (dessertEaten[dessertNo]){
        return true;
    } else{
        dessertEaten[dessertNo] = true;
        return false;
    }
}

int countDesserts(vector<bool> dessertsEaten) {
    int sum = -1;
    for (auto dessert : dessertsEaten) {
        if (dessert)
            sum++;
    }
    return sum < 0 ? sum : sum + 1;
}

inline void moveNode(vector<int>& node, int directionIndex) {
    node[drow] += direction[directionIndex][drow];
    node[dcol] += direction[directionIndex][dcol];
}

void showEatenDessert(const vector<bool>& dessertEaten) {
    for (auto i = 0; i < dessertEaten.size(); ++i) {
        if (dessertEaten[i])
            cout << i << " ";
    }
    cout << endl << endl;
}

int checkSquare(vector<vector<int>> nodes) {
    vector<bool> dessertEaten(101, false);
    int result = 0;
    for (auto i = 0; i < nodes.size() - 1; ++i) {
        for (auto begin = nodes[i]; begin != nodes[i + 1]; moveNode(nodes[i], i)) {
            bool check = checkDessert(dessertEaten, begin);
            result++;
            if (check) return 0;
        }
        return result;
    }
}

void findSquare(int row, int col) {
    vector<vector<int>> nodes = {
        {row, col}, {row + direction[0][drow], row + direction[0][dcol]},
        {row + direction[0][drow] +  direction[1][drow], col + direction[0][dcol] + direction[1][dcol]},
        {row + direction[1][drow], col + direction[1][dcol]}
    };
    vector<bool> dessertEaten(100, false);
    vector<bool> copyDessert;
    while (1) {
        if (checkSquare(nodes))
            return;

        moveNode(nodes[1], 0);

        if (!inBoundary(nodes[1])) return;

        nodes[2].clear();
        nodes[2] = vector<int>(nodes[1]);
        nodes[3].clear();
        nodes[3] = vector<int>(nodes[0]);
        moveNode(nodes[2], 1);
        moveNode(nodes[3], 1);
        bool outBoundary = false;

        while (!outBoundary) {
            moveNode(nodes[2], 1);
            moveNode(nodes[3], 1);
            if (!inBoundary(nodes[2]) || !inBoundary(nodes[3]))
                outBoundary = true;
            
            if (!outBoundary) {
                if (checkSquare(nodes)) {

                }
            }
        }
        if (!inBoundary(nodes[2]) || !inBoundary(nodes[3])) continue;


        vector<bool> secondCopy;
        while (inBoundary(nodes[2]) && inBoundary(nodes[3]) && secondOkay) {
            bool check2 = checkDessert(dessertEaten, nodes[2]);
            bool check3 = checkDessert(dessertEaten, nodes[3]);
            if (!check2 && !check3) {
                int cnt = countDesserts(dessertEaten);
                if (cnt > answer)
                    answer = cnt;
                
                moveNode(nodes[2], 1);
                moveNode(nodes[3], 1);
            } else{
                secondOkay = false;
            }
        }

        dessertEaten = vector<bool>(copyDessert);
        copyDessert.clear();
    }
}

void showMap() {
    for (auto i = 0; i < mapSize; ++i) {
        for (auto j = 0; j < mapSize; ++j) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}