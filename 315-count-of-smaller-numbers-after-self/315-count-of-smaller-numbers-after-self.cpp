class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        const int mod = 10001;
        const int m = 20001;
        int n = nums.size();
        vector<int> ans(n), bit(m+1);
        for (int i = n-1; i >= 0; --i) {
            for (int j = nums[i]+mod-1; j; j &= j-1)
                ans[i] += bit[j];
            for (int j = nums[i]+mod; j <= m; j += j&-j)
                ++bit[j];
        }
        return ans;
    }
};