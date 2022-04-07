class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> products(nums.size(), 1);
	    int r;
	    int lprod = 1;
	    int rprod = 1;
	    for(int l=0; l<nums.size(); l++) {
            r = nums.size() - l - 1;
		    products[l] *= lprod;
		    products[r] *= rprod;
		    lprod *= nums[l];
		    rprod *= nums[r];
	    }
	    return products;    
    }
};