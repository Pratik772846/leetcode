class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        for(int i=0;i<s.size();i++){
            map<char,int>m;
            int res =0;
            bool flag = true;
            for(int j=i;j<s.size() && flag;j++){
                if(m[s[j]]){
                    flag = false;
                }
                else{
                    m[s[j]]++;
                    res++;
                }
            }
            ans = max(ans,res);
        }
        return ans;
    }
};