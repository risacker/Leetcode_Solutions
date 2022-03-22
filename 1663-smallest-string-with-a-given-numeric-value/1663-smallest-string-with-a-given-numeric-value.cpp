class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans = "";
        for(int i = 1;i <= n;i++)
        {  
            for(char c = 'a';c <= 'z';c++)
            {
                int val = c - 'a' + 1;
                int rem = k-val;     
                if(rem <= (n-i)*26) 
                {
                    ans += c; 
                    k -= val;  
                    break;
                }
            }
        }
        return ans;
    }
};