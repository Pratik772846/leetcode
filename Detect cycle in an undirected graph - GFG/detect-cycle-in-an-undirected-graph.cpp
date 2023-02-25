//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
    private:
    bool detectcycle(vector<int> adj[],int vis[],int node){
        queue<pair<int,int>> q;
        q.push({node,-1});
        vis[node]=1;
        while(!q.empty()){
            int chld = q.front().first;
            int par = q.front().second;
            q.pop();
            for(auto it:adj[chld]){
                if(vis[it] && it!=par){
                    return true;
                }
                if(!vis[it]){
                    q.push({it,chld});
                    vis[it] =1;
                }
            }
        }
        return false;
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V] = {0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detectcycle(adj,vis,i)){
                    return true;
                }
            }
        }
        return false;
    }
};


// using dfs
// class Solution {
//     private:
//     bool detectcycle(vector<int> adj[],int vis[], int src,int par[]){
//         vis[src]=1;
        
        
//         for(auto child : adj[src]){
//             if(vis[child]!=1){
//                 par[child]=src;
//                 if(detectcycle(adj,vis,child,par)){
//                     return true;
//                 }
                
//             }
//             else if(vis[child]==1 && child!= par[src]){
//                 return true;
//             }
//         }
//         return false;
//     }
//   public:
//     // Function to detect cycle in an undirected graph.
//     bool isCycle(int V, vector<int> adj[]) {
//         // Code here
//         int vis[V]={0};
//       for(int i=0;i<V;i++){
//             if(!vis[i]){
//             int par[V]={-1};
//             if(detectcycle(adj,vis,i,par)){
//                 return true;
//             }
//             }
//         }
//         return false;

//     }
// };





//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends