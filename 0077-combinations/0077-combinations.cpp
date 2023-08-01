class Solution {
    private:
    void comb(int n, int k , vector<vector<int>> &ans,vector<int> &res,int num){
        if(res.size()==k){
            ans.push_back(res);
            return;
        }
        for(int i=num;i<=n;i++){
                res.push_back(i);
                comb(n,k,ans,res,i+1);
                res.pop_back();
            // }
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans ;
        vector<int> res;
        comb(n,k,ans,res,1);
        return ans;
    }
};