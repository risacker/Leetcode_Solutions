class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        int up = 1, down = 1;
        if(n < 2)
            return n;
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i-1])
                up = down + 1;
            else if(nums[i] < nums[i-1])
                down = up + 1;
        }
        return max(up, down);
    }
};