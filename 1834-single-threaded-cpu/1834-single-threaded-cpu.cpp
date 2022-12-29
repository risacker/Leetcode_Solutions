class Solution {
private:
	long long max(long long a, int b){
		if(a > b){
			return a;
		}
		return b;
	}
    
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
		if(n == 0){
			return {};
		}
		for(int i = 0; i < n; i++){
			tasks[i].push_back(i);
		}
		sort(tasks.begin(), tasks.end());
		vector<int> ans;
		priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; 
		long long time = tasks[0][0]; 
		int i = 0;
		while(i < n && tasks[i][0] <= time){
			pq.push({tasks[i][1], tasks[i][2]});
			i++;
		}
		while(!pq.empty()){
			pair<int,int> task = pq.top();
			pq.pop();
			ans.push_back(task.second);
			time += task.first; 
			if(pq.empty()){
				if(i < n){
					time = max(time, tasks[i][0]);
				}
			}
			while(i < n && time >= tasks[i][0]){
				pq.push({tasks[i][1], tasks[i][2]});
				i++;
			}
		}

		return ans;
	}
};