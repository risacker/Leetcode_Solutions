class Solution {
    int maxLength = 1;
    int dfs(int i, vector<vector<int>> &child, string &s){
        int maxTreePath = 0, maxStraightPath = 0;
        for(auto j : child[i]){
            int x = dfs(j, child, s);
            if(s[i] == s[j])
                x = 0;
            maxTreePath = max(maxTreePath, maxStraightPath + x);
            maxStraightPath = max(maxStraightPath, x);
        }
        maxLength = max(maxLength, maxTreePath + 1);
        return maxStraightPath + 1;
    }
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> child(n);
        for(int i = 1; i < n; i++)
            child[parent[i]].push_back(i);    
        dfs(0, child, s);
        return maxLength;
    }
};