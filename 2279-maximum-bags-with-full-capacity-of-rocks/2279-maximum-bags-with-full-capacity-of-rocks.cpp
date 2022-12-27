class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> v;
        for(int i = 0; i < n; ++i){
            v.push_back(capacity[i] - rocks[i]);
        }
        sort(v.begin(), v.end());
        int ans = 0;
        for(int i = 0; i < n; ++i){
            if(additionalRocks < v[i]) 
                break;
            additionalRocks -= v[i];
            ans++;
        }
        return ans;
    }
};