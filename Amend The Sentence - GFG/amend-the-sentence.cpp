// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string amendSentence (string s){
        // your code here
        string ans;
        int n = s.size(), start = 0, end = 1;
        while(end <= n){
            if((isupper(s[end])) || end == n){
                string st = s.substr(start, end - start);
                st[0] = tolower(st[0]);
                ans += st;
                ans.push_back(' ');
                start = end;
            }
            end++;
        }
        ans.pop_back();
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		Solution ob;
		cout << ob.amendSentence (s) << endl;
	}
}  // } Driver Code Ends