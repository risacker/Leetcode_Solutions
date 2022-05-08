// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s){
        // Your code here
        vector<int> ans;
        long long curr_s = 0;
        long long st = 0;
        long long i = 0;
        while(curr_s != s && st < n){
            curr_s += arr[i];
            i++;
            while(curr_s > s){
                curr_s -= arr[st];
                st++;
            }
        }
        if(curr_s == s){
            ans.push_back(st+1);
            ans.push_back(i);
            return ans;
        }
        ans.push_back(-1);
        return ans;
    }
};

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends