class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> dummy;
        dummy = nums;
        int n = nums.size();
        int len = 0;
        sort(nums.begin(), nums.end());
        while(len < n && dummy[len] == nums[len]){
            len++;
        }
        int m = nums.size() - 1;
        while(m >= 0 && dummy[m] == nums[m]){
            m--;
        } 
        if(len == n)
            return 0;
        return m - len + 1;
    }
};