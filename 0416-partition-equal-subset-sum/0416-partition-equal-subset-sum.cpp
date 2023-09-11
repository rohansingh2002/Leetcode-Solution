class Solution {
public:
//     bool partition(int ind, vector<int>&nums, int target, vector<vector<int>>&dp){
//         if(target == 0) return true;
//         if(ind == 0) return (target == nums[0]);
        
//         if(dp[ind][target] != -1)  return dp[ind][target];
        
//         int not_take = partition(ind-1,nums,target,dp);
        
//         int take = false;
        
//         if(nums[ind] <= target){
//             take = partition(ind-1,nums,target-nums[ind],dp);
//         }
//         return dp[ind][target] = not_take || take;
//     }
    bool canPartition(vector<int>& nums){
        int total_sum = 0;
        for(int i = 0; i < nums.size(); i++){
            total_sum += nums[i];
        }
        if(total_sum % 2 != 0){
            return false;
        }
        
        int n = nums.size();
         
        int k = total_sum/2;
        
        vector<vector<bool>>dp(n,vector<bool>(k+1,false));
        
        for(int i = 0; i < n; i++){
            dp[i][0] = true;
        }
        
        if (nums[0] <= k){
           dp[0][nums[0]] = true;
        }
        
        for(int ind = 1 ; ind < n ; ind++){
            for(int target = 1; target <= k ; target++){
                bool not_take = dp[ind-1][target];        
                bool take = false;
                if(nums[ind] <= target){
                   take = dp[ind-1][target-nums[ind]];
                }
                 dp[ind][target] = not_take || take;
            }
           
        }
        return dp[n-1][k];
    }
};