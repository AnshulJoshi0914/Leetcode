class Solution {
public:
    int f(vector<int>& coins, int amount, int ind, vector<vector<int>>& dp) {
        if (ind == 0) {
            if (amount % coins[ind] == 0)
                return amount / coins[ind];
            else
                return -1;
        }
        if (dp[ind][amount] != -1)
            return dp[ind][amount];
        int notake = 0 + f(coins, amount, ind - 1, dp);
        int take = INT_MAX;
        if (amount >= coins[ind]) {
            take = 1 + f(coins, amount - coins[ind], ind, dp);
        }
        return dp[ind][amount] = min(notake, take);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount+1,0);
        vector<int> curr(amount+1,0);
        for (int T = 0; T <= amount; T++) {
            if (T % coins[0] == 0)
               prev[T] = T / coins[0];
            else
                 prev[T]=1e9;
        }
        for (int i = 1; i < n; i++) {
            for (int tar = 0; tar <= amount; tar++) {
                int notake = 0 + prev[tar];
                int take = 1e9;
                if (tar >= coins[i]) {
                    take = 1 + curr[tar-coins[i]];
                }
                curr[tar] = min(notake, take);
            }
            prev=curr;
        }
        return prev[amount]>=1e9?-1:prev[amount];
    }
};