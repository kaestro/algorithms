#include <iostream>
#include <vector>
#include <queue>

const int max_int = 51;
using namespace std;

int tree_size, num, root_node;

vector<int> tree[max_int];

bool node_checked[max_int];

int count_leafnodes(int start);

int main() {
    cin >> tree_size;
    for (int i = 0; i < tree_size; ++i)
    {
        cin >> num;
        if (num == -1)
            root_node = i;
        else
        {
            tree[num].push_back(i);
            tree[i].push_back(num);
        }
        
    }

    int remove_node;
    cin >> remove_node;
    node_checked[remove_node] = true;

    if(!node_checked[root_node])
        cout << count_leafnodes(root_node) << endl;
    
    return 0;
}

int count_leafnodes(int start) {
    int leafnode_cnt = 0;
    node_checked[start] = true;
    queue<int> leafNodes;
    leafNodes.push(start);
    while(!leafNodes.empty())
    {
        int cur_node = leafNodes.front();
        leafNodes.pop();

        int child_cnt = 0;
        for (int i = 0; i < tree[cur_node].size(); ++i)
        {
            int next_node = tree[cur_node][i];
            if (!node_checked[next_node])
            {
                child_cnt++;
                node_checked[next_node] = true;
                leafNodes.push(next_node);
            }
        }

        if (child_cnt == 0) {
            leafnode_cnt++;
        }
    }

    return leafnode_cnt;
}