class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
       vector<int> dp(10001, 0);
        for(auto i : nums) dp[i] += i;
        for(int i = 2 ; i < 10001 ; i++){
            dp[i] = max(dp[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[10000]; 
    }
};