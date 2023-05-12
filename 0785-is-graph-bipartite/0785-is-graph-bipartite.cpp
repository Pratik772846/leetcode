class Solution {
    private:
    bool solve(vector<vector<int>>&graph,vector<int>&vis,int node,int color,vector<int>&col){
        vis[node] = 1;
        col[node] = color;
        for(auto it:graph[node]){
            if(col[it]==-1){
                if(solve(graph,vis,it,!color,col)==false){
                    return false;
                }
            }
            else{
                if(col[it]==color){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int num = graph.size();
        vector<int> vis(num,0);
        vector<int> col(num,-1);
        for(int i=0;i<num;i++){
            if(!vis[i]){
                if(solve(graph,vis,i,0,col)==false){
                    return false;
                }
            }
        }
        return true;
    }
};