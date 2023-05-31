// class Solution {
// public:
//     int countPaths(int n, vector<vector<int>>& roads) {
//         vector<vector<pair<long long,long long>>> adj(n+5);
//         for(auto it:roads){
//             adj[it[0]].push_back({it[1],it[2]});
//             adj[it[1]].push_back({it[0],it[2]});
//         }
//         priority_queue<pair<long long,long long>,
//                        vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
// //         time,node
//         pq.push({0,0});
//         vector<long long> dist(n+1,1e9);
//         vector<long long> ways(n+1,0);
//         dist[0] =0;
//         ways[0] = 1;
        
//         long long mod = (int)1e9+7;
//         while(!pq.empty()){
//             auto it = pq.top();
//             pq.pop();
//             long long tm = it.first;
//             long long nd = it.second;
//             for(auto p:adj[nd]){
//                 long long adjnode = p.first;
//                 long long time = p.second;
//                 if(dist[adjnode]>tm+time){
//                     dist[adjnode] = tm+time;
//                     ways[adjnode] = ways[nd];
//                     pq.push({dist[adjnode],adjnode});
//                 }
//                 else if(dist[adjnode]==tm+time){
//                     ways[adjnode] = (ways[adjnode] + ways[nd] )%mod;
//                 }
//             }
//         }
//         return ways[n-1]%mod;
        
//     }
// };

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long,long long>>adj[n];
        
        for(auto it: roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>>pq;
    
        vector<long long> dist(n,LONG_MAX),ways(n,0);
        dist[0]=0;
        ways[0]=1;
        int mod=(1e9 +7);
        pq.push({0,0});
        while(!pq.empty())
        {
          long long d=pq.top().first;
          long long int node=pq.top().second;
          pq.pop();
          for(auto it:adj[node])
          {
              long long adjnode=it.first;
              long long int edgwt=it.second;
              if((d+edgwt)<dist[adjnode])
              {
                  dist[adjnode]=d+edgwt;
                  ways[adjnode]=ways[node];
                  pq.push({dist[adjnode],adjnode});
              } else if((d+edgwt)==dist[adjnode])
              {
                   ways[adjnode]=((ways[adjnode]%mod + ways[node])%mod)%mod;
              }
          }
         
        }
        return ways[n-1]%mod;
    }
};