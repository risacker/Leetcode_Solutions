class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        int n = pattern.size();
        for(auto i : words){
                int c = 0;
                bool a = true;
                unordered_map<char, char> mp, m;
                for(auto j:i){      
                    if(mp.find(pattern[c]) == mp.end() && m.find(j) == m.end()){
                        //key not found
                        mp[pattern[c]] = j;
                        m[j] = pattern[c];   
                    }
                    else{
                        //when our key already exists
                        if(mp[pattern[c]] != j || m[j]!=pattern[c]){
                            a=false;
                        }
                    }
                    c++;
                }  
                if(a) 
                    ans.push_back(i);
        }
        return ans;
    }
};