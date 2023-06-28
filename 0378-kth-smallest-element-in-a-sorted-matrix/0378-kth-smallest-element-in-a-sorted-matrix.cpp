class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue< pair<int,pair<int,int>>              ,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int r = matrix.size();
        int c = matrix[0].size();
//         min heap declared
//         value,row,col
        pq.push({matrix[0][0],{0,0}});
        int size =0;
        set<pair<int,int>> s;
        s.insert({0,0});
        while(!pq.empty() && size<k){
            auto it = pq.top();
            pq.pop();
            int val = it.first;
            int row = it.second.first;
            int col = it.second.second;
            size++;
            cout<<val<<" "<<size<<endl;
            if(size==k){
                return val;
            }
            if(row+1 < r && s.find({row+1,col})==s.end()){
                s.insert({row+1,col});
                pq.push({matrix[row+1][col],{row+1,col}});
            }
            if(col+1 <c && s.find({row,col+1})==s.end()){
                s.insert({row,col+1});
                pq.push({matrix[row][col+1],{row,col+1}});
            }
            
        }
        return 0;
        
    }
};