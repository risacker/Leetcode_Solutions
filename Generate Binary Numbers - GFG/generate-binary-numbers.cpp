// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

//Function to generate binary numbers from 1 to N using a queue.
vector<string> generate(int N){
	// Your code here
	vector<string> v;
    queue<string> q;
    q.push("1");
    for(int i = 0; i < N; i++){
        v.push_back(q.front());
        q.push(q.front()+"0");
        q.push(q.front()+"1");
        q.pop();
    }
    return v;
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends