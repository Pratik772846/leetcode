class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> m;
        for(auto it:nums){
            m[it]++;
        }
        for(auto it:m){
            if(it.second==1) return it.first;
        }
        return -1;
    }
};