class Solution {
public:
    vector<int> ans; 
    vector<int> numsSameConsecDiff(int n, int k) { 
        // Specifies the first digit of any number
        // It must lie in the range 1 to 9 only.    
        for(int i = 1; i < 10; i++)
            findX(i, 1, n, k);
        return ans;
    }
    
    void findX(int num, int size, int n, int k){      
        // If no. of digits in num == n, add that num to result and stop recursive loop
        if(size == n){
            ans.push_back(num);
            return;
        }
        // Gives the last digit of the number
        int lastDigit = num % 10;
        // If absolute difference is 0, use recursion only once to avoid duplicate values
        if(k == 0){
            int temp = (num*10) + lastDigit;
            findX(temp, size+1, n, k);
        }
        else{ 
            if((lastDigit+k) <= 9){
                int temp = (num*10) + (lastDigit+k);
                findX(temp, size+1, n, k);
            } 
            if((lastDigit-k) >= 0){
                int temp = (num*10) + (lastDigit-k);
                findX(temp, size+1, n, k);
            }
        }
    }
};