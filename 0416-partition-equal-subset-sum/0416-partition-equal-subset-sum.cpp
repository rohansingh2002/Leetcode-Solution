class Solution {
public:
    bool partition(int ind, vector<int>&nums, int target, vector<vector<int>>&dp){
        if(target == 0) return true;
        if(ind == 0) return (target == nums[0]);
        
        if(dp[ind][target] != -1)  return dp[ind][target];
        
        int not_take = partition(ind-1,nums,target,dp);
        
        int take = false;
        
        if(nums[ind] <= target){
            take = partition(ind-1,nums,target-nums[ind],dp);
        }
        return dp[ind][target] = not_take || take;
    }
    bool canPartition(vector<int>& nums){
        int total_sum = 0;
        for(int i = 0; i < nums.size(); i++){
            total_sum += nums[i];
        }
        if(total_sum % 2 != 0){
            return false;
        }
        
        int n = nums.size();
        
        vector<vector<int>>dp(n,vector<int>((total_sum/2)+1,-1));
        
        return partition(n-1,nums,total_sum/2,dp);
    }
};