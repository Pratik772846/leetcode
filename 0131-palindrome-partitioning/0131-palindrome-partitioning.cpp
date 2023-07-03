class Solution {
    private:
    
    vector<vector<string>> ans;
    
    bool check(string s){
        int num = s.size();
        int i =0;
        int j = num-1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    // vector<vector<string>> ans;
    
    void solve(string s,int ind,vector<string>&res){
        int num = s.size();
        if(ind>num) return;
        if(ind==num){
            bool flag = true;
            // cout<<res.size();
            int ct =0;
            for(auto it:res){
                // cout<<it<<" ";
                ct+= it.size();
                if(!check(it)) flag = false;
            }
            // cout<<endl;
            if(flag && ct==num){
                ans.push_back(res);
            }
            return;
        }
        
        for(int i=ind;i<num;i++){
            for(int j=1;j<=num-i;j++){
                string a = s.substr(i,j);
                
                if(check(a)){
                    // cout<<a<<endl;
                    res.push_back(a);
                    solve(s,i+j,res);
                    res.pop_back();
                }
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> res;
        solve(s,0,res);
        // cout<<check("b")<<endl;
        return ans;
    }
};