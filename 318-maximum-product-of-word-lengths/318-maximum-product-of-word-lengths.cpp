class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans = 0;
        int n = words.size();
        vector<int> v;
        for (int i = 0; i < n; i++){
            int x = 0;
            for (int j = 0; j < words[i].size(); j++)
                x |= (1 << (words[i][j] - 'a'));
            v.push_back(x);
            for (int j = 0; j < i; j++){
                if (v[i] & v[j])
                    continue;
                ans = max(ans, (int)(words[i].size() * words[j].size()));
            }
        }
        return ans;
    }
};