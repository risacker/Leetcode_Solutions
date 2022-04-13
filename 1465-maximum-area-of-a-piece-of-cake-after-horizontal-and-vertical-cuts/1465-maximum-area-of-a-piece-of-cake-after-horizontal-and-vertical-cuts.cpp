class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        long long mod = 1000000007;
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h%mod);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w%mod);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int hdiff = 0;
        int vdiff = 0;
        for(int i = 0;i < horizontalCuts.size()-1;i++){
            int a = ((horizontalCuts[i+1]%mod)-(horizontalCuts[i]%mod))%mod;
            hdiff = max(hdiff, a);
        }
        for(int i = 0;i < verticalCuts.size()-1;i++){
            int a = ((verticalCuts[i+1]%mod)-(verticalCuts[i]%mod))%mod;
            vdiff = max(vdiff, a);
        }
        
        int ans = (hdiff%mod)*(vdiff%mod)%mod;
        return ans;
    }
};