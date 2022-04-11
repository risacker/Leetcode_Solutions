#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
	//code
	int t;cin>>t;
    while (t--){
       int n,d;
       cin>>n>>d;
       vector<int>v(n),ans;
       for(int i=0;i<n;i++){
           cin>>v[i];
        }
        reverse(v.begin(),v.begin()+d);
        reverse(v.begin()+d,v.end());
        reverse (v.begin(),v.end());
        for(int i=0;i<n;i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
	return 0;
}