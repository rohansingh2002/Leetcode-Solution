class Solution {
public:
    
    int minInsertions(string s) {
        int ind1 = s.size();
        int ind2 = s.size();
        
        string str1 = s;
        string ss = s;
        reverse(ss.begin() , ss.end());
        string str2 = ss;
        
        vector<vector<int>>dp(ind1+1,vector<int>(ind2+1,-1));
        
        for(int i = 0; i <= ind1; i++){
            dp[i][0] = 0;
        }
        
        for(int i = 0; i <= ind1; i++){
            dp[0][i] = 0;
        }
        
        for(int i = 1; i <= ind1; i++){
            for(int j = 1; j <= ind2; j++){
               if(str1[i-1] == str2[j-1]){
                      dp[i][j]= 1 + dp[i-1][j-1];
                  }
               else{
                 dp[i][j] = 0 + max(dp[i-1][j],dp[i][j-1]);
                } 
            }
          }
        return ind1 - dp[ind1][ind2];
    }
};