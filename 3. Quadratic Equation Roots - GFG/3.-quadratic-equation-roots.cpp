// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> quadraticRoots(int a, int b, int c) {
        // code here
       vector<int> p;
       double D = sqrt(b*b - 4*a*c);
       if(D >= 0){
           double d = (floor((-b+D)/(2.0*a)));
           double e = (floor((-b-D)/(2.0*a)));
           if(d >= e){
               p.push_back(d);
               p.push_back(e);
           }
           else{
               p.push_back(e);
               p.push_back(d);
           }
       }
       else 
           p.push_back(-1);
       return p;
    }
};

// { Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;
        Solution ob;
        vector<int> roots = ob.quadraticRoots(a, b, c);
        if (roots.size() == 1 && roots[0] == -1)
            cout << "Imaginary";
        else
            for (int i = 0; i < roots.size(); i++) cout << roots[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends