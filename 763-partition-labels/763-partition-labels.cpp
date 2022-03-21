class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last_idx(26);
        int sz = s.size();
        for(int i = 0;i < sz;i++){
            last_idx[s[i]-'a'] = i;
        }     
        vector<int> res;                       
        int start = 0;                         
        int end = 0;                         
        for(int i = 0;i < sz;i++){
            end = max(end,last_idx[s[i]-'a']);
            if(i == end){
                res.push_back(end-start+1);
                start = i+1;
            }
        }   
        return res;
    }
};