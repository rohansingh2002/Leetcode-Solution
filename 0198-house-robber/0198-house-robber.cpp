class Solution {
public:
    int robber(int ind, vector<int>&nums,vector<int>&dp){
        if(ind == 0) return nums[0];
        if(ind < 0) return 0;
        if(dp[ind] != -1) return dp[ind];
        int not_take = 0 + robber(ind-1,nums,dp);  
        int take = nums[ind] + robber(ind-2,nums,dp);
        return dp[ind] = max(take,not_take);  
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return robber(n-1,nums,dp);
    }
};