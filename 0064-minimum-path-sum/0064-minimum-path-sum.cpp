class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int> > dp(n,vector<int>(m,0));
       for(int i=0; i<n ; i++){
        for(int j=0; j<m; j++){
            if(i==0 && j==0) dp[i][j] = grid[i][j];
            else{
                
                int up = INT_MAX;
                if(i>0) up =grid[i][j]+ dp[i-1][j];
         
                
                int left =  INT_MAX;
                if(j>0) left=grid[i][j]+dp[i][j-1];
           
                
                dp[i][j] = min(up,left);
            }
        }
    }
    
    return dp[n-1][m-1];
    
    }
    // int minSumpath(int i,int j,vector<vector<int>>&grid, vector <vector<int>> &dp){  
    //    if (i == 0 && j == 0) {
    //         return grid[i][j];
    //     }
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int m = INT_MAX;
    //     if (j > 0) {
    //         m = grid[i][j] +  minSumpath( i, j - 1,grid,dp);
    //     }
    //     if (i > 0) {
    //         int s = grid[i][j] +  minSumpath(i - 1, j,grid,dp);
    //         m = min(m, s);
    //     }
    //     return m;
    // }
};