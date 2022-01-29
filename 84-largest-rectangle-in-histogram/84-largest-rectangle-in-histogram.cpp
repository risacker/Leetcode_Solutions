class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
      int res = 0, curr = 0, n = heights.size();
        stack<int> s;
        for(int i=0;i<n;i++){
            while(s.empty() == false && heights[s.top()]>=heights[i]){
                int top = s.top();
                s.pop();
                if(s.empty())
                    curr = heights[top]*i;
                else
                    curr = heights[top]*(i-s.top()-1);
                res = max(curr,res);
            }
            s.push(i);
        }
        while(s.empty() == false){
                int top = s.top();
                s.pop();
                if(s.empty())
                    curr = heights[top]*n;
                else
                    curr = heights[top]*(n-s.top()-1);
                res = max(curr,res);
            }
        return res;  
    }
};