class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> a = {".-","-...","-.-.","-..",".","..-.","--.","....",
                  "..",".---","-.-",".-..","--","-.","---",".--.",
                  "--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_map<string,int> unmap;
        for(int i = 0; i < words.size(); i++) {
            string st;
            for(int j = 0; j < words[i].size(); j++) 
                st += a[words[i][j] - 'a'];
  		    unmap[st] = 1;
  	    }
        return unmap.size();
    }
};