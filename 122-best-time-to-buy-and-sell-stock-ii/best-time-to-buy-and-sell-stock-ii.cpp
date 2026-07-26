class Solution {
public:
    int f(vector<int>& prices, int ind, int buy, vector<vector<int>>& dp) {
        int n = prices.size();
        if (ind == n)
            return 0;
        int profit;
        if (dp[ind][buy] != -1)
            return dp[ind][buy];
        if (buy) {
            profit = max(-prices[ind] + f(prices, ind + 1, 0, dp),
                         0 + f(prices, ind + 1, 1, dp));
        } else {
            profit = max(prices[ind] + f(prices, ind + 1, 1, dp),
                         0 + f(prices, ind + 1, 0, dp));
        }
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n+1, vector<int>(2, 0));
        vector<int>prev(2,0),curr(2,0);
        // dp[n][1] = dp[n][0] = 0;
        
         for (int ind = n - 1; ind >= 0; ind--) {
            curr[1] = max(-prices[ind] + prev[0],
                          prev[1]);
            curr[0] = max(prices[ind] + prev[1],
                          prev[0]);
            prev = curr;
        }
    return prev[1];
    }
};