class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int prefix=0;
        unordered_map<int,int> map;
        int ans = 0;
        map[0] = 1;
        for(int i = 0;i < nums.size();i++){
            int sum = prefix + nums[i];
            prefix = (((sum%k)+k)%k);
            if(map.find(prefix) == map.end())
                map[prefix] = 1;
            else{
                ans += map[prefix];
                map[prefix]++;
            }
        }
        return ans;
    }
};