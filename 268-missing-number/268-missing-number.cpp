class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n * (n + 1) / 2;       
        int s = 0;
        for(int x : nums)
            s += x;        
        return sum-s;
    }
};