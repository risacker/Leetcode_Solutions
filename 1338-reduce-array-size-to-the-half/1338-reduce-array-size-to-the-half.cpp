class Solution {
public:
    int minSetSize(vector<int>& arr){
        int n = arr.size();
        int ans = 0;
        int cnt = 0;
        vector<int> v; 
        unordered_map<int, int> unmap;
        for(int i = 0; i < n; i++)  
          unmap[arr[i]]++;
        for(auto x : unmap)
           v.push_back(x.second);
        if(v.size() == 1)
            return 1;
        sort(v.begin(), v.end());
        for(int i = v.size()-1; i >= 0; i--){
            if(ans >= n/2)
              return cnt; 
            cnt++;
            ans += v[i];
        }
        return 0;
    }
};