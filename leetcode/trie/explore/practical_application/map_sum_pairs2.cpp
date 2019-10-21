#include <unordered_map>
#include <string>

using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    int sum_value;
    TrieNode():sum_value(0){}
};

class MapSum {
private:
    TrieNode* root;
    unordered_map<string, int> key_value;
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        int add_to_substr = val - key_value[key];
        key_value[key] = val;

        TrieNode* cur_node = root;
        for (auto letter : key)
        {
            if (cur_node->children.find(letter) == cur_node->children.end())
                cur_node->children[letter] = new TrieNode();
            cur_node = cur_node->children[letter];
            cur_node->sum_value += add_to_substr;
        }
    }
    
    int sum(string prefix) {
        TrieNode* cur_node = root;
        for (auto letter : prefix)
        {
            if (cur_node->children.find(letter) == cur_node->children.end())
                return 0;
            cur_node = cur_node->children[letter];
        }
        return cur_node->sum_value;
    }
};
