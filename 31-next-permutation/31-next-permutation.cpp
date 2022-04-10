class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), k, l;
    	for (k = n - 2; k >= 0; k--) {// finding breakpoint which we know the 1st breakpoint can be at second last index
            if (nums[k] < nums[k + 1]) {// linearly iterate from 2nd last index and try to find breakpoint that is k and if we find the breakpoint then break out.
                break;
            }
        }
    	if (k < 0) {// if there's no breakpoint then simply reverse it
    	    reverse(nums.begin(), nums.end());
    	} 
        else {// if there's a breakpoint then again we linearly iterate from back
    	    for (l = n - 1; l > k; l--) {
                if (nums[l] > nums[k]) {// if any element is greater then break out
                    break;
                }
            } 
    	    swap(nums[k], nums[l]);// swap it
    	    reverse(nums.begin() + k + 1, nums.end());//everything on right will be reversed using inbuilt stl
            //if reverse fucn is not allowedin the interview then use 2 pointer approach to reverse it
        }
    }
};