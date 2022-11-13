class Solution {
public:
    string reverseWords(string s) {
    int n = s.size();
    stack<string> words;
    for (int i = 0; i < n; i++) {
        if (s[i] == ' ')
            continue;
        string word = "";
        while (i < n && s[i] != ' ') {
            word += s[i++];
        }
        words.push(word);
    }
    string result = "";
    if (!words.empty()) {
        result = words.top(); words.pop();
        for (; !words.empty(); words.pop()) {
            result += " " + words.top();
        }
    }
    return result;
    }
};