class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        // vector<vector<int>> dp(n+1, vector<int>(2, 0));
        vector<int>prev(2,0),curr(2,0);
        // dp[n][1] = dp[n][0] = 0;
        
         for (int ind = n - 1; ind >= 0; ind--) {
            curr[1] = max(-prices[ind]-fee + prev[0],
                          prev[1]);
            curr[0] = max(prices[ind] + prev[1],
                          prev[0]);
            prev = curr;
        }
    return prev[1];
    }
};