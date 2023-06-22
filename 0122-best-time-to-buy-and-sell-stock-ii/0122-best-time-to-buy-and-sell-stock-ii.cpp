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
public:
    int maxProfit(vector<int>& prices) {
        int num = prices.size();
        vector<vector<int>> dp(num,vector<int>(2,-1));
        return solve(prices,0,1,dp);
    }
};