class Solution {
    private:
    int solve(vector<int>&prices,int ind,int buy,vector<vector<vector<int>>>&dp,int trans){
        int num = prices.size();
        if(ind==num || trans==0) return 0;
        if(dp[ind][buy][trans]!=-1) return dp[ind][buy][trans];
        if(buy==1){
            return dp[ind][buy][trans] = max(-prices[ind]+solve(prices,ind+1,0,dp,trans), solve(prices,ind+1,1,dp,trans));
        }
        else{
            return dp[ind][buy][trans] = max(prices[ind]+solve(prices,ind+1,1,dp,trans-1),solve(prices,ind+1,0,dp,trans));
        }
        return 1;
    }
public:
    int maxProfit(vector<int>& prices) {
        int num = prices.size();
        vector<vector<vector<int>>>dp(num,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(prices,0,1,dp,2);
    }
};