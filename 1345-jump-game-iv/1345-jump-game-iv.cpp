class Solution {
public:
    int minJumps(vector<int>& arr) {
		int n = arr.size();
        unordered_map<int , vector<int>> StoreIndex;
        unordered_map<int , int>DoneElement;
        
        for(int index = 0; index < arr.size(); index++){
            StoreIndex[arr[index]].push_back(index); 
            DoneElement[arr[index]] = 1; 
        }
        
        
        vector<bool>visited(n , false);
        vector<int>parent(n , 0);
        queue<int>openList;
        openList.push(0);
        visited[0] = true;
        
        while(!openList.empty()){
            auto topElement = openList.front();
            openList.pop();
            if(topElement == arr.size() - 1) return parent[topElement];
            
            if((topElement + 1) < n && !visited[topElement + 1]){
                openList.push(topElement + 1);
                parent[topElement + 1] = 1+ parent[topElement];
                visited[topElement + 1] = true;
            }
            if((topElement - 1) >= 0 && !visited[topElement - 1]){
                openList.push(topElement - 1);
                parent[topElement - 1] = 1 + parent[topElement];
                visited[topElement - 1] = true;
            }
            if(DoneElement[arr[topElement]] == 1){
                for(auto equalValIndex : StoreIndex[arr[topElement]]){
                    if(!visited[equalValIndex] && equalValIndex != topElement){
                        if(equalValIndex == n-1) return parent[topElement] + 1;
                        
                        openList.push(equalValIndex);
                        parent[equalValIndex] = 1  + parent[topElement];
                        visited[equalValIndex] = true;
                    }
                }
                DoneElement[arr[topElement]] = 0;
            }
        }
        
        return -1;
	} 
};