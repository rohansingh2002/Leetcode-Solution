class Solution {
public:
    // int maxGain(int ind,vector<int>&prices, int buy){
    //     if(ind >= prices.size()){
    //         return 0;
    //     }
    //     int profit = 0;
    //     if(buy){
    //         int take = - prices[ind] + maxGain(ind+1,prices,0);
    //         int not_take = 0 + maxGain(ind+1, prices, 1);
    //         profit = max(take, not_take);
    //     }
    //     else{
    //         int take = prices[ind] + maxGain(ind+1,prices,1);
    //         int not_take = 0 + maxGain(ind+1, prices, 0);
    //         profit = max(take, not_take);
    //     }
    //     return profit;
    // }
     int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        dp[n][0] = 0;
        dp[n][1] = 0;
        int profit = 0 ;   
         for(int ind= n-1; ind>=0; ind--){
              for(int buy=0; buy<=1; buy++){
                 if(buy==0){// We can buy the stock
                    profit = max(0+dp[ind+1][0], -prices[ind] + dp[ind+1][1]);
                  }
    
                   if(buy==1){// We can sell the stock
                       profit = max(0+dp[ind+1][1], prices[ind] + dp[ind+1][0]);
                 }
            
            dp[ind][buy]  = profit;
        }
    }
            
    return dp[0][0];
    }
};