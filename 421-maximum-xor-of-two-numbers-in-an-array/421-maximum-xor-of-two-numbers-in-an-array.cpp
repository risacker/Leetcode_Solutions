class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        int ans=0;
        for(int i=0; i<n ; i++){
            if(ans>=pow(2,floor(log2(nums[i])+1))-1) 
                continue;
            for(int j=0; j<n; j++){
                if(i != j)
                    ans = max(ans, nums[i]^nums[j]);
            }
        }
        return ans;
    }
};