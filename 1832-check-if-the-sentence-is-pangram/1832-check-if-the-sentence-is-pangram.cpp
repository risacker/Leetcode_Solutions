class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char>ans(sentence.begin(), sentence.end());
        return ans.size() == 26;
    }
};