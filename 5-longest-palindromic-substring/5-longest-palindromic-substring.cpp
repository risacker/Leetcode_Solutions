class Solution {
public:
    string longestPalindrome(string A) {
       int N = A.size();   
        if(N == 0)
            return "";
        if(N == 1)
            return A ;   
       bool t[N][N];
       memset(t, 0, sizeof t);
       for(int i = 0;i < N;i++)
           t[i][i] = 1 ;    
        int mx = 1 ; 
        int in = 0 ;     
       for(int L = 2;L <= N ;L++ )
       for(int i = 0 ;i+L-1 < N; i++){
           int j = i+L-1;
           t[i][j] = A[i] == A[j] && (L == 2 || t[i+1][j-1]) ;     
           if(t[i][j]){
               if(L > mx){
                   mx = L ; 
                   in = i ; 
               }    
           }
       }
       return A.substr(in , mx);  
    }
};