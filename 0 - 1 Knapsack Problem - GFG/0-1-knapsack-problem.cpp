//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    private:
    int solve(int W,int n,int wt[],int val[],vector<vector<int>>&dp,int ind){
        int weight = W;
        if(ind==0){
        if(weight>=wt[0]){
            return val[0];
        }
        else return 0;
        }
        if(dp[ind][weight]!=-1) return dp[ind][weight];
        int nonpick = solve(W,n,wt,val,dp,ind-1);
        int pick = INT_MIN;
        if(weight>= wt[ind]){
            pick =val[ind] + solve(W-wt[ind],n,wt,val,dp,ind-1);
        }
        return dp[ind][weight] = max(pick,nonpick);
    }
    int tab(int values[],int wt[],int w,int n){
        // int n = wt.size();
        vector<vector<int>> dp(n,vector<int> (w+1,0));
        for(int i=wt[0];i<=w;i++){
            dp[0][i] = values[0];
        }
    
        for(int i=1;i<n;i++){
            for(int j=0;j<=w;j++){
                int notpick = dp[i-1][j];
                int pick = INT_MIN;
                if(j>=wt[i]){
                    pick = values[i] + dp[i-1][j-wt[i]];
                }
                dp[i][j] = max(pick,notpick);
            }
        }
        // cout<<dp[n-1][w];
        return dp[n-1][w];
    }
    public:
    int knapSack(int W, int wt[], int val[], int n) 
    {
       vector<vector<int>> dp(n,vector<int> (W+1,-1));
    //   return solve(W,n,wt,val,dp,n-1);
    return tab(val,wt,W,n);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends