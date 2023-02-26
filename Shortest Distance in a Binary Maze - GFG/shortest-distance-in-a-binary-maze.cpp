//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

// pta nhi kya chl rha hai
// class Solution {
//   public:
//     int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
//                      pair<int, int> destination) {

//         if(source.first == destination.first && source.second == destination.second){
//             return 0;
//         }
//         queue<pair<int,pair<int,int>>> pq;
//         int row = grid.size();
//         int col = grid[0].size();
//         int dist[row][col]={INT_MAX};
//         pq.push({0,{source.first,source.second}});
//         dist[source.first][source.second] =0;
        
        
//         while(!pq.empty()){
//             int wt = pq.front().first;
//             int row1 = pq.front().second.first;
//             int col1=  pq.front().second.second;
//             pq.pop();
//             for(int i=-1;i<=1;i++){
//                 for(int j=-1;j<=1;j++){
//                     if(abs(i+j)==1 && row1+i >=0 && row1+i <row && col1+j>=0 && col1+j<col && grid[row1+i][col1+j]==1 && wt+1 <dist[row1+i][col1+j]){
//                             dist[row1+i][col1+j] = wt+1;
//                             if(row1+i == destination.first && col1+j ==destination.second){
//                                 return wt+1;
//                             }
//                             pq.push({wt+1,{row1+i,col1+j}});
                        
//                     }
//                 }
//             }
//         }
//             if(dist[destination.first][destination.second]==INT_MAX){
//                 return -1;
//             }
//             return dist[destination.first][destination.second];
            
//         }
//     };

class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination)
    {
        // Edge Case: if the source is only the destination.
        if (source.first == destination.first &&
            source.second == destination.second)
            return 0;

        // Create a queue for storing cells with their distances from source
        // in the form {dist,{cell coordinates pair}}.
        queue<pair<int, pair<int, int>>> q;
        int n = grid.size();
        int m = grid[0].size();

        // Create a distance matrix with initially all the cells marked as
        // unvisited and the source cell as 0.
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[source.first][source.second] = 0;
        q.push({0, {source.first, source.second}});

        // The following delta rows and delts columns array are created such that
        // each index represents each adjacent node that a cell may have 
        // in a direction.
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // Iterate through the maze by popping the elements out of the queue
        // and pushing whenever a shorter distance to a cell is found.
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            // Through this loop, we check the 4 direction adjacent nodes
            // for a shorter path to destination.
            for (int i = 0; i < 4; i++)
            {
                int newr = r + dr[i];
                int newc = c + dc[i];

                // Checking the validity of the cell and updating if dist is shorter.
                if (newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] 
                == 1 && dis + 1 < dist[newr][newc])
                {
                    dist[newr][newc] = 1 + dis;

                    // Return the distance until the point when
                    // we encounter the destination cell.
                    if (newr == destination.first &&
                        newc == destination.second)
                        return dis + 1;
                    q.push({1 + dis, {newr, newc}});
                }
            }
        }
        // If no path is found from source to destination.
        return -1;
    }
};




//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends