class Solution {
public:
    // int unique(int i, int j, vector<vector<int>>&dp){
    //     if( i==0 && j==0){
    //         return 1;
    //     }
    //     if(i < 0 || j < 0){
    //         return 0;
    //     }
    //     if(dp[i][j] != -1) return dp[i][j];
    //     int left = unique(i,j-1,dp);
    //     int upper = unique(i-1,j,dp);
    //     return dp[i][j] = upper + left;
    // }
    int uniquePaths(int m, int n) {
         vector<vector<int>>dp(m,vector<int>(n,-1));
         
         for(int i = 0; i < m ; i++){
             for(int j = 0; j < n ; j++){
                 if( i == 0 && j == 0){
                  dp[0][0] = 1;   
                 }
                 else{
                    int left = 0;
                    int upper = 0;
                    if(j>0){
                     left = dp[i][j-1];
                    }
                    if(i > 0){
                      upper = dp[i-1][j];
                    }
                    dp[i][j] = upper + left;   
                 }      
             }
         }
         return dp[m-1][n-1];
    }
};