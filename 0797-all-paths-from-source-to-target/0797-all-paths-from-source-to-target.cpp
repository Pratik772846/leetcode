class Solution {
    private:
    void dfs(vector<vector<int>>&graph,vector<vector<int>>&ans,vector<int>&temp,int node,vector<int>&vis){
        vis[node] = 1;
        int num = graph.size();
        for(auto it: graph[node]){
            vector<int> temp1= temp;
            temp1.push_back(it);
            if(it==num-1){
               ans.push_back(temp1);
            }
            else{
                dfs(graph,ans,temp1,it,vis);
            }
            
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int num = graph.size();
        vector<vector<int>> ans;
        vector<int> temp;
        temp.push_back(0);
        vector<int> vis(num,0);
        dfs(graph,ans,temp,0,vis);
        return ans;
    }
};