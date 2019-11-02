#include <string>
#include <vector>

using namespace std;

bool answer = true;

class Node {
 public:
    Node* nextNode[10];
    bool hasNext, isEnd;
    
    Node():hasNext(false), isEnd(false) {
        for (int i = 0; i < 10; ++i) {
            nextNode[i] = NULL;
        }
    }
    
    void insert(string input) {
        if (input.length() == 0) {
            isEnd = true;

            if (hasNext) {
                answer = true;
            }
            return;
        }

        int nextInt = input[0] - '0';
        Node* next = nextNode[nextInt];
        if (next == NULL) {
            next = new Node;
            hasNext = true;

            if (isEnd) {
                answer = true;
                return;
            }
        }
        next->insert(input.substr(1));
    }
};

bool solution(vector<string> phone_book) {
    Node root;
    for(auto s : phone_book) {
        root.insert(s);
        if (answer == false) {
            break;
        }
    }
    return answer;
}