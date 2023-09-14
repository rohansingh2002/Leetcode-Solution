class Solution {
public:
    int maxGain(vector<int>&prices, int ind, int buy, int cap,int n,  vector<vector<vector<int>>>&dp){
        if(ind == n || cap == 0){
            return 0;
        }
        if(dp[ind][buy][cap] != -1)  return dp[ind][buy][cap];
        
        int profit;
        if(buy == 0){
            int not_taken = 0 + maxGain(prices,ind+1,0,cap,n,dp);
            int taken = -prices[ind] + maxGain(prices,ind + 1, 1, cap,n,dp);
            profit = max(not_taken,taken);
        }
        if(buy == 1){
            int not_taken = 0 + maxGain(prices,ind+1,1,cap,n,dp);
            int taken = prices[ind] + maxGain(prices,ind + 1, 0, cap-1,n,dp);
            profit = max(not_taken,taken);
        }
        return dp[ind][buy][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int buy = 0;
        int ind = 0;
        int cap = 2;
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return maxGain(prices, ind, buy, cap, n, dp);
    }
};