class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int Sub = nums[0],Sum = 0;
        
        for (int n : nums) {
            if (Sum < 0)
                Sum = 0;
            Sum += n;
            Sub = max(Sub,Sum);
        }
        return Sub;
    }
};