// { Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int numOfWays(int n, int x){
        // code here
        vector<long long int> v(n,0);
        for (int i = 0; i < n; ++i){
            v[i] = (long long int)pow(i+1,x);
        }
        int sum=n;
        long long int dp[n+1][sum+1];
        for(int i = 0;i <= n;i++)
            dp[i][0] = 1;
        for(int j = 1;j <= sum;j++)
            dp[0][j] = 0;
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= sum; ++j){
                dp[i][j] = dp[i-1][j]%(1000000007);
                if(j >= v[i-1])
                   dp[i][j] = (dp[i][j]+dp[i-1][j-v[i-1]])%(1000000007);
            }
        }
        return dp[n][sum]%(1000000007);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}
  // } Driver Code Ends