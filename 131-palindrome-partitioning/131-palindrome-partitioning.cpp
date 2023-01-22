class Solution {
public:
    vector<vector<string>> ans;
    bool isPalindrome(string s){
        for(int i = 0 ; i < s.size() /2 ; i++){
            if(s[i] != s[s.size()-1-i]){
                return false;
            }
        }
        return true;
    }
    
    void palindromePartition(string s , int index , vector<string>& arr){
        
        if(index == s.size()){
            ans.push_back(arr);
        }
        for(int i = index ; i < s.size() ; i++ ){
            string left =  s.substr(index ,(i-index)+1);
            if(isPalindrome(left)){
                arr.push_back(left);
                palindromePartition(s , i+1 , arr);
                arr.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> arr;
        palindromePartition(s, 0 ,arr );
        return ans;
    }
};