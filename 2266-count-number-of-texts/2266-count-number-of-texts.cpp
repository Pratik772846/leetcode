// class Solution {
//     private:
   
// public:
//     int mod = 1e9+7;
    
//      int solve(string pressedKeys,vector<int>&dp,int ind){
         
//         int num = pressedKeys.size();
//         if(ind>=num) return 1;
//         if(dp[ind]!=-1) return dp[ind];
        
         
//          int maxkeys = (pressedKeys[ind]=='7' || pressedKeys[ind]=='9') ?4 :3;
//          int ans = 0;
//          int ct =1 ;
//          int ctind = ind;
//          while(ct<=maxkeys && pressedKeys[ctind] ==  pressedKeys[ind]){
//              ++ct;
//              ++ctind;
//              ans += solve(pressedKeys,dp,ctind) % mod;
//          }
//          return dp[ind] = ans%mod;
        
//     }
//     int countTexts(string pressedKeys) {
//         int num = pressedKeys.size();
//         vector<int> dp(num+1,-1);
//         return solve(pressedKeys,dp,0)%mod;
//     }
// };
class Solution {
public:
    int dp[100005];
    int mod = 1e9+7;
    int solve(string &str, int idx) {
        if(idx == str.length()) return 1;
        if(dp[idx] != -1) return dp[idx];
        int maxKeyPress = (str[idx] == '7' || str[idx] == '9') ? 4 : 3;
        long long currIndex = idx, pressFrequency = 1, ans = 0;
        while(pressFrequency <= maxKeyPress && str[currIndex] == str[idx]) {
            ++currIndex;
            ++pressFrequency;
            ans += solve(str, currIndex) % mod;
        }
        return dp[idx] = ans%mod;
    }
    int countTexts(string pressedKeys) {
        memset(dp, -1, sizeof(dp));
        return solve(pressedKeys, 0) % mod;
    }
};