class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        //fill zeros in a string of smaller length
        if(num1.length() < num2.length()){
                while(num1.length() != num2.length()){
                num1 += "0";
            }
        }  
        else if(num1.length() > num2.length())
        {
            while(num1.length() != num2.length()){
                num2 += "0";
            }
        }
        string ans = "";
        int carry = 0; 
        //start addition from the left instead of right
        // - '0' to convert from string to integer
        // + '0' to convert from integer to string
        for(int i = 0;i < num1.length();i++){
            int value = (num1[i] - '0') + (num2[i] - '0') + carry;
            int curr = value%10;    
            carry = value/10;       
            ans += ('0'+curr);
        }
        if(carry)// if there exists a carry at the end then add it to the answer
            ans += ('0'+carry);
        reverse(ans.begin(), ans.end());//reverse the whole answer again 
        return ans;
    }
};