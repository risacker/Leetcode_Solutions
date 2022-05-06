// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        string ans = "";
        while(n > 26){
           int x = n%26;
           if(x == 0){ 
             ans = 'Z'+ans;
             n--;
           }
           else 
             ans = (char)(x - 1 + 'A') + ans;
           n /= 26;
       }
       ans = (char)(n - 1 + 'A') + ans;
       return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}
  // } Driver Code Ends