#include <bits/stdc++.h>

class Solution {
    private:
    set<string> ans;
    
    void solve(vector<int>s1,int ind,vector<string>&res,int sum){
        int num = s1.size();
        
        if(res.size()==4 && sum==num){
            // cout<<ind<<" SDS ";
            string s;
            string a = ".";
            for(auto it:res){
                // cout<<it<<" ";
                s.append(it);
                s.append(a);
            }
            s.pop_back();
            cout<<s;
            int ct=0;
            for(auto it:s){
                if(it!='.'){
                    ct++;
                }
            }
            if(ct==num) ans.insert(s);
            cout<<endl;
        }
        if(ind>=num) return;
        if(res.size()>4) return;
        
        if(s1[ind]==0 ){
            res.push_back("0");
            sum++;
            solve(s1,ind+1,res,sum);
            sum--;
            res.pop_back();
        }
        
        int i = ind;
        
        res.push_back(to_string(s1[i]));
        sum++;
        solve(s1,ind+1,res,sum);
        sum--;
        res.pop_back();
        
        
        // int a = s[i]*10 + s[i+1];
        if(i+1<num){
        res.push_back(to_string(s1[i]*10 + s1[i+1]));
        sum += 2;
        solve(s1,ind+2,res,sum);
        sum-=2;
        res.pop_back();
        }
        
        if(i+2<num && (s1[i]*100+ s1[i+1]*10 + s1[i+2])<=255){
        res.push_back(to_string(s1[i]*100+ s1[i+1]*10 + s1[i+2]));
        sum += 3;
        solve(s1,ind+3,res,sum);
        sum-=3;
        res.pop_back();
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<int> s1;
        for(auto it:s){
            // cout<<it-'0'<<" ";
            s1.push_back(it-'0');
        }
        solve(s1,0,res,0);
        vector<string> ans1;
        for(auto it:ans){
            ans1.push_back(it);
        }
        return ans1;
    }
};