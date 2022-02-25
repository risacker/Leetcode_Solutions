class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        while(i < version1.length() or j < version2.length()){
            string currRevision1 = "0", currRevision2 = "0";
            while(i < version1.length() and version1[i] != '.'){
                currRevision1.push_back(version1[i++]);
            }
            i++;
            while(j < version2.length() and version2[j] != '.'){
                currRevision2.push_back(version2[j++]);
            }
            j++;     
            int revision1 = stoi(currRevision1);
            int revision2 = stoi(currRevision2);
            if(revision1 == revision2){continue;}
            if(revision1 > revision2) return 1;
            else return -1;
        }
        return 0;
    }
};