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
        
         vector<int>prev(n,0);
         for(int i = 0; i < m ; i++){
             vector<int>curr(n,0);
             for(int j = 0; j < n ; j++){
                 if( i == 0 && j == 0){
                  curr[0] = 1;   
                 }
                 else{
                    int left = 0;
                    int upper = 0;
                    if(j>0){
                     left = curr[j-1];
                    }
                    if(i > 0){
                      upper = prev[j];
                    }
                   curr[j] = upper + left;   
                 }
                 
             }
             prev = curr;
         }
         return prev[n-1];
    }
};