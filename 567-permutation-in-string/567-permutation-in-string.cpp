class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.length(),m=s2.length(),i,j;   
        vector <int> v1(26,0), v2(26,0);    
        if(n>m)
            return false;   
        for(i=0;i<n;i++)
        {
            v1[s1[i]-'a']++;
            v2[s2[i]-'a']++;
        }       
        for(i=0;i<26;i++)
        {
            if(v1[i]!=v2[i])
                break;
        }     
        if(i==26)
            return true;      
        for(i=n;i<m;i++)
        {
            v2[s2[i-n]-'a']--;
            v2[s2[i]-'a']++;
            for(j=0;j<26;j++)
            {
                if(v1[j]!=v2[j])
                    break;
            }           
            if(j==26)
                return true;
        }       
        return false;   
    }
};