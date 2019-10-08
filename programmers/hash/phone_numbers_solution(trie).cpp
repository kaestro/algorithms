#include <string>
#include <vector>

using namespace std;

bool answer;
class Node {
 public:
    Node* next[10];
    bool isNext;
    bool isFinish;

    Node(): isNext(false), isFinish(false) {
        for (int i = 0; i < 10; ++i)
            next[i] = NULL;
    }

    void insert(string temp) {
        if (temp.length() == 0) {
            isFinish = true;
            if (isFinish == isNext)
                answer = false;
            
            return;
        }
        int nextNum = temp[0] - '0';

        if (next[nextNum] == NULL) {
            next[nextNum] = new Node;
            isNext = true;
            if (isFinish == true) {
                answer = false;
            }
        }

        next[nextNum]->insert(temp.substr(1, temp.length() - 1));
    }
};

bool solution(vector<string> phoneBook) {
    answer = true;

    Node *root = new Node;
    auto size = phoneBook.size();
    for (auto i = 0; i < size; ++i) {
        root->insert(phoneBook[i]);
    }

    return answer;
}