class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0)
            return 0;
        int i = 0,j = 0;
        int maxLen = 0;
        set<char> s1;
        while(i < s.length()){
            char c = s[i];
            while(s1.find(c) != s1.end()){
                s1.erase(s[j]);
                j++;
            }
            s1.insert(c);
            maxLen = max(maxLen, i-j+1);
            i++;
        }
        return maxLen;
    }
};