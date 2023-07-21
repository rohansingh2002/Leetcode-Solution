class Solution {
public:
    int unique_path(vector<vector<int>>&dp, int m, int n ){
        if( m == 0 && n == 0) return 1;
        if( m<0 || n<0) return 0;
        if(dp[m][n] != 0)  return dp[m][n];
        int top = unique_path(dp,m-1,n);
        int right = unique_path(dp,m,n-1);
        return dp[m][n] = top+right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        return unique_path(dp,m-1,n-1);
    }
};