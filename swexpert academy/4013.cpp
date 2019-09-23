#include <iostream>
#include <vector>
#include <cstdio>
#include <string.h>

using namespace std;

const int noMagnet = 4;
const int sizeMagnet = 8;
const int clockwise = 1;
const int counterClockwise = -1;
const int RIGHT = 2; 
const int LEFT = 6;

int magnet[noMagnet][sizeMagnet];
int magPointer[noMagnet];
int noRotate;
bool rotated[noMagnet];

int solution();
void rotate(int magNumber, int direction);
void indivRotate(int magNumber, int direction);
void checkMagnet();
void showPointer();

int main(int argc, char** argv)
{
	int test_case;
	int T;
    int direction, number;

    freopen("4013.txt", "r", stdin);

	cin >> T;

	for(test_case = 1; test_case <= T; ++test_case)
	{

        cin >> noRotate;

        for(int i = 0; i < noMagnet; ++i){
            magPointer[i] = 0;
            for(int j = 0; j < sizeMagnet; ++j){
                cin >> magnet[i][j];
            }
        }


        //showPointer();
        for(int i = 0; i < noRotate; ++i){
            cin >> number >> direction;

            memset(rotated, false, sizeof(rotated));

            rotate(number - 1, direction);
            //showPointer();
        }
        //showPointer();

        cout << "#" << test_case << " " << solution() << endl;
	}
	return 0;
}

int solution(){
    int answer = 0;
    int weight = 1;

    for(int i = 0; i < noMagnet; ++i){
        answer += (weight * magnet[i][magPointer[i]]);
        weight *= 2;
    }
    return answer;
}

void rotate(int magNumber, int direction){
    if(rotated[magNumber]) return;

    int curRightIndex, curLeftIndex;
    int curRight, curLeft;
    int nextLeftIndex, prevRightIndex;
    int nextLeft = -1, prevRight = -1;

    curRightIndex = (magPointer[magNumber] + RIGHT) % sizeMagnet;
    curLeftIndex = (magPointer[magNumber] + LEFT) % sizeMagnet;

    curRight = magnet[magNumber][curRightIndex];
    curLeft = magnet[magNumber][curLeftIndex];

    indivRotate(magNumber, direction);
    rotated[magNumber] = true;

    if(magNumber != 0){
        prevRightIndex = (magPointer[magNumber - 1] + RIGHT) % sizeMagnet;
        prevRight = magnet[magNumber - 1][prevRightIndex];
    }

    if(magNumber != noMagnet - 1){
        nextLeftIndex = (magPointer[magNumber + 1] + LEFT) % sizeMagnet;
        nextLeft = magnet[magNumber + 1][nextLeftIndex];
    }
    
    if(curLeft + prevRight == 1){
        rotate(magNumber - 1, -direction);
    }

    if(curRight + nextLeft == 1){
        rotate(magNumber + 1, -direction);
    }
}

void indivRotate(int magNumber, int direction){
    magPointer[magNumber] = (magPointer[magNumber] + sizeMagnet - direction) % sizeMagnet; 
}

void checkMagnet(){
    for(int i = 0; i < noMagnet;++i){
        for(int j = 0; j < sizeMagnet; ++j){
            if(magnet[i][j] != 0 && magnet[i][j] != 1){
                cout << "magnet[" << i << "][" << j << "] isn't correct" << endl;
            }
        }
    }
}

void showPointer(){
    cout << "show Pointers: [";
    for(int i = 0; i < noMagnet; ++i){
        cout << magPointer[i] << ",";
    }
    cout << endl;
}