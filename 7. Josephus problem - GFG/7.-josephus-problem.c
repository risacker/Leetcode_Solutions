// { Driver Code Starts
//Initial Template for C

#include <stdio.h>


 // } Driver Code Ends
//User function Template for C

int josephus(int n, int k)
{
   //Your code here
   int ans = 0;
   for(int i = 1; i <= n; i++){
       ans = (ans+k) % i;
    }
    return ans+1;
}

// { Driver Code Starts.

int main() {
	
	int t;
	scanf("%d", &t);//testcases
	while(t--)
	{
		int n,k;
		scanf("%d%d", &n, &k);//taking input n and k
		
		//calling josephus() function
		printf("%d\n", josephus(n,k));
	}
	return 0;
}  // } Driver Code Ends