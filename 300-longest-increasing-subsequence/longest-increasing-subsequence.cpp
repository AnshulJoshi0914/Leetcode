class Solution {
public:
    int f(vector<int>& nums, int ind, int prev_ind, vector<vector<int>>& dp) {
        int n = nums.size();
        int len;
        if (ind == n)
            return 0;
        if (dp[ind][prev_ind + 1] != -1)
            return dp[ind][prev_ind + 1];
        len = (0 + f(nums, ind + 1, prev_ind, dp)); // Not take
        if (prev_ind == -1 || nums[ind] > nums[prev_ind]) {
            len = max(len, 1 + f(nums, ind + 1, ind, dp));
        }
        return dp[ind][prev_ind + 1] = len;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int len;
        vector<int>next(n+1,0),curr(n+1,0);
        for (int i = n - 1; i >= 0; i--) {
            for (int p = i - 1; p >= -1; p--) {
            len = (next[p+1]); // Not take
            if (p == -1 || nums[i] > nums[p]) {
                len=max(len,1+next[i+1]);
            }
                curr[p + 1] = len;
            }
        next=curr;
        }
        return next[0];
    }
};