// class Solution {
//     int solve(vector<vector<int>>&grid,vector<vector<int>>&vis){
//         int a = grid.size();
//         int b = grid[0].size();
//         queue<pair<pair<int,int>,int>>q;
//         q.push({{0,0},1});
//         int r[]= {-1,0,1,0};
//         int c[] = {0,1,0,-1};
//         while(!q.empty()){
//             auto it  = q.front();
//             q.pop();
//             int row = it.first.first;
//             int col = it.first.second;
//             int steps= it.second;
//             if(row==a-1 && col ==b-1){
//                 return steps;
//             }
            
//             vis[row][col]=1;
//             for(int i=-1;i<=1;i++){
//                 for(int j=-1;j<=1;j++){
//                     int nr = row + i;
//                     int nc = col + j;
//                     if(nr>=0 && nr<a && nc>=0 && nc<b && !vis[nr][nc]  && grid[nr][nc] == 0){
//                         q.push({{nr,nc},steps+1});
//                     }   
//                 }
//             }
//         }
//         return -1;
        
        
//     }
// public:
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         int row = grid.size();
//         int col = grid[0].size();
//         vector<vector<int>> vis(row,vector<int>(col,0));
//         if(grid[0][0]==1 || grid[row-1][col-1]==1){
//             return -1;
//         }
//         else{
//             return solve(grid,vis);
//         }
        
//         }
// };



class Solution {
public:

bool visit[101][101];
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[n-1][m-1]==1 || grid[0][0]==1){
            return -1;
        }

        queue<vector<int>>Q;
        Q.push({0,0,1});
        visit[0][0] = true;
        int ans = 1;
        int direction[8][8] = {{0,1},{1,0},{-1,0},{0,-1},{-1,1},{1,1},{1,-1},{-1,-1}};


        while(!Q.empty()){
            vector<int>front = Q.front();
            Q.pop();
            // distance of path  from start to end  
            ans = max(ans , front[2]);

            // another stopping conditions 
            if(front[0]==n-1 && front[1]==m-1){
                break;
            }
            // traverse in all 8 directions
            for(int i =0 ; i<8 ; i++){
                int x = front[0] + direction[i][0];
                int y = front[1] + direction[i][1];
        if(x<0 || x>=n || y<0 || y>=m || grid[x][y]==1 || visit[x][y]== true){
            continue;
        }
        if(grid[x][y]==0){
            Q.push({x,y,1+front[2]});
        visit[x][y] = true;
        
        }
            }

        }

        // check if last cell is visited or not 
if(visit[n-1][m-1]==false){
    return -1;
}


return ans;
    }
};