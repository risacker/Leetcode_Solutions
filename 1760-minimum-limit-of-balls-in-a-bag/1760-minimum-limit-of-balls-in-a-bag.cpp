class Solution {
private:
    int operation(vector<int>& nums, int mid){
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] >= mid){
                int s = (nums[i]%mid == 0) ? (nums[i]/mid) : (nums[i]/mid + 1);
                ans += s-1;
            }
        }
        return ans;
    }
    
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int right = *max_element(nums.begin(), nums.end());
        int left = 1;
        while(left < right){
            int mid = (left + right) / 2;
            if(operation(nums, mid) <= maxOperations) 
                right = mid;
            else 
                left = mid + 1;
        }
        return right;
    }
};