#include<iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
    freopen("8741.txt", "r", stdin);
	cin>>T;
    string line;
    cin.ignore();// getline 쓸 때 이전에 cin 쓴적이 있으면 이렇게 입력버퍼를 비워야 한다.
	for(test_case = 1; test_case <= T; ++test_case)
	{
        getline(cin, line);
        bool first = true;
        string ans;
        for (auto c : line) {
            if (first) {
                ans += toupper(c);
                first = false;
            } else if (c == ' ') {
                first = true;
            }
        }
        cout << "#" << test_case << " " << ans << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}