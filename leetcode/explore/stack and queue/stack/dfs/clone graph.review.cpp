#include <unordered_map>
#include <vector>

class Node {
public:
    int val;
    std::vector<Node*> neighbors;

    Node() {}

    Node(int _val, std::vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

using mymap = std::unordered_map<Node*, Node*>;

class Solution {
 private:
    mymap clone;
 public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return NULL;
        }

        if (clone.find(node) == clone.end()) {
            clone[node] = new Node(node->val, {});
            for (auto neighbor : node->neighbors) {
                clone[node]->neighbors.push_back(cloneGraph(neighbor));
            }
        }

        return clone[node];
    }
};