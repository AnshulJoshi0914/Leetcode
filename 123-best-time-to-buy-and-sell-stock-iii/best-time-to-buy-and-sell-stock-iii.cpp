class Solution {
public:
    int f(vector<int>& prices, int ind, int buy, int cap,
          vector<vector<vector<int>>>& dp) {
        int n = prices.size();
        if (ind == n || cap == 0)
            return 0;
        if (dp[ind][buy][cap] != -1)
            return dp[ind][buy][cap];
        if (buy) {
            return dp[ind][buy][cap] =
                       max(-prices[ind] + f(prices, ind + 1, 0, cap, dp),
                           0 + f(prices, ind + 1, 1, cap, dp));
        } else {
            return dp[ind][buy][cap] =
                       max(prices[ind] + f(prices, ind + 1, 1, cap - 1,dp),
                           0 + f(prices, ind + 1, 0, cap,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(prices, 0, 1, 2, dp);
    }
};