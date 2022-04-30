class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& eqs, vector<double>& vals, vector<vector<string>>& quers) {   
        unordered_map<string, int> varVerMap;
        int v = 0;
        for(auto vars: eqs){
            if(varVerMap.count(vars[0]) == 0)
                varVerMap[vars[0]] = v++;
            if(varVerMap.count(vars[1]) == 0)
                varVerMap[vars[1]] = v++;
        }
        vector<vector<int>> graph(v);
        vector<vector<double>> edgeWt(v, vector<double>(v, -1)); 
        for(int i = 0; i < eqs.size(); ++i){
            int u = varVerMap[ eqs[i][0] ];
            int v = varVerMap[ eqs[i][1] ];
            double wt = vals[i];
            graph[u].push_back(v);
            edgeWt[u][v] = wt;
            graph[v].push_back(u);
            edgeWt[v][u] = 1/wt;
        }   
        vector<double> res;
        for(auto qry: quers) {
            if(varVerMap.count(qry[0]) == 1 && varVerMap.count(qry[1]) == 1) {
                int s = varVerMap[qry[0]];
                int d = varVerMap[qry[1]]; 
                res.push_back(getProdOfPath(graph, edgeWt, s, d));
            }
            else {
                res.push_back(-1.0);
            }
        }
        return res;
    }
    
    double getProdOfPath(vector<vector<int>>& graph, vector<vector<double>>& edgeWt, int s, int d) {
        int V =  graph.size();
        vector<bool> visit(V, false);
        if(s == d) 
            return 1.0;
        visit[s] = true;
        for(int u: graph[s]) {
            if(visit[u] == false) {
                double prod = edgeWt[s][u]*FindPathProdDFS(graph, edgeWt, visit, u, d);
                if(prod > 0)
                    return prod;
            }   
        }
        return -1.0;
    }
    double FindPathProdDFS(vector<vector<int>>& graph, vector<vector<double>>& edgeWt, vector<bool>& visit, int u, int d) {
        if(u == d)  
            return 1.0;
        visit[u] = true;
        for(int v: graph[u]) {
            if(visit[v] == false) {
                double prod = edgeWt[u][v]*FindPathProdDFS(graph, edgeWt, visit, v, d);
                if(prod > 0)
                    return prod;
            }
        }
        return -1.0;
    }
};