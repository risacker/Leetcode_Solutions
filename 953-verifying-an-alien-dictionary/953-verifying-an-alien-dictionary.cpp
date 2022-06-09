class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order){
        unordered_map<char, int> mp;
        for(int i = 0; i < order.size(); i++)
            mp[order[i]] = i;    
        for(int i = 0; i < words.size()-1; i++){
            if(!compare(words[i], words[i+1], mp))
                return false;
        }  
        return true;
    }
    
    // returns true if lexicographically  w1 <= w2
    bool compare(string w1, string w2, unordered_map<char, int>& mp){
        int i = 0, j = 0;
        int m = w1.size(), n = w2.size();
        while(i < m && j < n && mp.at(w1[i]) == mp.at(w2[j])){
            i++;
            j++;
        }
        
		// either of the word is finished
        if(i >= m) 
            return true;
        if(j >= n) 
            return false;   
        return mp.at(w1[i]) < mp.at(w2[j]);
    }
};