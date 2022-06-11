class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int i = 0; // starting point of window
        int j = 0; // ending point of window
        int total = accumulate(nums.begin(), nums.end(), 0); // total sum of the array
        int target = total - x; // target sum
        int maxm = INT_MIN; // max length
        int sum = 0; // sum of the elements in the window
        for(j = 0; j < n; j++){ 
            sum += nums[j];
            while(i <= j && sum > target){
                sum -= nums[i];
                i++;
            }
            if(sum == target)
                maxm = max(maxm, j - i + 1);
        }
        return (maxm == INT_MIN) ? -1 : n - maxm;
    }
};