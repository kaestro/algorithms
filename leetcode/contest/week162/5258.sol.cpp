#include <vector>
#include <string>

using namespace std;

class Solution {
 private:
    vector<string> word_candidates;
    vector<int> cnt_by_char;
    vector<int> score_by_char;
    vector<int> score_by_word;
    int max_score;
 public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        initialize(words, letters, score);
        backtrack(0, 0);
        return max_score;
    }

    void initialize(const vector<string>& words, const vector<char>& letters, const vector<int>& score) {
        word_candidates = words;
        score_by_char = score;
        max_score = 0;

        cnt_by_char.resize(26);
        for (auto letter : letters) {
            ++cnt_by_char[letter - 'a'];
        }

        score_by_word.resize(words.size());
        for (size_t i = 0; i < words.size(); ++i) {
            for (auto letter : words[i]) {
                score_by_word[i] += score_by_char[letter-'a'];
            }
        }
    }

    void backtrack(int step, int cur_score) {
        if (step == word_candidates.size()) {
            if (cur_score > max_score)
                max_score = cur_score;
            return;
        }

        if (word_creatable(step)) {
            reduce_cnt(step);
            backtrack(step+1, cur_score + score_by_word[step]);
            recover_cnt(step);
        }
        backtrack(step+1, cur_score);
    }

    bool word_creatable(int step) {
        vector<int> temp_cnt = cnt_by_char;
        string word = word_candidates[step];
        for (auto letter : word) {
            --temp_cnt[letter-'a'];
            if (temp_cnt[letter-'a'] < 0)
                return false;
        }
        return true;
    }

    void reduce_cnt(int step) {
        string word = word_candidates[step];
        for (auto letter : word) {
            --cnt_by_char[letter-'a'];
        }
    }

    void recover_cnt(int step) {
        string word = word_candidates[step];
        for (auto letter : word) {
            ++cnt_by_char[letter-'a'];
        }
    }
};