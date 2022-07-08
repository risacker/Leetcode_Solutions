class Solution {
public:
    
    int recurr(vector<int> &houses, vector<vector<int>> &cost, int m, int n, int currHouse, int lastSelect, int currNHs, int target, map<pair<int,pair<int,int>>,int> &mm) {
         
        // memoization
        auto memoPair = make_pair(lastSelect, make_pair(currHouse,currNHs));
        if(mm.find(memoPair) != mm.end()) {
            return mm[memoPair];
        }
        
        // cases that would result in -1
        if(currNHs > target or (currNHs < target and currHouse == m)) {
            mm[memoPair] = 1e9;
            return 1e9;
        }
        
        // acceptable cases
        if(currNHs == target and currHouse == m) {
            mm[memoPair] = 0;
            return 0;
        }
        
        // house already painted
        if(houses[currHouse] != 0) {
            
        // if prev house is same colored then don't increase NHs 
        if(houses[currHouse] == lastSelect) {
            mm[memoPair] = recurr(houses, cost, m, n,currHouse + 1, lastSelect, currNHs, target, mm);
                return mm[memoPair];
            }
            
            // else increase NHs 
            else {
                mm[memoPair] = recurr(houses, cost, m, n, currHouse + 1, houses[currHouse], currNHs + 1, target, mm);
                return mm[memoPair];
            }
        }
        
        // same for unpainted house but we add cost each time since we are supposed to paint it
        int minm = 1e9;
        for(int i = 0; i < n; i++) {
            if(i + 1 == lastSelect) {
                minm = min(minm,cost[currHouse][i] + recurr(houses, cost, m, n, currHouse + 1, i + 1, currNHs, target, mm));
            }
            else {
                minm = min(minm,cost[currHouse][i] + recurr(houses, cost, m, n, currHouse + 1, i + 1, currNHs + 1, target, mm));
            }
        }   
        mm[memoPair] = minm;
        return minm;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        map<pair<int,pair<int,int>>,int> mm;
        int ans = recurr(houses, cost, m, n, 0, -1, 0, target, mm);
        if(ans == 1e9) {
            return -1;
        }
        return ans;
    }
};