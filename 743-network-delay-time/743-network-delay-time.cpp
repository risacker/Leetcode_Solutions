class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int S) {
        vector<vector<int>> adj[N+1];
        for(auto x:times){
            adj[x[0]].push_back({x[1],x[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
        pq.push({0, S});
        vector<int> ans(N+1,INT_MAX);
        ans[S] = 0;
        while(!pq.empty())
        { 
            int u = pq.top().second; 
            pq.pop(); 
            for (auto it : adj[u]) {
                int v = it[0];
                int weight = it[1];
                if (ans[v] > (weight + ans[u])) {
                    ans[v] = weight + ans[u]; 
                    pq.push({ans[v], v});    
                }
            }
        } 
        int time = -1;
        for(int i = 1;i <= N;i++){
            time = max(ans[i],time);
        }   
        return (time == INT_MAX)? -1 : time;
    }
};