#include <string>
#include <vector>
#include <cmath>

using namespace std;

typedef pair<int, int> ii;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    vector< ii > candidates;
    for (int divisor = 1; divisor <= sqrt(red); ++divisor) {
        if (red % divisor == 0) {
            candidates.push_back({red / divisor, divisor});
        }
    }
    for (auto it = candidates.begin(); it != candidates.end(); ++it) {
        int remnant = 0;
        int width = it->first, height = it->second;
        while (remnant < brown) {
            width += 2, height += 2;
            remnant = (width * height) - red;
        }
        if (remnant == brown) {
            answer.push_back(width);
            answer.push_back(height);
            break;
        }
    }
    return answer;
}