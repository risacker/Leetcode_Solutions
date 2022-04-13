class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        long long n = cardPoints.size();
        long long sum = 0;
        for(long long i = 0;i < k;i++)
            sum += cardPoints[i]; 
        long long maxi = sum;   
        long long c = n;
        long long d = k-1; 
        while(c-- > n - k){
            if(d < 0 )
                d = n-1;
            sum = sum - cardPoints[d--] + cardPoints[c];
            maxi = max(sum, maxi);
           
        }
        return maxi;
        
    }
};