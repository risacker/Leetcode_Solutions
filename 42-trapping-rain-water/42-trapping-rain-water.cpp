class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> mxL(n);
        vector<int> mxR(n);    
        mxL[0] = height[0];
        for(int i = 1;i < n;i++)
            mxL[i] = max(mxL[i-1],height[i]);    
        mxR[n-1] = height[n-1];
        for(int i = n-2;i >= 0;i--)
            mxR[i] = max(mxR[i+1], height[i]);    
        int water[n];
        int sum = 0;
        for(int i = 0;i < n;i++){
            water[i] = min(mxL[i],mxR[i])-height[i];
            sum = sum+water[i];
        }
        return sum;
    }
};
