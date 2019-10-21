#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
#include <iostream>

using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEnd;
    TrieNode():isEnd(false){}
};

struct Trie {
private:
    TrieNode* root;
public:
    Trie()
    {
        root = new TrieNode();
    }
    void insert(string input) {
        TrieNode* cur = root;
        for (auto letter : input)
        {
            if (cur->children.find(letter) == cur->children.end())
                cur->children[letter] = new TrieNode;
            cur = cur->children[letter];
        }
        cur->isEnd = true;
    }

    string findShortestRoot(string input) {
        TrieNode* cur = root;
        if (cur->children.find(input[0]) == cur->children.end())
            return input;
        string result;
        result.reserve(input.length());
        for (auto letter : input)
        {
            if (cur->children.find(letter) != cur->children.end())
            {
                result += letter;
                cur = cur->children[letter];
                if (cur->isEnd) break;
            } else
                break;
        }
        if (cur->isEnd) return result;
        else return input;
    }
};

class Solution {
private:
    Trie roots;
public:
    string replaceWords(vector<string>& dict, string sentence) {
        for (auto word : dict)
            roots.insert(word);
        istringstream ss(sentence);
        string result;
        result.reserve(sentence.length());
        do {
            string word;
            ss >> word;
            result.append(roots.findShortestRoot(word) + " ");
        } while(ss);

        return result.substr(0, result.length() - 2);
    }
};

int main() {
    Solution example;
    /*
    vector<string> dict = {
        "cat", "bat", "rat"
    };
    string sentence = "the cattle was rattled by the battery";
    */
    vector<string> dict = {
       "a", "aa", "aaa", "aaaa"
    };
    string sentence = "a aa a aaaa aaa aaa aaa aaaa bbb baba a";

    cout << example.replaceWords(dict, sentence) << endl;
}