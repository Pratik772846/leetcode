class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int row = maze.size();
        int col = maze[0].size();
        vector<vector<int>> exit(row,vector<int>(col,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(maze[i][j]=='.' && (i==0 || i==row-1 || j==0 || j==col-1 )){
                    exit[i][j] = 1;
                }
            }
        }
        
        int a = entrance[0];
        int b = entrance[1];
        exit[a][b] =0;
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>> vis(row,vector<int>(col,0));
        q.push({{a,b},0});
        vis[a][b] = 1;
        
        int r[]={-1,0,1,0};
        int c[]={0,-1,0,1};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int i = it.first.first;
            int j = it.first.second;
            int steps = it.second;
            if(exit[i][j]==1){
                return steps;
            }
            for(int k=0;k<4;k++){
                int ni = r[k]+i;
                int nj = c[k]+j;
                if(ni>=0 && ni<row && nj>=0 && nj<col && maze[ni][nj]=='.' && !vis[ni][nj]){
                    vis[ni][nj] = 1;
                    q.push({{ni,nj},steps+1});
                }
            }
        }
        
        return -1;
    }
};