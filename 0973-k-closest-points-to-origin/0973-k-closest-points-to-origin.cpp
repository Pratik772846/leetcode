class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long,pair<int,int>>> pq;
        for(auto it:points){
            int a = it[0];
            int b = it[1];
            long long c=  (a*a) + (b*b);
            pq.push({c,{a,b}});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            ans.push_back({it.second.first,it.second.second});
        }
        return ans;
    }
};