#include <string>
#include <unordered_map>

using namespace std;

class MapSum {
private:
    unordered_map<string, int> values;
public:
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        values[key] = val;
    }
    
    int sum(string prefix) {
        int result = 0;
        for (auto it = values.begin(); it != values.end(); ++it)
        {
            if (it->first.find(prefix) == 0)
            {
                result += values[it->first];
            }
        }
        return result;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */