//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        if(end == start) return 0;
                    
        queue<pair<int,int>>pq;
        
        vector<int>dist(1e5,1e9);
        
        pq.push({start,0});
        dist[start] = 0; 
        
        while(!pq.empty()){
            
            int node = pq.front().first;
            int steps = pq.front().second;
            pq.pop();
            
            
            for(auto it : arr){
                int value = (it*node)%100000;
                
                if(steps + 1 < dist[value]){
                    dist[value] = steps + 1;
                    
                    pq.push({value,steps+1});
                    
                    if(end == value){
                        return steps + 1;
                    }
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends