class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        priority_queue<pair<int,int>> pq;
        for(auto it:arr){
            pq.push({abs(it-x),it});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> ans(k);
        // vector<int> res;
        int ct =k-1;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            ans[ct]= it.second;
            // res.push_back(it.second);
            ct--;
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};