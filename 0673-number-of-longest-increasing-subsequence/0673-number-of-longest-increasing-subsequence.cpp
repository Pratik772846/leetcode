class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int num = nums.size();
        int maxi =0;
        vector<int> dp(num,1),count(num,1);
        for(int i=0;i<num;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[i]>nums[prev] && 1+dp[prev]>dp[i]){
                    dp[i]= 1+dp[prev];
                    count[i] = count[prev];
                }
                else if(nums[i]>nums[prev] && 1+dp[prev]==dp[i]){
                    count[i]+=count[prev];
                }
            }
            maxi= max(maxi,dp[i]);
        }
        int ct =0;
        for(int i=0;i<num;i++){
            if(dp[i]==maxi){
                ct+=count[i];
            }
        }
        return ct;
    }
};