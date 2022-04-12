class Solution {
public:
    int jump(vector<int>& nums) {
         int pointer1 = 0, pointer2 = 1;
         int maxRight = nums[0], maxRightIndex = 0, jumpCount = 0;
         int n = nums.size(); 
         // corner case
         if (n == 1) 
             return 0;  
         while(maxRight < n-1) {
            int rightMostLimit = maxRight;
            while(pointer2 <= rightMostLimit && pointer2 < n) {
                if (maxRight < nums[pointer2]+pointer2) {
                    maxRight = nums[pointer2]+pointer2;
                    maxRightIndex = pointer2;
                } 
                pointer2++;
            }
            pointer1 = maxRightIndex;
            jumpCount++;
        } 
        return jumpCount+1;
    }
};