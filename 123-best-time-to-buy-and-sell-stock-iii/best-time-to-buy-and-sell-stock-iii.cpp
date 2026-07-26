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
                       max(prices[ind] + f(prices, ind + 1, 1, cap - 1, dp),
                           0 + f(prices, ind + 1, 0, cap, dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>after(2, vector<int>(3, 0));
        vector<vector<int>>curr(2, vector<int>(3, 0));
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <=1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {
                    if (buy) {
                        curr[buy][cap] =max(-prices[ind] + after[0][cap], 0 + after[1][cap]);
                    } else {
                        curr[buy][cap] =max(prices[ind] + after[1][cap - 1], 0 + after[0][cap]);
                    }
                }
            }
            after=curr;
        }
        return after[1][2];
    }
};