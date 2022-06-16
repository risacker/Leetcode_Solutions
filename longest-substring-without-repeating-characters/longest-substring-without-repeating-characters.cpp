class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> mpp(256, -1);
        int l = 0, r = 0;
        int len = 0;
        while(r < n){
            if(mpp[s[r]] != -1)
                l = max(mpp[s[r]] + 1, l);
            mpp[s[r]] = r;
            len = max(len, r - l + 1);
            r++;
        }
        return len;
    }
};