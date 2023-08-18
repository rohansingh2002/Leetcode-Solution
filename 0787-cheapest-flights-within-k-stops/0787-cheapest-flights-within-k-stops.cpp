class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<int>dist(n,INT_MAX);
        
        pq.push({0,{src,0}});
        dist[src] = 0;
        while(!pq.empty()){
            int stops = pq.top().first;
            int node = pq.top().second.first;
            int dis = pq.top().second.second;
            pq.pop();
            
            if(stops > k) continue;
            for(auto it : adj[node]){
                int adjnode = it.first;
                int adjw = it.second;
                
                if(dis + adjw < dist[adjnode] && stops <= k){
                    dist[adjnode] = dis + adjw;
                    pq.push({stops+1,{adjnode,dis+adjw}});
                    
                    
                }
            }
            
        }
       if (dist[dst] == INT_MAX)
            return -1;
        return dist[dst];
    }
};