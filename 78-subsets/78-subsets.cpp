class Solution {
public:
   vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans ={{}};
        vector<int> curr;
        for(auto j:nums)
		{
            int size=ans.size();
            for(int i=0;i<size;i++)
			{
                curr=ans[i];
                curr.push_back(j);
                ans.push_back(curr);
            }
        }
        return ans;
    }
};