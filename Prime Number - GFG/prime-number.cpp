// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int isPrime(int N){
        if(N == 1) // if N = 1 return 0
            return 0;
        for(int i = 2;i*i <= N;i++) // loop from 2 to sqrt(N)
            if(N%i == 0) // if N is divisble by any other number return 0 
                return 0;
        return 1; // return 1 if N is not divisible by any other number.
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.isPrime(N) << endl;
    }
    return 0; 
}  // } Driver Code Ends