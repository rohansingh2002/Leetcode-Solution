class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int maxPro = 0;
    int n = prices.size();
    int minPrice = INT_MAX;
    int cost=0;
    for (int i = 0; i < prices.size(); i++) {
        cost=prices[i] - minPrice;
        maxPro = max(maxPro, cost);
        minPrice = min(minPrice, prices[i]);
    }
    return maxPro;
    }
};
 // similar ques - buy and sell 2
 // trick - min then difference taken
 // TC- O(n)
 // SC-O(1)