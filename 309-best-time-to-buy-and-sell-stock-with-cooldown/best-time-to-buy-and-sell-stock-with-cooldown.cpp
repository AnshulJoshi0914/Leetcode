class Solution {
public:
    int f(vector<int>& prices, int ind, int buy, vector<vector<int>>& dp) {
        int n = prices.size();
        if (ind >= n)
            return 0;
        if (dp[ind][buy] != -1)
            return dp[ind][buy];
        if (buy) {
            return dp[ind][buy] = max(-prices[ind] + f(prices, ind + 1, 0, dp),
                                      0 + f(prices, ind + 1, 1, dp));
        } else {
            return dp[ind][buy] = max(prices[ind] + f(prices, ind + 2, 1, dp),
                                      0 + f(prices, ind + 1, 0, dp));
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> curr(2, 0);
        vector<int> front1(2, 0); 
        vector<int> front2(2, 0); 
        for (int ind = n - 1; ind >= 0; ind--) {
            curr[1] = max(-prices[ind] + front1[0],front1[1]);
            curr[0] = max(prices[ind] + front2[1],front1[0]);
            front2 = front1;
            front1 = curr;
        }
        return front1[1];
    }
};