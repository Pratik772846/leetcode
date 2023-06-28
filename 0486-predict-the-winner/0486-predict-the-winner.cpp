class Solution {
    private:
    int solve(vector<int>&nums,vector<vector<int>>&dp,int i,int j){
        if(i>j) return 0;
        if(i==j) return nums[i];
        if(dp[i][j]!=-1) return dp[i][j];
        
        int opt1 = nums[i] - solve(nums,dp,i+1,j);
        int opt2 = nums[j] - solve(nums,dp,i,j-1);
        return dp[i][j] = max(opt1,opt2);
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        int num = nums.size();
        vector<vector<int>>dp(num,vector<int>(num,-1));
        return solve(nums,dp,0,num-1)>=0;
    }
};