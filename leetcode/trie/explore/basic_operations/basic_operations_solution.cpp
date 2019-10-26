#include <unordered_map>

using namespace std;

struct Node {
    unordered_map<char, Node*> children;
    bool isWord;
    Node(): isWord(false){}
};

class Trie {
private:
    Node* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* curr = root;
        for (int i = 0; i < word.size(); ++i)
        {
            if (curr->children[word[i]] == 0)
                curr->children[word[i]] = new Node();
            curr = curr->children[word[i]];

            if (i == word.size() - 1)
                curr->isWord = true;
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* curr = root;
        for (auto ch: word)
        {
            if (curr->children[ch] > 0)
                curr = curr->children[ch];
            else
                return false;
        }
        return curr->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* curr = root;
        for (auto ch : prefix)
        {
            if (curr->children.find(ch) != curr->children.end())
                curr = curr->children[ch];
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