#include <unordered_map>

using namespace std;

struct Node {
    unordered_map<char, Node*> children;
    string prefix;
    bool isWord;

    Node(string s): prefix(s), isWord(false) {}
};

class Trie {
private:
    Node* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node("");
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* curr = root;
        for (int i = 0; i < word.length(); ++i)
        {
            if (curr->children[word[i]] == 0)
                curr->children[word[i]] = new Node(word.substr(0, i + 1));

            curr = curr->children[word[i]];
            if (i == word.length() -1)
                curr->isWord = true;
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* curr = root;
        for (int i = 0; i < word.length(); ++i)
        {
            if (curr->children.find(word[i]) != curr->children.end())
                curr = curr->children[word[i]];
            else
                return false;
        }
        return curr->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* curr = root;
        for (auto c : prefix)
        {
            if (curr->children.find(c) != curr->children.end())
                curr = curr->children[c];
            else
                return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */