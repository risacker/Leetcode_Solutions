// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
     bool isPrime(int n){
        if(n <= 1)
            return false;
        for(int i = 2;i <= sqrt(n);i++)
            if(n%i == 0)
                return false;
        return true ;
    }
    
    int exactly3Divisors(int N){
        int counter = 0; 
        N = sqrt(N);     
        for(int i = 1;i <= N;i++){
            if(isPrime(i)) 
                counter++;
        }
        return counter;
    }
    
};

// { Driver Code Starts.


int main()
 {
    int T;
    
    //taking testcases
    cin>>T;
    while(T--)
    {
        int N;
        
        //taking N
        cin>>N;
        Solution ob;
        //calling function exactly3Divisors()
        cout<<ob.exactly3Divisors(N)<<endl;
    }
	return 0;
}  // } Driver Code Ends