class Solution {
    int solve(vector<vector<int>>&grid,vector<vector<int>>&vis){
        
        int a = grid.size();
        int b = grid[0].size();
        
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},1});
        vis[0][0] = 1;
        
        while(!q.empty()){
            auto it  = q.front();
            q.pop();
            int row = it.first.first;
            int col = it.first.second;
            int steps= it.second;
            
            if(row==a-1 && col ==b-1){
                return steps;
            }
            
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nr = row + i;
                    int nc = col + j;
                    if(nr>=0 && nr<a && nc>=0 && nc<b && !vis[nr][nc]  && grid[nr][nc] == 0){
                        q.push({{nr,nc},steps+1});
                        vis[nr][nc]=1;
                    }   
                }
            }
        }
        return -1;
        
        
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> vis(row,vector<int>(col,0));
        if(grid[0][0]==1 || grid[row-1][col-1]==1){
            return -1;
        }
        else{
            return solve(grid,vis);
        }
        
        }
};


