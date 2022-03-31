class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int i = 0;
        int n = nums.size();
        vector<int> ans;
        while(i < n) {
                while(!ans.empty() && ans.back() > nums[i] && n-i-1 >= k-ans.size()) 
                    ans.pop_back();
            if(ans.size() < k)
            ans.push_back(nums[i]);
            i++;
        }
     return ans;
    }
};