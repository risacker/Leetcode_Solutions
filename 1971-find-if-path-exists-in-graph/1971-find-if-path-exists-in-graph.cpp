class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        vector<int> visited(n+1, 0);
        for(int i = 0; i < edges.size(); ++i){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int>q;
        q.push(source);
        while(!q.empty()){
            int node = q.front();
            visited[node] = 1;
            q.pop();
            if(node == destination) 
                return 1;
            for(auto &edge : adj[node]){
                if(!visited[edge]){
                    q.push(edge);
                }
            }
        }
        return 0;
    }
};