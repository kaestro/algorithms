#include <vector>

using namespace std;

bool rotate(vector<vector<int>>matrix) {
    if (matrix.size() == 0 || matrix.size() != matrix[0].size()) return false;

    int n = matrix.size();

    for (int layer = 0; layer < n / 2; ++layer)
    {
        int first = layer;
        int last = n - 1 - layer;
        for (int i = first; i < last; ++i)
        {
            int offset = i - first;

            int top = matrix[first][i]; // save top

            // left -> top
            matrix[first][i] = matrix[last - offset][first];

            // bottom -> left
            matrix[last - offset][first] = matrix[last][last - offset];

            // right -> bottom
            matrix[last][last - offset] = matrix[i][last];

            // top -> right
            matrix[i][last] = top;
        }
        return true;
    }
}