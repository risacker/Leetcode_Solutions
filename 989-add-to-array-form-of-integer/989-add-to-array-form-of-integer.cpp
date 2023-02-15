class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int carry = 0;
        int sum = 0;
        for (int i = A.size() - 1; i >= 0; --i) {
            sum = carry;
            if (K) {
                sum += (K % 10);
                K /= 10;
            }
            
            sum += A[i];
            A[i] = sum % 10;
            carry = sum / 10;
        }
        
        while (K) {
            sum = carry;
            sum += K % 10;
            A.insert(A.begin(), sum%10);
            carry = sum / 10;
            K /= 10;
        }
        
        if (carry) {A.insert(A.begin(), 1);}
        
        return A;
    }
};