class Solution {
public:
    int trap(vector<int>& height) {
        int lo = 0;
        int hi  = height.size()-1;
        int res =0;
        int maxlo = 0;
        int maxhi = 0;
        while(hi>lo){
            if(height[hi]>=height[lo]){
                // maxlo = max(maxlo,height[lo]);
                if(height[lo]>= maxlo) maxlo = height[lo];
                else res+= maxlo - height[lo];
                
                lo++;
                
            }
            else{
                if(height[hi]>= maxhi) maxhi = height[hi];
                else res+= maxhi - height[hi];
                
                hi--;
            }
        }
        return res;
    }
};