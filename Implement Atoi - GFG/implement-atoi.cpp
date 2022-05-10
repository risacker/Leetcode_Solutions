// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int ans = 0, factor = 1;
        if(str[0] == '-'){
            factor = -1;
            str[0] = '0';
        }
        for(auto c : str){
            if(c > '9' || c < '0'){
                return -1;
            }
            ans *= 10;
            ans += c - '0';
        }
        return factor*ans;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends