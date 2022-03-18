class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char,int>m; 
        for(auto i : s){
            m[i]++;
        }
        map<char,int>vis;
        string res = "";
         for(int i = 0;i < s.length();i++){
             m[s[i]]--;
              if(!vis[s[i]]){
                  while(res.size() > 0 && res.back() > s[i] && m[res.back()] > 0){
                      vis[res.back()] = 0;
                      res.pop_back();
                  }                 
                  res+=s[i];
                  vis[s[i]]=1;
              }           
         }        
        return res;
    }
};