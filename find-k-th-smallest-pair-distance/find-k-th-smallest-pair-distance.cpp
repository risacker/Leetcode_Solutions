class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int lo = 0;
        int hi = nums[nums.size() - 1] - nums[0];
        while(lo < hi) {
            int mid = (lo + hi) / 2;
            int cnt = 0, left = 0;
            for(int right = 0; right < nums.size(); ++right) {
                while(nums[right] - nums[left] > mid) 
                    left++;
                cnt += right - left;
            }
            if(cnt >= k) 
                hi = mid;
            else 
                lo = mid + 1;
        }
        return lo;
    }
};