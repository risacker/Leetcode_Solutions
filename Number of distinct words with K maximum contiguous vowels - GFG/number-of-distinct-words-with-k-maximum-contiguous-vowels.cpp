// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    long long t[1001][1001];
    long long solve(int n , int k , int cnt ){
      if(n == 0)
      return 1;
      if(t[n][cnt] != -1)
         return t[n][cnt];
      if(cnt < k){
          return t[n][cnt] = (21*solve(n-1, k, 0) + 5*solve(n-1, k , cnt+1)) % 1000000007;
      }
      if(cnt == k)
      {
          return t[n][cnt] = (21*solve(n-1, k, 0)) % 1000000007;
      }
  }
  
    int kvowelwords(int n, int k) {
        // Write Your Code here
        memset(t, -1, sizeof(t)) ;
        return solve(n, k, 0) % 1000000007;
    }

};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;int K;
        cin >>N>>K;
        
        Solution ob;
        int ans = ob.kvowelwords(N,K);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends