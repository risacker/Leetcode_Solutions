class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) 
            return "";
        int n = strs.size();
        string ans  = "";
        sort(begin(strs), end(strs));
        string s1 = strs[0];
        string s2 = strs[n-1];
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] == s2[i])
                ans += s1[i];
            else 
                break;
        }
        return ans;
    }
};