class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        int sum;
        for(int i=1;i<=9;i++){
            sum=0;
            for(int j=i;j<=9;j++){
                sum=sum*10+j;
                if(sum>=low && sum<=high){
                    ans.push_back(sum);
                }
                if(sum>high){
                    break;
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};