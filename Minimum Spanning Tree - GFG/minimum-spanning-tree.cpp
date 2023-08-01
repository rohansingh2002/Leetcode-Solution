//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class disjointset{
    public:
     vector<int>parent,rank;
     
     disjointset(int n){
         parent.resize(n+1,0);
         rank.resize(n+1,0);
         for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
     }
     
     int findup(int n){
         if( n == parent[n]){
             return n;
         }
         return parent[n] = findup(parent[n]);
     }
     
     void unionbyrank(int u,int v){
         int ulpu = findup(u);
         int ulpv = findup(v);
         
         if(ulpu == ulpv)  return;
         
         if(rank[ulpu] < rank[ulpv]){
             parent[ulpu] = ulpv;
         }
         else if(rank[ulpu] > rank[ulpv]){
             parent[ulpv] = ulpu;
         }
         else{
             parent[ulpv] = ulpu;
             rank[ulpu]++;
         }
         
     }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {  
       disjointset ds(V);
       vector<pair<int,pair<int,int>>>edges;
        
       for(int i = 0 ; i < V ; i++){
           for( auto it : adj[i]){
               int wt = it[1];
               int v = it[0];
               int u = i;
               edges.push_back({wt,{u,v}});
           }
       }
       sort(edges.begin(),edges.end());
       
       int sum = 0;
       
       for(auto it : edges){
           int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (ds.findup(u) != ds.findup(v)) {
                sum += wt;
                ds.unionbyrank(u, v);
            }
        }

        return sum;
       
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends