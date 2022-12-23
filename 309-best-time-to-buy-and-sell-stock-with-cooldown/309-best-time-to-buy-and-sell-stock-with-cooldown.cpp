class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MIN, maxm = INT_MIN;
        int coolDown = 0, sell = 0;
        for(int p : prices) {
            maxm = max(maxm, buy);
            buy = coolDown - p;
            coolDown = max(coolDown, sell);
            sell = maxm + p;
        }
        return max(coolDown, sell);
    }
};