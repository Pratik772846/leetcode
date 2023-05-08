//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    int num = nums.size();
	    vector<int> dp(num,1);
	    int maxi =0;
	    for(int i=0;i<num;i++){
	        for(int prev=0;prev<i;prev++){
	            if(nums[i]>nums[prev] && 1+dp[prev]>dp[i]){
	                dp[i] = 1+ dp[prev];
	            }
	        }
	    }
	    
	    vector<int> dp1(num,1);
	    for(int i=num-1;i>=0;i--){
	        for(int j=num-1;j>i;j--){
	            if(nums[i]>nums[j] && 1+dp1[j]>dp1[i]){
	                dp1[i]= 1+dp1[j];
	            }
	        }
	    }
	    
	    for(int i=0;i<num;i++){
	        maxi = max(maxi,dp[i]+dp1[i]-1);https://www.geeksforgeeks.org/jobs?tab=studentjobfair
	    }
	    
	    return maxi;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends