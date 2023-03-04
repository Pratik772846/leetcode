//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        long maxsofar = 0;
        long sum =0;
         long k = K;
        for(int i=0;i<k;i++){
            sum += Arr[i];
            maxsofar = max(maxsofar,sum);
        }
        long it =0;
        while(it+k < N){
            sum -= Arr[it];
            sum += Arr[it+k];
            maxsofar = max(maxsofar,sum);
            it++;
        }
        return maxsofar;
        }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends