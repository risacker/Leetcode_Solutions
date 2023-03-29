class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        vector<int> prev(satisfaction.size() + 2, 0);
        for (int index = satisfaction.size() - 1; index >= 0; index--) {
            vector<int> dp(satisfaction.size() + 2);
            for (int time = 1; time <= satisfaction.size(); time++) {
                dp[time] = max(satisfaction[index] * time + prev[time + 1], prev[time]);
            }
            prev = dp;
        }
        return prev[1];
    }
};