class Solution {
public:
    int Profit(int ind, int n, int buy, vector<int>prices, vector<vector<int>>&dp){
        if(ind >= n) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        int profit = 0;
        if(buy == 0){
            int not_take = 0 + Profit(ind+1,n,0,prices,dp);
            int take = -prices[ind] + Profit(ind+1,n,1,prices,dp);
            profit = max(not_take,take);
        }
        else{
            int not_take = 0 + Profit(ind+1,n,1,prices,dp);
            int take = prices[ind] + Profit(ind+2,n,0,prices,dp);
             profit = max(not_take,take);
        }
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return Profit(0, n, 0, prices, dp);
    }
};