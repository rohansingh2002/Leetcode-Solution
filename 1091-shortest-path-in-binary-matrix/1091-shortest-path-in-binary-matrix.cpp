class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    
       int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>adj(n,vector<int>(m,1e9));
        queue<pair<int,pair<int,int>>>q;
        if(grid[0][0]==1){
            return -1;
        }
        if(n==1 && m==1 && grid[0][0]==0){
            return 1;
        }
        q.push({1,{0,0}});
        int ans=0;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int step=it.first;
            int row=it.second.first;
            int col=it.second.second;
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int newr=row+i;
                    int newc=col+j;
                    if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]!=1 && step+1<adj[newr][newc] ){
                    adj[newr][newc]=step+1;
                    if(newr==n-1 && newc==m-1){
                        return step+1;
                    }
                    q.push({step+1,{newr,newc}});
                    }
                }
            }
        }
        return -1;
        
        
    }
};