class Solution {
public:
      void dfs(vector<int>&vis,vector<int>ad[],int node,vector<vector<int>>& isConnected,int V){
        vis[node]=1;
        for(int i = 0 ; i < V; i++){
            if(node != i && isConnected[node][i] == 1){
            if(!vis[i]){
                 dfs(vis,ad,i,isConnected,V);
              }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V=isConnected.size();
        vector<int>ad[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j]==1 && i!=j){
                   ad[i].push_back(j);
                   ad[j].push_back(i);
                }
            }
        }
        int c=0;
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                c++;
                dfs(vis,ad,i,isConnected,V);
            }
        }
        return c;  
    }
};