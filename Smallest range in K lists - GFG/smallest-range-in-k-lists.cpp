// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


 // } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k){
          //code here
          set<pair<int,pair<int,int>>> s;
          for(int i = 0; i < k; i++){
              s.insert({KSortedArray[i][0],{i,0}});
           }
           pair<int,int> range = {0,100000};
           int minDiff = INT_MAX;
           while(true){
               auto p1 = *s.rbegin(); 
               auto p2 = *s.begin(); 
               int row = p2.second.first,col = p2.second.second;
               int currDiff = p1.first - p2.first;
               if(currDiff < minDiff){
                   minDiff = currDiff;
                   range = {p2.first,p1.first};
                }
                int old_ele = KSortedArray[row][col];
                auto it = s.find({old_ele,{row,col}});
                s.erase(it);
                col++;
                if(col == n) 
                  break;
                int new_ele = KSortedArray[row][col];
                s.insert({new_ele,{row,col}});
            }
       return (range);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

  // } Driver Code Ends