class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trust_judge(n+1, 0);
        for(auto t : trust){
            trust_judge[t[0]]--;
            trust_judge[t[1]]++;
        }    
        for(int i = 1; i <= n; i++)
            if(trust_judge[i] == n-1) 
                return i;
        return -1;
    }
};