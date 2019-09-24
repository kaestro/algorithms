#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;

const int drow = 0, dcol = 1;
const int mapsize = 10;
const int maxBattery = 8;
const int direction[5][2] = {
    {0, 0}, {-1, 0}, {0, 1}, {1, 0}, {0, -1}
};
const int maxMove = 100;

int map[mapsize][mapsize];
int bcPosition[maxBattery][2];
bool bcArea[maxBattery][mapsize][mapsize];
int bcPower[maxBattery];
int aPos[2], bPos[2];
int aMoveDirection[maxMove], bMoveDirection[maxMove];
int numMove, numBC;

void colorArea(int bcNum, int influence);
void showMap();
void move(int cnt);
void resetAB();
int chargedPower();

int main(int argc, char** argv)
{
	int test_case;
	int T;

    freopen("5644.txt", "r", stdin);

	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> numMove >> numBC;
        resetAB();

        for(int n = 0; n < numMove; ++n){
            cin >> aMoveDirection[n];
        }

        for(int n = 0; n < numMove; ++n){
            cin >> bMoveDirection[n];
        }

        memset(bcArea, false, sizeof(bcArea));
        //showMap();
        for(int n = 0; n < numBC; ++n){
            cin >> bcPosition[n][dcol];
            bcPosition[n][dcol]--;

            cin >> bcPosition[n][drow];
            bcPosition[n][drow]--;

            int area;
            cin >> area;
            colorArea(n, area);
            //showMap();

            cin >> bcPower[n];
        }

        int answer = 0;
        answer += chargedPower();
        //showMap();
        for(int n = 0; n < numMove; ++n){
            move(n);
            //showMap();
            answer += chargedPower();
        }

        std::cout << "#" << test_case << " " << answer << endl;
	}
	return 0;
}

void colorArea(int bcNum, int influence){
    int row = bcPosition[bcNum][drow];
    int col = bcPosition[bcNum][dcol];

    for(int i = 0; i <= influence; ++i){
        int nr = row - i;
        if(nr >= 0 && nr < mapsize){
            for(int c = 0; c <= influence - i; ++c){
                int nc = col - c;

                if(nc >= 0 && nc < mapsize){
                    bcArea[bcNum][nr][nc] = true;
                    //showMap();
                }

                if(c != 0){
                    nc = col + c;
                    if(nc >= 0 && nc < mapsize){
                        bcArea[bcNum][nr][nc] = true;
                        //showMap();
                    }
                }
            }
        }

        if(i == 0) continue;
        nr = row + i;
        for(int c = 0; c <= influence - i; ++c){
            int nc = col - c;
            if(nc >= 0 && nc < mapsize){
                bcArea[bcNum][nr][nc] = true;
                //showMap();
            }

            if(c != 0){
                nc = col + c;
                if(nc >= 0 && nc < mapsize){
                    bcArea[bcNum][nr][nc] = true;
                    //showMap();
                }
            }
        }
    }
}

void showMap(){
    for(int r = 0; r < mapsize; ++r){
        for(int c = 0; c < mapsize; ++c){
            std::cout << "[";
            if(aPos[drow] == r && aPos[dcol] == c){
                std::cout << "a,";
            }
            if(bPos[drow] == r && bPos[dcol] == c){
                std::cout << "b,";
            }

            for(int n = 0; n < numBC; ++n){
                if(bcArea[n][r][c]){
                    std::cout << n + 1 << ",";
                }
            }

            std::cout << "] \t";
        }
    }
        std::cout << endl;
}

int chargedPower(){
    vector<int> aFirstIndex, aSecondIndex, bFirstIndex, bSecondIndex;
    int aFirstPower = 0, aSecondPower = 0, bFirstPower = 0, bSecondPower = 0;
    int aRow = aPos[drow], aCol = aPos[dcol];
    int bRow = bPos[drow], bCol = bPos[dcol];
    int answer = 0;

    for(int bc = 0; bc < numBC; ++bc){
        if(bcArea[bc][aRow][aCol]){
            int power = bcPower[bc];

            if(power > aFirstPower){
                aSecondPower = aFirstPower;
                aFirstPower = power;

                aSecondIndex = vector<int>(aFirstIndex);
                aFirstIndex.clear();
                aFirstIndex.push_back(bc);
            }else if(power == aFirstPower){
                aFirstIndex.push_back(bc);
            }else if(power > aSecondPower){
                aSecondIndex.clear();
                aSecondIndex.push_back(bc);
                aSecondPower = power;
            }else if(power == aSecondPower){
                aSecondIndex.push_back(bc);
            }
        }

        if(bcArea[bc][bRow][bCol]){
            int power = bcPower[bc];

            if(power > bFirstPower){
                bSecondPower = bFirstPower;
                bFirstPower = power;

                bSecondIndex = vector<int>(bFirstIndex);
                bFirstIndex.clear();
                bFirstIndex.push_back(bc);
            }else if(power == bFirstPower){
                bFirstIndex.push_back(bc);
            }else if(power > bSecondPower){
                bSecondIndex.clear();
                bSecondIndex.push_back(bc);
                bSecondPower = power;
            }else if(power == bSecondPower){
                bSecondIndex.push_back(bc);
            }
        }
    }

    if(aFirstIndex.empty() && bFirstIndex.empty()) answer = 0; 
    else if(aFirstPower != bFirstPower) answer = aFirstPower + bFirstPower;
    else if(aFirstIndex.size() != bFirstIndex.size() || !equal(aFirstIndex.begin(), aFirstIndex.end(), bFirstIndex.begin())){
        answer = aFirstPower + bFirstPower;
    } else if(aFirstPower != 0 || bFirstPower != 0){
        int aBigger = aFirstPower + bSecondPower;
        int bBigger = aSecondPower + bFirstPower;
        answer = (aBigger > bBigger) ? aBigger : bBigger;
    }

    return answer;
}

void move(int cnt){
    int aDirection[2] = {direction[aMoveDirection[cnt]][drow], direction[aMoveDirection[cnt]][dcol]};
    int bDirection[2] = {direction[bMoveDirection[cnt]][drow], direction[bMoveDirection[cnt]][dcol]};
    aPos[drow] += aDirection[drow];
    aPos[dcol] += aDirection[dcol];

    bPos[drow] += bDirection[drow];
    bPos[dcol] += bDirection[dcol];
}

void resetAB(){
    aPos[drow] = 0;
    aPos[dcol] = 0;
    bPos[drow] = mapsize - 1;
    bPos[dcol] = mapsize - 1;
}