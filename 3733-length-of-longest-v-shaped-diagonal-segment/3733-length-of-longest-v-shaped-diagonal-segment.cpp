class Solution {
public:
     vector<vector<int>> d={{1,1},{1,-1},{-1,-1},{-1,1}};
    int dp[500][500][4][2];
    bool valid(int i,int j){
        return i>=0 && i<n && j>=0 && j<m;
    }
    int solve(int i,int j,int t,vector<vector<int>>& grid,int val,bool canTurn){
        if(dp[i][j][t][canTurn]!=-1) return dp[i][j][t][canTurn];
        int i_=i+d[t][0];
        int j_=j+d[t][1];
        if(!valid(i_,j_) || grid[i_][j_]!=val){
            return 0;
        }
        int keepMoving=1+solve(i_,j_,t,grid,val^2,canTurn);
        int length=keepMoving;
        if(canTurn){
            length=max(length,1+solve(i_,j_,(t+1)%4,grid,val^2,false));
        }
        return dp[i][j][t][canTurn]=length;
    }
    int n,m;
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    for(int t=0;t<4;t++){
                        bool canTurn=true;
                        ans=max(ans,solve(i,j,t,grid,2,canTurn)+1);
                    }
                }
            }
        }
        return ans;
    }
};