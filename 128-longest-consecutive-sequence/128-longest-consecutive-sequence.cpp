class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(s.find(nums[i]-1) == s.end()){
                int end = nums[i];
                while(s.find(end) != s.end())
                    end++;	
                ans = max(ans, end-nums[i]);
            }
        }
        return ans;
    }
};