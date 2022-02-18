class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size(),i=0;        
        string s;
        for( ;i<n;i++)
        {
            while(s.size()>0 && k>0 && s.back()>num[i])
            {
                s.pop_back();
                k--;
            }
            s.push_back(num[i]);
        }
        while (k>0) 
        {
            s.pop_back();
            k--;
        }
        i=0;
        n=s.size();
        while(i<n && s[i]=='0')
            i++;
        return (n==i)?"0":s.substr(i,n); 
    }
};