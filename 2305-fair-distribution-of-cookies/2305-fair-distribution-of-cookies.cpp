class Solution {
public:
    int ans=INT_MAX;
    void solve(int ind,vector<int>&child,vector<int>& cookies){

        if(ind==cookies.size()){
            ans=min(ans,*max_element(child.begin(), child.end()));
            return;
        }
        for(int i=0;i<child.size();i++){
            child[i]+=cookies[ind];
            solve(ind+1,child,cookies);
            child[i]-=cookies[ind];
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>child(k,0);
        solve(0,child,cookies);
        return ans;
    }
};