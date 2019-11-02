#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef vector<int> vi;

int count_bumps(const vector<vi>& input);
vector<vi>* blank_filled_lock(const int key_length, const int lock_length, const vector<vi>& lock);
void showLock(const vector<vi>& lock);
bool solution(vector<vector<int>> key, vector<vector<int>> lock);
void rotateArray(vector<vi>& input);
bool test_keys(const vector<vector<vi>>& keys, const vector<vi>& lock, const int row, const int col, const int no_holes);
vector<vector<vi>> create_keys(vector<vi>& key);

int main() {
    vector<vi> key = {
        {0, 0, 0},
        {1, 0, 0},
        {0, 1, 1}
    };
    vector<vi> lock = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    solution(key, lock);
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    auto lock_length = lock.size(), key_length = key.size();
    auto lock_size = lock_length * lock_length;
    auto lock_holes_count = lock_size - count_bumps(lock);

    vector<vector<vi>> keys = create_keys(key);
    if (count_bumps(key) < lock_holes_count) return false;
    vector<vi>* testing_lock = blank_filled_lock(key_length, lock_length, lock);

    for (auto row = 0; row < lock_length + key_length - 1; ++row)
    {
        for (auto col = 0; col < lock_length + key_length - 1; ++col)
        {
            if (test_keys(keys, lock, row, col, lock_holes_count) == true) return true;
        }
    }

    return false;
}

// *******************TODO************************ //
// name with better one than blank_filled_lock -> padded lock
// implement this with using copy_n
vector<vi>* blank_filled_lock(const int key_length, const int lock_length, const vector<vi>& lock) {
    auto result_length = 2 * (key_length - 1) + lock_length;
    vector<vi>* result = new vector<vi>(result_length, vi(result_length, 0));
    for (auto row = 0; row < lock_length; ++row)
    {
        for (auto col = 0; col < lock_length; ++col)
        {
            (*result)[row + key_length - 1][col + key_length - 1] =lock[row][col];
        }
    }

    return result;
}

int count_bumps(const vector<vi>& input) {
    int num_bumps = 0;
    for (auto& row : input)
    {
        for (auto& col : row)
        {
            num_bumps += col;
        }
    }
    return num_bumps;
}

void rotateArray(vector<vi>& input)
{
    vector<vi> rotated;
    for (size_t i = 0; i < input[0].size(); ++i)
    {
        vi newRow;
        newRow.reserve(input.size());
        for (int j = input.size() - 1; j >= 0; j--)
        {
            newRow.push_back(input[j][i]);
        }
        rotated.push_back(newRow);
    }
    input = rotated;
}

vector<vector<vi>> create_keys(vector<vi>& key) {
    vector<vector<vi>> result;
    result.push_back(key);
    for(int i = 0; i < 3; ++i)
    {
        rotateArray(key);
        result.push_back(key);
    }
    return result;
}

bool test_keys(const vector<vector<vi>>& keys, const vector<vi>& lock, const int row, const int col, const int no_holes) {
    return false;
    auto key_length = keys[0].size();
    for (int key_idx = 0; key_idx < 4; ++key_idx)
    {
        for (int row_idx = row; row_idx < row + key_length; ++row_idx)
        {
            if (row_idx < key_length - 1) continue;
            for (int col_idx = col; col_idx < col + key_length; ++col_idx)
            {
                if (col_idx < key_length - 1) break;
            }
        }
    }
}

void showLock(const vector<vi>& lock) {
    size_t lock_size = lock.size();
    for (size_t row = 0; row < lock_size; ++row)
    {
        for (size_t col = 0; col < lock_size; ++col)
        {
            cout << lock[row][col] << " ";
        }
        cout << "\n";
    }
}