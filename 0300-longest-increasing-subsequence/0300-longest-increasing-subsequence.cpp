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
        vector<int>dp(n,1);
        int maxi = 1;
        for(int ind = 0; ind < n; ind++){
            for(int prev_ind = 0; prev_ind <ind ; prev_ind++){
               if(nums[ind]>nums[prev_ind] && (1 + dp[prev_ind]) > dp[ind]){
                   dp[ind] = 1 + dp[prev_ind];
                   maxi = max(maxi, dp[ind]);
               }     
            }
        }
      return maxi;
    }
};