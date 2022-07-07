class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
    for(int i = 0; i < ransomNote.size(); i++){
       char c = ransomNote[i];
       auto it = find(magazine.begin(), magazine.end(), c);
       if(it == magazine.end())
           return false;
       else
           magazine.erase(it);
    }
   return true;
  }
};