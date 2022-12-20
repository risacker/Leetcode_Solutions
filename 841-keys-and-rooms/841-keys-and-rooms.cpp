class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        unordered_set<int> seen;
        seen.insert(0);
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int nextRoom : rooms[u]){
                if(seen.count(nextRoom)) 
                    continue;
                seen.insert(nextRoom);
                q.push(nextRoom);
            }
        }
        return seen.size() == n;
    }
};