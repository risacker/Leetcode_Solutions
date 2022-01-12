class Solution {
public:
   int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int profit = 0;
        for(auto i: prices){
            if(i<min) 
                min = i;
            else if(i-min>profit) 
                profit = i-min;
            }
        
        return profit;
    }
};