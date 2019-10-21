#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        istringstream ss(sentence);
        string result;
        result.reserve(sentence.length());
        do {
            string word;
            ss >> word;

            for (auto root : dict)
            {
                if (word.find(root) == 0)
                {
                    word = root;
                    break;
                }
            }
            result += word;
            result += " ";
        } while (ss);
        result.pop_back();
        result.pop_back();

        return result;
    }
};

int main() {
    Solution example;
    vector<string> dict = {
        "cat", "bat", "rat"
    };
    string sentence = "the cattle was rattled by the battery";

    example.replaceWords(dict, sentence);
}