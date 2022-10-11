class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int low = INT_MAX, mid = INT_MAX;
        int n = nums.size();
         //edge case: if size of array is less than 3 we can't make triplate
        if(n < 3)
            return false;      
        for(int i = 0;i < n;i++){
            if(nums[i] > mid) 
                return true;
            else if(nums[i] < low) 
                low = nums[i];
            else if(nums[i] > low && nums[i] < mid) 
                mid = nums[i];
        }
        return false;
    }
};