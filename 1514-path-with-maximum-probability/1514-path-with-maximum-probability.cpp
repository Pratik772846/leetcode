class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<vector<pair<double,int>>> adj(n+1);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({succProb[i],edges[i][1]});
            adj[edges[i][1]].push_back({succProb[i],edges[i][0]});
        }
        
        
        double ans =0;
        // priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> pq;
        priority_queue<pair<double,int>>pq;
        pq.push({1,start});
        vector<double> dist(n+1,0);
        dist[start]=1;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            double dis = it.first;
            int node = it.second;
            if(node==end){
                return dis;
            }
            // cout<<dis<<" "<<node<<" SSSSSSSS"<<endl;
            for(auto p:adj[node]){
                double ndis = dis * p.first;
                int nnode = p.second;
                // cout<< ndis <<" "<<nnode<<endl;
                if(ndis>dist[nnode]){
                    dist[nnode ] = ndis;
                    pq.push({ndis,nnode});
                }
            }
        }
        return dist[end];
    }
};