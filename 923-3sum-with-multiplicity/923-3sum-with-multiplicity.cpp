class Solution {
public:
    int MOD = 1e9+7;
    int freq[201];
    int threeSumMulti(vector<int>& arr, int target) {
        int ans = 0;
        for(int k = 0; k < (int)arr.size(); k++) {
           int t = target - arr[k];
           if(t >= 0 && t <= 200) 
               ans = (ans + freq[t]) % MOD;
           for(int i = 0; i < k; i++) 
               freq[arr[i] + arr[k]] = (freq[arr[i] + arr[k]] + 1) % MOD;
        }
        return ans;
    }
};