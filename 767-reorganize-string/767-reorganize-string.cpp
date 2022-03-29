class Solution {
public:
    string reorganizeString(string s) {
        int j = 0;
        for (auto i = 1; i < s.size(); i++){
            j = max(j, i);
            while(j < s.size() && s[j] == s[i-1])
                j++;
            if(j == s.size())
                break;
            swap(s[i],s[j]);
        }
        if (j < s.size()) 
            return s;
        j = s.size();
        for(int i = s.size()-2; i >= 0; i--){
            j = min(j, i);
            while(j >= 0 && s[j] == s[i+1])
                j--;
            if(j < 0)
                return "";
            swap(s[i],s[j]);
        }
        return s;
    }
};