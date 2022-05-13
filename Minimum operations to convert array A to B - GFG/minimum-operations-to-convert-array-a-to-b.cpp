// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minInsAndDel(int A[], int B[], int N, int M) {
        // code here
        map<int,int> mp;
        for(int i = 0;i < M;i++)
          mp[B[i]]++;
        vector<int> v;
        for(int i = 0;i < N;i++){
           if(mp[A[i]]){
               auto it = lower_bound(v.begin(), v.end(), A[i]);
               if(it == v.end())
                 v.push_back(A[i]);
               else
                (*it) = A[i];
           }
       }
       int ans = N+M-2*v.size();
       return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M;
        cin>>N>>M;
        
        int A[N], B[M];
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<M; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.minInsAndDel(A,B,N,M) << endl;
    }
    return 0;
}  // } Driver Code Ends