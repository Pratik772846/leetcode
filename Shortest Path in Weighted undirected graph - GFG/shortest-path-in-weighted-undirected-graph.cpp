//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        int N =n;
        vector<pair<int,int>> adj[n+1];
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<int> todist(N+1,INT_MAX);
        int par[N+1];
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,1});
        todist[1] =0;
        par[1] =-1;
        while(!pq.empty()){
            int wt = pq.top().first;
            int node=  pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int fst = it.first;
                int scnd = it.second;
                if(wt+scnd < todist[fst]){
                    todist[fst] = wt+scnd;
                    pq.push({wt+scnd, fst});
                    par[fst] = node;
                }
            }
        }
        if(todist[n] == INT_MAX){
            return {-1};
        }
        vector<int> path;
        int node = n;
        while (par[node] != -1)
        {
            path.push_back(node);
            node = par[node];
        }
        path.push_back(1);

        reverse(path.begin(), path.end());
        return path;

    }
};



//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends