class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;// minPrice will store the minimal to the left 
        int maxProfit = 0;
        for(int i = 0;i < prices.size(); i++){
            minPrice = min(minPrice, prices[i]);// update the minimal at every stage
            maxProfit = max(maxProfit, prices[i] - minPrice);// trying to sell the stocks 
        }
        return maxProfit;// return the maxProfit
    }
};