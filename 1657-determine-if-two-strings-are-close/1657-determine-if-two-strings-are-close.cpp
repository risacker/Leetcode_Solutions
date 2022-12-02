class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char, int> m;
        unordered_map<char, int> v;
        int i, j;
        int n = word1.length();
        int c = word2.length();
        if(n != c)
            return false;
        for(i = 0; i < n; i++){
            m[word1[i]]++;
            v[word2[i]]++;
        }   
        if(m.size() != v.size())
            return false;
        vector<int> w1;
        vector<int> w2;
        for(auto it : m){
            if(v[it.first] == 0)
                return false;    
            w1.push_back(it.second);
            w2.push_back(v[it.first]);
        }
        sort(w1.begin(), w1.end());
        sort(w2.begin(), w2.end());   
        for(i = 0; i < w1.size(); i++){
            if(w1[i] != w2[i])
                return false;
        }
        return true;
    }
};