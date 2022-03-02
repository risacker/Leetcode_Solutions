class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0, m = s.size(), n = t.size();
        while ( i < m && j < n && n - j >= m - i )
        {
            if ( s[i] == t[j] )
                i += 1;
                j += 1;
        }
            
        return i == m;
    }
};