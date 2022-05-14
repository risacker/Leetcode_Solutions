// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    vector<int>w(arr,arr+n),T[n+1];
        int sum = accumulate(w.begin(),w.end(),0);
        int i,j,k,l;
        for(i = 0;i < n+1;++i){
            for(j = 0;j < sum+1;++j){
                T[i].push_back(-1);
            }
        }
        for(i = 0;i < n+1;++i){
            for(j = 0;j < sum+1;++j){
                if(j == 0){
                    T[i][j] = 1;
                }
                else if(i == 0){
                    T[i][j] = 0;
                }
                else if(w[i-1] <= j){
                    T[i][j] = (T[i-1][j] || T[i-1][j-w[i-1]]);
                }
                else{
                    T[i][j]  = T[i-1][j];
                }
            }
        }
        vector<int> pos;
        for(i = 0;i < sum+1;++i){
            if(T[n][i]==1){
              pos.push_back(i);
            }
        }
        int p = pos.size();
        if(p%2 ==0){
            k = p/2;
        }
        else{
            k = (p+1)/2;
        }
        int mid = pos[k-1];
        int rem = sum - mid;
        int val = rem - mid;
        return val;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends