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
bool test_keys(const vector<vi>* keys, const vector<vi>& lock, const int row, const int col, const int no_holes);
vector<vi>* create_keys(vector<vi>& key);

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

    vector<vi>* keys = create_keys(key);
    if (count_bumps(key) < lock_holes_count) return false;
    vector<vi>* testing_lock = blank_filled_lock(key_length, lock_length, lock);

    for (auto row = 0; row < lock_length + key_length - 1; ++row)
    {
        for (auto col = 0; col < lock_length + key_length - 1; ++col)
        {
            if (test_keys(keys, *testing_lock, row, col, lock_holes_count) == true) {
                cout << "some key works here" << endl;
                cout << "row:" << row << ", " << col << endl;
                return true;
            }
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

vector<vi>* create_keys(vector<vi>& key) {
    vector<vi>* result = new vector<vi>[4];
    result[0] = vector<vi>(key);
    for(int i = 1; i < 4; ++i)
    {
        rotateArray(key);
        result[i] = vector<vi>(key);
    }
    return result;
}

bool test_keys(const vector<vi>* keys, const vector<vi>& lock, const int row, const int col, const int no_holes) {
    auto key_length = keys[0].size();
    auto lock_length = lock.size();
    for (int key_idx = 0; key_idx < 4; ++key_idx)
    {
        int left_holes = no_holes;
        for (int row_idx = row; row_idx < row + key_length; ++row_idx)
        {
            if (row_idx < key_length - 1) continue;
            if (row_idx > lock_length - key_length) continue;
            for (int col_idx = col; col_idx < col + key_length; ++col_idx)
            {
                if (col_idx < key_length - 1) continue;
                if (col_idx > lock_length - key_length) break;

                int lock_val = lock[row_idx][col_idx];
                int key_val = keys[key_idx][row_idx - row][col_idx - col];
                if (lock_val == 1 && key_val == 1 || lock_val == 0 && key_val == 0)
                {
                    left_holes = -1;
                    break;
                } else if (lock_val == 0 && key_val == 1) left_holes--;
            }
            if (left_holes < 0) break;
            else if (left_holes == 0) return true;
        }
    }
    return false;
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