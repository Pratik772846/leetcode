class Solution {
    private:
    void dfs(vector<vector<int>> &adj,vector<int>&vis,int node){
        vis[node]= 1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(adj,vis,it);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int num = isConnected.size();
        vector<vector<int>>adj(num+1);
        for(int i=0;i<num;i++){
            for(int j=0;j<num;j++){
                if(isConnected[i][j] && i!=j){
                    adj[i+1].push_back(j+1);
                }
            }
        }
        
        for(int i=1;i<=num;i++){
            for(auto it:adj[i]){
                cout<<it<<" ";
            }
            cout<<endl;
        }
        vector<int> vis(num+1,0);
        int ct=0;
        for(int i=1;i<=num;i++){
            if(!vis[i]){
                dfs(adj,vis,i);
                ct++;
            }
        }
        return ct;
        
    }
};