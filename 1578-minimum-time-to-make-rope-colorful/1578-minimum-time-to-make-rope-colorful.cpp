class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int total = 0, curr = 0;
        for (int i = 0; i < n; ++i){
            if (i > 0 && colors[i] != colors[i - 1])
                curr = 0;
            total += min(curr, neededTime[i]);
            curr = max(curr, neededTime[i]);
        }
        return total;
    }
};