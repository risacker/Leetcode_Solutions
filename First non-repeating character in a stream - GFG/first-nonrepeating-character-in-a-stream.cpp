// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    unordered_set<char>s;
		    list<char>list;
		    string ans = "";
		    int n = A.size();
		    for(int i = 0;i < n;i++){
		        if(s.find(A[i]) != s.end()){
		            list.remove(A[i]);
		            if(list.size() > 0)
		                ans += list.front();
		            else
		                ans += '#';
		        }
		        else{
		            list.push_back(A[i]);
		            s.insert(A[i]);
		            ans += list.front();
		        }
		    }
		    
		    return ans;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends