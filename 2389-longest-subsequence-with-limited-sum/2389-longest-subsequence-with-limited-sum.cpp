class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<int>ans;
        int subs = 0;
        int i, j;
        sort(nums.begin(), nums.end());
        for(i = 1; i < n; i++){
            nums[i] += nums[i-1];
        }
        for(auto i : queries){
            for(j = 0; j < n; j++){
                if(nums[j] + subs > i)
                    break;
            }
            ans.push_back(j);
        }
        return ans;
    }
};