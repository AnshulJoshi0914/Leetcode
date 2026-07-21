class Solution {
public:
    int f(string text1, string text2, int ind1, int ind2,
          vector<vector<int>>& dp) {
        if (ind1 < 0 || ind2 < 0)
            return 0;
        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];
        if (text1[ind1] == text2[ind2]) {
            return 1 + f(text1, text2, ind1 - 1, ind2 - 1, dp);
        }
        return dp[ind1][ind2] = max(f(text1, text2, ind1 - 1, ind2, dp),
                                    f(text1, text2, ind1, ind2 - 1, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<int>prev(m+1,0),curr(m+1,0);
        for (int ind1 = 1; ind1 <= n; ind1++) {
            for (int ind2 = 1; ind2 <= m; ind2++) {
                if (text1[ind1-1] == text2[ind2-1]) {
                    curr[ind2]= 1 + prev[ind2-1];
                }
                else curr[ind2] = max(prev[ind2],curr[ind2-1]);
            }
            prev=curr;
        }
        return prev[m];
    }
};