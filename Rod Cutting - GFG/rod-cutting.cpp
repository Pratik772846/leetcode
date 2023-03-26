//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    private:
    int solve(int ind,int v[],vector<vector<int>> &dp,int len){
        if(ind==0){
            return len*v[0];
        }
        if(dp[ind][len]!=-1) return dp[ind][len];
        int nonpick = 0 + solve(ind-1,v,dp,len);
        int pick = -1e9;
        int length = ind + 1;
        if(len>=length){
            pick = v[ind] + solve(ind,v,dp,len-length);
        }
        return dp[ind][len] = max(pick,nonpick);
    }
    int tab(int v[],int num){
        // int num = v.size();
        vector<vector<int>> dp(num,vector<int> (num+1,-1));
        for(int i=0;i<=num;i++){
            dp[0][i] = i*v[0];
        }
        for(int ind = 1; ind <num;ind++){
            for(int length = 0;length<=num;length++){
                int notpick = 0 + dp[ind-1][length];
                int pick = -1e9;
                int len = ind + 1;
                if(length>=len){
                    pick = v[ind] +  dp[ind][length-len];
                }
                dp[ind][length] = max(pick,notpick);
            }
        }
        return dp[num-1][num];
    }
    int space(int v[],int num){
        // int num = v.size();
        vector<int> prev(num+1,0),curr(num+1,0);
        for(int i=0;i<=num;i++){
            prev[i] = i * v[0];
        }
        for(int ind = 1; ind <num;ind++){
            for(int length = 0;length<=num;length++){
                int notpick = 0 + prev[length];
                int pick = -1e9;
                int len = ind + 1;
                if(length>=len){
                    pick = v[ind] +  prev[length-len];
                }
                curr[length] = max(pick,notpick);
            }
            prev= curr;
        }
        return prev[num];
        
    }
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        // return solve(n-1,price,dp,n);
        return tab(price,n);
        // return space(price,n);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends