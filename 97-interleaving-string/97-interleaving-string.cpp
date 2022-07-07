class Solution {
public:
    bool help(string &s1, string &s2, string &s3, int i, int j, int k, vector<vector<int>>&v){
        if(v[i][j] != -1) 
            return v[i][j];
        int p = s1.size(), q = s2.size(), r = s3.size();
        if(i == p and j == q and k == r)
            return true;
        if(i < p and s1[i] == s3[k] and j < q and s2[j] == s3[k]) 
            return v[i][j] = help(s1, s2, s3, i + 1, j, k + 1, v) || help(s1, s2, s3, i, j + 1, k + 1, v);
        else if(i < p and s1[i] == s3[k]) 
            return help(s1, s2, s3, i + 1, j, k + 1, v);
        else if(j < q and s2[j] == s3[k]) 
            return help(s1, s2, s3, i, j + 1, k + 1, v);
        return false;
    }
    bool isInterleave(string s1, string s2, string s3){
        int p = s1.size(), q = s2.size(), r = s3.size();
        if(r != p + q) 
            return false;
        vector<vector<int>> v(p + 1, vector<int>(q + 1, -1));
        return help(s1, s2, s3, 0, 0, 0, v);
    }
};