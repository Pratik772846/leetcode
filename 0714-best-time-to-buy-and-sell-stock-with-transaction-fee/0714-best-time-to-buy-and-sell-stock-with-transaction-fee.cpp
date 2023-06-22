class Solution {
    private:
    int solve(vector<int>&prices,int fee,int ind,int buy,vector<vector<int>>&dp){
        int num = prices.size();
        if(ind==num) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        
        if(buy==1){
            return dp[ind][buy] = 
max(-prices[ind]+solve(prices,fee,ind+1,0,dp),solve(prices,fee,ind+1,1,dp));
        }
        else{
            return dp[ind][buy] = max(prices[ind]-fee+solve(prices,fee,ind+1,1,dp),solve(prices,fee,ind+1,0,dp));
        }
        return 1;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int num = prices.size();
        vector<vector<int>>dp(num+1,vector<int>(2,-1));
        return solve(prices,fee,0,1,dp);
    }
};