// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        deque<int>dq1, dq2;
        vector<int>ans, temp;
        for(int i = 0; i < n; i++){
            if(!dq1.empty() && dq1.front() == (i - k)){
                dq1.pop_front();
            }
            if(!dq2.empty() && dq2.front() == (i - k)){
                dq2.pop_front();
            }
            while(!dq1.empty() && arr[i] >= arr[dq1.back()]){
                dq1.pop_back();
            }
            while(!dq2.empty() && arr[i] <= arr[dq2.back()]){
                dq2.pop_back();
            }
            dq1.push_back(i);
            dq2.push_back(i);
            if(i >= k - 1){
                ans.push_back(arr[dq1.front()]);
                temp.push_back(arr[dq2.front()]);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}  // } Driver Code Ends