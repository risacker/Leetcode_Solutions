class Solution {
public:
    map<int, vector<pair<int, int>>> rows, cols;
    map<int, map<int, int>> mp;  
    int removeStones(vector<vector<int>>& g){
        for(auto n : g){ 
            int i = n[0]; 
            int j = n[1];
            rows[i].push_back({i, j});
            cols[j].push_back({i, j});
            mp[i][j] = 1;
        }
        int n = 0;
        for(auto e : g) 
            if(mp[e[0]][e[1]]) dfs(e[0], e[1]), n++;
        return g.size() - n;
    }
    void dfs(int i, int j){
        if(mp[i][j] == 0) 
            return;
        mp[i][j] = 0;
        for(auto n : rows[i]) 
            dfs(n.first, n.second);
        for(auto n : cols[j])
            dfs(n.first, n.second);
    }
};