class Solution {
public:
     void rotate(vector<int>& nums, int k) {
        if(nums.size()!=1){
            k = k%nums.size();
        vector<int> tmp(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            if(i+k <= nums.size()-1)
            {
                tmp[i+k] = nums[i];
            }
            else
            {
                int dif = i+k-(nums.size()-1)-1;
                tmp[dif] = nums[i];
            }
        }
        nums = tmp;
      }
    }
};