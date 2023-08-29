class Solution {
public:
    int bestClosingTime(string customers) {
        int num = customers.size();
//         computes for y
        map<int,int> m;
//         computes for n
        map<int,int> m1;
        m[-1] =0;
        m1[-1] =0;
        for(int i=0;i<num;i++){
            if(customers[i]=='Y'){
                m[i] = m[i-1]+1;
                m1[i] = m1[i-1];
            }
            else{
                m[i] = m[i-1];
                m1[i] = m1[i-1]+1;
            }
        }
        int ans =INT_MAX;
        int ind =0;
        for(int i=0;i<=num;i++){
            int res = (m[num-1]-m[i-1]) ;
            int res1 = (m1[i-1]);
            if(res+res1<ans){
                ans = res+res1;
                ind = i;
                
            }
        }
        return ind;
    }
};