class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums[0].size();
        vector<int> ans;
        for(int i = 0;i < queries.size();i++){
            int k = queries[i][0];
            int trim = queries[i][1];
            vector<pair<string, int>> v;
            for(int j = 0;j < nums.size();j++){
                string str = nums[j].substr(n-1-trim+1, trim);
                v.push_back({str, j});
            }
            sort(v.begin(), v.end());
            ans.push_back(v[k-1].second);
        }
        return ans;
    }
};