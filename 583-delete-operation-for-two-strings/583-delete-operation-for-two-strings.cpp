class Solution {
public:
    int dp[501][501];
    int lcs(int i, int j, string& w1, string& w2) {
        if (i == w1.size() || j == w2.size()) 
            return 0;
        if (dp[i][j] != -1) 
            return dp[i][j];
        return dp[i][j] = w1[i] == w2[j] ? 1 + lcs(i+1, j+1, w1, w2) : max(lcs(i, j+1, w1, w2), lcs(i+1, j, w1, w2));
    }
    
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof dp);
        int maxLcs = lcs(0, 0, word1, word2);
        return (word1.size() - maxLcs) + (word2.size() - maxLcs);
    }
};