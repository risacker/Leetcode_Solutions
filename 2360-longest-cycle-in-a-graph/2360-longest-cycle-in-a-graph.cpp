class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        int i,j,ans = -1;
        queue<int>q;
        vector<int>v(n, 0);
        vector<bool>go(n, 0);
        for(int i = 0; i < n; i++){
            if(edges[i] != -1)
                v[edges[i]] += 1;
        }
        for(int i = 0; i < n; i++){
            if(v[i] == 0)
                q.push(i);
        }
        while(!q.empty()){
            i = q.front();
            q.pop();
            go[i] = 1;
            j = edges[i];
            if(j != -1){
                --v[j];
                if(v[j] == 0)
                    q.push(j);
            }
        }
       for(int i = 0; i < n; i++){
           if(!go[i])
               ans = max(ans, solve(edges, i, go));
       }
        return ans;
    }
    
    int solve(vector<int>&edges, int i, vector<bool>&go){
        int j = i;
        int x = 0;
        while(1){
            j = edges[j];
            go[j] = 1;
            x++;
            if(j == i)
                break;
        }
        return x;
    }
};