class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        dp[2] = 1;
        for(int i = 2; i <= n; i++){
            int k = i-1;
            while(k--){
                dp[i] = max(dp[i], dp[i-k]*k);
                dp[i] = max(dp[i], (i-k)*k);
            }
        }
        return dp[n];
    }
};