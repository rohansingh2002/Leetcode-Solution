class Solution {
public:
    // bool Partition(int ind, int target, vector<int>nums, vector<vector<bool>>&dp){
    //     if(ind == 0) return (target == nums[0]);
    //     if(target == 0) return true;
    //     if(dp[ind][target] != false)  return dp[ind][target];
    //     bool not_take = Partition(ind-1, target, nums, dp);
    //     bool take = false;
    //     if(nums[ind] < target) {
    //         take = Partition(ind-1, target - nums[ind], nums, dp);
    //     }
    //     return dp[ind][target] = take || not_take;
    // }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0;
       
        for(int i = 0; i < n; i++){
            total_sum += nums[i];
        }
        if(total_sum % 2 != 0){
            return false;
        }
        int k = total_sum/2;
        vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    
        for(int i=0; i<n; i++){
            dp[i][0] = true;
        }
        
        if(nums[0]<=k)
            dp[0][nums[0]] = true;
        
        for(int ind = 1; ind<n; ind++){
            for(int target= 1; target<=k; target++){
                
                bool notTaken = dp[ind-1][target];
        
                bool taken = false;
                    if(nums[ind]<=target)
                        taken = dp[ind-1][target-nums[ind]];
            
                dp[ind][target]= notTaken||taken;
            }
        }
        
        return dp[n-1][k];
    }
};