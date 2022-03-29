class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i = 0; i < heights.size()-1; i++){
            if(heights[i+1] > heights[i]){
                int diff = heights[i+1]-heights[i];
                q.push(diff);
                if(q.size() <= ladders){
                    continue;
                }       
                bricks -= q.top();
                q.pop();
                if(bricks < 0)
                    return i;
            }
        }
        return heights.size()-1;
    }
};