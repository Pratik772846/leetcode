class Solution {
public:
    int solve(string &s,string &t,int i,int j,vector<vector<int>>&dp){
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==t[j]){
            return dp[i][j] = 1+solve(s,t,i-1,j-1,dp);
        }
        else{
            return dp[i][j] = 0+ max(solve(s,t,i-1,j,dp),solve(s,t,i,j-1,dp));
        }
    }
    bool isSubsequence(string s, string t) {
        int num = s.size();
        int num1 = t.size();
        vector<vector<int>>dp(num,vector<int>(num1,-1));
        int ans = solve(s,t,num-1,num1-1,dp);
        cout<<ans;
        if(ans==num){
            return 1;
        }
        return 0;
    }
};