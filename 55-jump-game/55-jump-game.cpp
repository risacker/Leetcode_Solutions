class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jumps = 1;
        for(int i = 0;i < nums.size(); i++){
            jumps--;
            jumps = max(jumps, nums[i]);
            if(jumps == 0) 
                return i == nums.size()-1;
        }
        return true;
    }
};