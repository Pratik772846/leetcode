//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // int MinimumEffort(vector<vector<int>>& heights) {
    //     // Code here
    //     priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    //     int row = heights.size();
    //     int col = heights[0].size();
        
    //     int dist[row][col]= {INT_MAX};
    //     dist[0][0] = 0;
    //     pq.push({0,{0,0}});
        
    //     int dr[] = {-1, 0, 1, 0};
    //     int dc[] = {0, 1, 0, -1};


    //     while(!pq.empty()){
    //         auto it = pq.top();
    //         pq.pop();
    //         int diff = it.first;
    //         int nrow = it.second.first;
    //         int ncol = it.second.second;
            
    //         if(nrow == row-1 && ncol ==col-1){
    //             return diff;
    //         }
    //         for(int i=0;i<4;i++){
    //           int nrow1=  nrow + dr[i];
    //           int ncol1 = ncol + dc[i];
                
    //             if(nrow1>=0 && ncol1>=0 && nrow1 <row && ncol1<col){
                    
    //                 int dis = max(abs(heights[nrow][ncol] - heights[nrow1][ncol1]), diff);
                    
    //                 if(dis<dist[nrow1][ncol1]){
    //                     dist[nrow1][ncol1] = dis;
    //                     pq.push({dis,{nrow1,ncol1}});
    //                 }
    //             }
    //         }
    //     }
    //     return 0;
    // }
    
    int MinimumEffort(vector<vector<int>> &heights)
    {
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if (row == n - 1 && col == m - 1)
                return diff;
           
            for (int i = 0; i < 4; i++)
            {

                int newr = row + dr[i];
                int newc = col + dc[i];
                if (newr >= 0 && newc >= 0 && newr < n && newc < m)
                {
                    int newEffort = max(abs(heights[row][col] - heights[newr][newc]), diff);

                    if (newEffort < dist[newr][newc])
                    {
                        dist[newr][newc] = newEffort;
                        pq.push({newEffort, {newr, newc}});
                    }
                }
            }
        }
        return 0; // if unreachable
    }
    
    
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends