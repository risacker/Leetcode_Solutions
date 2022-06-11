class Solution {
public:
    bool isIsomorphic(string s, string t) {
       int m[255] = {0};
        int n[255] = {0};
        for(int i = 0; i < s.length(); ++i) {
            if(m[s[i]] != 0) {
                if(t[i] != m[s[i]]) {
                    return false;
                }
            }
            else {
                m[s[i]] = t[i];
            }
            if(n[t[i]] != 0) {
                if(s[i] != n[t[i]]) {
                    return false;
                }
            }
            else {
                n[t[i]] = s[i];
            }
        }
        return true;
    }
};