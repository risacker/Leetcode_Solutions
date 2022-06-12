class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0, ans = 0, sum = 0;
        unordered_map<int,int> mp; //to store the index and value at that index 
        for(int i = 0; i < n; i++){
            if(mp.find(nums[i]) != mp.end()){ //if the value is already available in map
                int right = mp[nums[i]];  
                for(int j = left; j <= right; j++){ //sliding the window size 
                    sum -= nums[j];
                    mp.erase(nums[j]);
                }
                left = right+1; //left of new window
            }
            mp[nums[i]] = i;
            sum += nums[i];
            ans = max(ans, sum);    
        }
        return ans;
    }
};