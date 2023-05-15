class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int num = graph.size();
        vector<int> safe(num,0);
        queue<int> q;
        vector<vector<int>> adj(num);
        for(int i=0;i<num;i++){
            if(graph[i].size()==0){
                q.push(i);
                safe[i] = 1;
            }
            for(auto it:graph[i]){
                adj[it].push_back(i);
            }
            
        }
        
        vector<int> ans;
        while(!q.empty()){
            auto it = q.front();
            ans.push_back(it);
            q.pop();
            
            for(auto p : adj[it]){
                bool flag = true;
                if(!safe[p]){
                    for(auto n :graph[p]){
                        if(!safe[n]){
                            flag = false;
                        }
                    }
                    if(flag){
                      safe[p] = 1;
                      q.push(p);
                    }
                }
                
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};