class Solution {
public:
    static bool comp(string &s1, string &s2){
        return s1.size() > s2.size();
    }
    
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        string ans;
        for(auto s : words){
            string st = s.append("#");
            if(ans.find(st) == string ::npos){
                ans += st;
            }
        }
        cout<<ans;
        return ans.size();
    }
};