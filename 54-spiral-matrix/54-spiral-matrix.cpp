#define pb push_back
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int r = 0;
        int c = 0;
        vector<int> ans;
        while(r < m && c < n){
            for(int i = r;i < m;i++)
                ans.pb(mat[r][i]);
            c++;
            for(int i = c;i < n;i++)
                ans.pb(mat[i][m-1]);
            m--;
            if(r < m && c < n){   
                for(int i = m-1;i >= r;i--)
                    ans.pb(mat[n-1][i]);
                n--;
                for(int i = n-1;i >= c;i--)
                    ans.pb(mat[i][r]);
                r++;
               }
       }   
      return ans;  
    }
};