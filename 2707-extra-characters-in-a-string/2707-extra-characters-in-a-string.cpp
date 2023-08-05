class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<int> dp(n+2,0);
        unordered_set<string> dictionarySet(dictionary.begin(),dictionary.end());
        // int len =0;
        // for(auto it:dictionary){
        //     int a = it.size();
        //     len = max(len,a);
        // }
        for (int start = n - 1; start >= 0; start--) {
            dp[start] = dp[start + 1] + 1;
            for (int end = start; end < n; end++) {
                auto curr = s.substr(start, end - start + 1);
                if (dictionarySet.count(curr)) {
                    dp[start] = min(dp[start], dp[end + 1]);
                }
            }
        }
        return dp[0];
        
    }
};