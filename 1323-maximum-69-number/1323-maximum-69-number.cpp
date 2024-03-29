class Solution {
public:
    int maximum69Number (int num) {
        int numCopy = num;
        int indexFirstSix = -1;
        int currDigit = 0;
        while(numCopy > 0){
            if (numCopy % 10 == 6)
                indexFirstSix = currDigit;
            numCopy /= 10;
            currDigit++;
        }
        return indexFirstSix == -1 ? num : num + 3 * (int)pow(10, indexFirstSix);
    }
};