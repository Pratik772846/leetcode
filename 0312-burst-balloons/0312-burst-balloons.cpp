class Solution {
    private:
    int solve(vector<int>&nums,vector<vector<int>>&dp,int i,int j){
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int res = INT_MIN;
        for(int idx=i; idx<=j; idx++){
            int coins = nums[i-1]*nums[idx]*nums[j+1]
                + solve(nums,dp,i, idx-1)
                + solve(nums,dp,idx+1, j);
            
            res = max(res, coins);
        }
        
        return dp[i][j] = res;
    }
public:
    int maxCoins(vector<int>& nums) {
        int num = nums.size();
        vector<int> arr;
        arr.push_back(1);
        for(auto it:nums){
            arr.push_back(it);
        }
        arr.push_back(1);
        vector<vector<int>>dp(num+2,vector<int>(num+2,-1));
        return solve(arr,dp,1,num);
    }
};