// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++


const int n = 1e2, m = 1e5;
bool dp[n][m + 1];
class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for (int i = 0; i < N; i++)
            sum += arr[i];
        if (sum & 1) 
          return false;
        memset(dp, false, sizeof(dp));
        dp[0][0] = dp[0][arr[0]] = true;
        for(int i = 1; i < N; i++) {
            dp[i][0] = true;
            for (int j = 0; j <= sum; j++) {
                dp[i][j] |= dp[i - 1][j];
                dp[i][j + arr[i]] |= dp[i - 1][j];
            }
        }
        return dp[N - 1][sum >> 1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends