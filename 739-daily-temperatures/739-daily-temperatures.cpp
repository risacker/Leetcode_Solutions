class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tem) {
        int n=tem.size();        
        vector<int> loc(n,0);        
        if(n==1) 
            return loc;               
        for(int i=n-2;i>=0;i--){
            if(tem[i]<tem[i+1]){
                loc[i]=i+1;
                continue;
            }
            int temp=loc[i+1];
            while(temp!=0){
                if(tem[temp]>tem[i])
                    break;
                temp=loc[temp];
            }
            loc[i]=temp;
        }       
        for(int i=0;i<n;i++){
           if(loc[i]!=0)
               loc[i]=loc[i]-i;  
        }
        return loc;
    }
};