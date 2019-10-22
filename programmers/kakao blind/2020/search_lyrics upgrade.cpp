#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <stack>
#include <queue>

using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    // store number of substrings by left length
    // ex) if abcde is inserted, abc has subst...length[2] gets incremented.
    unordered_map<int, int> substrings_by_length; 
    TrieNode(){}
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
        int input_length = input.length();
        curNode->substrings_by_length[input_length]++;
        for (auto it = input.cbegin(); it != input.cend(); ++it)
        {
            if (curNode->children.find(*it) == curNode->children.end())
                curNode->children[*it] = new TrieNode();
            curNode = curNode->children[*it];
            curNode->substrings_by_length[--input_length]++;
        }

        TrieNode *bcurNode = backRoot;
        input_length = input.length();
        bcurNode->substrings_by_length[input_length]++;
        for (auto rit = input.crbegin(); rit != input.crend(); ++rit)
        {
            if (bcurNode->children.find(*rit) == bcurNode->children.end())
                bcurNode->children[*rit] = new TrieNode();
            bcurNode = bcurNode->children[*rit];
            bcurNode->substrings_by_length[--input_length]++;
        }
    }

    void set_defaults(int& start_index, int& end_index, int& increment, const char first_letter, TrieNode** curNode)
    {
        if (first_letter != '?')
        {
            *curNode = frontRoot;
            increment = 1;
        } else
        {
            *curNode = backRoot;
            swap(start_index, end_index);
            increment = -1;
        }
    }

    // return number of substrings inside Trie use input as prefix
    int count_substring(const string& input) {
        TrieNode* curNode;
        int question_count = input.length();
        int start_index = 0, end_index = question_count - 1, increment;

        set_defaults(start_index, end_index, increment, input[0], &curNode);

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

        return curNode->substrings_by_length[question_count];
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
        int query_result = bi_root.count_substring(query);
        answer.push_back(query_result);
    }

    return answer;
}

int main() {
    vector<string> words = {
        "frodo", "front", "frost", "frozen", "frame", "kakao"
    };
    vector<string> queries = {
        "?????", "fro??", "????o", "fr???", "fro???", "pro?", "abcde"
    };
    /*
    vector<string> queries = {
        "abcde"
    };
    */

    solution(words, queries);


    return 0;
}