class Solution {
public:
    string toDigit(int num) {
    string word[10] = {"", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine "};
    return word[num];
}

string toTeens(int num) {
    string words = "";
    switch(num) {
        case 10 : 
            words = "Ten ";
            break;
        case 11 : 
            words = "Eleven ";
            break;
        case 12 : 
            words = "Twelve ";
            break;
        case 13 : 
            words = "Thirteen ";
            break;
        case 14 : 
            words = "Fourteen ";
            break;
        case 15 : 
            words = "Fifteen ";
            break;
        case 16 : 
            words = "Sixteen ";
            break;
        case 17 : 
            words = "Seventeen ";
            break;
        case 18 : 
            words = "Eighteen ";
            break;
        case 19 : 
            words = "Nineteen ";
            break;
    }
    return words;
}

string tens(int num) {
    string tens[10] = {"", "", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};
    return tens[num];
}

string countHundreds(int num) {
    string ans = "";
    if(num/100) {
        ans += toDigit(num/100) + "Hundred ";
    }
    num = num%100;
    if(num <= 9) 
        ans += toDigit(num);
    else if(num <= 19)
        ans += toTeens(num);
    else {
        ans += tens(num/10);
        if(num%10) {
             ans += toDigit(num%10);
        }
    }
    if(ans.size() > 0)
        ans.pop_back();
    return ans;
}


string numberToWords(int num) {
    string place[4] = {"", " Thousand ", " Million ", " Billion "};
    if(num == 0)
        return "Zero";
    string ans = "";
    int i=0;
    while(num > 0) {
        int d = num%1000;
        string temp = countHundreds(d);
        int size = temp.size();
        if(size) 
            temp += place[i];
        ans = temp + ans;
        num = num/1000;
        i++;
    }
    if(ans[ans.length()-1] == ' ')
        ans.pop_back();
    return ans;
  }
};