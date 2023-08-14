class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>> pq;

        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        int ct =0;
        while(ct <= k){
            ct++;
            int num = pq.top();
            pq.pop();
            if(ct==k){
                return num;
            }
        }
        return 0;

    }
};