class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         if(size(nums) <= 2)
            return vector<vector<int>>();
        sort(nums.begin(), nums.end(), std::less<int>());
        vector<vector<int>> ans;
        for(int i = 0;i < size(nums)-2;i++){
            if(i != 0 && nums[i-1] == nums[i])
                continue;
            int start = i+1, end = size(nums)-1;
            while(start < end){
                if(nums[start] + nums[end] + nums[i] == 0){
                    ans.emplace_back(vector<int>{nums[i], nums[start], nums[end]});
                    start++;
                    end--;
                    while(nums[start] == nums[start-1] && start < end)
                        start++;
               }
                else if(nums[start] + nums[end] + nums[i] > 0){
                    end--;
                }
                else{
                    start++;
                }
            }
        }
        return ans;
    }
};