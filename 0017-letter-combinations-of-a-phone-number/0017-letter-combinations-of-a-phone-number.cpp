class Solution {
    void func(string digits , vector<string>&ans, int ind,string &s,map<int,string>m){
        if(s.size()==digits.size()){
            bool flag = true;
            for(auto it:s){
                if(it==' '){
                    flag = false;
                }
            }
            if(flag){
                ans.push_back(s);
            }
        }
        char a = digits[ind];
        int b = a - '0';
        for(auto it:m[b]){
            s[ind] = it;
            func(digits,ans,ind+1,s,m);
            s[ind]= ' ';
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        map<int,string> m;
        m[2] = "abc";
        m[3] ="def";
        m[4] = "ghi";
        m[5] = "jkl";
        m[6] = "mno";
        m[7] = "pqrs";
        m[8] = "tuv";
        m[9] = "wxyz";
        vector<string> ans;
        if(digits.size()==0){
            return {};
        }
        string s(digits.size(),' ');
        func(digits,ans,0,s,m);
        return ans;
    }
};