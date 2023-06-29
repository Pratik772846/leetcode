class Solution {
public:
    
class Compare{
      public:
      bool operator()(const pair<int, string>& a, const pair<int, string>& b){
        if(a.first == b.first){
          return a.second > b.second;
        }
        return a.first < b.first;
      }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> m;
        for(auto it:words){
            m[it]++;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> pq;
       
        for(auto it:m){
            pq.push({it.second,it.first});
        }
        vector<string> ans;
        while(k--){
            auto it = pq.top();
            pq.pop();
            ans.push_back(it.second);
        }
        return ans;
    }
};