class Solution {
public:

    bool f(int ind,int target,vector<int>& nums,vector<vector<int>>& dp){
        if(target==0) return true;
        if(ind==0) return target==nums[0];
        if(dp[ind][target]!=-1) return dp[ind][target];
        bool take=f(ind-1,target,nums,dp);
        bool notake=false;
        if(target>=nums[ind]){
            notake=f(ind-1,target-nums[ind],nums,dp);
        }
        return dp[ind][target]=take||notake;
    }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totalsum=0;
        for(int i=0;i<n;i++){
            totalsum+=nums[i];
        }
        if(totalsum%2==1){
            return false;
        }else{
            int k=totalsum/2;
            vector<vector<int>> dp(n,vector<int>(k+1,-1));
            return f(n-1,k,nums,dp);
        }
    }
};