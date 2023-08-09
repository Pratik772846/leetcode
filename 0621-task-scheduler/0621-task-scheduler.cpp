class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // map<char,int> m;
        // priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>>pq;
        // for(auto it:tasks){
        //     m[it]++;
        // }
//         int ct =0;
        
//         for(auto it:m){
//             pq.push({0,it.first});
//         }
//         while(!pq.empty()){
//             auto it = pq.top();
//             cout<<it.first<<" "<<it.second<<" "<<m[it.second]<<" ";
//             if(it.first<=ct){
//                 pq.pop();
//                 m[it.second]--;
//                 cout<<m[it.second]<<endl;
//                 if(m[it.second]>0){
//                     pq.push({ct+n+1,it.second});
//                 }
//             }
//             ct++;
//         }
//         return ct;
        int num = tasks.size();
        map<char,int> m;
        priority_queue<pair<int,char>>pq;
        priority_queue< pair<int,pair<int,char>>,vector<pair<int,pair<int,char>>>,greater<pair<int,pair<int,char>>>>pq1;
        for(auto it:tasks){
            m[it]++;
        }
        for(auto it:m){
            pq.push({it.second,it.first});
        }
        int ct = 0;
        while(num>0){
            if(!pq.empty()){
                
                auto it = pq.top();
                cout<<num<<" "<<it.first<<" "<<it.second<<endl;
                pq.pop();
                if(it.first>1){
                    pq1.push({ct+n+1,{it.first-1,it.second}});
                }
                if(!pq1.empty()){
                    auto it1 = pq1.top();
                    if(it1.first==ct+1){
                        pq1.pop();
                       pq.push({it1.second.first,it1.second.second});
                    }
                }
                
                num--;
            }
            else if(!pq1.empty()){
                auto it1 = pq1.top();
                    if(it1.first==ct+1){
                        pq1.pop();
                       pq.push({it1.second.first,it1.second.second});
                    }
            }
            ct++;
            
        }
        return ct;
        
    }
};