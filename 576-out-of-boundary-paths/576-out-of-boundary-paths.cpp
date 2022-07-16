class Solution {
public:
        int memo[51][51][51];    
        int mod = 1000000007;
      int findPaths1(int m, int n, int maxMove, int R, int C){
          if(maxMove < 0)     
              return 0;
          if(R == m || C == n || R == -1 || C == -1)         
              return 1;
          if(memo[R][C][maxMove]!=-1)   
              return memo[R][C][maxMove];
          int ans = 0;
          ans = (ans + findPaths1(m, n, maxMove-1, R-1, C))%mod;     
          ans = (ans + findPaths1(m, n, maxMove-1, R+1, C))%mod;     
          ans = (ans + findPaths1(m, n, maxMove-1, R, C-1))%mod;      
          ans = (ans + findPaths1(m, n, maxMove-1, R, C+1))%mod;     
          memo[R][C][maxMove] = ans;         
          return ans;
    }
    
    int findPaths(int m, int n, int maxMove, int R, int C){
        memset(memo, -1, sizeof(memo));             
        return findPaths1(m, n, maxMove, R, C);
    }
};