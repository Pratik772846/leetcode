class Solution {
  public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>>q;
        // stops,node,price
        q.push({0,{src,0}});
        vector<int> dist(n,1e9);
        dist[src] =0;
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int price = it.second.second;
            
            if(stops>K) continue;
            
            for(auto p:adj[node]){
                int city = p.first;
                int cost = p.second;
                if(dist[city]> cost+price){
                    dist[city] = cost+price;
                    q.push({stops+1,{city,dist[city]}});
                }
            }
        }
        
        if(dist[dst]==1e9) return -1;
        return dist[dst];
        
    }
};

