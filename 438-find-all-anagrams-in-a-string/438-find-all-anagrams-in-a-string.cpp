class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
          vector<int>ans;
        int m1[26],m2[26];
        for(int i = 0 ; i <26 ; i++){
            m1[i] = 0 , 
            m2[i] = 0;
        }
        for(auto i : p){
            m1[i - 'a']++;
        }
        int ws = p.size();
        int cnt = 0;
        int start = 0;
        for(int i = 0 ; i < s.size(); i++){
           m2[s[i] - 'a']++;
           if(i - start + 1 == p.size()){
               bool flag = false;
               for(int j = 0 ; j < 26 ; j++){
                   if(m1[j] != m2[j]){
                       flag = true; 
                       break;
                   }
               }
               if(!flag) 
                   ans.push_back(start);
               m2[s[start] - 'a']--;
               start++;
           }
        }
        return ans;
    }
};