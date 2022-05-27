class Solution {
public:
    vector<int> getRow(int rowIndex) {
         vector<int> ans = {1};
         for(int k = 1; k <= rowIndex; k++)
             ans.push_back((int)((ans.back() * (long long)(rowIndex - k + 1)) / k));
         return ans;
    }
};