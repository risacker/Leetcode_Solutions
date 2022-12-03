class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        vector<string> bucket(s.size()+1, "");
        string ans;
        for(char c : s) 
            freq[c]++;
        for(auto& it : freq){
            int n = it.second;
            char c = it.first;
            bucket[n].append(n, c);
        }
        for(int i = s.size(); i > 0; i--) {
            if(!bucket[i].empty())
                ans.append(bucket[i]);
        }
        return ans;
    }
};