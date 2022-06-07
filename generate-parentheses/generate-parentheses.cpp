class Solution {
private:
    int size = 0;
public:   
    void parenGen(vector<string>& arr, string temp, int l, int r){
		//If the string is at max size, add to array and return
        if(temp.size()==size*2) {
            arr.push_back(temp);
            return;
        }  
		//Check to see if you should append ( at the current depth
        if(r < size) 
            parenGen(arr, temp+'(', l, r+1);
		//Check to see if you should append ) at the current depth
        if(l < size && l < r) 
            parenGen(arr, temp+')', l+1, r);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> arr;
        size = n;
        parenGen(arr, "", 0, 0);
        return arr;
    }
};