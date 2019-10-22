#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <stack>
#include <queue>

using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEnd;
    TrieNode():isEnd(false){}
};

class Trie {
 private:
    TrieNode *frontRoot, *backRoot;
 public:
    Trie() {
        frontRoot = new TrieNode();
        backRoot = new TrieNode();
    }

    void insert(const string& input) {
        TrieNode *curNode = frontRoot;
        for (auto it = input.cbegin(); it != input.cend(); ++it)
        {
            if (curNode->children.find(*it) == curNode->children.end())
                curNode->children[*it] = new TrieNode();
            curNode = curNode->children[*it];
        }
        curNode->isEnd = true;

        TrieNode *bcurNode = backRoot;
        for (auto rit = input.crbegin(); rit != input.crend(); ++rit)
        {
            if (bcurNode->children.find(*rit) == bcurNode->children.end())
                bcurNode->children[*rit] = new TrieNode();
            bcurNode = bcurNode->children[*rit];
        }
        bcurNode->isEnd = true;
    }

    int search(const string& input) {
        TrieNode* curNode;
        int count = 0;
        int question_count = input.length();
        int start_index = 0, end_index = question_count - 1, increment;

        if (input[0] != '?')
        {
            curNode = frontRoot;
            increment = 1;
        }
        else
        {
            curNode = backRoot;
            swap(start_index, end_index);
            increment = -1;
        } 

        for (int idx = start_index; idx != end_index; idx += increment)
        {
            char letter = input[idx];
            if (letter != '?')
            {
                if (curNode->children.find(letter) == curNode->children.end())
                    return 0;
                curNode = curNode->children[letter];
                question_count--;
            } else
                break;
        }

        return searchQuestions(curNode, question_count);
    }

    int searchQuestions(TrieNode* cur, int question_count) {
        if (question_count == 0)
            return cur->isEnd;

        question_count--;
        int count = 0;
        for (auto& node : cur->children)
            count += searchQuestions(node.second, question_count);
        return count;
    }

};

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    answer.reserve(queries.size());
    Trie bi_root;
    for (auto& word : words)
        bi_root.insert(word);
    
    for (auto& query : queries)
    {
        int query_result = bi_root.search(query);
        answer.push_back(query_result);
    }

    return answer;
}

int main() {
    vector<string> words = {
        "frodo", "front", "frost", "frozen", "frame", "kakao"
    };
    /*
    vector<string> queries = {
        "fro??", "????o", "fr???", "fro???", "pro?", "abcde"
    };
    */
    vector<string> queries = {
        "abcde"
    };

    solution(words, queries);


    return 0;
}