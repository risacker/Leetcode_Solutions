class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> v;  
        for (string c : ops) {
            int n = v.size();
            if (c == "+") {
                int new_score = v[n-1] + v[n-2];
                v.emplace_back(new_score);
            } 
            else if (c == "D") {
                int new_score = v[n-1];
                v.emplace_back(2*new_score);
            }
            else if (c == "C") {
                v.pop_back();
            } 
            else {
                int num = stoi(c);
                v.emplace_back(num);
            }
        }
        return accumulate(v.begin(), v.end(), 0);
    }
};