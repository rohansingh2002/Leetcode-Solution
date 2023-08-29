class Solution {
public:
    int count(int ind,vector<int> coins,int amount,vector<vector<int>>&dp){
        if(ind == 0){
            if(amount % coins[0] == 0){
                return amount/coins[0];
            }
            else{
                return 1e9;
            }
        }
        if(dp[ind][amount] != -1) return dp[ind][amount];
        int not_take = 0 + count(ind-1,coins,amount,dp);
        int take = 1e9;
        if(coins[ind] <= amount){
            take = 1 + count(ind,coins,amount-coins[ind],dp);
        }
        return dp[ind][amount] = min(not_take , take) ;
    }
    int coinChange(vector<int>& coins, int amount){
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = count(n-1,coins,amount,dp);
        if(ans >= 1e9) return -1;
        return ans;
    }
};