// class Solution {
// public:
//     int shortestPathAllKeys(vector<string>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
        
//         set<int> s;
//         int keys =0;
//         priority_queue< pair<int,pair<int,pair<int,int>>>, vector< pair<int,pair<int,pair<int,int>>>>, greater<pair<int,pair<int,pair<int,int>>>>>pq;
//         // if(grid[0][0]!='.') return -1;
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(grid[i][j]=='@'){
//                     pq.push({0,{0,{i,j}}});
//                 }
//                 if(grid[i][j]>='a' && grid[i][j]<='z'){
//                     keys++;
//                 }
//             }
//         }
        
        
//         int r[] = {-1,0,1,0};
//         int c[] = {0,1,0,-1};
        
//         set<pair<int,int>> vis;
        
//         while(!pq.empty()){
//             auto it = pq.top();
//             pq.pop();
//             int count = it.first;
//             int row = it.second.second.first;
//             int col = it.second.second.second;
//             int key = it.second.first;
//             if(key==keys) return count;
            
//             cout<<row<<" "<<col<<endl;
//             vis.insert({row,col});
            
            
//             for(int i=0;i<4;i++){
//                 int nrow = row + r[i];
//                 int ncol = col + c[i];
                
                
//                 if(nrow>=0 && nrow<m && ncol>=0 && ncol<n ){
//                     if(grid[nrow][ncol]>='A' && grid[nrow][ncol]<='Z'){
//                         // cout<<grid[nrow][ncol]<<" "<<nrow<<" "<<ncol<<endl;
                        
//                         if(s.find(tolower(grid[nrow][ncol]))!=s.end() && vis.find({nrow,ncol})==vis.end()){
//                             pq.push({count+1,{key,{nrow,ncol}}});
//                             // cout<<nrow<<" "<<ncol<<" lock "<<endl;
//                         }
//                     }
//                     else if(grid[nrow][ncol]>='a' && grid[nrow][ncol]<='z'){
//                         // cout<<grid[nrow][ncol]<<" "<<nrow<<" "<<ncol<<endl;
//                         // cout<<grid[nrow][ncol]-'0'<<endl;
//                         if(s.find(grid[nrow][ncol])==s.end() && vis.find({nrow,ncol})==vis.end()){
//                             s.insert(grid[nrow][ncol]);
//                             pq.push({count+1,{key+1,{nrow,ncol}}});
//                             cout<<nrow<<" "<<ncol<<" key "<<key+1<<endl;
//                             // keys--;
//                             // if(keys==0) return count+1;
//                         }
                        
//                     }
//                     else if(grid[nrow][ncol]=='.' && vis.find({nrow,ncol})==vis.end()){
//                         pq.push({count+1,{key,{nrow,ncol}}});
//                         cout<<nrow<<" "<<ncol<<" dfsdf "<<endl;
//                     }
//                 }
//             }
//         }
//         // cout<<"jgbj<<endl;
//         return -1;
//     }
// };

class Solution {
public:
    void find(int i,int j,vector<string>&grid,string &s,
              vector<vector<unordered_set<string>>>&vis,
              queue< pair <  pair<int,int>, string  > >&qmt,int m,int n)
    {
        if(i>=m||i<0||j>=n||j<0)return;
        if(grid[i][j]=='#')return;
        

        
        if(grid[i][j]>='a'&&grid[i][j]<='z')
        {
            string tmp=s;
            
            int flg=0;
            for(auto&p:tmp)if(p==grid[i][j])flg=1;
            if(flg==0)
            tmp.push_back(grid[i][j]);
            sort(tmp.begin(),tmp.end());
            if(vis[i][j].find(tmp)!=vis[i][j].end())return;
            vis[i][j].insert(tmp);
            qmt.push({ {i,j},tmp});
            return;
        }
        if(grid[i][j]=='.'||grid[i][j]=='@')
        {
            string tmp=s;
            if(vis[i][j].find(tmp)!=vis[i][j].end())return;
            vis[i][j].insert(tmp);
            qmt.push({ {i,j},tmp});
            return;
        }
        if(grid[i][j]>='A'&&grid[i][j]<='Z')
        {
            string tmp=s;
            char t=grid[i][j]+32;
            int flg=0;
            for(auto&p:tmp)if(p==t)flg=1;
            if(flg==0)return;
            
            if(vis[i][j].find(tmp)!=vis[i][j].end())return;
            vis[i][j].insert(tmp);
            qmt.push({ {i,j},tmp});
        }
    }
    
    int shortestPathAllKeys(vector<string>& grid) 
    {
        int m=grid.size(),n=grid[0].size(),cntk=0,strti,strtj;
        vector<vector<unordered_set<string>>>mp
        (m,vector<unordered_set<string>> (n, unordered_set<string> {}));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='@')
                {
                    strti=i;strtj=j;
                }
                if(grid[i][j]>='a'&&grid[i][j]<='z')cntk++;
            }
        }
        int ans=-1;
        queue< pair <  pair<int,int>, string > >qmt;
        qmt.push({{strti,strtj},""});
        while(qmt.size()>0)
        {
            ans++;
            int sz=qmt.size();
            
            for(int k=0;k<sz;k++)
            {
            pair< pair<int,int>,string >p=qmt.front();
            qmt.pop();
            int i=p.first.first,j=p.first.second;
            string s=p.second;

            if(s.size()==cntk)return ans;
            find(i+1,j,grid,s,mp,qmt,m,n);
            find(i-1,j,grid,s,mp,qmt,m,n);
            find(i,j+1,grid,s,mp,qmt,m,n);
            find(i,j-1,grid,s,mp,qmt,m,n);
            }
        }
        return -1;
    }
};