#include <vector>
#include <unordered_map>


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
    mymap copies;
 public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return NULL;
        }
        if (copies.find(node) == copies.end()) {
            copies[node] = new Node(node->val, {});
            for (Node* neighbor : node->neighbors) {
                copies[node]->neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return copies[node];
    }
};