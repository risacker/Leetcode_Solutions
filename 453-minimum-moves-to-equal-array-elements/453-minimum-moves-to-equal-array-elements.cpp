class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int minm = INT_MAX, sum = 0;
        if(n == 1)
            return 0;
        for(int i = 0 ;i < n; i++){
            sum += nums[i];
            minm = min(nums[i], minm);
        }
        return sum - n * minm;
    }
};