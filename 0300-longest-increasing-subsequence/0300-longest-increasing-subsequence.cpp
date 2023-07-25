class Solution {
public:
    // int LIS(int ind,vector<int>nums,int n,int prev_ind){
    //     if(ind == n){
    //         return 0;
    //     }
    //     int not_take = 0 + LIS(ind+1,nums,n,prev_ind);
    //     int take = 0;
    //     if(prev_ind == -1 || nums[ind]>nums[prev_ind]){
    //         take = 1 + LIS(ind+1,nums,n,ind);
    //     }
    //     return max(take,not_take);
    // }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int ind = n-1; ind>=0; ind--){
            for(int prev_ind = ind - 1 ; prev_ind >= -1 ; prev_ind--){
               int not_take = 0 + dp[ind+1][prev_ind+1];
               int take = 0;
               if(prev_ind == -1 || nums[ind]>nums[prev_ind]){
                    take = 1 + dp[ind+1][ind+1];
               } 
               dp[ind][prev_ind+1] = max(take,not_take);
            }
        }
        return dp[0][0];
    }
};