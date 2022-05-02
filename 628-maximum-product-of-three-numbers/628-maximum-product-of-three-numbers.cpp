class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        int n = nums.size();
        if(nums[0] * nums[1] * nums[n - 1] > nums[n - 1] * nums[n - 2] * nums[n - 3])
            ans = nums[0] * nums[1] * nums[n - 1];
        else
            ans = nums[n - 1] * nums[n - 2] * nums[n - 3];
        return ans;
    }
};