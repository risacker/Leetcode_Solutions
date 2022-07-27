class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> v;
        int n = t.length();
        int c = 0;
        for(int i = 0; i < t.length(); i++)
            v[t[i]]--;
        queue<int> q;
        int a = 0;
        int rs = 0;
        int re = 1000000;
        for(int i = 0; i < s.length(); i++){
            if(v.find(s[i]) == v.end())
                continue;
            v[s[i]]++;
            q.push(i);
            if(v[s[i]] <= 0)
                c++;
            if(c == 1)
                a = i;
            if(c == n){
                while(!q.empty()){
                    int p = q.front();
                    if(v[s[p]] > 0){
                        v[s[p]]--;
                        q.pop();
                    }
                    else{
                        a = p;
                        break;
                    }
                }
                if(re - rs > i-a){
                    rs = a;
                    re = i;
                }
            }
        }
        if(re-rs > s.length()){
            return "";
        }
        return 
            s.substr(rs,re-rs+1);
    }
};