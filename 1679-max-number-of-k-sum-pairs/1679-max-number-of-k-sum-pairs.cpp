class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int, int> ans;
        int cnt = 0;
        for(int i : nums){
            if(ans[k - i]){
                ans[k - i]--;
                cnt++;
            }
            else
                ans[i]++;
        }
        return cnt;
    }
};