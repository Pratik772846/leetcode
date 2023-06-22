class Solution {
    private:
    int solve(vector<int>&prices,int ind,int buy,vector<vector<int>>&dp){
        int num = prices.size();
        if(ind==num) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit=0;
        if(buy){
            int take = - prices[ind] + solve(prices,ind+1,0,dp);
            int nottake = solve(prices,ind+1,1,dp);
            profit = max(take,nottake);
        }
        else{
            int take = prices[ind] + solve(prices,ind+1,1,dp);
            int nottake = solve(prices,ind+1,0,dp);
            profit = max(take,nottake);
        }
        return dp[ind][buy] =profit;
        
    }
    private:
    int tab(vector<int> &prices){
        int num = prices.size();
        vector<vector<int>>dp(num+1,vector<int>(2,0));
        dp[num][0] = 0; 
        dp[num][1] =0;
        for(int i=num-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j==1){
                    int take = - prices[i] + dp[i+1][0];
                    int nottake = dp[i+1][1];
                    dp[i][j] = max(take,nottake);
                }
                else{
                    int take = prices[i] + dp[i+1][1];
                    int nottake = dp[i+1][0];
                    dp[i][j] = max(take,nottake);
                }
            }
        }
        return dp[0][1];
    }
public:
    int maxProfit(vector<int>& prices) {
        int num = prices.size();
        vector<vector<int>> dp(num,vector<int>(2,-1));
        return tab(prices);
        // return solve(prices,0,1,dp);
    }
};