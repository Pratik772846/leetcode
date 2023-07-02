class Solution {
public:
    // vector<vector<int>> ans;
    
    void solve(vector<int>&nums,vector<int>&freq,vector<int>&res,vector<vector<int>> &ans){
        int num = nums.size();
        if(res.size()==nums.size()){
            ans.push_back(res);
            for(auto it:res){
                cout<<it<<" ";
            }
            cout<<endl;
            return ;
        }
        
        for(int i=0;i<num;i++){
            if(!freq[i]){
                res.push_back(nums[i]);
                freq[i] = 1;
                solve(nums,freq,res,ans);
                freq[i]=0;
                res.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int num = nums.size();
        vector<int> freq(num,0);
        vector<vector<int>> ans;
        vector<int> res;
        solve(nums,freq,res,ans);
        return ans;
        
    }
};