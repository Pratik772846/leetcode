class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for(int i=0;i<manager.size();i++){
            if(manager[i]!=-1)
                adj[manager[i]].push_back(i);;
        }
        
        queue<pair<int,int>>q;
        vector<int> vis(n,0);
        
        q.push({headID,0});
        vis[headID]= 1;
        
        int num =0;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int par = it.first;
            int time = it.second;
            int inform = informTime[par];
            
            for(auto it1:adj[par]){
                if(!vis[it1]){
                    vis[it1]= 1;
                    q.push({it1,time+inform});
                    num = max(num,time+inform);
                }
            }
            
        }
        
        return num;
    }
};