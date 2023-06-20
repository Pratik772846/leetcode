class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int num = nums.size();
        int lo = 0;
        int hi =0;
        long long sum =0;
        vector<int> ans;
        bool flag = false;
        for(int i=0;i<num;i++){
            if(i<k){
                cout<<" -1 ";
                ans.push_back(-1);
                // continue;
            }
            else if(i+k>=num){
                cout<<" -1 ";
                ans.push_back(-1);
                // continue;
            }
            else if(!flag){
                cout<<"no"<<" ";
                int a = i-k;
                int b= i+k;
                for(int j =a;j<=b;j++){
                    sum+=nums[j];
                }
                lo = a;
                hi = b;
                ans.push_back(sum/(2*k+1));
                flag = true;
            }
            else{
                cout<<"yes"<<" ";
                sum -= nums[lo];
                sum += nums[hi+1];
                lo++;
                hi++;
                ans.push_back(sum/(2*k+1));
            }
        }
        return ans;
    }
};