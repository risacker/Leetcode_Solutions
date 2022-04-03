class Solution {
    #define data vector<int>
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(const auto &x : flights){
            adj[x[0]].push_back({x[1], x[2]});
        }
        set<data> q;
        q.insert({0,src,k});
        while(q.size() > 0){
            auto x = *q.begin(); q.erase(q.begin());
            int cost = x[0], node = x[1], stops = x[2];
            if(node == dst)
                return cost;
            if(stops >= 0){
                for(auto &y : adj[node]){
                    q.insert({y.second + cost, y.first, stops-1});
                }
            }
        }
        return -1;
    }
};