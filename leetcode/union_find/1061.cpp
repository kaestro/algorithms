#include <string>
#include <vector>

using namespace std;

typedef vector<char> vc;

inline int charToInt(char input) {
    return input - 'a';
}

char findRoot(vc& parent, const int childIndex) {
    char child = childIndex + 'a';
    if (parent[childIndex] != child) {
        parent[childIndex] = findRoot(parent, charToInt(parent[childIndex]));
    }

    return parent[childIndex];
}

void unionParent(vc& parent, const char first, const char second) {
    int firstIndex = charToInt(first);
    int secondIndex = charToInt(second);

    char firstRoot = findRoot(parent, firstIndex);
    char secondRoot = findRoot(parent, secondIndex);
    parent[charToInt(firstRoot)] = parent[charToInt(secondRoot)] = min(firstRoot, secondRoot);
}

class Solution {
public:
    string smallestEquivalentString(string A, string B, string S) {
        int length = A.length();
        int charLength = 'z' - 'a' + 1;

        vc parent(charLength);

        for (int i = 0; i < charLength; ++i) {
            parent[i] = i + 'a';
        }

        for (int i = 0; i < length; ++i) {
            unionParent(parent, A[i], B[i]);
        }

        int ansLength = S.length();
        string answer(ansLength, ' ');
        for (int i = 0; i < ansLength; ++i) {
            answer[i] = findRoot(parent, S[i] - 'a');
        }

        return answer;
    }
};

int main() {
    Solution s;
    // string A = "abc", B = "cde", S = "eed";
    string A = "leetcode";
    string B = "programs";
    string S = "sourcecode";
    s.smallestEquivalentString(A, B, S);
}