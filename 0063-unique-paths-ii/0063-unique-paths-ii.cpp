class Solution {
public:
    int fun(int m,int n,vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp){
        if((m==0 && n==0) && obstacleGrid[0][0]!=1){
            return 1;
        }
        else if((m<0 || n<0 )|| obstacleGrid[m][n]==1){
            return 0;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        int lo=fun(m-1,n,obstacleGrid,dp);
        int hi=fun(m,n-1,obstacleGrid,dp);
        return dp[m][n]=lo+hi;   
    }
    int tab(vector<vector<int>> &obstacleGrid){
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        // dp[0][0] = 1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    dp[i][j]=1;
                    continue;
                }
                int right=0,down=0;
                if(j-1>=0 && obstacleGrid[i][j-1]==0){
                    right = dp[i][j-1];
                }
                if(i-1>=0 && obstacleGrid[i-1][j]==0){
                    down = dp[i-1][j];
                }
                dp[i][j] = right+down;
            }
        }
        if(obstacleGrid[m-1][n-1]==1) return 0;
        return dp[m-1][n-1];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        // return fun(m-1,n-1,obstacleGrid,dp);
        return tab(obstacleGrid);
    }
};