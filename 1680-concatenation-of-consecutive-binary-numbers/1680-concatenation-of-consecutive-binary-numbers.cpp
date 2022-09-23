class Solution {
public:
    int concatenatedBinary(int n) {
        long ans = 0;
        long mod = 1e9+7;
        long cnt = 0;
        for(int i = 1; i <= n; ++i) {   
            if((i & (i - 1)) == 0) 
                cnt++;
            ans = ((ans << cnt) + i) % mod;
        }
        return ans;
    }
};