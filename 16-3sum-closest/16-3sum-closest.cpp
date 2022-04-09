class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        long long int i, j, k, res = INT_MAX;
        for(i = 0; i < nums.size()-2; i++) {
            j = i+1, k = nums.size()-1;
            while(j < k) {
                int curr_sum = nums[i]+nums[j]+nums[k];
                if(abs(curr_sum - target) < abs(res - target))
                    res = curr_sum;
                if(curr_sum > target)
                    k--;
                else if(curr_sum < target)
                    j++;
                else
                    return curr_sum;
            }
        }
        return res;
    }
};