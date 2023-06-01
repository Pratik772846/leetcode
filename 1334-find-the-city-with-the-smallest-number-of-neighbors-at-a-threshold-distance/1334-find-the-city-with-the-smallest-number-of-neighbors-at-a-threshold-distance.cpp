class Solution {
    private:
    int bfs(int node,vector<vector<pair<int,int>>> &adj,int k){
        int n = adj.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,node});
        vector<int> dist(n,1e9);
        dist[node] =0;
        while(!pq.empty()){
            int dis = pq.top().first;
            int nnode = pq.top().second;
            pq.pop();
            for(auto it:adj[nnode]){
                int adjnode = it.first;
                int wt = it.second;
                if(dis+wt > k) continue;
                if(dist[adjnode]>dis+wt){
                    dist[adjnode] = dis+wt;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        
        int ct=0;
        for(int i=0;i<n;i++){
            // cout<<i<<" "<<dist[i]<<endl;
            if(dist[i]!=0 && dist[i]!=1e9){
                ct++;
            }
        }
        return ct;
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
            
        }
        
        int mini = 1e9;
        int node =-1;
        vector<int> city(n);
        for(int i=0;i<n;i++){
            city[i] = bfs(i,adj,distanceThreshold);
            if(city[i]<=mini){
                mini = city[i];
                node = i;
            }
        }
        // bfs(1,adj,distanceThreshold);
        return node;
        
    }
};