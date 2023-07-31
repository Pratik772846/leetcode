class Solution {
public:
    vector<vector<int>>dp;
    int solve(string &s1,string &s2,int i,int j){
        
        if(i<0 || j<0) return 0;
        int ans =0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            ans = solve(s1,s2,i-1,j-1) + int(s1[i]);
        }
        else{
            ans = max(solve(s1,s2,i-1,j),solve(s1,s2,i,j-1));
        }
        return dp[i][j] = ans;
    }
    int minimumDeleteSum(string s1, string s2) {
        int n = 1001;
        dp.assign(n,vector<int>(n,-1));
        int val =0;
        for(auto it:s1){
            val += int(it);
        }
        for(auto it:s2){
            val += int(it);
        }
        cout<<val<<endl;
        int val1 = solve(s1,s2,s1.size()-1,s2.size()-1);
        cout<<val1<<endl;
        return val-(2*val1);
    }
};