class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 2;
        if(nums.size()<=2) 
            return nums.size(); 
        for (int curr = 2; curr < nums.size(); curr++)
        {
            if (nums[curr] != nums[i-2])
            {
                nums[i++] = nums[curr];
            }
        }
        return i;  
    }
};