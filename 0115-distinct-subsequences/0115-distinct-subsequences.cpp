class Solution {
    private:
    int solve(string &s,string &t,int ind,int ind1,vector<vector<int>>&dp){
        if(ind1==0) return 1;
        if(ind==0) return 0;
        
        if(dp[ind][ind1]!=-1) return dp[ind][ind1];

        if(s[ind-1]==t[ind1-1]){
            return dp[ind][ind1] = solve(s,t,ind-1,ind1-1,dp) + solve(s,t,ind-1,ind1,dp);
        }
        // cout<<solve(s,t,ind-1,ind1,dp);
        return dp[ind][ind1] =  solve(s,t,ind-1,ind1,dp);
    }
    

    
public:
    int numDistinct(string s, string t) {
        int num = s.size();
        int num1 = t.size();
        vector<vector<int>> dp(num+1,vector<int>(num1+1,-1));
        return solve(s,t,num,num1,dp);
    }
};