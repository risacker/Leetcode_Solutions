class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int n = costs.size();
        int ans = 0;
        while(ans < n && costs[ans] <= coins){ 
            coins -= costs[ans];
            ans += 1;
        }
        return ans;
    }
};