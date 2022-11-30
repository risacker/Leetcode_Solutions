class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        for(int num : arr){
            m[num]++;
        }
        unordered_set<int> n;
        for(auto [key, value] : m){
            n.insert(value);
        }
        return n.size() == m.size();
    }
};