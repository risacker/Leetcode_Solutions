// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    vector<long long> lcmAndGcd(long long A , long long B) {
        // code here
       long long C=A;
       long long D=B;
       while(A!=B){
           if(A>B){
               A=A-B;
           }
           if(B>A){
               B=B-A;
           }
       }
       long long gcd = A;
       long long lcm = (C*D)/gcd;
       return {lcm , gcd};
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends