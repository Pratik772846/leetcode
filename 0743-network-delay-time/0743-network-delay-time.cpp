class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+2);
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
            // adj[it[1]].push_back({it[0],it[2]});
            
        }
        vector<int> dist(n+1,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        dist[k] =0;
        while(!pq.empty()){
            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int adjnode = it.first;
                int adjtime = it.second;
                if(dist[adjnode]>time+adjtime){
                    dist[adjnode]= time+adjtime;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        int maxi = -1e9;
        for(int i=1;i<=n;i++){
            maxi= max(maxi,dist[i]);
        }
        if(maxi==1e9) return -1;
        return maxi;
    }
};