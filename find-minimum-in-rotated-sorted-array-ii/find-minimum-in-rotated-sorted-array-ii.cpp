class Solution {
public:
    int findMin(vector<int>& nums) {
        auto minm = min_element(nums.begin(), nums.end());
        return minm[0];
    }
};