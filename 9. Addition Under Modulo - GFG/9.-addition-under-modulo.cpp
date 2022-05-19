// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long sumUnderModulo(long long a,long long b){
        // code here
        long c = a%1000000007;
        long d = b%1000000007;
        return (c+d)%1000000007;
    }
};

// { Driver Code Starts.
int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    long long a;
	    long long b;
	    cin>>a>>b;
	    Solution ob;
	    cout<<ob.sumUnderModulo(a,b)<<endl;
	}
	return 0;
}  // } Driver Code Ends