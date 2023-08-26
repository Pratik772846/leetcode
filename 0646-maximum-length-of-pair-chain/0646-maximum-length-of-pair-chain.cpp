// class Solution {
// public:
//     bool comp(vector<vector<int>>a,vector<vector<int>>b){
//         return a[1]<b[0];
//     }
//     int solve(vector<vector<int>>&pairs,int ind,vector<int>&dp,int l){
//         int num = pairs.size();
//         if(ind>=num) return 0;
//         if(dp[ind]!=-1) return dp[ind];
//         int take=-1e9,nottake=0;
//         if(pairs[ind][0]>l){
//             take = 1+ solve(pairs,ind+1,dp,pairs[ind][1]);
//             // cout<<l<<" "<<pairs[ind][0]<<endl;
//         }
//         nottake = solve(pairs,ind+1,dp,l);
//         return dp[ind] = max(take,nottake);
        
        
//     }
//     int findLongestChain(vector<vector<int>>& pairs) {
//         sort(pairs.begin(),pairs.end(),comp());
//         int num = pairs.size();
        
//         int ans=0;
//         for(int i=0;i<num;i++){
//             vector<int> dp(num+1,-1);
//             cout<<solve(pairs,i,dp,-3000)<<" ";
//             ans= max(ans,solve(pairs,i,dp,-3000));
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        
        int n = pairs.size();
        int last = INT_MIN;
        int chain = 0;

        sort(pairs.begin(), pairs.end(), [](vector<int> const& a, vector<int> const& b){
            return a[0] < b[0];
        });

        for(auto & p : pairs)
        {
            if(last == INT_MIN || last < p[0])
                last = p[1], chain++;
            else if(last > p[1])
                last = p[1];
        }

        return chain;
    }
};