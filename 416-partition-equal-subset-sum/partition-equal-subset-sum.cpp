class Solution {
public:
    // bool f(int ind,int target,vector<int>& nums,vector<vector<int>>& dp){
    //     if(target==0) return true;
    //     if(ind==0) return target==nums[0];
    //     if(dp[ind][target]!=-1) return dp[ind][target];
    //     bool take=f(ind-1,target,nums,dp);
    //     bool notake=false;
    //     if(target>=nums[ind]){
    //         notake=f(ind-1,target-nums[ind],nums,dp);
    //     }
    //     return dp[ind][target]=take||notake;
    // }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalsum = 0;

        for (int i = 0; i < n; i++)
            totalsum += nums[i];

        if (totalsum % 2)
            return false;

        int targetsum = totalsum / 2;

        vector<bool> prev(targetsum + 1, false);
        prev[0] = true;

        if (nums[0] <= targetsum)
            prev[nums[0]] = true;

        for (int index = 1; index < n; index++) {
            vector<bool> curr(targetsum + 1, false);
            curr[0] = true;

            for (int target = 1; target <= targetsum; target++) {
                bool notTake = prev[target];

                bool take = false;
                if (nums[index] <= target)
                    take = prev[target - nums[index]];

                curr[target] = take || notTake;
            }

            prev = curr;
        }

        return prev[targetsum];
    }
};