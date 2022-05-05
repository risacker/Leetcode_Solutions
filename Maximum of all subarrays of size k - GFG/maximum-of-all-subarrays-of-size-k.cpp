// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k){
        // your code here
       multiset<int>s;//multi set allows duplication 
       vector<int>ans;
       for(int i = 0;i < k;i++){
           s.insert(arr[i]);
       }
       ans.push_back(*(s.rbegin()));
       for(int i = k;i < n;i++){
           s.insert(arr[i]);
           int x = arr[i-k];
           auto it = s.find(x);
           s.erase(it);//delete first occurence only not all
           ans.push_back(*(s.rbegin()));
       }
       return ans;
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends