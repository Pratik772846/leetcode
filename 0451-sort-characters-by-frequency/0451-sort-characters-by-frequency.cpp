class Solution {
public:
    string frequencySort(string s) {
        string ans="";
        priority_queue<pair<int,char>> pq;
        map<char,int> m;
        for(auto it:s){
            m[it]++;
        }
        for(auto it:m){
            pq.push({it.second,it.first});
        }
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int count = it.first;
            auto character = it.second;
            while(count--){
                ans+= character;
            }
        }
        return ans;
    }
};