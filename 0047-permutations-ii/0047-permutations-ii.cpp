// class Solution {
// public:
    
//     void solve(vector<int>&nums,vector<int>&freq,vector<int>&res,vector<vector<int>> &ans){
//         int num = nums.size();
//         if(res.size()==nums.size()){
//             ans.push_back(res);
//             for(auto it:res){
//                 cout<<it<<" ";
//             }
//             cout<<endl;
//             return ;
//         }
        
//         for(int i=0;i<num;i++){
//             if(!freq[i]){
//                 res.push_back(nums[i]);
//                 freq[i] = 1;
//                 solve(nums,freq,res,ans);
//                 freq[i]=0;
//                 res.pop_back();
//             }
//         }
//     }
    
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         int num = nums.size();
//         vector<int> freq(num,0);
//         vector<vector<int>> ans,ans1;
//         vector<int> res;
//         solve(nums,freq,res,ans);
//         map<vector<int>,int> mp;
//          for(int i = 0; i < ans.size(); i++)
//         {
//             mp[ans[i]]++;
//         }
//         // return ans;
//          for(auto & it: mp)
//         {
//             ans1.push_back(it.first);
//         }

//         return ans1;
//         return {{1,2,3}};
//     }
// };

class Solution {
public:

    void solve(vector<int> nums, int index, vector<vector<int>> & ans)
    {
        if(index >= nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for(int i = index; i < nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            solve(nums, index + 1, ans);

            //backtrack
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans, unique;
        int index = 0;

        map<vector<int>, int> mp;

        solve(nums, index, ans);

        for(int i = 0; i < ans.size(); i++)
        {
            mp[ans[i]]++;
        }

        for(auto & it: mp)
        {
            unique.push_back(it.first);
        }

        return unique;
    }
};


