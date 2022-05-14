// { Driver Code Starts
//Initial Template for C



#include<stdio.h>

 // } Driver Code Ends
//User function Template for C


void rotate(int n,int a[][n]){
    //code here
    int tl,tr,bl,br;
    for(int i = 0;i < n;i++){
        for(int j = i;j < n-i-1;j++){
            tl = a[i][j]; 
            tr = a[j][n-i-1]; 
            br = a[n-i-1][n-j-1]; 
            bl = a[n-j-1][i]; 
            a[i][j] = tr; 
            a[j][n-i-1] = br; 
            a[n-i-1][n-j-1] = bl; 
            a[n-j-1][i] = tl; 
        }
   }
}

// { Driver Code Starts.

int main()
{
    int t;
    scanf("%d",&t); 
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[n][n];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                scanf("%d",&a[i][j]);
        }
        rotate(n,a);
        for (int i = 0; i < n; ++i)
        {
            for(int j=0; j<n; j++)
                printf("%d ",a[i][j]);
            printf("\n");
        }
    }
    return 0;
}

  // } Driver Code Ends