class Solution {
public:
    int soln(string &s, int begin, int end,vector<vector<int>> &v){
		if(begin > end) 
            return 0;
		else if(begin == end) 
            return 1;
		else if(v[begin][end] != -1) 
            return v[begin][end];
		else if(s[begin] == s[end]) 
            return v[begin][end] = 2 + soln(s, begin+1, end-1, v);
		return v[begin][end] = max(soln(s, begin+1, end, v), soln(s, begin, end-1, v));
	}
    
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if(n == 0) 
            return 0;
        vector<vector<int>> v(n, vector<int>(n, -1));
        return soln(s, 0, n-1, v);
    }
};