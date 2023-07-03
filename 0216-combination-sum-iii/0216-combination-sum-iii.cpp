class Solution {
public:
    
    vector<vector<int>> ans;
    
    void solve(int k,int n,int ind,vector<int>&res,int sum){
        
        if(res.size()==k && sum==n){
            for(auto it:res){
                cout<<it<<" ";
            }
            cout<<endl;
            ans.push_back(res);
            return;
        }
        
        if(res.size()>k || sum>n){
            // cout<<sum<<endl;
            return;
        }
        if(ind>n) return;
        
        for(int i=ind;i<=9;i++){
                if(i>n) break;
                res.push_back(i);
                solve(k,n,i+1,res,sum+i);
                res.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> freq(10,0);
        vector<int> res;
        int sum =0;
        solve(k,n,1,res,sum);
        return ans;
    }
};

