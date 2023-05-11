class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int ct1=0;
        
        queue<pair<int,int>> q;
        
        vector<vector<int>> vis(row,vector<int> (col,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    ct1++;
                }
                if(grid[i][j]==1 && (i==0 || i==row-1 || j==0 || j==col-1)){
                    vis[i][j]  = 1;
                    q.push({i,j});
                }
            }
        }
        int vr[] ={-1,0,1,0};
        int vc[] ={0,1,0,-1};
        
        int ct2 =0;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            ct2++;
            int r= it.first;
            int c= it.second;
            for(int i=0;i<4;i++){
                int nr = r + vr[i];
                int nc = c + vc[i];
                if(nr>=0 && nr<row && nc>=0 && nc<col && !vis[nr][nc] && grid[nr][nc]==1){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
        return ct1-ct2;
        
    }
};