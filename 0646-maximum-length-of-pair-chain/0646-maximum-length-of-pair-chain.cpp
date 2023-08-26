class Solution {
public:
    
    int solve(int ind, int n, vector<vector<int>>& pairs, int prev,vector<vector<int>> &dp){
        if(ind == n)
            return 0;
        if(dp[ind][prev + 1] != -1)
            return dp[ind][prev + 1];
        int ans = 0;
        if(prev == -1 ||  pairs[ind][0] > pairs[prev][1])
            ans = max(ans, 1 + solve(ind + 1, n, pairs, ind,dp));
        ans = max(ans, solve(ind + 1, n, pairs, prev,dp));
        return dp[ind][prev + 1] = ans;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int n = pairs.size();
       vector<vector<int>>dp(1001,vector<int>(1002,-1));
        return solve(0, n, pairs, -1,dp);
    }
};