class Solution {
    private:
    vector<int> solve(vector<int> &v){
        int num = v.size();
        sort(v.begin(),v.end());
        vector<int> dp(num,1),hash(num);
        int maxi =0;
        for(int i=0;i<num;i++){
            hash[i] = i ;
            for(int prev = 0 ;prev<i;prev++){
                if(v[i]%v[prev]==0 && 1+dp[prev]>dp[i]){
                    hash[i]= prev;
                    dp[i]= 1+dp[prev];
                }
            }
            if(dp[i]>dp[maxi]){
                maxi = i;
            }
        }
        vector<int> temp;
        int a = maxi;
        while(maxi!=hash[maxi]){
            temp.push_back(v[maxi]);
            maxi = hash[maxi];
        }
        temp.push_back(v[maxi]);
        return temp;
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        return solve(nums);
    }
};