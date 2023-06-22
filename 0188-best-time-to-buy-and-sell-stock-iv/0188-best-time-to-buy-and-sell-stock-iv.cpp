class Solution {
    private:
    int solve(vector<int>&prices,int ind,int buy,vector<vector<vector<int>>>&dp,int k){
        int num = prices.size();
        if(ind==num || k==0) return 0;
        if(dp[ind][buy][k]!=-1) return dp[ind][buy][k];
        
        if(buy==1){
            return dp[ind][buy][k] = max(-prices[ind]+solve(prices,ind+1,0,dp,k), solve(prices,ind+1,1,dp,k));
        }
        else{
            return dp[ind][buy][k] = max(prices[ind]+solve(prices,ind+1,1,dp,k-1),solve(prices,ind+1,0,dp,k));
        }
        return 1;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int num = prices.size();
        vector<vector<vector<int>>>dp(num+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(prices,0,1,dp,k);
    }
};