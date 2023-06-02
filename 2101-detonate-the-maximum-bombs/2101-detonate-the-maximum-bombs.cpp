class Solution {
    private:
    void solve(int i,vector<vector<int>>&adj,vector<int>&vis,int &ct){
        for(auto it:adj[i]){
            if(!vis[it]){
                vis[it] = 1;
                ct++;
                solve(it,adj,vis,ct);
            }
        }
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long xi = bombs[i][0];
                long long yi = bombs[i][1];
                long long ri = bombs[i][2];
                
                long long xj = bombs[j][0];
                long long yj = bombs[j][1];
                long long rj = bombs[j][2];
                
                if((long long)(ri*ri)>= (long long)(xi-xj)*(xi-xj) + (long long)(yi-yj)*(yi-yj) ){
                    adj[i].push_back(j);
                }
                if((long long)(rj*rj)>= (long long)((xi-xj)*(xi-xj)) + (long long)((yi-yj)*(yi-yj))){
                    adj[j].push_back(i);
                }
                
            }
        }
        
        for(int i=0;i<n;i++){
            cout<<" index "<<i<<" ";
            for(int j=0;j<adj[i].size();j++){
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }
        
        int maxi = -1e9;
        for(int i=0;i<n;i++){
            vector<int> vis(n,0);
            int ct = 1;
            vis[i] = 1;
            solve(i,adj,vis,ct);
            cout<<" index "<< i<< " has ct "<<ct<<endl;
            maxi = max(maxi,ct);
        }
        return maxi;
    }
};