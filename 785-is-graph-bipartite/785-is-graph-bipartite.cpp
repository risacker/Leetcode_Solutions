class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // To store color of the node
        unordered_map<int,int> color;
        stack<int> s;
        unordered_map<int,int> visited;
        visited[0] = 1;
        for(int i = graph.size()-1;i >= 0;i--){
            s.push(i);
        }
        while(!s.empty()){
            int i = s.top();
            s.pop();
            cout<<color[i]<<"-"<<i<<endl;
			// If node hase no color assign it 1
            if(color[i] == 0){
                color[i] = 1;
            }
            for(int j = 0;j < graph[i].size();j++){
                if(visited[graph[i][j]] != 1){
                    s.push(graph[i][j]);
                    visited[graph[i][j]] = 1;
                }
				// If current node color is 1 and adjecent node does not have color then assign it different color
                if(color[graph[i][j]] == 0 && color[i] == 1){
                    color[graph[i][j]] = 2;
                }
				// If current node color is 2 and adjacent node does not have color then assign it 1 color
                else if(color[graph[i][j]] == 0 && color[i] == 2){
                    color[graph[i][j]] = 1;
                }
				// both adjacent node have same color return false
				else if(color[graph[i][j]] == color[i]){
                    return false;
                }
            }
        }
        return true;
    }
};