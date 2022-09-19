class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> m;
        for(string path : paths) {
            string s;
            int i;
            int n = path.size();
            for(i = 0; i < n && path[i] != ' '; ++i) 
                s += path[i];
            s += '/'; // common part for every file
            ++i; // skip the space
            while(i < n){
                string temp, file;
                while(i < n && path[i] != '(') 
                    temp += path[i++];
                while(i < n && path[i] != ' ') 
                    file += path[i++];
                m[file].push_back(s + temp);
                ++i;
            }
        }
        for(auto &x : m){
            if(x.second.size() > 1) 
                ans.push_back(x.second);
        }
        return ans;
    }
};