class Solution {
public:
    string reverseWords(string s) {
        int n;
        string str = ""; 
        string ans = "";
        int c = 0;
        for(int j = 0;j < s.size();j++){
            if(s[j] != ' ' ){
              str += s[j];
              continue;
            }    
           n = str.size();
           c++;   
           for(int i = 0;i < n/2;i++)
               swap(str[i],str[n-i-1]);
            ans += str+" ";
            str = "";
        }
        if(c == 0){
            reverse(str.begin(), str.end());
            return str;
        }
        int i = s.size()-1;
        while(s[i] != ' '){
            ans += s[i];
            i--;
        }
       return ans;
    } 
};