class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> result;
        int m = mat.size();
        int n = mat[0].size();
        unordered_set<int> M;
        for(int j = 0; j <= n;j++){
            for(int i = 0; i < m;i++){
                if(j == n || mat[i][j] == 0){
                    if(M.find(i) == M.end()){
                        result.push_back(i);
                        M.insert(i);
                        if(result.size() == k){
                            return result;
                        }
                    }
                }
            }
        }
        return result;
    }
};