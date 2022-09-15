class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();        
        sort(changed.begin(), changed.end());
		vector<int>ans;
        for(int i = 0; i < n; i++) {
            int num = changed[i];
            if(num < 0) 
                continue; 
            auto idx = lower_bound(changed.begin()+i+1, changed.end(), 2*num);
            if(idx != changed.end() && *idx == 2*num) {
                *idx = -1; //mark it
                 ans.push_back(num); //found it
            } 
            else
                return {}; //not found
        }
        return ans;
    }
};