class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0;i < n;i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            for(int j = i+1;j < n;j++){
                if(j != (i+1) && nums[j] == nums[j-1])
                    continue;
                int rem = target-(nums[i]+nums[j]);
                int p1 = j+1;
                int p2 = n-1;
                while(p1 < p2){
                    int curr = nums[p1]+nums[p2];
                    if(curr < rem)
                        p1++;
                    else if(curr > rem)
                        p2--;
                    else{
                        ans.push_back({nums[i], nums[j], nums[p1], nums[p2]});
                        if(nums[p1] == nums[p2])
                            break;
                            int x = nums[p1];
                            int y = nums[p2];
                            while(x == nums[p1])
                                p1++;
                            while(y == nums[p2])
                                p2--;
                    }
                }
            }
        }
        return ans;        
    }
};